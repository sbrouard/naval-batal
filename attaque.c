# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "batal.h"


struct position depart_torpille(struct bateau liste_bateaux[], struct contenu_case grille[][TAILLE_GRILLE], enum Joueur attaquant){
  
/*

Fonction qui prend en argument :
-La liste des bateaux 
-la grille
-Un entier qui correspond au joueur qui attaque

Retourne une position (la position qui sera attaquee)

Pas d'effet de bord 

*/

  
  //printf("Depart_torpille joueur %d\n", attaquant);

  // srand(time(NULL));
  //printf("depart torpille joueur %d\n", attaquant); //debugage
  int j = 0;
  int alive = 0;
  int bateau_attaquant = 0;
  int case_attaquante = 0;
  int h = 0; // Si le bateau est horizontal
  int v = 0; // Si le bateau est vertical
  struct position pos;
  if (attaquant == 2){
    j = 1;
  }
  
  while (alive == 0){ // On choisi d'abord quel bateau va lancer la torpille 
    bateau_attaquant = 1+rand()%5;
    // printf("bateau : %d\n", bateau_attaquant);
    // printf("bla : %d\n", liste_bateaux[bateau_attaquant+j-1].cases_restantes);
    // printf("bla : %d\n", liste_bateaux[1].cases_restantes);
    if (liste_bateaux[2*bateau_attaquant+j-2].cases_restantes > 0) 
      alive = 1;
  }
  //printf("Bateau attaquant du joueur %d: %d \n",attaquant, bateau_attaquant); // debugage
  alive = 0;
  pos.ligne = liste_bateaux[2*bateau_attaquant+j-2].position.ligne;
  pos.colonne = liste_bateaux[2*bateau_attaquant+j-2].position.colonne;
  //printf("ligne : %d\n", pos.ligne);
  //printf("colonne : %d\n", pos.colonne);
  //printf("direction : %d\n", liste_bateaux[2*bateau_attaquant+j-2].direction);
  //printf("bateau case init : joueur 1 : %d, joueur 2 : %d\n", grille[pos.ligne][pos.colonne].joueur1, grille[pos.ligne][pos.colonne].joueur2); 
  
  if (liste_bateaux[2*bateau_attaquant+j-2].direction == 0){
    v = -1;
  }
  if (liste_bateaux[2*bateau_attaquant+j-2].direction == 1){
    v = 1;
  }
  if (liste_bateaux[2*bateau_attaquant+j-2].direction == 2){
    h = -1;
  }
  if (liste_bateaux[2*bateau_attaquant+j-2].direction == 3){
    h = 1;
  }
  //printf("Position dans la liste : [%d,%d]\n", pos.ligne, pos.colonne); 
  //printf("Bateau du joueur 1 à cette position : %d\n", grille[pos.ligne][pos.colonne].joueur1);
  //printf("Bateau du joueur 2 à cette position : %d\n", grille[pos.ligne][pos.colonne].joueur2);

  //  printf("h : %d, v : %d\n", h, v);
  while (alive == 0){ // Puis la case du bateau
    case_attaquante = rand()%bateau_attaquant;
    /*printf("\nBateau attaquant du joueur %d : %d \n",attaquant,  bateau_attaquant); // debugage
    printf("bateau case init : joueur 1 : %d, joueur 2 : %d\n", grille[pos.ligne][pos.colonne].joueur1), grille[pos.ligne][pos.colonne].joueur2); 
    printf("case attaquante : %d\n", case_attaquante);
    printf("alive : %d\n", alive);
    printf("bateau joueur 1 sur case : %d\n", grille[pos.ligne+v*case_attaquante][pos.colonne+h*case_attaquante].joueur1); //debugage
    printf("bateau joueur 2 sur case : %d\n", grille[pos.ligne+v*case_attaquante][pos.colonne+h*case_attaquante].joueur2); //debugage*/
    //struct position nvlle_pos;
    //nvlle_pos.ligne = pos.ligne + v*case_attaquante;
    //nvlle_pos.colonne = pos.colonne + h*case_attaquante; 
    if (((attaquant == 1) && grille[pos.ligne+v*case_attaquante][pos.colonne+h*case_attaquante].joueur1 > 0) || ((attaquant == 2) && grille[pos.ligne+v*case_attaquante][pos.colonne+h*case_attaquante].joueur2 > 0)){ // Si le bateau n'a pas ete detruit sur cette case
      /*if (grille[nvlle_pos.ligne][nvlle_pos.colonne].joueur1 > 0){
	alive = 1;*/
	//printf("if\n");
	//printf("aliveif : %d\n", alive);
	pos.ligne += v*case_attaquante;
	pos.colonne += h*case_attaquante; 
	alive = 1;
  
    }
  }
  
