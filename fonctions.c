//
// Created by solix on 02/11/2022.
//
#include "bibli.h"

void Choix_Affichage(int constru, BITMAP* buffer, coord souris, int screenx, int screeny)
{
    if(constru == 1)
    {
        Affichage_Route(buffer,souris,screenx,screeny);
    }
    if(constru == 4)
    {
        Affichage_Centale_Eau(buffer,souris,screenx,screeny);
    }
    if(constru == 5)
    {
        Affichage_Centrale_Nucleaire(buffer,souris,screenx,screeny);
    }
    if(constru == 6)
    {
        Affichage_TerrainVague(buffer,souris,screenx,screeny);
    }
}

t_map test_connexion_Routiere_Maison(t_map Ville)
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].existe == 1)
            {
                if(Ville.type[i][j+2] == 1 || Ville.type[i+1][j+2] == 1 || Ville.type[i-1][j+2]
                   || Ville.type[i][j-2] == 1 || Ville.type[i+1][j-2] == 1 || Ville.type[i-1][j-2]
                   || Ville.type[i-2][j+1] == 1 || Ville.type[i-2][j-1] == 1 || Ville.type[i-2][j]
                   || Ville.type[i+2][j+1] == 1 || Ville.type[i+2][j-1] == 1 || Ville.type[i+2][j])
                {
                    Ville.maisons[i][j].relie = 1;

                    if(Ville.reseau_connecte == 1)
                    {
                        Ville.maisons[i][j].relieElec = 1;
                    }
                }
            }

        }
    }
    return Ville;
}

t_map test_connexion_Routiere_Utilitaire(t_map Ville)
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.industrielle[i][j].existe == 1)
            {
                if( Ville.type[i-1][j-2] == 1 || Ville.type[i][j-2] == 1 || Ville.type[i+1][j-2]
                || Ville.type[i+2][j-2] == 1 || Ville.type[i+3][j-2] == 1 || Ville.type[i+4][j-2]

                || Ville.type[i-1][j+3] == 1 || Ville.type[i][j+3] == 1 || Ville.type[i+1][j+3]
                || Ville.type[i+2][j+3] == 1 || Ville.type[i+3][j+3] == 1 || Ville.type[i+4][j+3]

                || Ville.type[i-2][j-1] == 1 || Ville.type[i-2][j] == 1 || Ville.type[i-2][j+1] || Ville.type[i-2][j+2] == 1
                || Ville.type[i+5][j-1] == 1 || Ville.type[i+5][j] == 1 || Ville.type[i+5][j+1] || Ville.type[i+5][j+2] == 1)
                {

                    Ville.industrielle[i][j].relie = 1;

                }
            }

        }
    }

    return Ville;
}

void Actualisation_map(BITMAP* buffer, t_map Ville, int screenx, int screeny) /// Affichage sur buffer des éléments nouveau
{
    //int route = makecol(0,0,0);
    int rouge = makecol(255,0,0);
    int verte = makecol(0,255,0);
    int usine = makecol(180,144,118);
    int maisonR = makecol(0,255,0);
    int maisonNR = makecol(255,0,0);
    int UsineNR = makecol(255,0,0);
    int UsineR = makecol(0,255,0);
    int Eau = makecol(85,162,215);
    int Elec = makecol(255,255,0);

    BITMAP* route;
    route = load_bitmap("route.bmp",NULL);

    int y,x;

    Ville = test_connexion_Routiere_Maison(Ville);
    Ville = test_connexion_Routiere_Utilitaire(Ville);
    Ville = test_connexion_Routiere_Elec(Ville);
    Ville = test_connexion_Routiere_Eau(Ville);

    for(int i=1; i < LIGNE; i++)
    {
        for(int j=1; j < COLONNE; j++)
        {
            y = i*20;
            x = j*20;

            if(Ville.type[i][j] == 1) /// Routes
            {
                blit(route, buffer, 0,0, x + 1- screenx, y + 1- screeny,1024,670);
                //rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,route);
            }
            /*if(Ville.type[i][j] == 6) /// Maison
            {
                if(Ville.maisons[i][j].relie == 1)
                {
                    rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,maisonR);
                }
                if(Ville.maisons[i][j].relie == 0)
                {
                    rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,maisonNR);
                }

            }*/
            /*if(Ville.type[i][j] == 4) /// Centrale Eau
            {
                if(Ville.industrielle[i][j].relie == 1)
                {
                    rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,verte);
                }
                if(Ville.industrielle[i][j].relie == 0)
                {
                    rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,Eau);
                }
            }
            if(Ville.type[i][j] == 5) /// Centrale Elec
            {
                if(Ville.industrielle[i][j].relie == 1)
                {
                    rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,verte);
                }
                if(Ville.industrielle[i][j].relie == 0)
                {
                    rectfill(buffer, x + 1- screenx, y + 1- screeny, x + 18- screenx, y + 18 - screeny,Elec);
                }
            }*/

        }
    }
}

