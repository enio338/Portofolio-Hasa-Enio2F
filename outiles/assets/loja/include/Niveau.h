#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED

#include "Objet.h"
#include <vector>
#include <iostream>

class Niveau{

vector <Objet> _lesObjets;
int _nbBonus;
public:
//constructeur
Niveau(const Image ,  string& , const Dictionnaire&);

//méthodes
void dessiner()const;
bool caseEstLibre(int x, int y) const;
bool testerBonusEtPrendre(int ,int );
bool gagne()const;
int indiceObjet(int x, int y, const string& propriete)const;

};

#endif // NIVEAU_H_INCLUDED
