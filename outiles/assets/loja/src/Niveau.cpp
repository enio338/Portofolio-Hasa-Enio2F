#include "Image.h"
#include "Objet.h"
#include "Niveau.h"
#include <fstream>
#include <stdexcept>

using namespace std;
Niveau::Niveau(const Image image,  string& nomFichier, const Dictionnaire&dictionnaire)
{
    ifstream fichierNiveau;
    _nbBonus=0;
    Tuile resultat("", 0, 0,"bonus");
    fichierNiveau.open(nomFichier);

    if (!(fichierNiveau.is_open()))
    {
        throw runtime_error("Impossible d'ouvrir le fichier " + nomFichier);
    }

    int nombreObjets;
    fichierNiveau >> nombreObjets; // Lire le nombre d'objets
    fichierNiveau.ignore();       // Ignorer le reste de la ligne

    string nomObjet;
    int x, y;

    // Lire les objets ligne par ligne
    int i=0;
    while (fichierNiveau >> nomObjet >> x >> y)
    {


        _lesObjets.emplace_back(image, nomObjet, dictionnaire, x, y);
        // Comptabilisation des bonus
        if (_lesObjets[i].getPropriety()=="bonus")
        {
            _nbBonus++;

        }
        i++;
    }

    fichierNiveau.close(); // Fermer le fichier
}

void Niveau::dessiner()const
{

    for(int i=0; i<_lesObjets.size(); i++)
    {
        if (_lesObjets[i].getPropriety() !="cache")   // Ne dessine pas les objets cachés
        {
            _lesObjets[i].dessiner();

            _lesObjets[i].dessiner();
        }
    }

}

//methode caseEstLibre: Vérifie si une case est libre (pas occupée par un objet "solide").
bool Niveau::caseEstLibre(int x, int y) const
{
    return (indiceObjet(x, y, "solide") == -1);
}


//methode qui Teste si un bonus est présent sur une case et le prend si oui
bool Niveau::testerBonusEtPrendre(int x,int y)
{
    int index = indiceObjet(x, y, "bonus");
    if (index != -1)
    {
        _nbBonus--;

        _lesObjets[index].cacher();
        return true;
    }
    return false;
}





int Niveau::indiceObjet(int x, int y, const string& propriete) const
{
    for (size_t i = 0; i < _lesObjets.size(); ++i)
    {
        if (_lesObjets[i].getPropriety() == propriete && _lesObjets[i].getObj_x() == x && _lesObjets[i].getObj_y() == y)
        {
            return i;
        }
    }
    return -1;
}


bool Niveau::gagne()const
{
    return (_nbBonus==0);
}
