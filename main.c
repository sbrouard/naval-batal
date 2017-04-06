# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "batal.h"


/* 
Fichier qui créer la grille et fait tourner le jeu
*/

int main(int argc, char *argv[]){
  srand(time(NULL));

  struct contenu_case grille[TAILLE_GRILLE][TAILLE_GRILLE]; // Initialisation de la grille
  
  init_plateau(grille);
  
// Création des joueurs

  struct joueur joueur1; // Création joueur1
  joueur1.num = 1;
  joueur1.nb_bateaux_restants = 5;
  joueur1.cases_restantes = NB_CASES_TOT;
  
  struct joueur joueur2; // Création joueur2
  joueur2.num = 2;
  joueur2.nb_bateaux_restants = 5;
  joueur2.cases_restantes = NB_CASES_TOT;

// Création des bateaux
  
  struct bateau liste_bateaux[10]; // Création des bateaux
  for (int i = 0; i < 5; ++i){ // Parcourt les 5 bateaux
    for (int j = 0; j < 2; ++j){ // Pour chaque joueur
      liste_bateaux[2*i+j].taille = i+1;
      liste_bateaux[2*i+j].position.ligne = -1;
      liste_bateaux[2*i+j].position.colonne = -1;
      liste_bateaux[2*i+j].direction = -1;
      liste_bateaux[2*i+j].cases_restantes = i+1;
      liste_bateaux[2*i+j].joueur = j+1;
    }
  }
       
  for (int i = 0; i < 5; ++i){  // On place les bateaux du joueur 1
    placer_bateau(&liste_bateaux[2*i], joueur1, grille);
  }
  for (int i = 0; i < 5; ++i){  // On place les bateaux du joueur 2 (en deux fois pour un pb avec rand()
    placer_bateau(&liste_bateaux[2*i+1], joueur2, grille);
  }
  /*int l = liste_bateaux[6].position.ligne;
  int c = liste_bateaux[6].position.colonne;
  printf("Position dans la liste : [%d,%d]\n", l, c); 
  printf("Bateau à cette position : %d\n", grille[l][c].joueur1);*/

  //Création de Godzilla

  struct monstre godzilla;
  godzilla.nom = "godzilla";
  godzilla.attaque_par = 0;
  
  liste_monstres[0] = godzilla;

  placer_monstre(&liste_monstres[0], grille);
  
  afficher_grille(grille);


  jeu(grille, liste_bateaux, liste_monstres, &joueur1, &joueur2);

  afficher_grille(grille);

  
  return 0;
}


// test
