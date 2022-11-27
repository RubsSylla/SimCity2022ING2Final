//
// Created by solix on 10/11/2022.
//

#include "bibli.h"

t_map Recup_Sauvegarde(t_jeu* J, t_map Ville, t_depenses* P)
{
    int compteur = 0;
    int x,y;

    FILE * ifs = fopen("Sauvegarde.txt","r+");

    if(!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }

    fscanf(ifs,"%d",&J->sauvegarde);
    fscanf(ifs,"%d",&J->mode);
    fscanf(ifs,"%d",&J->budget);
    fscanf(ifs,"%d",&J->nbtotalHabitantsVille);
    fscanf(ifs,"%d",&J->nbMaison);
    fscanf(ifs,"%d",&J->nbCentrales);
    fscanf(ifs,"%d",&J->nbChateau_Eau);
    fscanf(ifs,"%d\n",&J->capaciteTotaleCentralesElectriques);
    fscanf(ifs,"%d\n",&J->capaciteTotaleChateauEau);
    fscanf(ifs,"%d",&Ville.hydro_connecte);
    fscanf(ifs,"%d",&Ville.reseau_connecte);

    printf("Recuperation initialisation struct Jeu...\n");

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            fscanf(ifs,"%d",&Ville.occupation[i][j]);
            printf("%d ", Ville.occupation[i][j]);
            //printf("TurboProut");
        }
    }

    printf("\nRecuperation Occupation...\n");

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            fscanf(ifs,"%d",&Ville.type[i][j]);
            printf("%d ", Ville.type[i][j]);
        }

    }
    printf("\n");

    printf("Recuperation Type effectue...\n");

    printf("%d -> nombre maison\n", J->nbMaison);

    while(compteur != J->nbMaison)
    {
        fscanf(ifs,"%d %d",&x,&y);
        fscanf(ifs,"%d %d %d %d %d %d %d",&Ville.maisons[x][y].existe,&Ville.maisons[x][y].niveau, &Ville.maisons[x][y].relieElec, &Ville.maisons[x][y].relieEau, &Ville.maisons[x][y].relie, &Ville.maisons[x][y].Jonction->x, &Ville.maisons[x][y].Jonction->y);
        compteur++;
    }

    printf("Fin recuperation Maison\n");

    compteur = 0;

    printf("%d -> nombre Elec\n", J->nbCentrales);

    while(compteur != J->nbCentrales)
    {
        fscanf(ifs,"%d %d",&x,&y);
        fscanf(ifs,"%d %d %d %d", &Ville.Courant[x][y].type, &Ville.Courant[x][y].liaison, &Ville.Courant[x][y].occupation, &Ville.Courant[x][y].capaciteMax);
        compteur++;
    }

    printf("Fin recuperation Centrales\n");

    compteur = 0;

    printf("%d -> nombre Eau\n", J->nbChateau_Eau);

    while(compteur != J->nbChateau_Eau)
    {
        fscanf(ifs,"%d %d",&x,&y);
        fscanf(ifs,"%d %d %d %d", &Ville.Eau[x][y].type, &Ville.Eau[x][y].liaison, &Ville.Eau[x][y].occupation, &Ville.Eau[x][y].capaciteMax);
        compteur++;
    }

    printf("Fin recuperation Chateau Eau\n");

    compteur = 0;

    printf("Recuperation Batiment industrielle reliage...\n");

    int somme;

    somme = J->nbChateau_Eau + J->nbCentrales;

    while(compteur != somme)
    {
        fscanf(ifs,"%d %d",&x,&y);
        fscanf(ifs,"%d %d %d", &Ville.industrielle[x][y].existe, &Ville.industrielle[x][y].relie, &Ville.industrielle[x][y].statut);
        compteur++;
    }

    printf("Fin Recuperation Batiment industrielle reliage...\n");

    fscanf(ifs,"%d\n", &P->route);
    fscanf(ifs,"%d\n", &P->terrainvague);
    fscanf(ifs,"%d\n", &P->centralesElectrique);
    fscanf(ifs,"%d\n", &P->chateauEau);

    printf("Route %d\n", P->route);
    printf("terrainV %d\n", P->terrainvague);
    printf("Elec %d\n", P->centralesElectrique);
    printf("Eau %d\n", P->chateauEau);

    printf("Recuperation depenses...\n");

    fclose(ifs);

    return Ville;

}

