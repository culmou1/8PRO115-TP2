#include "utils.h"
#include <cstdlib> 
#include <ctime> 

//----------------------------------------------------------------- convert string to Date
Date To_Date(std::string date) {
	Date convert;
    //Date Show Be like that: 01-01-2015
    try{	
		convert.tm_day = std::stoi(date.substr(0,2));
    	convert.tm_month = std::stoi(date.substr(3,2));
    	convert.tm_year = std::stoi(date.substr(6,4));
    }
    catch(const std::length_error& e){
        std::cout<< e.what() << std::endl;
        std::cout << "You should Format the Date like this: \'dd-mm-year\'-\'01-01-2015\'" << std::endl;

    }
    catch(const std::exception& e){
        std::cout<< e.what()<<std::endl;
    }

	return convert;
}


int RandomInt(int max) {
    return rand()%max+1; 
}

std::ostream &operator <<(std::ostream &o, const Date &a)
	{
		if(a.tm_day == 0 && a.tm_month == 0) {
		   o << std::to_string(a.tm_year);
		   return o;
		}
	  else if (a.tm_day < 10 && a.tm_month < 10) {
			o << "0" << std::to_string(a.tm_day) << "-0" << std::to_string(a.tm_month) << "-" << std::to_string(a.tm_year);
			return o;
		}
	  else if (a.tm_day < 10) { 
			o << "0" << std::to_string(a.tm_day) << "-" << std::to_string(a.tm_month) << "-" << std::to_string(a.tm_year);
			return o;
		}
	  else if (a.tm_month < 10) {
		  o << std::to_string(a.tm_day) << "-0" << std::to_string(a.tm_month) << "-" << std::to_string(a.tm_year);
		  return o;
		}
	  else {
		  o << std::to_string(a.tm_day) << "-" << std::to_string(a.tm_month) << "-" << std::to_string(a.tm_year);
		  return o;
		}
	}