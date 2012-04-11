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
#include "XMLextractor.hpp"

//<editor-fold desc="Constructors/Initializers/Destructors">
void XMLextractor::LoadXMLConfigurationFile(const std::string& fileName)
{
    m_doc = xmlReadFile(fileName.c_str(),NULL,0);
    
    if(m_doc == NULL)
    {
        // Log Error and Quit
    }
    
    m_root_element = xmlDocGetRootElement(m_doc);
    
    if(m_root_element == NULL)
    {
        // Log Error and quit
    }
}

void XMLextractor::LoadXMLFromMemory(const std::string& xml)
{
    m_doc = xmlReadMemory(xml.c_str(),xml.length(),"noname.xml",NULL,0);
    
    if(m_doc == NULL)
    {
        fprintf(stderr, "Could not parse xml from memory\n");
    }
    else
    {
        m_root_element = xmlDocGetRootElement(m_doc);
        fprintf(stderr,"Loaded xml from memory\n");
    }
}

XMLextractor::~XMLextractor()
{
    xmlFreeDoc(m_doc);
    xmlCleanupParser();
}

//</editor-fold>

//<editor-fold desc="Public Accessors">

std::string XMLextractor::get_node_content(const std::string& nodeName)
{
    return(get_node_content(nodeName,m_root_element)); 
}

std::string XMLextractor::get_node_attribute(const std::string& nodeName,
        const std::string& attribute)
{
    return(get_node_attribute(nodeName, attribute, m_root_element));
}
//</editor-fold>

//<editor-fold desc="Private Methods">
std::string XMLextractor::get_node_attribute(const std::string& nodeName,
        const std::string& attribute, xmlNode *node)
{
    //base case
    if(node == NULL)
        return("null");
    
    xmlNode *cur_node = node;
    std::string attrib = "null";
    
    // Check if this is the node we need
    if(cur_node->type == XML_ELEMENT_NODE &&
            !nodeName.compare((char*)cur_node->name) )
    {
        xmlChar *val = 
                xmlGetProp(cur_node,(const xmlChar *)attribute.c_str());
        if(val != NULL)
        {
            attrib = (char*)val;
            xmlFree(val);
        }
        
        return(attrib);
    }
    
    attrib = get_node_attribute(nodeName, attribute, node->children);
    
    if(attrib == "null")
        return( get_node_attribute(nodeName, attribute, cur_node->next));
    
    return(attrib);
    
}
std::string XMLextractor::get_node_content(const std::string& nodeName, 
        xmlNode *node)
{
    // Check Base Case
    if(node == NULL)
        return("null");
    
    xmlNode *cur_node = node;
    std::string content = "null";
    
    // Check if this is the node we need
    if(cur_node->type == XML_ELEMENT_NODE &&
            !nodeName.compare((char*)cur_node->name) ) 
    {
        content = (char*)cur_node->children->content;
        return(content);
    }

    content = get_node_content(nodeName,cur_node->children);
    
    if(content == "null")
        return( get_node_content(nodeName, cur_node->next));
    
    return(content);
    
}
//</editor-fold>