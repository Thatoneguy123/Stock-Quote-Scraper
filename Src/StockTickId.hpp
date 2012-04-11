/* 
 * File:   StockTickId.hpp
 * Author: bag
 *
 * Created on October 19, 2011, 1:51 AM
 */

#ifndef _STOCKTICKID_HPP
#define	_STOCKTICKID_HPP

class StockTickId
{
public:
    StockTickId(std::string ticker, long id)
        { this->ticker = ticker; this->id = id;}
    std::string get_ticker(){ return(this->ticker); }
    long get_id(){ return(this->id); }
private:
    std::string ticker;
    long id;
};


#endif	/* _STOCKTICKID_HPP */

