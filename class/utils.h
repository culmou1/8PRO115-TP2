#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "equipe.h"

enum Role {
    ENTRAINEUR,
    MANAGER,
    SECRETAIRE,
    RECRUTEUR,
    INFIRMIER
};

struct Date { // Format DD/MM/YYYY
  int tm_day;  // day of month from 1 to 31
  int tm_month;   // month of year from 1 to 12
  int tm_year;  // year since 1900

  bool Compare(Date out){
    if(tm_day != out.tm_day)
        return false;
    if(tm_month != out.tm_month)
        return false;
    if(tm_year != out.tm_year)
        return false;

    return true;
  }

  // Conversion de la date en une string
  std::string To_String() {
    return std::to_string(tm_day) + "/" + std::to_string(tm_month) + "/" + std::to_string(tm_year);
  }
};

Date To_Date(std::string date) {
	Date convert;
    //Date Show Be like that: 01-01-2015
    try{	convert.tm_day = std::stoi(date.substr(0,2));
    	convert.tm_month = std::stoi(date.substr(3,2));
    	convert.tm_year = std::stoi(date.substr(6,4));
    }
    catch(std::lenght_error& e){
        std::cout<< e.what() << std::endl;
        std::cout << "You should Format the Date like this: \'dd-mm-year\'-\'01-01-2015\'" << std::endl;

    }
    catch(const std::exception& e){
        std::cout<< e.what();
    }

	return convert;
}

Equipe look_up_team(){

}


enum Titre {
    COUPE,
    CHAMPIONNAT
};

enum Raison {
    RETRAITE,
    SALAIREINSUFFISANT,
    TEMPSDEJEU,
    CONFLITSVESTIAIRE,
    FAMILLE,
    ENVIEDECHANGEMENT,
    PERFORMANCES
};





#endif
