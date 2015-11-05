#include <iostream>
#include <string>
#include "class/ligue.h"

using namespace std;



int main(){
	Ligue* ligue = new Ligue();
	ligue->CreerClub();
	ligue->CreerClub();
	ligue->CreerClub();
	ligue->AfficherClubs();
    system("pause");

    return 0;
};
