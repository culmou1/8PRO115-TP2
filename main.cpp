#include <iostream>
#include <string>
#include "class/ligue.h"
#include "class\utils.h"

using namespace std;



int main(){
	Ligue* ligue = new Ligue();
<<<<<<< HEAD
	ligue->CreerClub();
	ligue->CreerClub();
	ligue->CreerClub();
	ligue->AfficherClubs();

	Date currentDate = new Date;

	cout << currentDate.To_String << endl;
=======
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
>>>>>>> 0228e8b70690f17b8cf8250d65dd7e5e84825ed2
    system("pause");

    return 0;
};
