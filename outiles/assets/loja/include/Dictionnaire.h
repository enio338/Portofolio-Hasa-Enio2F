#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED

#include "Tuile.h"
#include <vector>
#include <iostream>
class Dictionnaire{
vector <Tuile>_lesTuiles;


public :
//constructeur
Dictionnaire(const string&);

//methodes
void afficher()const;
bool recherche(const string &,Tuile&)const;

};

#endif // DICTIONNAIRE_H_INCLUDED
