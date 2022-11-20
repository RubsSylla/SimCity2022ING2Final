//
// Created by solix on 08/11/2022.
//

#include "bibli.h"

t_map Remplissage_ReseauCanalVide(t_map Ville)
{
    for(int i=0; i<LIGNE; i++)
    {
        for (int j = 0; j < COLONNE; j++)
        {
            if(Ville.type[i][j] == 1)
            {
                Ville.Eau[i][j].type = 6;
                Ville.hydro_connecte = 1;
            }
        }
    }

    return Ville;
}

t_map Recherche_Parcours_Tuyau_Eau_Centrale(t_map Ville)
{
    int coordxSource;
    int coordySource;
    int i=0,j=0,k=0,l=0;

    int cote=0; /// 1 haut /// 2 bas /// 3 gauche /// 4 droite

    coord sortie;

    for(int k=0; k<LIGNE; k++)
    {
        for(int l=0; l<COLONNE; l++)
        {
            if(Ville.Eau[k][l].type == 3)
            {
                coordxSource = l;
                coordySource = k;

                if(Ville.industrielle[coordySource][coordxSource].relie == 1)
                {
                    for(int i=-1; i<2; i++)
                    {
                        if(Ville.type[coordySource-2][coordxSource+i] == 1) /// Test coté haut
                        {
                            cote = 1;

                            sortie.x = coordxSource + i;
                            sortie.y = coordySource - 2;
                        }
                        if(Ville.type[coordySource+5][coordxSource+i] == 1) /// Test coté bas
                        {
                            cote = 2;

                            sortie.x = coordxSource + i;
                            sortie.y = coordySource + 5;
                        }
                    }


                    for(int i = -1; i<4; i++)
                    {
                        if(Ville.type[coordySource+i][coordxSource-2] == 1) /// Test coté gauche
                        {
                            cote = 3;

                            sortie.x = coordxSource - 2;
                            sortie.y = coordySource + i;
                        }
                        if(Ville.type[coordySource+i][coordxSource+3] == 1) /// Test coté droit
                        {
                            cote = 4;

                            sortie.x = coordxSource + 3;
                            sortie.y = coordySource + i;
                        }
                    }

                    Ville.hydro_connecte = 1;
                }

                Ville.Eau[sortie.y][sortie.x].type = 4;

                i=0;
                j=0;

                if(cote == 1)
                {
                    Ville.Eau[coordySource-1][coordxSource].type = 5;
                    if(sortie.x > coordxSource)
                    {
                        i = coordxSource;

                        while(sortie.x != i)
                        {
                            i++;
                            Ville.Eau[coordySource-1][i].type = 5;
                        }
                    }
                    if(sortie.x < coordxSource)
                    {
                        Ville.Eau[coordySource-1][coordxSource-1].type = 5;
                    }
                }
                if(cote == 2)
                {
                    Ville.Eau[coordySource+1][coordxSource].type = 5;
                    Ville.Eau[coordySource+2][coordxSource].type = 5;
                    Ville.Eau[coordySource+3][coordxSource].type = 5;
                    Ville.Eau[coordySource+4][coordxSource].type = 5;

                    if(sortie.x > coordxSource)
                    {
                        i = coordxSource;

                        while(sortie.x != i)
                        {
                            i++;
                            Ville.Eau[coordySource+4][i].type = 5;
                        }
                    }
                    if(sortie.x < coordxSource)
                    {
                        Ville.Eau[coordySource+4][coordxSource-1].type = 5;
                    }
                    if(sortie.x == coordxSource)
                    {
                        Ville.Eau[coordySource+4][coordxSource].type = 5;
                    }
                }
                if(cote == 3)
                {
                    if(sortie.y < coordySource)
                    {
                        Ville.Eau[coordySource-1][coordxSource].type = 5;
                        Ville.Eau[coordySource-1][coordxSource-1].type = 5;
                    }
                    else if(sortie.y > coordySource)
                    {
                        j = coordySource;

                        while(sortie.y != j)
                        {
                            j++;
                            Ville.Eau[j][coordxSource].type = 5;
                        }
                        Ville.Eau[sortie.y][coordxSource - 1].type = 5;
                    }
                    else if(sortie.y == coordySource)
                    {
                        Ville.Eau[coordySource][coordxSource-1].type = 5;
                    }
                }
                if(cote == 4)
                {
                    if(sortie.y < coordySource)
                    {
                        Ville.Eau[coordySource-1][coordxSource].type = 5;
                        Ville.Eau[coordySource-1][coordxSource+1].type = 5;
                        Ville.Eau[coordySource-1][coordxSource+2].type = 5;
                    }
                    else if(sortie.y > coordySource)
                    {
                        j = coordySource;

                        while(sortie.y != j)
                        {
                            j++;
                            Ville.Eau[j][coordxSource].type = 5;
                        }
                        Ville.Eau[sortie.y][coordxSource+1].type = 5;
                        Ville.Eau[sortie.y][coordxSource+2].type = 5;
                    }
                    else if(sortie.y == coordySource)
                    {
                        Ville.Eau[coordySource][coordxSource+1].type = 5;
                        Ville.Eau[coordySource][coordxSource+2].type = 5;
                    }
                }
            }
        }
    }

    return Ville;

}

