README

Questions des Séances 2 à 5

Liste des questions traitées et fonctionnelles



Séance 2 :

Gestion des collisions simples pour empêcher le personnage de sortir des limites de l'écran.

Initialisation et affichage du personnage.

Séance 3 :

Implémentation de la classe Tuile pour stocker les informations des objets.

Implémentation de la classe Dictionnaire pour charger et rechercher des informations sur les tuiles.

Ajout d'une méthode de recherche dichotomique efficace dans le dictionnaire.

Séance 4 :

Implémentation de la classe Objet pour gérer les objets dans le jeu (bonus, obstacles, etc.).

Ajout d'une gestion des coordonnées différenciées (niveau et feuille de sprites).

Implémentation de la méthode dessiner pour les objets.

Implémentation de la classe Niveau pour charger et afficher un niveau.

Chargement des niveaux à partir de fichiers et comptabilisation des bonus.

Séance 5 :

Ajout de la méthode testerBonusEtPrendre pour gérer les bonus (collecte et disparition).

Ajout de la méthode caseEstLibre pour gérer les collisions avec les objets solides.

Mise à jour de la méthode dessiner pour ne pas afficher les objets "cachés".

Gestion de la fin du jeu (victoire/défaite) avec affichage d'écrans correspondants (bravo.png ou gameover.png).

Points d'intérêt et choix particuliers

1. Gestion des objets et des niveaux

La classe Objet gère la distinction entre les coordonnées de la feuille de sprites et celles du niveau.

La collecte des bonus est implémentée via la méthode testerBonusEtPrendre, qui change la propriété des objets à "cache".

La classe Niveau utilise un vecteur d'objets, ce qui permet une gestion flexible des différents éléments du jeu.

2. Optimisation des méthodes

Une sous-fonction indiceObjet a été proposée pour factoriser les recherches dans le vecteur d'objets, réduisant ainsi la duplication du code entre caseEstLibre et testerBonusEtPrendre.

Les objets "cachés" ne sont plus affichés, ce qui améliore les performances et la clarté visuelle.

3. Interactions avec les personnages

Les collisions avec les ennemis ("fille" et "fantôme") sont gérées via la méthode touche, mettant fin au jeu en cas de contact.

Les déplacements des personnages sont contrôlés par des tests de collisions (écran, murs, objets).

4. Gestion de la fin du jeu

Un booléen victoire permet de distinguer les cas de fin de jeu :

Victoire (tous les bonus collectés).

Défaite (collision avec un ennemi).

Des écrans de fin distincts sont affichés selon le résultat du jeu.

5. Rationalisation des interactions utilisateur

Les déplacements du personnage principal sont mappés sur les touches directionnelles (haut, bas, gauche, droite).

Une structure claire pour la boucle de jeu permet de séparer la gestion des événements, la mise à jour de l'état et l'affichage.

Fonctionnalités supplémentaires

Gestion des animations : Les personnages ("fille" et "fantôme") avancent automatiquement dans le niveau.

Compatibilité modulaire : Les classes Image, Objet, Dictionnaire et Niveau sont écrites de manière à pouvoir être réutilisées pour d'autres scénarios.

