#include "Image.h"
#include "Personnage.h"

// Constructeur
Personnage::Personnage(const Image image, int pointX, int pointY, int skin_x, int skin_y,Direction direction) {
    _image = image;
    _pointX = pointX;
    _pointY = pointY;
    _skin_x = skin_x;
    _skin_y = skin_y;
_direction=direction;
_compteurMouvement=0;
mettreAJourDirection();
}
//méthode dessiner: dessine le personnage à sa position actuelle

void Personnage::dessiner()const{
    _image.dessiner(_pointX, _pointY);
}

// Déplacements
void Personnage::allerDroite( Niveau& niveau) {
    static int frame = 0; // Animation frame
    if (!bordAtteint(_pointX + TAILLE_CASE, _pointY)&&niveau.caseEstLibre(_pointX + TAILLE_CASE, _pointY)) {
        _pointX += TAILLE_CASE;
        // Sprite pour "aller à droite" avec animation
        frame = (frame + 1) % 3; // Alterne entre 3 frames
        _image.selectionnerRectangle((_skin_x -1+frame ) * TAILLE_CASE, (_skin_y + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        niveau.testerBonusEtPrendre(_pointX, _pointY);
    }

}

void Personnage::allerGauche( Niveau& niveau) {
    static int frame = 0; // Animation frame
    if (!bordAtteint(_pointX - TAILLE_CASE, _pointY)&& niveau.caseEstLibre(_pointX - TAILLE_CASE, _pointY)) {
        _pointX -= TAILLE_CASE;
        // Sprite pour "aller à gauche" avec animation
        frame = (frame + 1) % 3; // Alterne entre 3 frames
        _image.selectionnerRectangle((_skin_x - 1 + frame) * TAILLE_CASE, (_skin_y + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
         niveau.testerBonusEtPrendre(_pointX, _pointY);
    }

}

void Personnage::allerHaut( Niveau& niveau) {
    static int frame = 0; // Animation frame
    if (!bordAtteint(_pointX, _pointY - TAILLE_CASE)&&niveau.caseEstLibre(_pointX, _pointY - TAILLE_CASE)) {
        _pointY -= TAILLE_CASE;
        // Sprite pour "aller en haut" avec animation
        frame = (frame + 1) % 3; // Alterne entre 3 frames
        _image.selectionnerRectangle((_skin_x - 1 + frame) * TAILLE_CASE, (_skin_y + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
         niveau.testerBonusEtPrendre(_pointX, _pointY);
    }

}

void Personnage::allerBas( Niveau& niveau) {
    static int frame = 0; // Animation frame
    if (!bordAtteint(_pointX, _pointY + TAILLE_CASE)&&niveau.caseEstLibre(_pointX, _pointY + TAILLE_CASE)) {
        _pointY += TAILLE_CASE;
        // Sprite pour "aller en bas" avec animation
        frame = (frame + 1) % 3; // Alterne entre 3 frames
        _image.selectionnerRectangle((_skin_x -1+frame) * TAILLE_CASE, (_skin_y  ) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
        niveau.testerBonusEtPrendre(_pointX, _pointY);
    }

}

// Vérifie si les coordonnées sont hors limites
bool Personnage::bordAtteint(int x, int y) const {
    // Vérifie si le personnage est en dehors des limites de la fenêtre
        return (x < 0 || x >= LARGEUR_FENETRE || y < 0 || y >= HAUTEUR_FENETRE);
}

// méthode qui met à jour l'apparence en fonction de la direction
void Personnage::mettreAJourDirection() {
    switch (_direction) {
        case HAUT:
            _image.selectionnerRectangle((_skin_x) * TAILLE_CASE, (_skin_y + 3) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case BAS:
            _image.selectionnerRectangle((_skin_x) * TAILLE_CASE, (_skin_y) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case GAUCHE:
            _image.selectionnerRectangle((_skin_x) * TAILLE_CASE, (_skin_y + 1) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
        case DROITE:
            _image.selectionnerRectangle((_skin_x) * TAILLE_CASE, (_skin_y + 2) * TAILLE_CASE, TAILLE_CASE, TAILLE_CASE);
            break;
    }
}

// méthode avance permet le déplacement automatique des enemis selon la direction
void Personnage::avancer(const Niveau& niveau) {
    _compteurMouvement++;
    if (_compteurMouvement < _frequenceMouvement) {
        return; // Attend que le compteur atteigne la fréquence
    }
    _compteurMouvement = 0; // Réinitialise le compteur

    int nouveauX = _pointX;
    int nouveauY = _pointY;

    // Calcule la nouvelle position en fonction de la direction
    switch (_direction) {
        case HAUT:
            nouveauY -= TAILLE_CASE;
            break;
        case BAS:
            nouveauY += TAILLE_CASE;
            break;
        case GAUCHE:
            nouveauX -= TAILLE_CASE;
            break;
        case DROITE:
            nouveauX += TAILLE_CASE;
            break;
    }

    // Vérifie si la nouvelle position est dans les limites et si la case est libre
    if (bordAtteint(nouveauX, nouveauY) || !niveau.caseEstLibre(nouveauX, nouveauY)) {
        // Inverse la direction si bord atteint ou case occupée
        switch (_direction) {
            case HAUT: _direction = BAS; break;
            case BAS: _direction = HAUT; break;
            case GAUCHE: _direction = DROITE; break;
            case DROITE: _direction = GAUCHE; break;
        }
    } else {
        // Déplace le personnage
        _pointX = nouveauX;
        _pointY = nouveauY;
    }

    mettreAJourDirection();
}

// méthode touche :Vérifie si deux personnages se touchent
bool Personnage::touche(const Personnage& autre) const {
    return (_pointX == autre._pointX && _pointY == autre._pointY);
}

// Getters
int Personnage::getX()const{return _pointX;}
int Personnage::getY()const{return _pointY;}