t_map achat(int constru,coord souris,t_map Ville, t_depenses prix, t_jeu* jeu)

{
    int x,y;
    x=souris.x / 20;
    y=souris.y / 20;
    int condition = 0;

    if(constru == 1) /// route 1x1
    {
        if(Ville.occupation[y][x] == 0)
        {
            if(x > 12)
            {
                condition = acheterBatiment(prix,jeu,constru);
                if(condition == 1)
                {
                    Ville.occupation[y][x] = 1;
                    Ville.type[y][x] = 1;
                    Ville = Acutalisation_Matrice_Route(Ville);
                }
            }


        }
    }
    else if(constru == 6) /// Maison 3x3
    {
        if(Ville.occupation[y][x] == 0
           && Ville.occupation[y][x - 1] == 0 && Ville.occupation[y][x + 1] == 0
           && Ville.occupation[y - 1][x] == 0 && Ville.occupation[y + 1][x] == 0
           && Ville.occupation[y - 1][x - 1] == 0 && Ville.occupation[y + 1][x - 1] == 0
           && Ville.occupation[y-1][x+1] == 0 && Ville.occupation[y+1][x+1] == 0)
        {
            if(x > 12) {
                condition = acheterBatiment(prix,jeu,constru);
                if(condition == 1)
                {
                    Ville.Courant[y][x].type = 2; /// 2 pour maison
                    Ville.Eau[y][x].type = 2;     /// 2 pour maison

                    Ville.maisons[y][x].existe = 1;
                    Ville.maisons[y][x].niveau = 1;

                    Ville.occupation[y][x] = 1;
                    Ville.occupation[y + 1][x] = 1;
                    Ville.occupation[y - 1][x] = 1;
                    Ville.occupation[y][x - 1] = 1;
                    Ville.occupation[y][x + 1] = 1;
                    Ville.occupation[y - 1][x + 1] = 1;
                    Ville.occupation[y + 1][x - 1] = 1;
                    Ville.occupation[y - 1][x - 1] = 1;
                    Ville.occupation[y + 1][x + 1] = 1;

                    Ville.type[y][x] = 6;
                    Ville.type[y + 1][x] = 6;
                    Ville.type[y - 1][x] = 6;
                    Ville.type[y][x - 1] = 6;
                    Ville.type[y][x + 1] = 6;
                    Ville.type[y - 1][x + 1] = 6;
                    Ville.type[y + 1][x - 1] = 6;
                    Ville.type[y - 1][x - 1] = 6;
                    Ville.type[y + 1][x + 1] = 6;
                }


            }
        }
    }

    else if(constru == 4) /// Zone centrale a eau 4x6
    {
        if(Ville.occupation[y][x] == 0
           && Ville.occupation[y][x - 1] == 0 && Ville.occupation[y][x + 1] == 0
           && Ville.occupation[y - 1][x] == 0 && Ville.occupation[y + 1][x] == 0
           && Ville.occupation[y - 1][x - 1] == 0 && Ville.occupation[y + 1][x - 1] == 0
           && Ville.occupation[y-1][x+1] == 0 && Ville.occupation[y+1][x+1] == 0

           && Ville.occupation[y+3][x] == 0
           && Ville.occupation[y+3][x - 1] == 0 && Ville.occupation[y+3][x + 1] == 0
           && Ville.occupation[y - 1+3][x] == 0 && Ville.occupation[y + 1+3][x] == 0
           && Ville.occupation[y - 1+3][x - 1] == 0 && Ville.occupation[y + 1+3][x - 1] == 0
           && Ville.occupation[y-1+3][x+1] == 0 && Ville.occupation[y+1+3][x+1] == 0

           && Ville.occupation[y-1][x+2] == 0
           && Ville.occupation[y][x+2] == 0
           && Ville.occupation[y+1][x+2] == 0
           && Ville.occupation[y+2][x+2] == 0
           && Ville.occupation[y+3][x+2] == 0
           && Ville.occupation[y+4][x+2] == 0) {
            if (x > 12)
            {
                condition = acheterBatiment(prix,jeu,constru);
                if(condition == 1)
                {
                    Ville.Eau[y][x].type = 3;

                    Ville.industrielle[y][x].existe = 1;
                    Ville.industrielle[y][x].statut = 2;
                    Ville.occupation[y][x] = 1;
                    Ville.occupation[y + 1][x] = 1;
                    Ville.occupation[y - 1][x] = 1;
                    Ville.occupation[y][x - 1] = 1;
                    Ville.occupation[y][x + 1] = 1;
                    Ville.occupation[y - 1][x + 1] = 1;
                    Ville.occupation[y + 1][x - 1] = 1;
                    Ville.occupation[y - 1][x - 1] = 1;
                    Ville.occupation[y + 1][x + 1] = 1;

                    Ville.occupation[y + 3][x] = 1;
                    Ville.occupation[y + 1 + 3][x] = 1;
                    Ville.occupation[y - 1 + 3][x] = 1;
                    Ville.occupation[y + 3][x - 1] = 1;
                    Ville.occupation[y + 3][x + 1] = 1;
                    Ville.occupation[y - 1 + 3][x + 1] = 1;
                    Ville.occupation[y + 1 + 3][x - 1] = 1;
                    Ville.occupation[y - 1 + 3][x - 1] = 1;
                    Ville.occupation[y + 1 + 3][x + 1] = 1;

                    Ville.occupation[y - 1][x + 2] = 1;
                    Ville.occupation[y][x + 2] = 1;
                    Ville.occupation[y + 1][x + 2] = 1;
                    Ville.occupation[y + 2][x + 2] = 1;
                    Ville.occupation[y + 3][x + 2] = 1;
                    Ville.occupation[y + 4][x + 2] = 1;

                    Ville.type[y][x] = 4;
                    Ville.type[y + 1][x] = 4;
                    Ville.type[y - 1][x] = 4;
                    Ville.type[y][x - 1] = 4;
                    Ville.type[y][x + 1] = 4;
                    Ville.type[y - 1][x + 1] = 4;
                    Ville.type[y + 1][x - 1] = 4;
                    Ville.type[y - 1][x - 1] = 4;
                    Ville.type[y + 1][x + 1] = 4;

                    Ville.type[y + 3][x] = 4;
                    Ville.type[y + 1 + 3][x] = 4;
                    Ville.type[y - 1 + 3][x] = 4;
                    Ville.type[y + 3][x - 1] = 4;
                    Ville.type[y + 3][x + 1] = 4;
                    Ville.type[y - 1 + 3][x + 1] = 4;
                    Ville.type[y + 1 + 3][x - 1] = 4;
                    Ville.type[y - 1 + 3][x - 1] = 4;
                    Ville.type[y + 1 + 3][x + 1] = 4;

                    Ville.type[y - 1][x + 2] = 4;
                    Ville.type[y][x + 2] = 4;
                    Ville.type[y + 1][x + 2] = 4;
                    Ville.type[y + 2][x + 2] = 4;
                    Ville.type[y + 3][x + 2] = 4;
                    Ville.type[y + 4][x + 2] = 4;
                }

        }

        }
    }
    else if(constru == 5) /// Zone centrale electrique 4x6
    {
        if(Ville.occupation[y][x] == 0
           && Ville.occupation[y][x - 1] == 0 && Ville.occupation[y][x + 1] == 0
           && Ville.occupation[y - 1][x] == 0 && Ville.occupation[y + 1][x] == 0
           && Ville.occupation[y - 1][x - 1] == 0 && Ville.occupation[y + 1][x - 1] == 0
           && Ville.occupation[y-1][x+1] == 0 && Ville.occupation[y+1][x+1] == 0

           && Ville.occupation[y+3][x] == 0
           && Ville.occupation[y+3][x - 1] == 0 && Ville.occupation[y+3][x + 1] == 0
           && Ville.occupation[y - 1+3][x] == 0 && Ville.occupation[y + 1+3][x] == 0
           && Ville.occupation[y - 1+3][x - 1] == 0 && Ville.occupation[y + 1+3][x - 1] == 0
           && Ville.occupation[y-1+3][x+1] == 0 && Ville.occupation[y+1+3][x+1] == 0

           && Ville.occupation[y-1][x+2] == 0
           && Ville.occupation[y][x+2] == 0
           && Ville.occupation[y+1][x+2] == 0
           && Ville.occupation[y+2][x+2] == 0
           && Ville.occupation[y+3][x+2] == 0
           && Ville.occupation[y+4][x+2] == 0)
        {
            if(x > 12) {
                condition = acheterBatiment(prix,jeu,constru);
                if(condition == 1)
                {
                    Ville.Courant[y][x].type = 3;

                    Ville.industrielle[y][x].existe = 1;
                    Ville.industrielle[y][x].statut = 3;
                    Ville.occupation[y][x] = 1;
                    Ville.occupation[y + 1][x] = 1;
                    Ville.occupation[y - 1][x] = 1;
                    Ville.occupation[y][x - 1] = 1;
                    Ville.occupation[y][x + 1] = 1;
                    Ville.occupation[y - 1][x + 1] = 1;
                    Ville.occupation[y + 1][x - 1] = 1;
                    Ville.occupation[y - 1][x - 1] = 1;
                    Ville.occupation[y + 1][x + 1] = 1;

                    Ville.occupation[y + 3][x] = 1;
                    Ville.occupation[y + 1 + 3][x] = 1;
                    Ville.occupation[y - 1 + 3][x] = 1;
                    Ville.occupation[y + 3][x - 1] = 1;
                    Ville.occupation[y + 3][x + 1] = 1;
                    Ville.occupation[y - 1 + 3][x + 1] = 1;
                    Ville.occupation[y + 1 + 3][x - 1] = 1;
                    Ville.occupation[y - 1 + 3][x - 1] = 1;
                    Ville.occupation[y + 1 + 3][x + 1] = 1;

                    Ville.occupation[y - 1][x + 2] = 1;
                    Ville.occupation[y][x + 2] = 1;
                    Ville.occupation[y + 1][x + 2] = 1;
                    Ville.occupation[y + 2][x + 2] = 1;
                    Ville.occupation[y + 3][x + 2] = 1;
                    Ville.occupation[y + 4][x + 2] = 1;

                    Ville.type[y][x] = 5;
                    Ville.type[y + 1][x] = 5;
                    Ville.type[y - 1][x] = 5;
                    Ville.type[y][x - 1] = 5;
                    Ville.type[y][x + 1] = 5;
                    Ville.type[y - 1][x + 1] = 5;
                    Ville.type[y + 1][x - 1] = 5;
                    Ville.type[y - 1][x - 1] = 5;
                    Ville.type[y + 1][x + 1] = 5;

                    Ville.type[y + 3][x] = 5;
                    Ville.type[y + 1 + 3][x] = 5;
                    Ville.type[y - 1 + 3][x] = 5;
                    Ville.type[y + 3][x - 1] = 5;
                    Ville.type[y + 3][x + 1] = 5;
                    Ville.type[y - 1 + 3][x + 1] = 5;
                    Ville.type[y + 1 + 3][x - 1] = 5;
                    Ville.type[y - 1 + 3][x - 1] = 5;
                    Ville.type[y + 1 + 3][x + 1] = 5;

                    Ville.type[y - 1][x + 2] = 5;
                    Ville.type[y][x + 2] = 5;
                    Ville.type[y + 1][x + 2] = 5;
                    Ville.type[y + 2][x + 2] = 5;
                    Ville.type[y + 3][x + 2] = 5;
                    Ville.type[y + 4][x + 2] = 5;
                }


            }
        }
    }

    return Ville;
}

