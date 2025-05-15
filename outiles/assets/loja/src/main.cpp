#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
    // Initialisation du jeu
    try
    {

// Initialisation du jeu
        Moteur moteur("Mon super jeu vidéo");
        Image I1(moteur, "assets/fond.png");
        Image imageObjets(moteur, "assets/objets.png");
        Dictionnaire dictionnaire("assets/dictionnaire.txt");

        Image Img_personne1(moteur, "assets/personnages.png");
        Personnage chevalier(Img_personne1, TAILLE_CASE, 2 * TAILLE_CASE, 4, 0, BAS);
        Personnage fille(Img_personne1, 5 * TAILLE_CASE, TAILLE_CASE, 6, 0, HAUT);
        Personnage fantome(Img_personne1, TAILLE_CASE, TAILLE_CASE * 5, 10, 0, DROITE);

        // Chargement du niveau
        string nomFichierNiveau = "assets/niveau1.txt";
        Niveau niveau(imageObjets, nomFichierNiveau, dictionnaire);


// Variables pour la gestion de l'état du jeu
        bool quitter = false;
        bool victoire = false;


        // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
        // (en general, 60 fois par seconde)
        while (!quitter)
        {
            // I. Gestion des evenements
            Evenement evenement = moteur.evenementRecu();
            while (evenement != AUCUN)
            {
                switch (evenement)
                {
                // QUITTER = croix de la fenetre ou Echap;h
                case QUITTER_APPUYE:
                    quitter = false;
                    break;
                case ESPACE_APPUYE:



                    break;
                case GAUCHE_APPUYE:

                    chevalier.allerGauche(niveau);

                    break;

                case DROITE_APPUYE:

                    chevalier.allerDroite(niveau);

                    break;
                case HAUT_APPUYE:

                    chevalier.allerHaut(niveau);
                    break;
                case BAS_APPUYE:

                    chevalier.allerBas(niveau);
                    break;
                // TODO: gerer les autres evenements
                default:
                    break;
                }

                evenement = moteur.evenementRecu();
            }

            // II. Mise à jour de l'état du jeu
            moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

            //I1.dessiner(0,0); // image de fond initial




            // III. Generation de l'image à afficher



            // Affichage du niveau
            niveau.dessiner();

            fille.dessiner();
            fantome.dessiner();
            chevalier.dessiner();
            fille.avancer(niveau);
            fantome.avancer(niveau);
// Vérification des collisions avec les personnages ennemis
            if (chevalier.touche(fille) || chevalier.touche(fantome))
            {
                quitter = true;
                victoire = false; // Défaite
            }

            // Vérification si le niveau est gagné
            if (niveau.gagne())
            {
                quitter = true;
                victoire = true; // Victoire
            }




            /*
              Affiche l'image en se cadencant sur la frequence de
              rafraichissement de l'ecran (donc va en general mettre le
              programme en pause jusqu'a ce que l'ecran soit rafraichi). En
              general, 60 images fois par seconde, mais ca peut dependre du
              materiel
            */
            moteur.finaliserRendu();
        }
// Affichage de la fin du jeu
        moteur.attendre(2); // Petite pause avant d'afficher l'écran de fin
        Image ecranFin(moteur, victoire ? "assets/bravo.png" : "assets/gameover.png");
        moteur.initialiserRendu();
        ecranFin.dessiner(0, 0);
        moteur.finaliserRendu();
        moteur.attendre(2); // Affiche l'écran de fin pendant 3 secondes
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}




