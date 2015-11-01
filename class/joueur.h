#ifndef HEADER_FILE
#define HEADER_FILE

class Joueur
{
    std::string _nom;
    std::string _prenom;
    float _taille;
    float _poids;
    std::string _villeNaissance;

public:
    Joueur();

    ~Joueur() = default;
    Joueur(const Joueur& other) = default;
    Joueur(Joueur&& other) = default;
    Joueur& operator=(const Joueur& other) = default;
    Joueur& operator=(Joueur&& other) = default;


//----------------------------------------------------------------- methods for Name
    std::string getName = function(){
        return _nom;
    }

    void setName = function(nom){
        _nom = nom;
    }
//----------------------------------------------------------------- methods for Prenom

    std::string getPrenom = function(){
        return _prenom;
    }

    void setPrenom = function(prenom){
        _prenom = prenom;
    }
//----------------------------------------------------------------- methods for Taille

    float getTaille = function(){
        return _taille;
    }

    void setTaille = function(taille){
        _taille = taille;
    }
//----------------------------------------------------------------- methods for Poids

    float getPoids = function(){
        return _poids;
    }

    void setPoids = function(poids){
        _poids = poids;
    }
//----------------------------------------------------------------- methods for villeNaissance

    float getVilleNaissance = function(){
        return _villeNaissance;
    }

    void setVilleNaissance = function(villeNaissance){
        _villeNaissance = villeNaissance;
    }
};


#endif
