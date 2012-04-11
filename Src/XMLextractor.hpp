#ifndef XMLEXTRACTOR_HPP
#define	XMLEXTRACTOR_HPP
/* 
 * File:   XMLextractor.hpp
 * Author: bag
 *
 * Created on December 3, 2011, 1:09 PM
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

#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/parser.h>

#include <string>

class XMLextractor
{
private:
    xmlDoc *m_doc;
    xmlNode *m_root_element;
    std::string get_node_content(const std::string& nodeName, xmlNode *node);
    std::string get_node_attribute(const std::string& nodeName,
        const std::string& attribute, xmlNode *node);
public:
    void LoadXMLConfigurationFile(const std::string& fileName);
    void LoadXMLFromMemory(const std::string& xml);
    std::string get_node_content(const std::string& nodeName);
    std::string get_node_attribute(const std::string& nodeName,
        const std::string& attribute);
    ~XMLextractor();
};

#endif	/* XMLEXTRACTOR_HPP*/

