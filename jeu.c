# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "batal.h"


void jeu(struct contenu_case grille[][TAILLE_GRILLE], 
	 struct bateau liste_bateaux[],
	 struct monstre liste_monstres[],
	 struct joueur *joueur1, 
	 struct joueur *joueur2){ // Fonction qui fait tourner une partie

  /*

Fonction qui prend en argument :
-La grille
-La liste de tous les bateaux
-Les deux joueurs

Ne retourne rien

Modifie la grille les bateaux et les joueurs (voir fonction attaquer)

affiche à l'écran le déroulement d'une partie :
Les évenements de chaque tour ainsi que le gagnant de la partie.

*/
    
  
  int tour = 0;
    
  while (joueur1->cases_restantes > 0 && joueur2->cases_restantes  > 0){ // Tq les deux joueurs ont au moins un bateau
    tour++;
    printf("\nTour %d : \n", tour);
    //afficher_grille(grille);


    // modif achievement 1
    /*
    struct position pos1;
    pos1.ligne = rand()%10;
    pos1.colonne = rand()%10;
    struct position pos2;
    pos2.ligne = rand()%10;
    pos2.colonne = rand()%10;
    attaquer(pos1, grille, &joueur1, &joueur2, 1, liste_bateaux);
    attaquer(pos2, grille, &joueur1, &joueur2, 2, liste_bateaux);
    printf("\n");
    */

    
    struct position torpille1 = depart_torpille(liste_bateaux, grille, 1);
    //torpille1.ligne = depart_torpille(liste_bateaux, grille, 1).ligne; // Choix de la position de depart des torpilles
    //torpille1.colonne = depart_torpille(liste_bateaux, grille, 1).ligne;
    struct position torpille2 = depart_torpille(liste_bateaux, grille, 2);
    //torpille2.ligne = depart_torpille(liste_bateaux, grille, 2).ligne; 
    //torpille2.colonne = depart_torpille(liste_bateaux, grille, 2).ligne;
    //printf("depart torpilles\n");
    //printf("torpille 1 lig : %d\n", torpille1.ligne);
    //printf("torpille 1 col : %d\n", torpille1.colonne);
    //printf("torpille 2 lig : %d\n", torpille2.ligne);
    //printf("torpille 2 col : %d\n", torpille2.colonne);

    struct position attaque1 = cherche_bateau(grille, torpille1, 1, liste_monstres);
    //attaque1.ligne = cherche_bateau(grille, torpille1, 1).ligne; // Recherche de la position a attaquer
    //attaque1.ligne = cherche_bateau(grille, torpille1, 1).colonne;
    struct position attaque2 = cherche_bateau(grille, torpille2, 2, liste_monstres);
    //attaque2.ligne = cherche_bateau(grille, torpille2, 2).ligne;
    //attaque2.ligne = cherche_bateau(grille, torpille2, 2).colonne;
    //printf("Case attaqué par le joueur 1 : [%d,%d]\n", attaque1.ligne, attaque1.colonne);
    //printf("Case attaqué par le joueur 2 : [%d,%d]\n", attaque2.ligne, attaque2.colonne);

    printf("Attaque du joueur 1\n");
    attaquer(attaque1, grille, joueur1, joueur2, 1 ,liste_bateaux); // attaque de joueur 1
    printf("attaque du joueur 2\n");
    attaquer(attaque2, grille, joueur1, joueur2, 2 ,liste_bateaux); // attaque de joueur 2
    
    printf("Il reste %d cases au joueur 1\n", joueur1->cases_restantes);
    printf("Il reste %d cases au joueur 2\n", joueur2->cases_restantes);

    // Au tour de godzilla :

    godzilla(grille, liste_bateaux, liste_monstres, joueur1, joueur2);

    // debugage

    /*for (int i = 0; i < 10; i++){
      if (liste_bateaux[i].cases_restantes > 0){
	printf("Bateau %d du joueur %d : \n", liste_bateaux[i].taille, liste_bateaux[i].joueur);
	printf("   -position : [%d,%d]\n", liste_bateaux[i].position.ligne, liste_bateaux[i].position.colonne);
	printf("   -direction : %d\n", liste_bateaux[i].direction);
	printf("   -nb de cases restantes : %d\n", liste_bateaux[i].cases_restantes);
      }
      }*/
    

    afficher_grille(grille); // debug
	

  }
  printf("\n\n");
    
    
  if (joueur1->cases_restantes == 0 && joueur2->cases_restantes  == 0){
      printf("Match nul ! \n");
  }
  else if (joueur2->cases_restantes == 0){
    printf("Le Joueur 1 a gagne !! \n");
  }
  else if (joueur1->cases_restantes == 0){
    printf("Le Joueur 2 a gagne !! \n");
    }
  
  printf("\n\n");
  
}
