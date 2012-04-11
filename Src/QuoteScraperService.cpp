/******************************************************************************
 QuoteScraperService extracts stock quotes from finance.google.com
    Copyright (C) 2011  Benjamin A. Gura

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

******************************************************************************/
#include <iostream>

#include "QuoteScraperService.hpp"


QuoteScraperService::QuoteScraperService()
{
    this->m_xmlExtractor = new XMLextractor();
    this->m_databaseAccess = new DBAccess();
    this->m_quoteAccess = new QuoteAccess();
}

void QuoteScraperService::Initalize(int argc, char *argv[])
{
    try
    {
        m_xmlExtractor->LoadXMLConfigurationFile("QuoteScraperServiceConfig.xml");
        LoadXMLConfiguration();
        delete m_xmlExtractor;

        m_quoteAccess->Initalize();
    }
    catch(std::exception &ex)
    {
        std::cerr << "Error loading configuration file.";
        exit(1);
    }
}

void QuoteScraperService::Run()
{
    std::list<Stock> stockList =
            m_databaseAccess->GetStocksFromDatabase();

    std::list<Stock>::iterator it = stockList.begin();

    while(it != stockList.end())
    {
        std::cerr << "\nGathering Data For " << it->get_symbol() << "...\n";
        StockPrice *stockPrice = m_quoteAccess->GetSockPrice(*it);
        std::cerr << "Writing Data For " << it->get_symbol() << "...\n";

        m_databaseAccess->WriteStockPriceToDatabase(stockPrice);

        delete stockPrice;

        it++;
    }

}

void QuoteScraperService::Stop()
{

}

void QuoteScraperService::LoadXMLConfiguration()
{
    this->m_databaseAccess->Initialize(
            m_xmlExtractor->get_node_content("database"),
            m_xmlExtractor->get_node_content("pricetable"),
            m_xmlExtractor->get_node_content("stocktable"),
            m_xmlExtractor->get_node_content("hostname"),
            m_xmlExtractor->get_node_content("username"),
            m_xmlExtractor->get_node_content("password"));
}