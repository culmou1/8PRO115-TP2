#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <stdexcept>

enum Role {
	JOUEUR,
    ENTRAINEUR,
	ADJOINT,
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

  bool operator==(Date &a) {
	  if(tm_day == a.tm_day && tm_month == a.tm_month && tm_year == a.tm_year)
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

	friend std::ostream &operator <<(std::ostream &o, const Date &a);

  // Conversion de la date en une string
  std::string To_String() {
	  if(tm_day == 0 && tm_month == 0)
		  return std::to_string(tm_year);
	  else if (tm_day < 10 && tm_month < 10)
		return "0"+std::to_string(tm_day) + "-0" + std::to_string(tm_month) + "-" + std::to_string(tm_year);
	  else if (tm_day < 10) 
		  return "0"+std::to_string(tm_day) + "-" + std::to_string(tm_month) + "-" + std::to_string(tm_year);
	  else if (tm_month < 10) 
		  return std::to_string(tm_day) + "-0" + std::to_string(tm_month) + "-" + std::to_string(tm_year);
	  else
		  return std::to_string(tm_day) + "-" + std::to_string(tm_month) + "-" + std::to_string(tm_year);
  }
};



Date To_Date(std::string date);
int RandomInt(int max);

typedef std::string Titre;



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
