#include <iostream>
#include <string>
#include "LigueApp.h"

using namespace std;

int main(){
	Application *app = new Application();

	app->CreerClubs();
	app->CreerEffectifs_Staffs_Titres();
	app->CreerRencontres();
	app->FaireAutresFonctions();

    system("pause");

    return 0;
};
