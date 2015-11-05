#include <iostream>
#include <string>
#include "class/ligue.h"
#include "class\utils.h"

using namespace std;



int main(){
	Ligue* ligue = new Ligue();
	//ligue->CreerClub();
	//ligue->CreerClub();
	//ligue->CreerClub();
	//ligue->AfficherClubs();

	Date curentDate; curentDate.Create(01,05,2000);
	Date previousDate; previousDate.Create(10,05,2000);

	bool x = curentDate>=previousDate;
	bool y = curentDate<=previousDate;

	cout << curentDate.To_String() << ">=" << previousDate.To_String() << "= " << x; 
	cout << endl << curentDate.To_String() << "<=" << previousDate.To_String() << "= " << y << endl; 
    system("pause");

    return 0;
};
