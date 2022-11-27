//
// Created by solix on 15/11/2022.
//

#include "bibli.h"

void Affichage_Industrielle(BITMAP* buffer,t_map Ville, int screenx, int screeny)
{
    BITMAP* Eau;
    Eau = load_bitmap("EauVrai.bmp", NULL);

    if(!Eau)
    {
        allegro_message("pas pu trouver/charger la eau");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Elec;
    Elec = load_bitmap("CentraleVrai.bmp", NULL);

    if(!Elec)
    {
        allegro_message("pas pu trouver/charger la centrale");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.Courant[i][j].type == 3)
            {
                rectfill(buffer,(j-1)*20 - screenx, (i-1)*20 - screeny, (j+3)*20 - screenx, (i+5)*20 - screeny,makecol(160,160,160));
                draw_sprite(buffer, Elec, (j-1)*20 - screenx, (i)*20 - screeny);
            }
            if(Ville.Eau[i][j].type == 3)
            {
                rectfill(buffer,(j-1)*20 - screenx, (i-1)*20 - screeny, (j+3)*20 - screenx, (i+5)*20 - screeny,makecol(160,160,160));
                draw_sprite(buffer, Eau, (j-1)*20 - screenx - 1, (i)*20 - 11 - screeny);
            }

        }
    }
}

