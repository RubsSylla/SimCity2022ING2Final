#include "bibli.h"

//Case = 20x20
//Hauteur 78 cases
//Longeur 94 cases -12
// -> 82


int main() {

    initialisation_allegro();

    BITMAP* premierFond;
    premierFond = load_bitmap("menu1.bmp", NULL);

    BITMAP* deuxiemeFond;
    deuxiemeFond = load_bitmap("menu2.bmp", NULL);

    BITMAP* buffer;
    buffer=create_bitmap(1024,678);

    mouse_x=5;
    mouse_b=5;

    while(!key[KEY_ESC])
    {
        clear(buffer);
        blit(premierFond,buffer,0,0,0,0,1024,678);
        blit(buffer,screen,0,0,0,0,1024,678);
        rest(1000);
        menu(buffer, premierFond, deuxiemeFond);
    }

    return 0;

}END_OF_MAIN();

void Jeu(int sauv, int cap, int com)  /// Fonction Jeu
{

    printf("Lancement de Simcity\n");

    int fin;
    fin = 0;
    int memoire;
    int grilleA = 0;

    t_jeu *J;
    t_depenses Valeur;

    t_map Ville;

    J = (t_jeu *) malloc(sizeof(t_jeu));

    Ville = Initialisation_Map(Ville);
    initialisation_StructJeu(J);
    Valeur = initialisation_Depenses(Valeur);
    Ville.Route = Initialisation_Matrice_route(Ville);

    if (cap == 1 && com == 0) {
        printf("mode capitaliste\n");
        J->mode = 1;
    }
    if (com == 1 && cap == 0) {
        printf("mode communiste\n");
        J->mode = 2;
    }

    if (sauv == 1)  /// recuperation sauvegarde
    {
        Ville = Recup_Sauvegarde(J, Ville, &Valeur);
        Ville = test_connexion_Routiere_Elec(Ville);
        Ville = test_connexion_Routiere_Eau(Ville);
        Ville = test_connexion_Routiere_Maison(Ville);
        Ville = Remplissage_Maison(Ville);
        //Ville = Connexion_Maison_ReseauElec(Ville);
    }

    /////////////////////Chrono///////////////////////////////
    int diffReset = 0;
    int min = 0;

    int *cote_affichage;

    *cote_affichage = 1;

    int compteur = 0;
    int secondes = 0;
    long clk_tck = CLOCKS_PER_SEC;
    clock_t t1;

    diffReset = ResetClock(diffReset);
    /////////////////Scrolling////////////////////////////////


    int screenx = 0;
    int screeny = 0;
    int xC = 0;
    int yC = 0;

    volatile int mouseXmonde;
    volatile int mouseYmonde;

    coord souris;

    /////////////////Scrolling////////////////////////////////

    int constru = 8;

    BITMAP *buffer;
    buffer = create_bitmap(1024, 670);

    BITMAP *grille;
    grille = load_bitmap("grille3.bmp", NULL);

    BITMAP *fond;
    fond = load_bitmap("map finale.bmp", NULL);

    if (!grille) {
        allegro_message("pas pu trouver/charger la grille");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if (!fond) {
        allegro_message("pas pu trouver/charger fond");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int compt_evo = 0;
    int signalE;
    signalE = 0;

    //////////////////////INIT BITMAP///////////////////////////////

    while (!key[KEY_ESC]) ///Boucle de jeu
    {

        if (key[KEY_G]) {
            if (grilleA == 0) {
                grilleA = 1;
            } else {
                grilleA = 0;
            }
            rest(100);
        }

        signalE = 0;

        t1 = myClock(diffReset); /// fonction de temps
        compteur = t1 / clk_tck;              ///

        signalE = Signal(compteur, &compt_evo); /// Envoi signal

        if (signalE == 1) {
            Ville = Incrementation_compt_maison(Ville);

            if (J->mode == 1) {
                Ville = Actualisation_Niveau_Maison_capitaliste(Ville, J);
            }
            if (J->mode == 2) {
                Ville = Actualisation_Niveau_Maison_communiste(Ville, J);
            }

            impots(J, Ville, compteur);
        }

        secondes = compteur;

        clear(buffer);

        scroll(xC, yC, &screenx, &screeny); /// Fonction scrolling

        mouseXmonde = mouse_x + screenx;
        mouseYmonde = mouse_y + screeny;

        souris = test(mouseXmonde - 20, mouseYmonde - 20); /// Recuperation x y Souris

        xC = renvoi_XC(xC, mouse_x);
        yC = renvoi_YC(yC, mouse_y);

        blit(fond, buffer, screenx, screeny, 0, 0, SCREEN_W, SCREEN_H);

        if (grilleA == 1) /// test d'afficahge de la grille
         {
            masked_stretch_blit(grille, buffer, screenx, screeny, SCREEN_W, SCREEN_H, 0, 0, SCREEN_W, SCREEN_H);
        }

        Actualisation_map(buffer, Ville, screenx, screeny); /// Actualisation de l map

        if (*cote_affichage == 1) /// choix d'affichage à gauche
        {
            constru = retourBarreOutil_Gauche(buffer, J, constru, cote_affichage); /// fonction récupération du choix de construction
        }

        if (*cote_affichage == 2) /// choix d'affichage à droit
         {
            constru = retourBarreOutil_Droite(buffer, J, constru, cote_affichage); /// fonction récupération du choix de construction
        }

        if (constru == 2) {
            Reseau_Eau(buffer, Ville); /// affichage du réseau d'eau
            constru = 0;
        }
        if (constru == 3) {
            Reseau_Electrique(buffer, Ville); /// affichage du réseau elec
            constru = 0;
        }

        if (*cote_affichage == 1) {
            if (mouse_x > 260) {
                if (mouse_b == 1) {
                    if (constru != 0) {
                        Ville = achat(constru, souris, Ville, Valeur, J); /// fonction d'achat du batiment
                    }
                }
                Choix_Affichage(constru, buffer, souris, screenx, screeny); /// affichage batiment sur la map
            }

        }

        if (*cote_affichage == 2) {
            if (mouse_x < 780) {
                if (mouse_b == 1) {
                    if (constru != 0) {
                        Ville = achat(constru, souris, Ville, Valeur, J);  /// fonction d'achat du batiment
                    }
                }
                Choix_Affichage(constru, buffer, souris, screenx, screeny); /// affichage batiment sur la map
            }
        }

        Ville = test_capacite_Production_elec(J,Ville); /// Fonction de test de surcharge du réseau eletrique

        if(key[KEY_H])
        {
            textprintf_centre_ex(buffer, font, 512, 0, makecol(255, 255, 255), makecol(0, 0, 0), "X : %d | Y : %d", souris.x / 20,souris.y / 20); /// Affichage des coordonnees de la souris
        }
        else
        {
            textprintf_centre_ex(buffer, font, 512, 0, makecol(255, 255, 255), makecol(0, 0, 0), "G pour afficher la grille  S pour Sauvegarder  O pour mettre le jeu en Pause"); /// affichage des touches outils
        }


        if (*cote_affichage == 1) /// affichage a gauche
        {
            if (compteur < 60) {
                textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 10, makecol(255, 255, 255), -1, "Temps ecoule : %d",compteur);
            }
            if (compteur >= 60)
            {
                min = compteur / 60;
                compteur = compteur - (min * 60);

                textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 10, makecol(255, 255, 255), -1, "Temps ecoule : %d:%d",min, compteur);
            }
            textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 20, makecol(255, 255, 255), -1, "Eletricite P/C : %d/%d",J->capaciteTotaleCentralesElectriques, J->nbtotalHabitantsVille);
            textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 30, makecol(255, 255, 255), -1, "Eau P/C: %d/%d",J->capaciteTotaleChateauEau, J->nbtotalHabitantsVille);
            textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 40, makecol(255, 255, 255), -1, "NbMaison : %d", J->nbMaison);
            textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 50, makecol(255, 255, 255), -1, "Nb Centrale hydro : %d",J->nbChateau_Eau);
            textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 60, makecol(255, 255, 255), -1, "Nb Centrale Elect : %d",J->nbCentrales);
            textprintf_ex(buffer, font, 0 + 20, 20 + 20 + 70, makecol(255, 255, 255), -1, "Nb Habitants : %d p",J->nbtotalHabitantsVille);
        }
        if (*cote_affichage == 2)  /// affichage a droite
        {
            if (compteur < 60) {
                textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 10, makecol(255, 255, 255), -1, "Temps ecoule : %d",compteur);
            }
            if (compteur >= 60) {
                min = compteur / 60;
                compteur = compteur - (min * 60);

                textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 10, makecol(255, 255, 255), -1,"Temps ecoule : %d:%d", min, compteur);
            }
            textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 20, makecol(255, 255, 255), -1,"Eletricite P/C : %d/%d", J->capaciteTotaleCentralesElectriques, J->nbtotalHabitantsVille);
            textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 30, makecol(255, 255, 255), -1, "Eau P/C: %d/%d",J->capaciteTotaleChateauEau, J->nbtotalHabitantsVille);
            textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 40, makecol(255, 255, 255), -1, "NbMaison : %d",J->nbMaison);
            textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 50, makecol(255, 255, 255), -1,"Nb Centrale hydro : %d", J->nbChateau_Eau);
            textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 60, makecol(255, 255, 255), -1,"Nb Centrale Elect : %d", J->nbCentrales);
            textprintf_ex(buffer, font, 0 + 20 + 774, 20 + 20 + 70, makecol(255, 255, 255), -1, "Nb Habitants : %d p",J->nbtotalHabitantsVille);
        }

        if (secondes >= 61) {
            secondes = 1;
        }

        ///textprintf_ex(buffer, font, 400, 0, makecol(255,255,255), makecol(0, 0, 0), "Compteur en secondes : %d", secondes);

        if (key[KEY_S]) {
            Sauvegarde_Text(J, Ville, Valeur); /// Activation fonction sauvegarde sauvegarde
        }

        if (key[KEY_O]) {
            fonctionPause(1, buffer, J, Ville, Valeur, &fin); /// Activation fonction de pause
        }

        Affichage_Industrielle(buffer, Ville, screenx, screeny); ///Fonction d'affichage des bitmaps des bâtiments industriels

        Affichage_Niveau_Maison(buffer, Ville, screenx, screeny); /// Fonction d'affichage des bitmaps des Maison

        show_mouse(buffer); /// affichage de la souris

        blit(buffer, screen, 0, 0, 0, 0, 1024, 670);
    }

}