void Affichage_Tuyaux(BITMAP* buffer, t_map Ville, int screenx, int screeny)
{
    int valeur;
    int gris = makecol (230,230,230);
    int rouge = makecol(255,0,0);
    int verte = makecol(0,255,0);
    int Source = makecol(255,255,0);
    int blanc = makecol(255,255,255);
    int Eau = makecol(0,0,255);


    for(int i = 0; i<LIGNE; i++)
    {
        for(int j = 0; j<COLONNE; j++)
        {
            if(Ville.Eau[i][j].type != 0)
            {
                valeur = Ville.Eau[i][j].type;
                if(valeur == 1)
                {
                    rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,Eau);
                }
                if(valeur == 6)
                {
                    rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,gris);
                }
                if(valeur == 2)
                {
                    if(Ville.maisons[i][j].relieEau == 1)
                    {
                        rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,verte);

                        rectfill(buffer, (j+1)*20 + 1 - screenx, i*20 + 1- screeny, (j+1)*20 + 18- screenx, i*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j+1)*20 + 1 - screenx, (i+1)*20 + 1- screeny, (j+1)*20 + 18- screenx, (i+1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j+1)*20 + 1 - screenx, (i-1)*20 + 1- screeny, (j+1)*20 + 18- screenx, (i-1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j-1)*20 + 1 - screenx, i*20 + 1- screeny, (j-1)*20 + 18- screenx, i*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j-1)*20 + 1 - screenx, (i+1)*20 + 1- screeny, (j-1)*20 + 18- screenx, (i+1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j-1)*20 + 1 - screenx, (i-1)*20 + 1- screeny, (j-1)*20 + 18- screenx, (i-1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, j*20 + 1 - screenx, (i+1)*20 + 1- screeny, j*20 + 18- screenx, (i+1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, j*20 + 1 - screenx, (i-1)*20 + 1- screeny, j*20 + 18- screenx, (i-1)*20 + 18 - screeny,blanc);
                    }
                    else
                    {
                        rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,rouge);

                        rectfill(buffer, (j+1)*20 + 1 - screenx, i*20 + 1- screeny, (j+1)*20 + 18- screenx, i*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j+1)*20 + 1 - screenx, (i+1)*20 + 1- screeny, (j+1)*20 + 18- screenx, (i+1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j+1)*20 + 1 - screenx, (i-1)*20 + 1- screeny, (j+1)*20 + 18- screenx, (i-1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j-1)*20 + 1 - screenx, i*20 + 1- screeny, (j-1)*20 + 18- screenx, i*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j-1)*20 + 1 - screenx, (i+1)*20 + 1- screeny, (j-1)*20 + 18- screenx, (i+1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, (j-1)*20 + 1 - screenx, (i-1)*20 + 1- screeny, (j-1)*20 + 18- screenx, (i-1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, j*20 + 1 - screenx, (i+1)*20 + 1- screeny, j*20 + 18- screenx, (i+1)*20 + 18 - screeny,blanc);
                        rectfill(buffer, j*20 + 1 - screenx, (i-1)*20 + 1- screeny, j*20 + 18- screenx, (i-1)*20 + 18 - screeny,blanc);
                    }
                }
                if(valeur == 3)
                {
                    rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,Source);
                }
                if(valeur == 4)
                {
                    rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,verte);
                }
                if(valeur == 5)
                {
                    rectfill(buffer, j*20 + 1- screenx, i*20 + 1- screeny, j*20 + 18- screenx, i*20 + 18 - screeny,blanc);
                }
            }
        }
    }
}

void Reseau_Eau(BITMAP *buffer, t_map Ville)
{
    int screenx = 0;
    int screeny = 0;
    int xC = 0;
    int yC = 0;

    volatile int mouseXmonde;
    volatile int mouseYmonde;

    clear(buffer);

    BITMAP* grille;
    grille = load_bitmap("grille3.bmp", NULL);

    BITMAP* fond;
    fond = load_bitmap("Niveau-1.bmp", NULL);
    if(!fond)
    {
        allegro_message("pas pu trouver/charger le fond eau");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    while(!key[KEY_2])
    {
        clear(buffer);

        scroll(xC,yC,&screenx,&screeny);

        mouseXmonde = mouse_x + screenx;
        mouseYmonde = mouse_y + screeny;

        xC = renvoi_XC(xC,mouse_x);
        yC = renvoi_YC(yC,mouse_y);

        blit(fond,buffer,screenx,screeny,0,0,SCREEN_W,SCREEN_H);

        masked_stretch_blit(grille,buffer,screenx,screeny,SCREEN_W,SCREEN_H,0,0,SCREEN_W,SCREEN_H);

        textprintf_centre_ex(buffer,font,500,0,makecol(255,255,255),makecol(0,0,0),"2 pour quitter");

        Ville = Recherche_Parcours_Tuyau_Eau_Centrale(Ville);

        Affichage_Tuyaux(buffer,Ville,screenx,screeny);

        affichage_legende_eau(buffer);

        show_mouse(buffer);

        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }


}

t_map test_connexion_Routiere_Eau(t_map Ville)
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
                    Ville.hydro_connecte = 1;
                    Ville = Remplissage_ReseauCanalVide(Ville);


                }
            }

        }
    }

    return Ville;
}
