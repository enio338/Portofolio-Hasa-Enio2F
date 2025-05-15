#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED

#include <iostream>
using namespace std;

class Tuile{
string _nom;
int _x;
int _y;
string _propriete;

public:
//constructeur
Tuile (const string &,int ,int ,const string &);

//méthodes
void afficher()const;

//Getters
string getNom()const;
int getX()const;
int getY()const;
string getPropriete()const;

};

#endif // TUILE_H_INCLUDED
