//
// Created by solix on 03/11/2022.
//

#include "bibli.h"

void menu(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond)
{
    int constanteFinDeMenu=0, regles=0, conception=0, sauvegarde=0;

    clear(buffer);

    blit(deuxiemeFond, buffer, 0,0,0,0, 1024,678);
    //blit(buffer,screen,0,0,0,0,1024,678);

    do
    {
        if(((mouse_x>=600)&&(mouse_x<=900))&&((mouse_y>=200)&&(mouse_y<=250)))
        {

            blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
            affichageDeBase(buffer);
            rectfill(buffer,600,200,900,250,violet);
            textprintf_centre_ex(buffer,font,750,225,vert,-1,"%s","COMMENCER UNE NOUVELLE PARTIE");

            if(mouse_b &1)
            {
                lancementPartie(buffer);
                menu(buffer,premierFond,deuxiemeFond);
                constanteFinDeMenu=1;
            }
            //blit(buffer,screen,0,0,0,0,1024,678);

        }

        if(((mouse_x>=600)&&(mouse_x<=900))&&((mouse_y>=300)&&(mouse_y<=350)))
        {
            blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
            affichageDeBase(buffer);
            rectfill(buffer,600,300,900,350,violet);
            textprintf_centre_ex(buffer,font,750,325,vert,-1,"%s","REPRENDRE UNE PARTIE SAUVEGARDEE");

            if(mouse_b &1)
            {
                lancementPartieSauvegarde(buffer, premierFond, deuxiemeFond);
            }
            //blit(buffer,screen,0,0,0,0,1024,678);

        }

        if(((mouse_x>=600)&&(mouse_x<=900))&&((mouse_y>=400)&&(mouse_y<=450)))
        {
            blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
            affichageDeBase(buffer);
            rectfill(buffer,600,400,900,450,violet);
            textprintf_centre_ex(buffer,font,750,425,vert,-1,"%s","REGLES");

            if(mouse_b &1)
            {
                reglesMenu(buffer, premierFond, deuxiemeFond);
            }
            //blit(buffer,screen,0,0,0,0,1024,678);

        }

        if(((mouse_x>=600)&&(mouse_x<=900))&&((mouse_y>=500)&&(mouse_y<=550)))
        {
            blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
            affichageDeBase(buffer);
            rectfill(buffer,600,500,900,550,violet);
            textprintf_centre_ex(buffer,font,750,525,vert,-1,"%s","CONCEPTION");

            if(mouse_b &1)
            {
                conceptionMenu(buffer, premierFond, deuxiemeFond);
            }
            //blit(buffer,screen,0,0,0,0,1024,678);
        }

        else
        {
            affichageDeBase(buffer);
            //blit(buffer,screen,0,0,0,0,1024,678);
        }
        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,1024,678);

    }while(!key[KEY_ESC]);
}


void affichageDeBase(BITMAP* buffer)
{

    rectfill(buffer,600,200,900,250,vert);
    textprintf_centre_ex(buffer, font, 750,225,violet,-1,"%s", "COMMENCER UNE NOUVELLE PARTIE");
    rectfill(buffer,600,300,900,350,vert);
    textprintf_centre_ex(buffer, font, 750,325,violet,-1,"%s", "REPRENDRE UNE PARTIE SAUVEGARDEE");
    rectfill(buffer,600,400,900,450,vert);
    textprintf_centre_ex(buffer, font, 750,425,violet,-1,"%s", "REGLES");
    rectfill(buffer,600,500,900,550,vert);
    textprintf_centre_ex(buffer, font, 750,525,violet,-1,"%s", "CONCEPTION");
}


