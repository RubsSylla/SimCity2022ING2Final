//
// Created by solix on 02/11/2022.
//

#ifndef TOUT_BIBLI_H
#define TOUT_BIBLI_H

#include <stdio.h>
#include <allegro.h>
#include <stdlib.h>
#include <time.h>

#define CARRE 20

#define COLONNE 94
#define LIGNE 78
#define vert makecol(224,235,214)
#define violet makecol(50,22,61)

typedef struct maillon{ /// Structure d'un maillon
    int numero; /// sommet
    struct maillon* next;

}t_maillon;

typedef struct file{   /// Structure d'une file
    t_maillon* debut;
    t_maillon* fin;
}t_file;

typedef struct
{
    int x;
    int y;

}coord;

typedef struct jeu{
    int budget; // Le budget du maire
    int impots;// les impots que les habitant payent
    int nbtotalHabitantsVille;
    int capaciteTotaleCentralesElectriques;
    int capaciteTotaleChateauEau;
    int nbCasernes;
    int nbRoutes;
    int nbChateau_Eau;
    int nbCentrales;
    int nbMaison;
    int sauvegarde;
    int mode; ///1 capitaliste /// 2 communiste
}t_jeu;

typedef struct habitations{
    int existe;
    int niveau; /// 1 Terrain Vague /// 2 maison1 /// 3 maison 2 /// 4 maison3 /// 5 maison4 /// 6 maison5
    int eau;
    int electricite;
    int dist_eau; /// Distance de la centrale a eau la plus proche
    int dist_elec; /// Distance de la centrale elec la plus proche
    int relieEau;
    int relieElec;
    int relie;
    int nbHabitants;
    coord coordonnees;
    int compteur;
    coord *Jonction;
    int distanceElec;
    int distanceEau;
}t_habitations;

typedef struct utilitaire{
    int existe;
    int statut; // Quel type d'infrastructure ? 1 Elec, 2 Eau, 3 Usine
    int relie;
    int EDistribue;
    int capaciteTotale;
    coord *Jonction;
    int compteur;

}t_Utilitaire;

typedef struct Canalisation
{
    int occupation;
    int type; /// 1 canal Relie /// 2 Maison /// 3 source /// 4 Sortie /// 5 PreSortie /// 6 vide /// 7 Sortie Maison
    int liaison;
    int flux;
    coord Jonction;
    int capaciteMax;
    int Nbconnexions;
}t_canal;

typedef struct FilElec
{
    int occupation;
    int type; /// 1 canal /// 2 Maison /// 3 source /// 4 Sortie /// 5 PreSortie /// 7 Sortie Maison
    int liaison;
    int flux;
    coord Jonction;
    int capaciteMax;
}t_Elec;

typedef struct RouteMatrice{
    int *existe;
    int **Adjacence;
    int *decouvert;
    int ordre;
    int *Prede;

}t_MatriceRoute;

typedef struct Map
{
    int **type;
    int **occupation;
    t_habitations **maisons;
    t_Utilitaire **industrielle;
    t_canal **Eau;
    t_Elec **Courant;
    t_MatriceRoute Route;
    int reseau_connecte;
    int hydro_connecte;


}t_map;

typedef struct depenses{
    int centralesElectrique; // Ce sont les couts des batiments
    int chateauEau;
    int route;
    int terrainvague;
    int nbterrainvague;
    int caserne;
}t_depenses;



void initialisation_allegro(); // Initialisation  d'allegro
t_map Initialisation_Map(t_map Ville); /// Initialisation structure map
void initialisation_StructJeu (t_jeu* jeu); // Initialisation de la structure Jeu: Structure contenant les donnees permettant d'informer l'utilisateur de ses infrastructures et habitants
t_depenses initialisation_Depenses (t_depenses prix); // Initialisation des prix des infrastructures

void Jeu(int sauv, int cap, int com);
void Affichage_TerrainVague(BITMAP* buffer, coord souris, int screenx, int screeny);
void Affichage_Route(BITMAP* buffer, coord souris, int screenx, int screeny);
void Affichage_Usine_Chateau(BITMAP* buffer, coord souris, int screenx, int screeny);
void Reseau_Eau(BITMAP *buffer, t_map Ville); /// Fonction d'affichage de tous le reseau d'eau
void Reseau_Electrique(BITMAP *buffer, t_map Ville); /// affichage du réseau électrique
void Affichage_Centale_Eau(BITMAP* buffer, coord souris, int screenx, int screeny);
void Affichage_Centrale_Nucleaire(BITMAP* buffer, coord souris, int screenx, int screeny);
void Choix_Affichage(int constru, BITMAP* buffer, coord souris, int screenx, int screeny);

