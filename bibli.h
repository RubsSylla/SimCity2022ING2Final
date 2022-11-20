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
}t_jeu;

typedef struct habitations{
    int existe;
    int niveau; /// 1 Terrain Vague /// 2 maison1 /// 3 maison 2 /// 4 maison3 /// 5 maison4 /// 6 maison5
    int eau;
    int electricite;
    int relieEau;
    int relieElec;
    int relie;
    int nbHabitants;
    coord coordonnees;
    int compteur;
    coord *Jonction;
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
    int type; /// 1 canal /// 2 Maison /// 3 source /// 4 Sortie /// 5 PreSortie /// 6 vide
    int liaison;
    int flux;
    int capaciteMax;
}t_canal;

typedef struct FilElec
{
    int occupation;
    int type; /// 1 canal /// 2 Maison /// 3 source /// 4 Sortie /// 5 PreSortie
    int liaison;
    int flux;
    int capaciteMax;
}t_Elec;

typedef struct Map
{
    int **type;
    int **occupation;
    t_habitations **maisons;
    t_Utilitaire **industrielle;
    t_canal **Eau;
    t_Elec **Courant;
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

void initialisation_allegro();
t_map Initialisation_Map(t_map Ville);
void initialisation_StructJeu (t_jeu* jeu);
t_depenses initialisation_Depenses (t_depenses prix);

void Jeu(int sauv);
void Affichage_TerrainVague(BITMAP* buffer, coord souris, int screenx, int screeny);
void Affichage_Route(BITMAP* buffer, coord souris, int screenx, int screeny);
void Affichage_Usine_Chateau(BITMAP* buffer, coord souris, int screenx, int screeny);
void Reseau_Eau(BITMAP *buffer, t_map Ville);
void Reseau_Electrique(BITMAP *buffer, t_map Ville);
void Affichage_Centale_Eau(BITMAP* buffer, coord souris, int screenx, int screeny);
void Affichage_Centrale_Nucleaire(BITMAP* buffer, coord souris, int screenx, int screeny);
void Choix_Affichage(int constru, BITMAP* buffer, coord souris, int screenx, int screeny);

void scroll(int playX, int playY, int *cameraX, int *cameraY);
coord test(int coordX, int coordY);
int renvoi_XC(int XC, int mouseX);
int renvoi_YC(int YC, int mouseY);

void Actualisation_map(BITMAP* buffer, t_map Ville, int screenx, int screeny);
t_map achat(int constru,coord souris,t_map Ville,t_depenses prix, t_jeu* jeu);

t_map test_connexion_Routiere_Maison(t_map Ville);

int retourBarreOutil(BITMAP* buffer, t_jeu* j, int retour);
int acheterBatiment (t_depenses prix, t_jeu *jeu, int choix);
int retourBarreOutil_Gauche(BITMAP* buffer, t_jeu* j, int retour, int* cote);
int retourBarreOutil_Droite(BITMAP* buffer, t_jeu* j, int retour, int* cote);

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

t_map Recherche_Parcours_Fil_Elec_Centrale(t_map Ville);
t_map Remplissage_ReseauElec(t_map Ville);

t_map Connexion_Maison_ReseauElec(t_map Ville);

void Affichage_Tuyaux(BITMAP* buffer, t_map Ville, int screenx, int screeny);
void Affichage_FilElec(BITMAP* buffer, t_map Ville, int screenx, int screeny);

t_map test_connexion_Routiere_Utilitaire(t_map Ville);
t_map test_connexion_Routiere_Elec(t_map Ville);

t_map Recherche_Parcours_Tuyau_Eau_Centrale(t_map Ville);
t_map Remplissage_ReseauCanalVide(t_map Ville);
t_map test_connexion_Routiere_Eau(t_map Ville);

t_map Recup_Sauvegarde(t_jeu* J, t_map Ville, t_depenses* P);
void Sauvegarde_Text(t_jeu* J, t_map Ville, t_depenses P);

t_map Incrementation_compt_maison(t_map Ville);
t_map Actualisation_Niveau_Maison(t_map Ville, t_jeu *J);

void fonctionPause(int kPause, BITMAP* buffer,t_jeu* J, t_map Ville, t_depenses P, int* fin);

void Affichage_Niveau_Maison(BITMAP* buffer,t_map Ville, int screenx, int screeny);
void Affichage_Industrielle(BITMAP* buffer,t_map Ville, int screenx, int screeny);

void affichage_legende_eau(BITMAP* buffer);
void affichage_legende_elec(BITMAP* buffer);

void impots(t_jeu* J, int compteur);

#endif //TOUT_BIBLI_H
