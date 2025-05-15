/*#include <iostream>
#include <vector>
#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version spéciale du main, ne pas modifier
{
    try {
        // Initialisation du moteur graphique
        Moteur moteur;
        moteur.init();

        // Chargement de l'image des objets
        Image imageObjets("assets/objets.png");

        // Chargement du dictionnaire
        Dictionnaire dictionnaire("assets/dictionnaire.txt");

        // Afficher le dictionnaire
        cout << "Contenu du dictionnaire :\n";
        dictionnaire.afficher();

        // Recherche d'une tuile
        string nomRecherche;
        cout << "\nEntrez le nom de la tuile à rechercher : ";
        cin >> nomRecherche;

        Tuile resultat("", 0, 0, "");
        if (dictionnaire.recherche(nomRecherche, resultat)) {
            cout << "Tuile trouvée : ";
            resultat.afficher();
        } else {
            cout << "Tuile non trouvée." << endl;
        }

        // Chargement du niveau
        string nomFichierNiveau = "assets/niveau1.txt";
        Niveau niveau(imageObjets, nomFichierNiveau, dictionnaire);

        // Boucle de jeu
        bool continuer = true;
        while (continuer) {
            moteur.clear();

            // Affichage du niveau
            niveau.dessiner();

            // Exemple : affichage des personnages (ajoutez vos personnages ici si nécessaire)
            // personnage.dessiner();

            moteur.display();

            // Gestion des événements
            continuer = moteur.gererEvenements();
        }

        // Fermeture propre du moteur
        moteur.close();

    } catch (const exception& e) {
        cerr << "Erreur : " << e.what() << endl;
    }

    return 0;
}

*/








/*#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "Personnage.h"
#include "Tuile.h"
#include "Dictionnaire.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  try {
        // Chargement du dictionnaire
        Dictionnaire dictionnaire("assets/dictionnaire.txt");

        // Afficher le dictionnaire
        cout << "Contenu du dictionnaire :\n";
        dictionnaire.afficher();
        // Recherche d'un élément
    string nomRecherche;
    cout << "\nEntrez le nom de la tuile à rechercher : ";
    cin >> nomRecherche;

    Tuile resultat("", 0, 0, "");
    if (dictionnaire.recherche(nomRecherche, resultat)) {
        cout << "Tuile trouvée : ";
        resultat.afficher();
    } else {
        cout << "Tuile non trouvée." << endl;
    }

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
  return 0;
}
*/
