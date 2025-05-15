// Personnage.h
#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "Moteur.h"
#include "Image.h"
#include "Niveau.h"

enum Direction { HAUT, BAS, GAUCHE, DROITE };

class Personnage {
private:
    Image _image;
    int _pointX;
    int _pointY;
    int _skin_x;
    int _skin_y;
    Direction _direction;
    int _compteurMouvement;
    static constexpr int _frequenceMouvement = 8; // Mouvements 8 fois par seconde

public:
    // Constructeur
Personnage(const Image image, int pointX, int pointY, int skin_x, int skin_y,Direction direction);
    // Méthodes principales
    void dessiner() const;
    void allerDroite(Niveau& niveau);
    void allerGauche(Niveau& niveau);
    void allerHaut(Niveau& niveau);
    void allerBas(Niveau& niveau);

    // Utilitaires
    bool bordAtteint(int x, int y) const;
    void mettreAJourDirection();
    void avancer(const Niveau& niveau);
    bool touche(const Personnage& autre) const;

    // Getters
    int getX() const;
    int getY() const;
};

#endif // PERSONNAGE_H_INCLUDED

