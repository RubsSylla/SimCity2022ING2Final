#include "bibli.h"

t_map Incrementation_compt_maison(t_map Ville)
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].existe == 1)
            {
                Ville.maisons[i][j].compteur++;
                //printf("Augmentation compteur maison en %d %d -> %d\n",i,j,Ville.maisons[i][j].compteur);
            }
        }
    }

    return Ville;
}

t_map Actualisation_Niveau_Maison(t_map Ville, t_jeu *J)
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].compteur % 15 == 0 && Ville.maisons[i][j].compteur != 0)
            {
                if(Ville.maisons[i][j].niveau < 5)
                {
                    Ville.maisons[i][j].niveau++;

                    if(Ville.maisons[i][j].niveau == 2)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 10;
                    }
                    if(Ville.maisons[i][j].niveau == 3)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 40;
                    }
                    if(Ville.maisons[i][j].niveau == 4)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 50;
                    }
                    if(Ville.maisons[i][j].niveau == 5)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 900;
                    }
                }
            }

        }
    }

    return Ville;
}

void Affichage_Niveau_Maison(BITMAP* buffer,t_map Ville, int screenx, int screeny)
{

    BITMAP* Maison1;
    Maison1 = load_bitmap("MAISON0.bmp", NULL);

    if(!Maison1)
    {
        allegro_message("pas pu trouver/charger la maison 1");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison2;
    Maison2 = load_bitmap("MAISON1.bmp", NULL);

    if(!Maison2)
    {
        allegro_message("pas pu trouver/charger la maison 2");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison3;
    Maison3 = load_bitmap("MAISON2.bmp", NULL);

    if(!Maison3)
    {
        allegro_message("pas pu trouver/charger la maison 3");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison4;
    Maison4 = load_bitmap("MAISON3.bmp", NULL);

    if(!Maison4)
    {
        allegro_message("pas pu trouver/charger la maison 4");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison5;
    Maison5 = load_bitmap("MAISON4.bmp", NULL);

    if(!Maison5)
    {
        allegro_message("pas pu trouver/charger la maison 5");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].existe==1)
            {
                //textprintf_centre_ex(buffer,font,j*20 + 1 - screenx + 10, i*20 + 1 - screeny + 10,makecol(255,255,255),-1,"%d",Ville.maisons[i][j].niveau);
                if(Ville.maisons[i][j].niveau == 1)
                {
                    draw_sprite(buffer, Maison1, (j-1)*20 - screenx, (i-1)*20 - 11 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 2)
                {
                    draw_sprite(buffer, Maison2, (j-1)*20 - screenx, (i-1)*20 - 22 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 3)
                {
                    draw_sprite(buffer, Maison3, (j-1)*20 - screenx, (i-1)*20 -11 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 4)
                {
                    draw_sprite(buffer, Maison4, (j-1)*20 - screenx, (i-1)*20 -11 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 5)
                {
                    draw_sprite(buffer, Maison5, (j-1)*20 - screenx, (i-1)*20 -47 - screeny);
                }
            }

        }
    }
}

void impots(t_jeu* J, int compteur)
{
    if(compteur % 15 == 0)
    {
        J->budget = J->budget + J->nbtotalHabitantsVille*10;
    }
}
