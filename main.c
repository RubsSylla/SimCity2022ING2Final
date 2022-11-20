#include "bibli.h"

//Case = 20x20
//Hauteur 78 cases
//Longeur 94 cases


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
        rest(5000);
        menu(buffer, premierFond, deuxiemeFond);
    }

    return 0;

}END_OF_MAIN();

void Jeu(int sauv)
{
    int fin;
    fin = 0;
    int memoire;

    t_jeu* J;
    t_depenses Valeur;

    t_map Ville;

    J = (t_jeu*)malloc(sizeof (t_jeu));

    Ville = Initialisation_Map(Ville);
    initialisation_StructJeu(J);
    Valeur = initialisation_Depenses(Valeur);

    if(sauv == 1)
    {
        Ville = Recup_Sauvegarde(J,Ville,&Valeur);
        Ville = test_connexion_Routiere_Elec(Ville);
        Ville = test_connexion_Routiere_Eau(Ville);
        Ville = test_connexion_Routiere_Maison(Ville);
        //Ville = Connexion_Maison_ReseauElec(Ville);
    }
    /////////////////////Chrono///////////////////////////////
    int diffReset = 0;
    int min=0;

    int* cote_affichage;

    *cote_affichage = 1;

    int compteur=0;
    int secondes=0;
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
    buffer = create_bitmap(1024,670);

    BITMAP *grille;
    grille = load_bitmap("grille3.bmp", NULL);

    BITMAP *fond;
    fond = load_bitmap("map finale.bmp", NULL);

    if(!grille)
    {
        allegro_message("pas pu trouver/charger la grille");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    if(!fond)
    {
        allegro_message("pas pu trouver/charger fond");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    int compt_evo = 0;
    int signalE;
    signalE = 0;

    while(!key[KEY_ESC])
    {
        signalE = 0;

        t1 = myClock(diffReset); /// fonction de temps
        compteur = t1/clk_tck;              ///

        signalE = Signal(compteur,&compt_evo);

        if(signalE == 1)
        {
            Ville = Incrementation_compt_maison(Ville);
            Ville = Actualisation_Niveau_Maison(Ville,J);
            impots(J,compteur);
        }

        secondes = compteur;

        clear(buffer);

        scroll(xC,yC,&screenx,&screeny);

        mouseXmonde = mouse_x + screenx;
        mouseYmonde = mouse_y + screeny;

        souris = test(mouseXmonde-20,mouseYmonde-20);

        xC = renvoi_XC(xC,mouse_x);
        yC = renvoi_YC(yC,mouse_y);

        blit(fond,buffer,screenx,screeny,0,0,SCREEN_W,SCREEN_H);

        masked_stretch_blit(grille,buffer,screenx,screeny,SCREEN_W,SCREEN_H,0,0,SCREEN_W,SCREEN_H);

        Actualisation_map(buffer,Ville,screenx,screeny);

        if(*cote_affichage == 1)
        {
            constru = retourBarreOutil_Gauche(buffer,J,constru,cote_affichage);
        }

        if(*cote_affichage == 2)
        {
            constru = retourBarreOutil_Droite(buffer,J,constru,cote_affichage);
        }

        if(constru == 2)
        {
            Reseau_Eau(buffer,Ville);
            constru = 0;
        }
        if(constru == 3)
        {
            Reseau_Electrique(buffer,Ville);
            constru = 0;
        }

        if(*cote_affichage == 1)
        {
            if(mouse_x > 260)
            {
                if(mouse_b == 1)
                {
                    if(constru != 0)
                    {
                        Ville = achat(constru,souris,Ville,Valeur,J);
                    }
                }
                Choix_Affichage(constru,buffer,souris,screenx,screeny);
            }

        }

        if(*cote_affichage == 2)
        {
            if(mouse_x < 780)
            {
                if(mouse_b == 1)
                {
                    if(constru != 0)
                    {
                        Ville = achat(constru,souris,Ville,Valeur,J);
                    }
                }
                Choix_Affichage(constru,buffer,souris,screenx,screeny);
            }
        }

        textprintf_ex(buffer, font, 500, 0, makecol(255, 255, 255),makecol(0, 0, 0), "X : %d | Y : %d",souris.x/20,souris.y/20);

        if(*cote_affichage == 1)
        {
            if(compteur < 60)
            {
                textprintf_ex(buffer, font, 0+20, 20+20+10, makecol(255,255,255), -1, "Temps ecoule : %d", compteur);
            }
            if(compteur >= 60)
            {
                min = compteur/60;
                compteur = compteur-(min*60);

                textprintf_ex(buffer, font, 0+20, 20+20+10, makecol(255,255,255), -1, "Temps ecoule : %d:%d", min,compteur);
            }
            textprintf_ex(buffer, font, 0+20, 20+20+20, makecol(255,255,255), -1, "Capacite Eletrique : %d", J->capaciteTotaleCentralesElectriques);
            textprintf_ex(buffer, font, 0+20, 20+20+30, makecol(255,255,255), -1, "Capacité Eau : %d", J->capaciteTotaleChateauEau);
            textprintf_ex(buffer, font, 0+20, 20+20+40, makecol(255,255,255), -1, "NbMaison : %d", J->nbMaison);
            textprintf_ex(buffer, font, 0+20, 20+20+50, makecol(255,255,255), -1, "Nb Centrale hydro : %d", J->nbChateau_Eau);
            textprintf_ex(buffer, font, 0+20, 20+20+60, makecol(255,255,255), -1, "Nb Centrale Elect : %d", J->nbCentrales);
            textprintf_ex(buffer, font, 0+20, 20+20+70, makecol(255,255,255), -1, "Nb Habitants : %d p", J->nbtotalHabitantsVille);
        }
        if(*cote_affichage == 2)
        {
            if(compteur < 60)
            {
                textprintf_ex(buffer, font, 0+20+774, 20+20+10, makecol(255,255,255), -1, "Temps ecoule : %d", compteur);
            }
            if(compteur >= 60)
            {
                min = compteur/60;
                compteur = compteur-(min*60);

                textprintf_ex(buffer, font, 0+20+774, 20+20+10, makecol(255,255,255), -1, "Temps ecoule : %d:%d", min,compteur);
            }
            textprintf_ex(buffer, font, 0+20+774, 20+20+20, makecol(255,255,255), -1, "Capacite Eletrique : %d", J->capaciteTotaleCentralesElectriques);
            textprintf_ex(buffer, font, 0+20+774, 20+20+30, makecol(255,255,255), -1, "Capacité Eau : %d", J->capaciteTotaleChateauEau);
            textprintf_ex(buffer, font, 0+20+774, 20+20+40, makecol(255,255,255), -1, "NbMaison : %d", J->nbMaison);
            textprintf_ex(buffer, font, 0+20+774, 20+20+50, makecol(255,255,255), -1, "Nb Centrale hydro : %d", J->nbChateau_Eau);
            textprintf_ex(buffer, font, 0+20+774, 20+20+60, makecol(255,255,255), -1, "Nb Centrale Elect : %d", J->nbCentrales);
            textprintf_ex(buffer, font, 0+20+774, 20+20+70, makecol(255,255,255), -1, "Nb Habitants : %d p", J->nbtotalHabitantsVille);
        }

        if(secondes >= 61)
        {
            secondes = 1;
        }

        ///textprintf_ex(buffer, font, 400, 0, makecol(255,255,255), makecol(0, 0, 0), "Compteur en secondes : %d", secondes);

        if(key[KEY_S])
        {
            Sauvegarde_Text(J,Ville,Valeur);
        }

        if(key[KEY_O])
        {
            fonctionPause(1,buffer,J,Ville,Valeur,&fin);
        }

        Affichage_Industrielle(buffer,Ville,screenx,screeny);

        Affichage_Niveau_Maison(buffer,Ville,screenx,screeny);

        show_mouse(buffer);

        blit(buffer,screen,0,0,0,0,1024, 670);
    }

}





