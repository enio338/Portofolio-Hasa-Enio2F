#include "Dictionnaire.h"
#include <fstream>


//constructeur
Dictionnaire::Dictionnaire(const string& nomFichier) {
    ifstream fichier;
    fichier.open(nomFichier);

    if (!(fichier.is_open())) {
        throw runtime_error("Impossible d'ouvrir le fichier " + nomFichier);
    }

    string nom, propriete;
    int x, y;

    // Ignorer la première ligne
    string ligne;
    getline(fichier, ligne);

    // Lecture des données à partir de la deuxième ligne
    while (fichier >> nom >> x >> y >> propriete) {
        _lesTuiles.emplace_back(nom, x, y, propriete);
    }

    fichier.close(); // Fermeture du fichier
}


//methode recherhce :Recherche une tuile dans le dictionnaire à l'aide de la recherche dichotomique.
bool Dictionnaire::recherche(const string &nomRecherche,Tuile& resultat)const{
bool trouve;
    int debut,fin,milieu;
    debut=0;
    fin=_lesTuiles.size()-1;

    trouve=false;

    while(!trouve && debut<=fin)
    {
        milieu=(debut+fin)/2;
        trouve=(_lesTuiles[milieu].getNom()==nomRecherche);

        if(trouve){
            resultat=_lesTuiles[milieu];
            trouve=true;

        }
        else if(_lesTuiles[milieu].getNom()>nomRecherche) fin=milieu-1;
        else
            debut=milieu+1;
    }
    return trouve;
}
//utilisation de l'algorithme de recherhce dicotomie car le dictionnaire qui nous est fourni est trié


void Dictionnaire::afficher()const{
for(int i=0;i<_lesTuiles.size();i++){
    _lesTuiles[i].afficher();

}
}
