# include <stdio.h>
# include "batal.h"

# define TAILLE_GRILLE 10
/*
# define PAS_DE_BATEAU 0
# define BATEAU_JOUEUR1 1
# define BATEAU_JOUEUR2 2
# define DEUX_BATEAU 3
*/

void init_plateau(struct contenu_case tab[][TAILLE_GRILLE]) {  
/*
Fonction qui prend en argument : un tableau 2D de taille TAILLE_GRILLE
Ne retourne rien
Modifie le tableau en le remplissant de 0 pour former la grille initiale.
*/
  int i = 0, j = 0;
  
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {

      tab[i][j].joueur1 = 0;
      tab[i][j].joueur2 = 0;
      tab[i][j].godzilla = 0;
    }
  }
}


void afficher_grille(struct contenu_case grille[][TAILLE_GRILLE]) {
/*
Fonction qui prend en argument un tableau 2D (la grille)
Ne retourne rien.
Affiche la grille (X pour un bateau, O pour une case vide)
*/

  char c;

  // Couleur pour les bateaux du joueur 1 (Arrière-plan blanc)

  //const char *const green = "\033[0;41;32m";
  const char *const black = "\033[0;41;30m";
  //const char *const red = "\033[0;41;31m";
  //const char *const blue = "\033[0;41;34m";
  //const char *const magenta = "\033[0;41;35m";
  //const char *const cyan = "\033[0;41;36m";
  const char *const normal = "\033[0m";

  // Couleur pour les bateaux du joueur 2 (Arrière-plan noir)
  
  const char *const black_2 = "\033[0;37;30m";
  const char *const black_3 = "\033[0;44;30m";

  /*
  const char *const green_2 = "\033[0;32;32m";
  const char *const red_2 = "\033[0;31;31m";
  const char *const blue_2 = "\033[0;34;34m";
  const char *const magenta_2 = "\033[0;35;35m";
  const char *const cyan_2 = "\033[0;36;36m";
  */
  
  printf("\n     A  B  C  D  E  F  G  H  I  J   \n\n");

  for (int i = 0; i < TAILLE_GRILLE; ++i){
    
    printf("%d   ", i);
    
    for (int j = 0; j < TAILLE_GRILLE; ++j){
      
      if (grille[i][j].joueur1 == 0 && grille[i][j].joueur2 == 0 && grille[i][j].godzilla == 0) {
	c = '*';
	printf("%s %c %s", black_2, c, normal);
      } 
      else if (grille[i][j].godzilla == 1) {
	c = 'G';
	printf("%s %c %s", black_2, c, normal);
      }
      
      else if (grille[i][j].joueur1 == 1) {
	c = ' ';
	printf("%s %c %s", black, c, normal);
      }

      else if (grille[i][j].joueur1 == 2) {
	c = ' ';
	printf("%s %c %s", black, c, normal);
      }

      else if (grille[i][j].joueur1 == 3) {
	c = ' ';
	printf("%s %c %s", black, c, normal);
      }

      else if (grille[i][j].joueur1 == 4) {
	c = ' ';
	printf("%s %c %s", black, c, normal);
      }
      else if (grille[i][j].joueur1 == 5) {
	c = ' ';
	printf("%s %c %s", black, c, normal);
      }

      else if (grille[i][j].joueur2 == 1) {
	c = ' ';
	printf("%s %c %s", black, c, normal);
      }

      else if (grille[i][j].joueur2 == 2) {
	c = ' ';
	printf("%s %c %s", black_3, c, normal);
      }

      else if (grille[i][j].joueur2 == 3) {
	c = ' ';
	printf("%s %c %s", black_3, c, normal);
      }

      else if (grille[i][j].joueur2 == 4) {
	c = ' ';
	printf("%s %c %s", black_3, c, normal);
      }

      else if (grille[i][j].joueur2 == 5) {
	c = ' ';
	printf("%s %c %s", black_3, c, normal);
      }
    }
    printf("\n");
  }
}


