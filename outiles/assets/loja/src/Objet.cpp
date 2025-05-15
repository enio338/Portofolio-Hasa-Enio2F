#include "Image.h"
#include "Objet.h"

using namespace std;
Objet::Objet(const Image image,const string &nomObjet,const Dictionnaire &dic,int obj_x,int obj_y){
// Initialisation d'une tuile pour stocker le r�sultat de la recherche
Tuile resultat("", 0, 0, "");

// Recherche dans le dictionnaire
if(dic.recherche(nomObjet,resultat)){
  _image=image;
 // _obj_proprity=resultat.
_obj_proprity = resultat.getPropriete();
_skin_x = resultat.getX();  // Coordonn�e x de la tuile dans la feuille de sprites
_skin_y = resultat.getY();  // Coordonn�e y de la tuile dans la feuille de sprites
_obj_x=obj_x* TAILLE_CASE; // Position en pixels
_obj_y=obj_y* TAILLE_CASE; // Position en pixels

// S�lectionner l'image correspondante � partir des coordonn�es de la tuile
        _image.selectionnerRectangle(_skin_x * TAILLE_CASE, _skin_y * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
}else {
throw runtime_error("Objet non trouv� dans le dictionnaire.");
}

}


//Dessine l'objet sur la fen�tre � sa position actuelle
void Objet::dessiner()const {
    _image.dessiner(_obj_x, _obj_y);
}

void Objet::cacher(){
_obj_proprity="cache";
}

//Getters
string Objet::getPropriety()const{return _obj_proprity;}
int Objet::getObj_x()const{return _obj_x;}
int Objet::getObj_y()const{return _obj_y;}


