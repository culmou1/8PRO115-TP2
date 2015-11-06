#include "utils.h"

//----------------------------------------------------------------- convert string to Date
Date To_Date(std::string date) {
	Date convert;
    //Date Show Be like that: 01-01-2015
    try{	convert.tm_day = std::stoi(date.substr(0,2));
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

//----------------------------------------------------------------- convert enum to string
static const char * TitreStrings[] = {"Coupe", "Championnat"};
const char * getTextForTitre( int enumVal )
{
  return TitreStrings[enumVal];
}