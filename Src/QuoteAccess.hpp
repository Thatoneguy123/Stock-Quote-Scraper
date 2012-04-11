/* 
 * File:   QuoteAccess.hpp
 * Author: bag
 *
 * Created on November 28, 2011, 11:44 PM
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
#ifndef _QUOTEACCESS_HPP
#define	_QUOTEACCESS_HPP

#include "stdafx.h"
#include "StockPrice.hpp"
#include "XMLextractor.hpp"
#include "Stock.hpp"

class QuoteAccess
{
private:
    XMLextractor *mp_xmlExtractor;
    //CURL *mp_curl;
    StockPrice* BuildStockPrice(Stock stock, std::string message);
public:
    void Initalize();
    StockPrice* GetSockPrice(Stock stock);
    ~QuoteAccess();
};
#endif	/* _QUOTEACCESS_HPP */