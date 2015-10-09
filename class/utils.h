#ifndef HEADER_FILE
#define HEADER_FILE

enum Role {

    Entraineur,
    JoueurAutonome,
    JoueurNonAutonome,
    Manageur,
    Secretaire,
    Recruteur,
    Infirmier
}

struct tm {
  int tm_mday;  // day of month from 1 to 31
  int tm_mon;   // month of year from 0 to 11
  int tm_year;  // year since 1900
}






#endif
