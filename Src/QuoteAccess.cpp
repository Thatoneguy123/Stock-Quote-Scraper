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
#include "QuoteAccess.hpp"
#include "Stock.hpp"
size_t handleData(void *buffer, size_t size, size_t nmemb,
        void *userp);

void QuoteAccess::Initalize()
{
    //mp_xmlExtractor = new XMLextractor();
}

QuoteAccess::~QuoteAccess()
{
    /* Always clean up */
    //curl_easy_cleanup(mp_curl);
}

StockPrice* QuoteAccess::BuildStockPrice(Stock stock, std::string message)
{
    std::string date;
    double open, close, low, high;
    long volume;

    XMLextractor xml;
    xml.LoadXMLFromMemory(message);
    std::string result;

    // Get High
    result = xml.get_node_attribute("high","data");
    if(result != "null")
    {
        result.erase(result.end(),result.end());
        result.erase(result.begin(),result.begin());
        high = atof(result.c_str());
    }

    // Get Low
    result = xml.get_node_attribute("low","data");
    if(result != "null")
    {
        result.erase(result.end(),result.end());
        result.erase(result.begin(),result.begin());
        low = atof(result.c_str());
    }

    // Get Volume
    result = xml.get_node_attribute("volume","data");
    if(result != "null")
    {
        result.erase(result.end(),result.end());
        result.erase(result.begin(),result.begin());
        volume = atoi(result.c_str());
    }

    // Get Open
    result = xml.get_node_attribute("open","data");
    if(result != "null")
    {
        result.erase(result.end(),result.end());
        result.erase(result.begin(),result.begin());
        open = atof(result.c_str());
    }

    // Get Close
    result = xml.get_node_attribute("last","data");
    if(result != "null")
    {
        result.erase(result.end(),result.end());
        result.erase(result.begin(),result.begin());
        close = atof(result.c_str());
    }

    // Get Date
    result = xml.get_node_attribute("trade_date_utc","data");
    if(result != "null")
    {
        result.erase(result.end(),result.end());
        result.erase(result.begin(),result.begin());
        date = result;
    }

    StockPrice *stockPrice = new StockPrice(date,stock.get_sid(),open,close,
            high,low,volume);

    return(stockPrice);
}

StockPrice* QuoteAccess::GetSockPrice(Stock stock)
{
    std::string message;

    CURLcode result;
    CURL *mp_curl;

    mp_curl = curl_easy_init();

    std::string url;
    url.append("http://www.google.com/ig/api?stock=");
    url.append(stock.get_symbol());
    
    /* Tell libcurl what the url is */
    curl_easy_setopt(mp_curl, CURLOPT_URL,url.c_str() );

    /* Tell libcurl to pass all data to write_data function */
    curl_easy_setopt(mp_curl, CURLOPT_WRITEFUNCTION, handleData);

    /* pointer to pass to our read function */
    curl_easy_setopt(mp_curl, CURLOPT_WRITEDATA, &message);
    
    /* get verbose debug output please */
    //curl_easy_setopt(mp_curl, CURLOPT_VERBOSE, 1L);

    /* Make libcurl perform its action, res is enum of errors */
    result = curl_easy_perform(mp_curl);

    curl_easy_cleanup(mp_curl);

    return( BuildStockPrice(stock,message) );
}
/*
 * Buffer holds the message
 * Size is the number of bytes for each element in buffer
 * nmeb is the number of elements, each with size of <size> bytes
 * void * is a pointer to an output stream object. can be set with
 * curl_easy_setopt(CURL *curl, CURLOPT_WRITEDATA, &struct) */
size_t handleData(void *buffer, size_t size, size_t nmemb,
        void *userp)
{
    std::string *message = (std::string *)userp;

    if(nmemb > 0 )
    {
        std::string data((const char*)buffer, nmemb);
        message->append(data);
    }

    return(nmemb*size);
}