void Affichage_Route(BITMAP* buffer, coord souris, int screenx, int screeny)
{
    int route = makecol(0,0,0);
    rectfill(buffer, souris.x + 1- screenx, souris.y + 1- screeny, souris.x + 18- screenx, souris.y + 18 - screeny,route);
}

void Affichage_TerrainVague(BITMAP* buffer, coord souris, int screenx, int screeny)
{
    int t_v = makecol(255,0,0);
    rectfill(buffer, souris.x + 1- screenx, souris.y + 1- screeny, souris.x + 18- screenx, souris.y + 18 - screeny,t_v);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 - screeny,t_v);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 - screeny,t_v);
    rectfill(buffer, souris.x + 1- screenx, souris.y + 20 + 1- screeny, souris.x + 18- screenx, souris.y + 20 + 18 - screeny,t_v);
    rectfill(buffer, souris.x + 1- screenx, souris.y - 20 + 1- screeny, souris.x + 18- screenx, souris.y - 20 + 18 - screeny,t_v);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y + 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 + 20 - screeny,t_v);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y + 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 + 20 - screeny,t_v);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y - 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 - 20 - screeny,t_v);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y - 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 - 20 - screeny,t_v);
}

void Affichage_Centale_Eau(BITMAP* buffer, coord souris, int screenx, int screeny)
{
    int usine = makecol(0,0,255);

    rectfill(buffer, souris.x + 1- screenx, souris.y + 1- screeny, souris.x + 18- screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y + 20 + 1- screeny, souris.x + 18- screenx, souris.y + 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y - 20 + 1- screeny, souris.x + 18- screenx, souris.y - 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y + 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y + 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y - 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 - 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y - 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 - 20 - screeny,usine);

    rectfill(buffer, souris.x  + 1 - screenx, souris.y+60 + 1- screeny, souris.x + 18- screenx, souris.y+60 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y+60 + 1- screeny, souris.x + 20 + 18- screenx, souris.y+60 + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y+60 + 1- screeny, souris.x - 20 + 18- screenx, souris.y+60 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y+60 + 20 + 1- screeny, souris.x + 18- screenx, souris.y+60 + 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y+60 - 20 + 1- screeny, souris.x + 18- screenx, souris.y+60 - 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y+60 + 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y+60 + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y+60 + 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y+60 + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y+60 - 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y+60 + 18 - 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y+60 - 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y+60 + 18 - 20 - screeny,usine);

    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y -20 + 1- screeny, souris.x +40 + 18- screenx, souris.y -20 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y + 1 - screeny, souris.x +40 + 18 - screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +20 + 1- screeny, souris.x +40 + 18- screenx, souris.y +20 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +40 + 1- screeny, souris.x +40 + 18- screenx, souris.y +40 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +60 + 1- screeny, souris.x +40 + 18- screenx, souris.y +60 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +80 + 1- screeny, souris.x +40 + 18- screenx, souris.y +80 + 18 - screeny,usine);

}

