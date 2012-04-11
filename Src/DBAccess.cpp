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

#include <iosfwd>

#include "DBAccess.hpp"

DBAccess::DBAccess()
{

}
void DBAccess::WriteStockPriceToDatabase(StockPrice* stock)
{
    std::stringstream str;
    str << "INSERT INTO " << m_priceTable << " VALUES(\'" << stock->get_date()
            << "\'," << stock->get_stockId() << "," << stock->get_close() << ","
            << stock->get_open() << "," << stock->get_high() << ","
            << stock->get_low() << "," << stock->get_volume() << ");";
    mysqlpp::Query query = m_connection.query(str.str().c_str());

    try
    {
        mysqlpp::StoreQueryResult res = query.store();
        std::cerr << "Successful write to database!\n";
    }
    catch(const mysqlpp::Exception &er)
    {
        std::cerr << "Could not write to database...\n";
        std::cerr << er.what() << "\n";
    }
}
void DBAccess::Initialize(std::string database, std::string priceTable,
        std::string stockTable, std::string host, std::string user,
        std::string pass, int port)
{
    this->m_priceTable = priceTable;
    this->m_stockTable = stockTable;

    if( !m_connection.connect(database.c_str(),host.c_str(),user.c_str(),
            pass.c_str(),port) )
    {
        std::cerr << "Could not establish database connection\n";
        exit(1);
    }
}

std::list<Stock> DBAccess::GetStocksFromDatabase()
{
    std::list<Stock> stockList;

    mysqlpp::Query query = m_connection.query("SELECT sid, ticker FROM %0;");
    query.parse();

    if ( mysqlpp::StoreQueryResult result = query.store(m_stockTable) )
    {
        for (size_t i = 0; i < result.num_rows(); i++)
        {
            Stock stock((int)result[i]["sid"],(std::string)result[i]["ticker"]);
            stockList.push_front(stock);
        }
    }
    else
    {
        std::cerr << "Query to retrieve stocks failed. " << query.error() << "\n";
        exit(1);
    }

    return(stockList);
}