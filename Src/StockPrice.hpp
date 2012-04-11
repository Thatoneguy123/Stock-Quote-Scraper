/* 
 * File:   StockPrice.hpp
 * Author: bag
 *
 * Created on October 19, 2011, 1:04 AM
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
#ifndef _STOCKPRICE_HPP
#define	_STOCKPRICE_HPP

#include "stdafx.h"

class StockPrice
{
public:
    ~StockPrice(){};
    StockPrice(std::string date, long stockId, double open, double close,
        double high, double low, double volume)
    {
        m_date = date;
        m_stockId = stockId;
        m_open = open;
        m_close = close;
        m_high = high;
        m_low = low;
        m_volume = volume;
    }

    // Accessors
    std::string get_date(){ return(this->m_date); }
    long get_stockId(){ return(this->m_stockId); }
    double get_open(){ return(this->m_open); }
    double get_close(){ return(this->m_close); }
    double get_high(){ return(this->m_high); }
    double get_low(){ return(this->m_low); }
    double get_volume(){ return(this->m_volume); }

private:
    std::string m_date;
    long m_stockId;
    double m_open;
    double m_close;
    double m_high;
    double m_low;
    double m_volume;
};

#endif	/* _STOCKPRICE_HPP */

