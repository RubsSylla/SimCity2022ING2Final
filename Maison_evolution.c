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

t_map Actualisation_Niveau_Maison_capitaliste(t_map Ville, t_jeu *J)
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
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+10;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 10;
                    }
                    if(Ville.maisons[i][j].niveau == 3)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 40;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+40;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 40;
                    }
                    if(Ville.maisons[i][j].niveau == 4)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 50;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+50;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 50;
                    }
                    if(Ville.maisons[i][j].niveau == 5)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 900;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+900;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 900;
                    }
                }
            }

        }
    }

    return Ville;
}

t_map Actualisation_Niveau_Maison_communiste(t_map Ville, t_jeu *J)
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].compteur % 15 == 0 && Ville.maisons[i][j].compteur != 0)
            {

                if(Ville.maisons[i][j].niveau < 5 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille && J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille)
                {
                    //allegro_message("test 2");
                    Ville.maisons[i][j].niveau++;

                    if(Ville.maisons[i][j].niveau == 2 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille && J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 10;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+10;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 10;
                    }
                    if(Ville.maisons[i][j].niveau == 3 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille && J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 40;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+40;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 40;
                    }
                    if(Ville.maisons[i][j].niveau == 4 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille && J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 50;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+50;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 50;
                    }
                    if(Ville.maisons[i][j].niveau == 5 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille && J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 900;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+900;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 900;
                    }
                }
                else if(Ville.maisons[i][j].niveau >= 2 && J->capaciteTotaleChateauEau < J->nbtotalHabitantsVille && J->capaciteTotaleCentralesElectriques < J->nbtotalHabitantsVille)
                {
                    Ville.maisons[i][j].niveau--;
                }
                else
                {
                    //allegro_message("ELLE A EST AU NIVEAU LE PLUS BAS OU ELLE STAGNE");
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

void impots(t_jeu* J, t_map Ville, int compteur)
{
    if(compteur % 15 == 0)
    {
        if(Ville.reseau_connecte == 1)
        {
            J->budget = J->budget + J->nbtotalHabitantsVille*10;
        }

    }
}

t_map Recherche_Jonction_Maison(t_map Ville)
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
            if(Ville.maisons[k][l].existe == 1)
            {
                coordxSource = l;
                coordySource = k;

                if(Ville.maisons[coordySource][coordxSource].relie == 1)
                {
                    for(int i=-1; i<1; i++)
                    {
                        if(Ville.type[coordySource-2][coordxSource+i] == 1) /// Test coté haut
                        {
                            cote = 1;

                            sortie.x = coordxSource + i;
                            sortie.y = coordySource - 2;
                        }
                        if(Ville.type[coordySource+2][coordxSource+i] == 1) /// Test coté bas
                        {
                            cote = 2;

                            sortie.x = coordxSource + i;
                            sortie.y = coordySource + 2;
                        }
                    }

                    for(int i = -1; i<1; i++)
                    {
                        if(Ville.type[coordySource+i][coordxSource-2] == 1) /// Test coté gauche
                        {
                            cote = 3;

                            sortie.x = coordxSource - 2;
                            sortie.y = coordySource + i;
                        }
                        if(Ville.type[coordySource+i][coordxSource+2] == 1) /// Test coté droit
                        {
                            cote = 4;

                            sortie.x = coordxSource + 2;
                            sortie.y = coordySource + i;
                        }
                    }
                }

                Ville.Eau[sortie.y][sortie.x].type = 7;
                Ville.Courant[sortie.y][sortie.x].type = 7;

                Ville.maisons[k][l].Jonction->x = sortie.x;
                Ville.maisons[k][l].Jonction->y = sortie.y;
            }
        }
    }

    return Ville;
}