  //printf("dep tropille : ligne : %d, colonne : %d\n", pos.ligne, pos.colonne);*/
  //printf("position de dep torp : [%d,%d]\n", pos.ligne, pos.colonne);
  //printf("\n");
  return pos;
}





















struct position cherche_bateau(struct contenu_case grille[][TAILLE_GRILLE], struct position dep_torpille, enum Joueur attaquant, struct monstre liste_monstres[]){
  
/*

Fonction qui prend en argument :
-La grille
-La postion de depart de la torpille
-Le joueur qui attaque (1 ou 2)

Retourne la position du bateau adverse le plus proche : case qui se fera attaquer

Pas d'effet de bord

*/

  
  //printf("Cherche_bateau joueur %d\n", attaquant);

  // srand(time(NULL));
  int l = dep_torpille.ligne;
  int c = dep_torpille.colonne;
  struct position pos;
  pos.ligne = -1;
  pos.colonne = -1;
  for (int d = 1; d < DISTANCE_MAX+1; d++){ // d parcourt toute les distances possible dans l'ordre croissant
    for (int i = 0; i < d+1; i++){ // i correspond à la ligne
      int j = d-i; // j correspond à la colonne
      if ((l+i < 10) && (c+j < 10) && (((grille[l + i][c + j].joueur2 > 0) && (attaquant == 1)) || ((grille[l + i][c + j].joueur1 > 0) && (attaquant == 2)) || (grille[l + i][c + j].godzilla > 0))){ 
	pos.ligne = l + i;
	pos.colonne = c + j;

	/*if ((grille[l + i][c + j].godzilla > 0)){
	    if (liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par == 0){
	    liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = attaquant;
	    }
	    else {
	      liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = 3;
	    }
	    }*/
	//printf("i>0 j>0\n");
	//printf("\n");
	return pos;
      }
      if ((l+i < 10) && (c-j >= 0) && (((grille[l + i][c - j].joueur2 > 0) && (attaquant == 1)) || ((grille[l + i][c - j].joueur1 > 0) && (attaquant == 2)) || (grille[l + i][c - j].godzilla > 0))){ 
	pos.ligne = l + i;
	pos.colonne = c - j;

	/*if ((grille[l + i][c - j].godzilla > 0)){
	    if (liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par == 0){
	    liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = attaquant;
	    }
	    else {
	      liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = 3;
	    }
	    }*/

	//printf("i>0 j>0\n");
	//printf("\n");
	return pos;
      }
      if ((l-i >= 0) && (c+j < 10) && (((grille[l - i][c + j].joueur2 > 0) && (attaquant == 1)) || ((grille[l - i][c + j].joueur1 > 0) && (attaquant == 2)) || (grille[l - i][c + j].godzilla > 0))){ 
	pos.ligne = l - i;
	pos.colonne = c + j;

	/*if ((grille[l - i][c + j].godzilla > 0)){
	    if (liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par == 0){
	    liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = attaquant;
	    }
	    else {
	      liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = 3;
	    }
	    }*/

	//printf("i<0 j>0\n");
      	//printf("\n");
	return pos;
      }
      if ((l-i >= 0) && (c-j >= 0) && (((grille[l - i][c - j].joueur2 > 0) && (attaquant == 1)) || ((grille[l - i][c - j].joueur1 > 0) && (attaquant == 2)) || (grille[l - i][c + j].godzilla > 0))){ 
	pos.ligne = l - i;
	pos.colonne = c - j;

	/*if ((grille[l - i][c - j].godzilla > 0)){
	    if (liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par == 0){
	    liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = attaquant;
	    }
	    else {
	      liste_monstres[grille[pos.ligne][pos.colonne].godzilla - 1].attaque_par = 3;
	    }
	  }*/

	//printf("i<0 j<0\n");
	//printf("\n");
	return pos;
      }
    }
  }
    //printf("\n");
  return pos;	
  
}



