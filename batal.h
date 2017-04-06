# ifndef _BATAL_H_
# define _BATAL_H_
 
# define TAILLE_GRILLE 10
# define DISTANCE_MAX 100 // que peut parcourir la torpille
# define PAS_DE_BATEAU 0
# define BATEAU_JOUEUR1 1
# define BATEAU_JOUEUR2 2
# define DEUX_BATEAU 3
# define NB_CASES_TOT 15


enum Batal{
  RIEN=0, PORTE_ETENDAL=1, SUBAQUAL, CONTRE_TORPAL, CROISAL, PORTAVIAL
};

struct position{
  int ligne;
  int colonne;
};

enum direction{
  HAUT=0, BAS=1, GAUCHE, DROITE
};

enum Joueur{
  PAS_DE_JOUEUR=0, JOUEUR1=1, JOUEUR2, JOUEURS1ET2, MONSTRE
};

enum Monstre{
  PAS_DE_MONSTRE=0, GODZILLA=1
};

struct bateau{
  enum Batal taille;
  struct position position;
  enum direction direction;
  int cases_restantes;
  enum Joueur joueur;
};


struct joueur{
  enum Joueur num;
  int nb_bateaux_restants;
  int cases_restantes;
};

struct bateau liste_bateaux[10];

struct contenu_case{
  enum Batal joueur1;
  enum Batal joueur2;
  enum Monstre godzilla;
};


struct monstre{
  char *nom;
  struct position position;
  enum Joueur attaque_par;
};

struct monstre liste_monstres[1];

void afficher_grille(struct contenu_case grille[][TAILLE_GRILLE]);

void init_plateau(struct contenu_case tab[][TAILLE_GRILLE]);

void placer_bateau(struct bateau *bateau, struct joueur joueur, struct contenu_case grille[][TAILLE_GRILLE]);

struct position depart_torpille(struct bateau liste_bateaux[], struct contenu_case grille[][TAILLE_GRILLE], enum Joueur attaquant);

struct position cherche_bateau(struct contenu_case grille[][TAILLE_GRILLE], struct position dep_torpille, enum Joueur attaquant, struct monstre liste_monstres[]);

void attaquer(struct position pos, struct contenu_case grille[][TAILLE_GRILLE], struct joueur *joueur1, struct joueur *joueur2, enum Joueur attaquant, struct bateau liste_bateaux[]);

void godzilla(struct contenu_case grille[][TAILLE_GRILLE], struct bateau liste_bateaux[], struct monstre liste_monstres[], struct joueur *joueur1, struct joueur *joueur2);

void placer_monstre(struct monstre *monstre, struct contenu_case grille[][TAILLE_GRILLE]);

void jeu(struct contenu_case grille[][TAILLE_GRILLE], struct bateau liste_bateau[], struct monstre liste_monstres[], struct joueur *joueur1, struct joueur *joueur2);

# endif
