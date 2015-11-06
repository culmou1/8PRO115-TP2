#ifndef UTILS_H
#define UTILS_H

#include <string>
#include<iostream>
#include <stdexcept>

enum Role {
	JOUEUR,
    ENTRAINEUR,
    MANAGER,
    SECRETAIRE,
    RECRUTEUR,
    INFIRMIER
};

struct Date {
public:// Format DD/MM/YYYY
  int tm_day;  // day of month from 1 to 31
  int tm_month;   // month of year from 1 to 12
  int tm_year;  // year since 1900

  void Create(int d, int m, int y) { tm_day=d; tm_month=m; tm_year=y;};

  bool Compare(Date out){
    if(tm_day != out.tm_day)
        return false;
    if(tm_month != out.tm_month)
        return false;
    if(tm_year != out.tm_year)
        return false;

    return true;
  }

  bool operator==(Date &a) {
	  if(a.tm_day == tm_day && a.tm_month == tm_month && a.tm_year == tm_year)
		  return true;
	  else
		  return false;
  }

  bool operator>=(Date &a) {
	  if (tm_day >= a.tm_day) {
		  if(tm_month >= a.tm_month) {
			  if (tm_year >= a.tm_year)
				  return true;
			  else
				  return false;
		  }
		  else
			  return false;
	  }
	  else
		  return false;
  }



    bool operator<=(Date &a) {
	  if (tm_year >= a.tm_year) {
		  if(tm_month >= a.tm_month) {
			  if (tm_day >= a.tm_day)
				  return false;
			  else
				  return true;
		  }
		  else
			  return true;
	  }
	  else
		  return true;
  }


  // Conversion de la date en une string
  std::string To_String() {
    return std::to_string(tm_day) + "-" + std::to_string(tm_month) + "-" + std::to_string(tm_year);
  }
};

Date To_Date(std::string date);
const char * getTextForTitre( int enumVal );

/*bool lookForDate(std::string date, Date dateComparer){

	Date dateEchance = To_Date(date);// Obtien la date a partire de la string
	bool dateDepaser = true;

	if (dateComparer.tm_year <= dateEchance.tm_year){
		if(dateComparer.tm_month <= dateEchance.tm_month){
			if(dateComparer.tm_day <= dateEchance.tm_day){
				dateDepaser = false;
				return dateDepaser;
			}
			dateDepaser = true;
		}
		dateDepaser = true;
	}
	return dateDepaser;
}*/


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
