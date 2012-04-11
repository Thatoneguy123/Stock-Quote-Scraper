/* 
 * File:   DBAccess.hpp
 * Author: bag
 *
 * Created on October 18, 2011, 9:27 PM
 */
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
#ifndef _DBACCESS_HPP
#define	_DBACCESS_HPP

#include "stdafx.h"
#include "Stock.hpp"
#include "StockPrice.hpp"

class DBAccess
{
public:
    DBAccess();
    void Initialize(std::string database, std::string priceTable,
        std::string stockTable, std::string host, std::string user,
        std::string pass, int port=3306);
    void WriteStockPriceToDatabase(StockPrice* stock);
    std::list<Stock> GetStocksFromDatabase();
    
    // Mutators
    void set_priceDatabase(std::string name){ this->m_priceTable = name; }
    void set_stockDatabase(std::string name){ this->m_stockTable = name; }
private:
    mysqlpp::Connection m_connection;
    std::string m_priceTable;
    std::string m_stockTable;
};


#endif	/* _DBACCESS_HPP */