void scroll(int playX, int playY, int *cameraX, int *cameraY);
coord test(int coordX, int coordY);
int renvoi_XC(int XC, int mouseX);
int renvoi_YC(int YC, int mouseY);
void enfilage(t_file*f, int numero);
int defiler(t_file*f);
void afficherfile(t_file *file);

void Actualisation_map(BITMAP* buffer, t_map Ville, int screenx, int screeny);
t_map achat(int constru,coord souris,t_map Ville,t_depenses prix, t_jeu* jeu);

t_map test_connexion_Routiere_Maison(t_map Ville);

int acheterBatiment (t_depenses prix, t_jeu *jeu, int choix); // Fonction d'achat d'un batiment
int retourBarreOutil_Gauche(BITMAP* buffer, t_jeu* j, int retour, int* cote); /// fonction de selection de batiments
int retourBarreOutil_Droite(BITMAP* buffer, t_jeu* j, int retour, int* cote); /// fonction de selection de batiments

int myClock(int diffAfterReset);
int ResetClock(int diffAfterReset);
int Signal(int t1, int *memoire);

void menu(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond);
void affichageDeBase(BITMAP* buffer);
void reglesMenu(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond);
void conceptionMenu(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond);
void lancementPartieSauvegarde(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond);
void pause(BITMAP* buffer);
void lancementPartie(BITMAP* buffer);

t_map Recherche_Parcours_Fil_Elec_Centrale(t_map Ville); /// recherche parcours fil à la route depuis la source
t_map Remplissage_ReseauElec(t_map Ville); /// allocation des fils élec sur la matrice de la map

t_map Connexion_Maison_ReseauElec(t_map Ville); /// test connextion Maison au réseau electrique

void Affichage_Tuyaux(BITMAP* buffer, t_map Ville, int screenx, int screeny); /// affichage des Tuyaux sur la map
void Affichage_FilElec(BITMAP* buffer, t_map Ville, int screenx, int screeny);

t_map test_connexion_Routiere_Utilitaire(t_map Ville);
t_map test_connexion_Routiere_Elec(t_map Ville); /// Condition de connexion à la route

t_map Recherche_Parcours_Tuyau_Eau_Centrale(t_map Ville); /// recherche des tuyaux dans la centrale
t_map Remplissage_ReseauCanalVide(t_map Ville); /// remplissage des tuyaux vide sur la map
t_map test_connexion_Routiere_Eau(t_map Ville);  /// Connextion de la centrale a la route

t_map Recup_Sauvegarde(t_jeu* J, t_map Ville, t_depenses* P); /// Recuperation de la sauvegarde
void Sauvegarde_Text(t_jeu* J, t_map Ville, t_depenses P); /// Ecriture de la sauvegarde

t_map Incrementation_compt_maison(t_map Ville);
t_map Actualisation_Niveau_Maison_capitaliste(t_map Ville, t_jeu *J);
t_map Actualisation_Niveau_Maison_communiste(t_map Ville, t_jeu *J);

void fonctionPause(int kPause, BITMAP* buffer,t_jeu* J, t_map Ville, t_depenses P, int* fin);

void Affichage_Niveau_Maison(BITMAP* buffer,t_map Ville, int screenx, int screeny);
void Affichage_Industrielle(BITMAP* buffer,t_map Ville, int screenx, int screeny);

void affichage_legende_eau(BITMAP* buffer);
void affichage_legende_elec(BITMAP* buffer);

void impots(t_jeu* J, t_map Ville, int compteur);

t_MatriceRoute Initialisation_Matrice_route(t_map Ville);
t_map Acutalisation_Matrice_Route(t_map Ville);

t_map Parcours_BFS_distance(coord debut, coord fin, t_map Ville, int ymaison, int xmaison);
t_map Distance_Maison_CentraleEau(t_map Ville); /// Calcul distance tuyaux
t_map Recherche_Jonction_Maison(t_map Ville);

coord conversion_produit_sommet(int x);  /// conversion sommet format matrice -> en coordonnees x | y

t_map test_capacite_Production_elec(t_jeu *j,t_map Ville); /// test de surcharge production et consommation électricité
t_map Remplissage_Maison(t_map Ville); /// alimentation des maisons en eletricité et en eau

#endif //TOUT_BIBLI_H
