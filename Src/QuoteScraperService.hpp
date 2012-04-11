/* 
 * File:   QuoteScraperService.hpp
 * Author: bag
 *
 * Created on October 18, 2011, 9:09 PM
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
#ifndef _QUOTESCRAPERSERVICE_HPP
#define	_QUOTESCRAPERSERVICE_HPP

#include "stdafx.h"
#include "DBAccess.hpp"
#include "XMLextractor.hpp"
#include "QuoteAccess.hpp"
#include "Stock.hpp"
#include "StockPrice.hpp"

class QuoteScraperService
{
public:
    QuoteScraperService();
    void Initalize(int argc, char *argv[]);
    void Run();
    void Stop();
private:
    void LoadXMLConfiguration();
    void ParseConfiguration(xmlNode *root_element);

    QuoteAccess *m_quoteAccess;
    DBAccess *m_databaseAccess;
    XMLextractor *m_xmlExtractor;
};


#endif	/* _QUOTESCRAPERSERVICE_HPP */

