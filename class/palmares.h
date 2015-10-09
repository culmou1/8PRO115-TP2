#ifndef HEADER_FILE
#define HEADER_FILE

#include "club.h"
#include "utils.h"

typedef tm Date; // Date pour dd/mm/yy

typedef Titre TitreChoice; // Choisir entre Championat ou Coupe


class Palmares
{

private:
    Date date; // Date
    TitreChoice titre; // titre
    Club *club; // Ajout d'un Club


public:
    Palmares();

    ~Palmares() = default;
    Palmares(const Palmares& other) = default;
    Palmares(Palmares&& other) = default;
    Palmares& operator=(const Palmares& other) = default;
    Palmares& operator=(Palmares&& other) = default;

    Date getDate function(){

        return date;
    }

    Date getDateDays function (){

        return date.tm_mday;
    }

    Date getDateMonth function (){

        return date.tm_mon;
    }

    Date getDateYear function (){

        return date.tm_year;
    }

    void setDate function(Date all_date){

        date.tm_mday = all_date.tm_day;
        date.tm_mon = all_date.tm_mon;
        date.tm_year = all_date.tm_year;
    }
    void setDateDays function(Date day){

        date.tm_mday = day.tm_day;
    }

    void setDateMonth function(Date month){

        date.tm_mday = mouth.tm_mon;
    }

    void setDateYear function(Date year){

        date.tm_mday = year.tm_Year;
    }

    TitreChoice getTitre function (){
        if(titre == Coupe){
            return Coupe ;
        }

        else {
            return Championat;
        }
    }

    void setTitre function (TitreChoice choix){
        if(choix){
            titre = Championat;
        }
        eles{
            titre = Coupe;
        }
    }

    Club getClub function(){

        return club;
    }

    void setClub function(){

        
    }

};

#endif
