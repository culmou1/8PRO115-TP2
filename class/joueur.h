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

    std::string getName = function(){
        return _nom;
    }

    void setName = function(nom){
        _nom = nom;
    }

    std::string getPrenom = function(){
        return _prenom;
    }

    void setPrenom = function(prenom){
        _prenom = prenom;
    }

    float getTaille = function(){
        return _taille;
    }

    void setTaille = function(taille){
        _taille = taille;
    }

    float getPoids = function(){
        return _poids;
    }

    void setPoids = function(poids){
        _poids = poids;
    }

    float getVilleNaissance = function(){
        return _villeNaissance;
    }

    void setVilleNaissance = function(villeNaissance){
        _villeNaissance = villeNaissance;
    }
};


#endif