void attaquer(struct position pos, struct contenu_case grille[][TAILLE_GRILLE], struct joueur *joueur1, struct joueur *joueur2, enum Joueur attaquant, struct bateau liste_bateaux[]){ // Fonction qui permet de detruire le contenu d'une case
  //printf("Debugage attaquer\n");
/*

Fonction qui prend en argument :
-Une position
-La grille
-Un pointeur vers les deux joueur
-Un entier (1 ou 2) pour savoir quel joueur attaque

Ne retourne rien.

Modifie la grille : la case correspondant  à la position revient à 0.
Modifie les joueurs : un joueur dont un bateau a été touché perd une case.

*/

//On suppose ici que la case qui va etre attaquee est deja choisie
  
  int l = pos.ligne;
  int c = pos.colonne;
  //printf("l : %d, c : %d\n", l, c); // debugage
  //printf("joueur 1 : %d\n", grille[l][c].joueur1);
  //printf("joueur 2 : %d\n", grille[l][c].joueur2);
  //printf("Godzilla : %d\n", grille[l][c].godzilla);
  //printf("l : %d c : %d\n", l, c);
  if (l < 0 || c < 0 || l > 9 || c > 9){
    printf("  - Echec de l'attaque du joueur %d \n", attaquant);
  }
  else {
    //printf("test else\n");
    if (grille[l][c].joueur1 > 0){ // On regarde d'abord si le joueur 1 a un bateau sur cette case
      //printf("test if 1\n");
      //printf("if joueur 1\n"); // debugage
      int bateau = grille[l][c].joueur1;
      liste_bateaux[2*bateau-2].cases_restantes--;
      joueur1->cases_restantes--;
      printf("  - Le joueur %d a touché un bateau du joueur 1 \n", attaquant); 
      if (liste_bateaux[2*bateau-2].cases_restantes == 0){
	char *nom = "test";
	//printf("test if 2\n");
	if (bateau == 1){
	  nom = "porte-etendal";
	}
	else if (bateau == 2){
	  nom = "subaqual";
	}
	else if (bateau == 3){
	  nom = "contre-torpal";
	}
	else if (bateau == 4){
	  nom = "croisal";
	    }
	else if (bateau == 5){
	  nom = "portavial";
	}

	printf("    Le %s du joueur 1 a été détruit \n", nom);
	joueur1->nb_bateaux_restants--;
      }
      grille[l][c].joueur1 = 0;
    }


    if (grille[l][c].joueur2 > 0){ // Idem pour le joueur 2
      //printf("test if 3\n");
      //printf("if joueur 2\n"); // debugage
      int bateau = grille[l][c].joueur2;
      liste_bateaux[2*bateau-1].cases_restantes--;
      joueur2->cases_restantes--;
      printf("  - Le joueur %d a touché un bateau du joueur 2 \n", attaquant);
      if (liste_bateaux[2*bateau-1].cases_restantes == 0){
	//printf("test if 4\n");
	char *nom = "truc";
	if (bateau == 1){
	  nom =  "porte-etendal";
	}
	else if (bateau == 2){
	  nom = "subaqual";
	}
	else if (bateau == 3){
	  nom = "contre-torpal";
	}
	else if (bateau == 4){
	  nom = "croisal";
	}
	else if (bateau == 5){
	  nom = "portavial";
	}

      
	printf("    Le %s du joueur 2 a été détruit \n", nom);
	joueur1->nb_bateaux_restants--;
      }
      grille[l][c].joueur2 = 0;
    }
  
  
    if ((grille[l][c].godzilla > 0)){
      //printf("if godzilla\n"); // debugage
      if (liste_monstres[grille[l][c].godzilla - 1].attaque_par == 0){
	liste_monstres[grille[l][c].godzilla - 1].attaque_par = attaquant;
      }
      else {
	liste_monstres[grille[l][c].godzilla - 1].attaque_par = 3;
      }
      printf("Godzilla a été attaqué par joueur %d. Il va s'énerver ... \n", attaquant);
    }
  }
  
  printf("\n");
}

/*
Partie du code qui sera surement supprimée

  if (grille[pos.ligne][pos.colonne] == 1){ // S'il y a un bateau de joueur 1
    joueur1->cases_restantes--;
    printf("Un bateau du Joueur 1 a ete touche par le joueur %d \n", attaquant);
  }
  else if (grille[pos.ligne][pos.colonne] == 2){ // S'il y a un bateau du joueur 2
    joueur2->cases_restantes--;
    printf("Un bateau du Joueur 2 a ete touche par le joueur %d \n", attaquant);
  }
  else if (grille[pos.ligne][pos.colonne] == 3){ // S'il y a deux bateaux
    joueur1->cases_restantes--;
    printf("Un bateau du Joueur 1 a ete touche par le joueur %d \n", attaquant);
    joueur2->cases_restantes--;
    printf("Un bateau du Joueur 2 a ete touche par le joueur %d \n", attaquant);
  }
  else { // S'il n'y a rien
    printf("Joueur %d : Rate ! \n", attaquant);
  }
  grille[pos.ligne][pos.colonne] = 0;
}
  
*/
