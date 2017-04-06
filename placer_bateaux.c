# include <stdio.h>
# include <stdlib.h>
# include "batal.h"
# include <time.h>

void placer_bateau(struct bateau *bateau, struct joueur joueur, struct contenu_case grille[][TAILLE_GRILLE]){

/*
Fonction qui prend en arguments : un bateau, le joueur auquel il appartient, la grille de jeu.
Ne retourne rien
Modifie la grille pour y placer le bateau
Le placement est se fait aléatoirement si la place est libre
 */

  int place = 1;
  int l;
  int c;
  
  
  
  while (place == 1){
    place = 0;
    bateau->position.ligne = rand()%10;
    bateau->position.colonne = rand()%10;
    bateau->direction = rand()%4;
    if (bateau->direction==0){ // On place le bateau vers le haut
      //int i = bateau->position.ligne;
      //int j = bateau->position.colonne;
      l  = -1; // On remonte d'une ligne
      c = 0;
    }
    else if (bateau->direction==1){ // On place le bateau vers le bas
      //int i = bateau.position.ligne;
      //int j = bateau.position.colonne;
      l = 1; // On descend d'une ligne
      c = 0;
    }
    else if (bateau->direction == 2){ //Vers la gauche
      //int i = bateau.position.colonne;
      //int j = bateau.position.ligne;
      l = 0;
      c = -1; // - une colonne
    }
    else if (bateau->direction == 3){ // Vers la droite
      //int i = bateau.position.colonne;
      //int j = bateau.position.ligne;
      l = 0;
      c = 1;
    }
    printf("Position : [%d,%d], direction : %d, l=%d c=%d\n", bateau->position.ligne, bateau->position.colonne, bateau->direction, l, c);
    for (int k = 0; k < bateau->taille; ++k){
      if ((bateau->position.ligne+k*l > 9) || (bateau->position.ligne+k*l < 0) || (bateau->position.colonne+k*c > 9) || (bateau->position.colonne+k*c < 0)  || (grille[(bateau->position).ligne+k*l][(bateau->position).colonne+k*c].joueur1 > 0 && joueur.num == 1) || (grille[(bateau->position).ligne+k*l][(bateau->position).colonne+k*c].joueur2 > 0 && joueur.num == 2)){
	place = 1; // Si la place est déjà prise, on ne peut pas le mettre là
      }
    }
    if (place == 0 ){ // Si on peut placer le bateau on le place (sinon on choisi au hasard un autre endroit)
      for (int k = 0; k < bateau->taille; ++k){
	if (joueur.num == 1){
	  grille[(bateau->position).ligne+k*l][(bateau->position).colonne+k*c].joueur1 = bateau->taille;
	}
	else if (joueur.num == 2){
	  grille[(bateau->position).ligne+k*l][(bateau->position).colonne+k*c].joueur2 = bateau->taille;
	}
	printf("[%d,%d]\n", bateau->position.ligne+k*l, bateau->position.colonne+k*c);
      }
    }
  }
  int t = bateau->taille-1;
  if (bateau->direction == 0)
    printf("Bateau %d du joueur %d : position :[%d,%d] direction : %d\n", bateau->taille, bateau->joueur, bateau->position.ligne-t, bateau->position.colonne, bateau->direction);
  else if (bateau->direction == 1)
    printf("Bateau %d du joueur %d : position :[%d,%d] direction : %d\n", bateau->taille, bateau->joueur, bateau->position.ligne+t, bateau->position.colonne, bateau->direction);
  else if (bateau->direction == 2)
    printf("Bateau %d du joueur %d : position :[%d,%d] direction : %d\n", bateau->taille, bateau->joueur, bateau->position.ligne, bateau->position.colonne-t, bateau->direction);
  else if (bateau->direction == 3)
    printf("Bateau %d du joueur %d : position :[%d,%d] direction : %d\n", bateau->taille, bateau->joueur, bateau->position.ligne-t, bateau->position.colonne+t, bateau->direction);
 
}