void Sauvegarde_Text(t_jeu* J, t_map Ville, t_depenses P)
{
    FILE * ifs = fopen("Sauvegarde.txt","w");

    FILE * ifz = fopen("SauvegardeMatriceRoute.txt","w");

    int existe = 1;

    if(!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    else if(!ifz)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }
    else
    {
        fprintf(ifs,"%d\n", existe);
        fprintf(ifs,"%d\n", J->mode);
        fprintf(ifs,"%d\n",J->budget);
        fprintf(ifs,"%d\n",J->nbtotalHabitantsVille);
        fprintf(ifs,"%d\n",J->nbMaison);
        fprintf(ifs,"%d\n",J->nbCentrales);
        fprintf(ifs,"%d\n",J->nbChateau_Eau);
        fprintf(ifs,"%d\n",J->capaciteTotaleCentralesElectriques);
        fprintf(ifs,"%d\n",J->capaciteTotaleChateauEau);

    }
    fprintf(ifs,"%d\n", Ville.hydro_connecte);
    fprintf(ifs,"%d\n", Ville.reseau_connecte);

    fprintf(ifs,"\n");

    for(int i=0; i<Ville.Route.ordre+1; i++)
    {
        for(int j=0; j<Ville.Route.ordre+1; j++) {

            if(Ville.Route.Adjacence[i][j] == 1 || Ville.Route.Adjacence[j][i] == 1)
            {
                fprintf(ifz, "%d %d = %d\n",i,j, Ville.Route.Adjacence[i][j]);
            }
        }
    }


    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            fprintf(ifs,"%d ",Ville.occupation[i][j]);
        }
        fprintf(ifs,"\n");
    }

    fprintf(ifs,"\n");

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            fprintf(ifs,"%d ",Ville.type[i][j]);
        }
        fprintf(ifs,"\n");
    }

    fprintf(ifs,"\n");

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].existe == 1)
            {
                fprintf(ifs,"%d %d %d %d %d %d %d %d %d",i,j,Ville.maisons[i][j].existe,Ville.maisons[i][j].niveau, Ville.maisons[i][j].relieElec, Ville.maisons[i][j].relieEau, Ville.maisons[i][j].relie, Ville.maisons[i][j].Jonction->x, Ville.maisons[i][j].Jonction->y);
                fprintf(ifs,"\n");
            }

        }

    }

    fprintf(ifs,"\n");

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.Courant[i][j].type == 3)
            {
                fprintf(ifs,"%d %d %d %d %d %d",i,j, Ville.Courant[i][j].type, Ville.Courant[i][j].liaison, Ville.Courant[i][j].occupation, Ville.Courant[i][j].capaciteMax);
                fprintf(ifs,"\n");
            }

        }

    }

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.Eau[i][j].type == 3)
            {
                fprintf(ifs,"%d %d %d %d %d %d",i,j, Ville.Eau[i][j].type, Ville.Eau[i][j].liaison, Ville.Eau[i][j].occupation, Ville.Eau[i][j].capaciteMax);
                fprintf(ifs,"\n");
            }

        }

    }

    fprintf(ifs,"\n");

    for(int i =0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.industrielle[i][j].existe == 1)
            {
                fprintf(ifs,"%d %d %d %d %d",i,j, Ville.industrielle[i][j].existe, Ville.industrielle[i][j].relie, Ville.industrielle[i][j].statut);
                fprintf(ifs,"\n");
            }

        }

    }

    fprintf(ifs,"\n");

    fprintf(ifs,"%d\n", P.route);
    fprintf(ifs,"%d\n", P.terrainvague);
    fprintf(ifs,"%d\n", P.centralesElectrique);
    fprintf(ifs,"%d\n", P.chateauEau);

    fprintf(ifs,"\n");

    fclose(ifs);

    allegro_message("Sauvegarde effectue");
}

