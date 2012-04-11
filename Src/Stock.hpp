/* 
 * File:   Stock.hpp
 * Author: bag
 *
 * Created on December 3, 2011, 2:30 PM
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
#ifndef _STOCK_HPP
#define	_STOCK_HPP

class Stock
{
private:
    std::string m_symbol;
    long m_sid;
public:
    Stock(long sid, std::string symbol) { m_sid = sid; m_symbol = symbol; }
    long get_sid(){ return(m_sid); }
    std::string get_symbol(){ return(m_symbol); }
};


#endif	/* _STOCK_HPP */

