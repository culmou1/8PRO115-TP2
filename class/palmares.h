#ifndef HEADER_FILE
#define HEADER_FILE


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
