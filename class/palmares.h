#ifndef HEADER_FILE
#define HEADER_FILE

struct tm {
  int tm_mday;  // day of month from 1 to 31
  int tm_mon;   // month of year from 0 to 11
  int tm_year;  // year since 1900
}

typedef tm Date;


class Palmares
{
public:
    Palmares();

    ~Palmares() = default;
    Palmares(const Palmares& other) = default;
    Palmares(Palmares&& other) = default;
    Palmares& operator=(const Palmares& other) = default;
    Palmares& operator=(Palmares&& other) = default;




};

#endif
