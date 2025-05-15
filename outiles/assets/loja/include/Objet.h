#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED


#include "Dictionnaire.h"
#include <vector>
#include <iostream>
class Objet{
//attributs privés
Image _image;
int _obj_x,_obj_y;
int _skin_x,_skin_y;
string _obj_proprity;

public:
//constucteur
Objet(const Image,const string &,const Dictionnaire&,int ,int );

//methodes
void dessiner()const;
void cacher();

//Getters
string getPropriety()const;
int getObj_x()const;
int getObj_y()const;

};

#endif // OBJET_H_INCLUDED