/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void reglesMenu(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond)
{
    int constanteDeFin=0;

    clear(buffer);
    blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
    rectfill(buffer, 924, 648, 1014, 688, vert);
    textprintf_ex(buffer, font, 927, 653, violet,-1, "%s", "RETOUR MENU");

    rectfill(buffer,600,130,950,370, vert);

    do {
        textprintf_ex(buffer, font, 610, 150, violet, -1, "%s", "Tiraben city est un jeu de constriction");
        textprintf_ex(buffer, font, 610, 160, violet, -1, "%s", "dont la regle principale est evidente :");
        textprintf_ex(buffer, font, 610, 170, violet, -1, "%s", "CONSTRUIRE LA MEGAPOLE LA PLUS IMPOSANTE.");

        textprintf_ex(buffer, font, 610, 200, violet, -1, "%s", "Dans cette version , il est possible de");
        textprintf_ex(buffer, font, 610, 210, violet, -1, "%s", "construire des routes, des usines, des");
        textprintf_ex(buffer, font, 610, 220, violet, -1, "%s", "terrains vagues ainsi que des maisons.");
        textprintf_ex(buffer, font, 610, 230, violet, -1, "%s", "Mais n'oubliez pas ; sans connexion,");
        textprintf_ex(buffer, font, 610, 240, violet, -1, "%s", "aux reseaux electrique et hydrolique,");
        textprintf_ex(buffer, font, 610, 250, violet, -1, "%s", "vous pourriez avoir de serieux");
        textprintf_ex(buffer, font, 610, 260, violet, -1, "%s", "problemes...");

        textprintf_ex(buffer, font, 610, 290, violet, -1, "%s", "Sauvegardez votre partie en cours ");
        textprintf_ex(buffer, font, 610, 300, violet, -1, "%s", "si celle-ci vous plait et gare");
        textprintf_ex(buffer, font, 610, 310, violet, -1, "%s", "a ne pas trop depenser, la hausse");
        textprintf_ex(buffer, font, 610, 320, violet, -1, "%s", "des impots peut vous etre fatale.");

        textprintf_ex(buffer, font, 610, 350, violet, -1, "%s", "Alors a vos marteaux !");

        if (((mouse_y >= 648) && (mouse_y <= 688)) && ((mouse_x >= 924) && (mouse_x <= 1014)))
        {
            if (mouse_b & 1) {
                menu(buffer, premierFond, deuxiemeFond);
                constanteDeFin=1;
            }
        }
        show_mouse(buffer);
        blit(buffer, screen, 0, 0, 0, 0, 1024, 678);
    }while(constanteDeFin!=1);
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void conceptionMenu(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond)
{
    int constanteDeFin=0;

    clear(buffer);
    blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
    rectfill(buffer, 924, 648, 1014, 688, vert);
    textprintf_ex(buffer, font, 927, 653, violet,-1, "%s", "RETOUR MENU");

    rectfill(buffer,600,250,900,440, vert);

    do {
        textprintf_ex(buffer, font, 610, 270, violet, -1, "%s", "Createurs : CORDONNIER Iris");
        textprintf_ex(buffer, font, 610, 280, violet, -1, "%s", "            DO OLIVAL Timothe");
        textprintf_ex(buffer, font, 610, 290, violet, -1, "%s", "            RUHOMUTALLY Lucas");
        textprintf_ex(buffer, font, 610, 300, violet, -1, "%s", "            SYLLA Ruben");

        textprintf_ex(buffer, font, 610, 330, violet, -1, "%s", "Ce jeu a ete entierement concu par");
        textprintf_ex(buffer, font, 610, 340, violet, -1, "%s", "des eleves de l'ECE PARIS pour un");
        textprintf_ex(buffer, font, 610, 350, violet, -1, "%s", "projet semstriel ; il est le");
        textprintf_ex(buffer, font, 610, 360, violet, -1, "%s", "fruit d'un travail de 4 semaines.");

        textprintf_ex(buffer, font, 610, 390, violet, -1, "%s", "Nous avons utilise le logiciel CLion");
        textprintf_ex(buffer, font, 610, 400, violet, -1, "%s", "ainsi que l'extension Allegro ce qui");
        textprintf_ex(buffer, font, 610, 410, violet, -1, "%s", "nous a permis de realiser ce jeu ");
        textprintf_ex(buffer, font, 610, 420, violet, -1, "%s", "en 2D graphiquement.");


        if (((mouse_y >= 648) && (mouse_y <= 688)) && ((mouse_x >= 924) && (mouse_x <= 1014))) {
            if (mouse_b & 1)
            {
                menu(buffer, premierFond, deuxiemeFond);
                constanteDeFin=1;
            }
        }
        blit(buffer, screen, 0, 0, 0, 0, 1024, 678);
    }while(constanteDeFin!=1);
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void lancementPartieSauvegarde(BITMAP* buffer, BITMAP* premierFond, BITMAP* deuxiemeFond)
{
    int existancePartieSauvegardee=-1, constanteDeFin=0;

    FILE* fichierSauvegarde;
    fichierSauvegarde=fopen("Sauvegarde.txt", "r+");

    if(fichierSauvegarde==NULL)
    {
        printf("erreur d'ouverture du fichier sauvegarde\n");
    }

    fscanf(fichierSauvegarde, "%d", &existancePartieSauvegardee);
    if(existancePartieSauvegardee==1)
    {
        printf("ouverture de la partie sauvegardee...\n");
        Jeu(1);
    }
    if(existancePartieSauvegardee==0)
    {
        clear(buffer);
        blit(deuxiemeFond,buffer,0,0,0,0,1024,678);
        rectfill(buffer, 924, 648, 1014, 688, vert);
        textprintf_ex(buffer, font, 927, 653, violet,-1, "%s", "RETOUR MENU");

        rectfill(buffer,600,340,900,400, vert);

        do {
            textprintf_ex(buffer, font, 610, 350, violet, -1, "%s", "Il n'hexiste pas de partie");
            textprintf_ex(buffer, font, 610, 360, violet, -1, "%s", "sauvegardee. Veuillez retourner");
            textprintf_ex(buffer, font, 610, 370, violet, -1, "%s", "au menu et choisissez :");
            textprintf_ex(buffer, font, 610, 390, violet, -1, "%s", "COMMENCER UNE NOUVELLE PARTIE.");

            if (((mouse_y >= 648) && (mouse_y <= 688)) && ((mouse_x >= 924) && (mouse_x <= 1014))) {
                if (mouse_b & 1) {
                    menu(buffer, premierFond, deuxiemeFond);
                    constanteDeFin=1;
                }
            }
            blit(buffer, screen, 0, 0, 0, 0, 1024, 678);
        } while (constanteDeFin!=1);
    }
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pause()
{
    allegro_message("mode PAUSE active !\nCliquez sur ENTER pour revenir au jeu.");
    getchar();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void lancementPartie(BITMAP* buffer) {
    int constanteDeFin = 0, kPause = 0;

    BITMAP *pause;
    pause = load_bitmap("pause.bmp", NULL);
    clear(buffer);

    while(!key[KEY_ESC])
    {

        Jeu(0);

        /*clear(buffer);
        rectfill(buffer, 900, 20, 1000, 50, vert);
        textprintf_ex(buffer, font, 915, 35, violet, "%s", "P : PAUSE");

        if(key[KEY_P])
        {
            kPause=1;
        }

        if(kPause==1)
        {
            blit(pause, buffer, 736, 0, 736, 0, 1024, 678);
            while(kPause==1)
            {
                blit(buffer, screen, 0,0,0,0,1024,678);
                if(key[KEY_P])
                {
                    clear(buffer);
                    kPause=0;
                }
            }
        }
        else
        {
            blit(buffer, screen, 0,0,0,0,1024,678);
        }*/

    } //NE SERA JAMAIS EGAL A DEUX CAR LA PARTIE CONTINUE MEME APRES LA PAUSE
}

void pause(BITMAP* buffer)
{
    int kPause=0;
    BITMAP *pause;
    pause = load_bitmap("pause.bmp", NULL);
    if(key[KEY_O])
    {
        kPause=1;
    }

    if(kPause==1)
    {
        blit(pause, buffer, 736, 0, 736, 0, 1024, 678);
        while(kPause==1)
        {
            blit(buffer, screen, 0,0,0,0,1024,678);
            if(key[KEY_P])
            {
                clear(buffer);
                kPause=0;
            }
        }
    }
}

void fonctionPause(int kPause, BITMAP* buffer,t_jeu* J, t_map Ville, t_depenses P, int* fin)
{

    BITMAP *pause;
    pause = load_bitmap("pause.bmp", NULL);

    BITMAP* premierFond;
    premierFond = load_bitmap("menu1.bmp", NULL);

    BITMAP* deuxiemeFond;
    deuxiemeFond = load_bitmap("menu2.bmp", NULL);

    blit(pause, buffer, 736, 0, 736, 0, 1024, 678);
    rectfill(buffer, 755, 625, 855, 650, vert);
    textprintf_centre_ex(buffer, font, 805, 635, violet, -1, "%s", "RETOUR MENU");
    rectfill(buffer, 900, 625, 1000, 650, vert);
    textprintf_centre_ex(buffer, font, 950, 635, violet, -1, "%s", "SAUVEGARDER");

    while(kPause==1)
    {
        blit(buffer, screen, 0, 0, 0, 0, 1024, 678);
        if (key[KEY_P])
        {
            clear(buffer);
            kPause = 0;
            *fin = 0;
        }
        if ((mouse_x > 755 && mouse_x < 855) && (mouse_y > 626 && mouse_y < 650)) {
            if (mouse_b & 1) {
                *fin = 1;
                kPause = 0;
                Sauvegarde_Text(J,Ville,P);
                menu(buffer, premierFond, deuxiemeFond);
            }
        }
        if ((mouse_x > 900 && mouse_x < 1000) && (mouse_y > 626 && mouse_y < 650)) {
            if (mouse_b & 1) {
                *fin = 0;
                kPause = 0;
                Sauvegarde_Text(J,Ville,P);
            }
        }
    }
}