void Affichage_Centrale_Nucleaire(BITMAP* buffer, coord souris, int screenx, int screeny)
{
    int usine = makecol(255,230,0);

    rectfill(buffer, souris.x + 1- screenx, souris.y + 1- screeny, souris.x + 18- screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y + 20 + 1- screeny, souris.x + 18- screenx, souris.y + 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y - 20 + 1- screeny, souris.x + 18- screenx, souris.y - 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y + 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y + 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y - 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y + 18 - 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y - 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y + 18 - 20 - screeny,usine);

    rectfill(buffer, souris.x  + 1 - screenx, souris.y+60 + 1- screeny, souris.x + 18- screenx, souris.y+60 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y+60 + 1- screeny, souris.x + 20 + 18- screenx, souris.y+60 + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y+60 + 1- screeny, souris.x - 20 + 18- screenx, souris.y+60 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y+60 + 20 + 1- screeny, souris.x + 18- screenx, souris.y+60 + 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x + 1- screenx, souris.y+60 - 20 + 1- screeny, souris.x + 18- screenx, souris.y+60 - 20 + 18 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y+60 + 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y+60 + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y+60 + 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y+60 + 18 + 20 - screeny,usine);
    rectfill(buffer, souris.x - 20 + 1- screenx, souris.y+60 - 20 + 1- screeny, souris.x - 20 + 18- screenx, souris.y+60 + 18 - 20 - screeny,usine);
    rectfill(buffer, souris.x + 20 + 1- screenx, souris.y+60 - 20 + 1- screeny, souris.x + 20 + 18- screenx, souris.y+60 + 18 - 20 - screeny,usine);

    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y -20 + 1- screeny, souris.x +40 + 18- screenx, souris.y -20 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y + 1 - screeny, souris.x +40 + 18 - screenx, souris.y + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +20 + 1- screeny, souris.x +40 + 18- screenx, souris.y +20 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +40 + 1- screeny, souris.x +40 + 18- screenx, souris.y +40 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +60 + 1- screeny, souris.x +40 + 18- screenx, souris.y +60 + 18 - screeny,usine);
    rectfill(buffer, souris.x +40 + 1 - screenx, souris.y +80 + 1- screeny, souris.x +40 + 18- screenx, souris.y +80 + 18 - screeny,usine);

}



