# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include "batal.h"



void godzilla(struct contenu_case grille[][TAILLE_GRILLE], 
	      struct bateau liste_bateaux[], struct monstre liste_monstres[],
	      struct joueur *joueur1, 
	      struct joueur *joueur2){ // Fonction qui fait tourner une partie

  /*

Fonction qui prend en argument :
 -La grille
 -La liste des monstres
 -La liste des monstres
 -Un pointeur vers chaque joueur

Ne retourne rien

Effets de bord
 -Modifie la grille, les joueurs et les bateaux (voir fonction attaquer)
 -Modifie Godzilla (position et attaque_par=0

  */

  // 1-Attaque

  int deplacer_godzilla = 1;

  struct position pos_godzilla = liste_monstres[0].position;
  struct position gauche = pos_godzilla;
  if (pos_godzilla.colonne > 0)
    gauche.colonne--;
  struct position droite = pos_godzilla;
  if (pos_godzilla.colonne < 9)
    droite.colonne++;
  struct position haut = pos_godzilla;
  if (pos_godzilla.ligne > 0)
    haut.ligne--;
  struct position bas = pos_godzilla;
  if (pos_godzilla.ligne < 9)
  bas.ligne++;
  
  /*if (((grille[pos_godzilla.ligne][pos_godzilla.colonne].joueur1 > 0) || (grille[pos_godzilla.ligne][pos_godzilla.colonne].joueur2 > 0)) && (grille[pos_godzilla.ligne][pos_godzilla.colonne].godzilla == 0)){
    attaquer(pos_godzilla, grille, joueur1, joueur2, 4, liste_bateaux);
    deplacer_godzilla = 0;
    }*/

  if (((grille[gauche.ligne][gauche.colonne].joueur1 > 0) || (grille[gauche.ligne][gauche.colonne].joueur2 > 0)) && (grille[gauche.ligne][gauche.colonne].godzilla == 0)){
    attaquer(gauche, grille, joueur1, joueur2, 4, liste_bateaux);
    deplacer_godzilla = 0;
    printf("Godzilla attaque\n"); // debug
  }

  if (((grille[droite.ligne][droite.colonne].joueur1 > 0) || (grille[droite.ligne][droite.colonne].joueur2 > 0)) && (grille[droite.ligne][droite.colonne].godzilla == 0)){
    attaquer(droite, grille, joueur1, joueur2, 4, liste_bateaux);
    deplacer_godzilla = 0;
    printf("Godzilla attaque\n"); // debug
  }

  if (((grille[haut.ligne][haut.colonne].joueur1 > 0) || (grille[haut.ligne][haut.colonne].joueur2 > 0)) && (grille[haut.ligne][haut.colonne].godzilla == 0)){
    attaquer(haut, grille, joueur1, joueur2, 4, liste_bateaux);
    deplacer_godzilla = 0;
    printf("Godzilla attaque\n"); // debug
  }

  if (((grille[bas.ligne][bas.colonne].joueur1 > 0) || (grille[bas.ligne][bas.colonne].joueur2 > 0)) && (grille[bas.ligne][bas.colonne].godzilla == 0)){
    attaquer(bas, grille, joueur1, joueur2, 4, liste_bateaux);
    deplacer_godzilla = 0;
    printf("Godzilla attaque\n"); // debug
  }


  // 2-Déplacement
  // 2.1-Séléction du bateau vers lequel se déplacer

  if (deplacer_godzilla) {
  
    grille[liste_monstres[0].position.ligne][liste_monstres[0].position.colonne].godzilla = 0; //On dit à la grille que Godzilla ne se trouve pas sur cette case
    //int joueur = 0;
    struct position bateau; // Position vers laquelle va se déplacer Godzilla
    bateau.ligne = -1;
    bateau.colonne = -1;
    if (liste_monstres[0].attaque_par == 1){ // Godzilla va vers le joueur qui l'a attaqué
      //joueur = 1;
      printf("Godzilla se dirige vers le joueur 1\n"); // debug
      bateau = cherche_bateau(grille, pos_godzilla, 1, liste_monstres);
    }
    else if (liste_monstres[0].attaque_par == 2){
      //joueur = 2;
      printf("Godzilla se déplace vers le joueur 2\n");
      bateau = cherche_bateau(grille, pos_godzilla, 2, liste_monstres);
    }
    else if (liste_monstres[0].attaque_par == 3){ // Aléatoirement si les deux l'ont attaqué
      int joueur = 1+rand()%2;
      bateau = cherche_bateau(grille, pos_godzilla, joueur, liste_monstres);
      printf("Godzilla, attaqué par le deux joueurs se dirige vers le joueur %d\n", joueur);
    }
    else if (liste_monstres[0].attaque_par == 0){ // Vers le bateau le plus proche sinon
      struct position pos1 = depart_torpille(liste_bateaux, grille, 1); // On cherche quel bateau est le plus proche
      struct position pos2 = depart_torpille(liste_bateaux, grille, 2);
      int dist1 = fabs(pos_godzilla.ligne - pos1.ligne) + fabs(pos_godzilla.colonne - pos1.colonne);
      int dist2 = fabs(pos_godzilla.ligne - pos2.ligne) + fabs(pos_godzilla.colonne - pos2.colonne);
      if (dist1 == dist2){
	int aleat = 1+rand()%2;
	if (aleat == 1){
	  bateau = pos1;
	}
	else{
	  bateau = pos2;
	}
      }
      else if (dist2 > dist1){
      bateau = pos1;
      }
      else {
	bateau = pos2;
      }  
    }
    
    // 2.2-Sélection de la direction vers laquelle se déplacer
    
    int v = 0; // verticalement
    int h = 0; // horizontalement
    
    if (fabs(pos_godzilla.ligne - bateau.ligne) > fabs(pos_godzilla.colonne - bateau.colonne)){
      if (bateau.ligne > pos_godzilla.ligne)
	v = 1;
      else if (bateau.ligne < pos_godzilla.ligne)
	v = -1;
    }
    else {
      if (bateau.colonne > pos_godzilla.colonne)
	h = 1;
      else if (bateau.colonne < pos_godzilla.colonne)
	h = -1;
    }
    
    liste_monstres[0].position.ligne += v;
    liste_monstres[0].position.colonne += h;
    grille[liste_monstres[0].position.ligne][liste_monstres[0].position.colonne].godzilla = 1; //On dit à la grille que Godzilla se trouve sur cette case
  }
  printf("Position de Godzilla : [%d,%d]\n", liste_monstres[0].position.ligne, liste_monstres[0].position.colonne);
}











void placer_monstre(struct monstre *monstre, struct contenu_case grille[][TAILLE_GRILLE]){

  /*

Fonction qui prend en argument :
 -La grille
 -un pointeur vers le monstre à placer

Ne retourne rien

effets de bord :
 -Modifie la grille (ajoute un monstre sur une case
 -initialise le monstre

  */

  int place = 1;
  struct position pos;

  monstre->attaque_par = 0;
  
  while (place){
    pos.ligne = rand()%10;
    pos.colonne = rand()%10;
    if (grille[pos.ligne][pos.colonne].godzilla == 0){
      monstre->position.ligne = pos.ligne;
      monstre->position.colonne = pos.colonne;
      grille[pos.ligne][pos.colonne].godzilla = 1;
      place = 0;
    }
  }
}
      
    
