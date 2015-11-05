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

	Date currentDate = new Date;

	cout << currentDate.To_String << endl;
    system("pause");

    return 0;
};
