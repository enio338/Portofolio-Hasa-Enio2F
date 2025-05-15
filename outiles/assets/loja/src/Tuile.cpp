
#include "Tuile.h"

//constructeur
Tuile::Tuile(const string &nom,int x,int y,const string &propriete){
 _nom=nom;
 _x=x;
 _y=y;
 _propriete=propriete;

}

//m�thode pour afficher
void Tuile::afficher()const{
cout<<_nom<<": x="<<_x<<", y="<<_y<<", objet "<<_propriete<<endl;

}

// Getters
string Tuile::getNom()const{
return _nom;
}
int Tuile::getX()const{return _x;}
int Tuile::getY()const{return _y;}
string Tuile::getPropriete()const{return _propriete;}
