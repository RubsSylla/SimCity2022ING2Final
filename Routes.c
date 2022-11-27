#include "bibli.h"

t_map Acutalisation_Matrice_Route(t_map Ville)
{
    int produit;

    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            produit = j+((i-1)*94);

            if(Ville.type[i][j] == 1)
            {
                Ville.Route.existe[produit+1] = 1;
                Ville.Route.decouvert[produit+1] = 0;

                //printf("existence de route en %d %d\n", j,i);

                if(Ville.type[i-1][j] == 1)
                {
                    //printf("route adjacente en haut\n");
                    Ville.Route.Adjacence[produit][j+((i-2)*94)] = 1;
                    //printf("%d est adjacent a %d\n",produit,j+((i-2)*94));
                    Ville.Route.Adjacence[j+((i-2)*94)][produit] = 1;
                    //printf("%d est adjacent a %d\n",j+((i-2)*94),produit);


                }
                else if(Ville.type[i][j-1] == 1)
                {
                    //printf("route adjacente a gauche\n");
                    Ville.Route.Adjacence[produit+1][produit] = 1;
                    Ville.Route.Adjacence[produit][produit+1] = 1;

                }
                else if(Ville.type[i+1][j] == 1)
                {
                    //printf("route adjacente en bas\n");
                    Ville.Route.Adjacence[produit][j+(i*94)] = 1;
                    //printf("%d est adjacent a %d\n",produit,j+(i*94));
                    Ville.Route.Adjacence[j+(i*94)][produit] = 1;
                    //printf("%d est adjacent a %d\n",j+(i*94),produit);


                }
                else if(Ville.type[i][j+1] == 1)
                {
                    //printf("route adjacente a droite\n");
                    Ville.Route.Adjacence[produit+1][produit+2] = 1;
                    Ville.Route.Adjacence[produit+2][produit+1] = 1;

                }
            }


        }
    }
    return Ville;

} /// Actualisation de la matrice des routes sur la map