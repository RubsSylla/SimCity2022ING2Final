//
// Created by solix on 07/11/2022.
//

#include "bibli.h"

void initialisation_StructJeu (t_jeu* jeu)
{
    jeu->budget = 250000;
    jeu->nbtotalHabitantsVille = 0;
    jeu->nbMaison = 0;
    jeu->nbChateau_Eau = 0;
    jeu->capaciteTotaleChateauEau = 0;
    jeu->nbCentrales = 0;
    jeu->capaciteTotaleCentralesElectriques = 0;
    jeu->nbRoutes = 0;
    jeu->nbCasernes = 0;
    jeu->mode = 0;
}

t_depenses initialisation_Depenses (t_depenses prix)
{
    prix.caserne = 10000;
    prix.centralesElectrique = 100000;
    prix.chateauEau = 100000;
    prix.route = 10;
    prix.terrainvague = 1000;

    return prix;
}

t_MatriceRoute Initialisation_Matrice_route(t_map Ville)
{
    t_MatriceRoute Reseau;

    Reseau.ordre = (LIGNE*COLONNE);

    Reseau.Adjacence = (int**)malloc((Reseau.ordre+1)*sizeof (int*));

    for(int i=0; i < Reseau.ordre+1; i++)
    {
        Reseau.Adjacence[i] = (int*)malloc((Reseau.ordre+1)*sizeof (int));
    }

    for(int i=0; i<Reseau.ordre+1; i++)
    {
        for(int j=0; j<Reseau.ordre+1; j++)
        {
            Reseau.Adjacence[i][j] = 0;
        }
    }

    Reseau.decouvert = (int*)malloc((Reseau.ordre+1)*sizeof (int));
    Reseau.existe = (int*)malloc((Reseau.ordre+1)*sizeof (int));
    Reseau.Prede = (int*)malloc((Reseau.ordre+1)*sizeof (int));

    for(int i=0; i<Reseau.ordre+1; i++)
    {
        Reseau.decouvert[i] = 0;
        Reseau.existe[i] = 0;
        Reseau.Prede[i] = -1;
    }

    return Reseau;

}

t_map Initialisation_Map(t_map Ville) /// Initialisation structure map
{
    Ville.reseau_connecte = 0;

    Ville.occupation = (int**)malloc(LIGNE*sizeof (int*));

    for(int i=0; i < LIGNE; i++)
    {
        Ville.occupation[i] = (int*)malloc(COLONNE*sizeof (int));
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.occupation[i][j] = 0;
        }
    }

    Ville.Eau = (t_canal **)malloc(LIGNE*sizeof (t_canal*));

    for(int i=0; i < LIGNE; i++)
    {
        Ville.Eau[i] = (t_canal*)malloc(COLONNE*sizeof (t_canal));
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.Eau[i][j].occupation = 0;
            Ville.Eau[i][j].type = 0;
        }
    }

    Ville.Courant = (t_Elec **)malloc(LIGNE*sizeof (t_Elec *));

    for(int i=0; i < LIGNE; i++)
    {
        Ville.Courant[i] = (t_Elec *)malloc(COLONNE*sizeof (t_Elec ));
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.Courant[i][j].occupation = 0;
            Ville.Courant[i][j].type = 0;
        }
    }

    Ville.type = (int**)malloc(LIGNE*sizeof (int*));

    for(int i=0; i < LIGNE; i++)
    {
        Ville.type[i] = (int*)malloc(COLONNE*sizeof (int));
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.type[i][j] = 0;
        }
    }

    Ville.maisons = (t_habitations **)malloc(LIGNE*sizeof (t_habitations*));

    for(int i=0; i < LIGNE; i++)
    {
        Ville.maisons[i] = (t_habitations*)malloc(COLONNE*sizeof (t_habitations));
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.maisons[i][j].existe = 0;
            Ville.maisons[i][j].compteur = 0;
            Ville.maisons[i][j].niveau = 4;
        }
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.maisons[i][j].Jonction = (coord*)malloc(12*sizeof (coord)); /// Ici 12 est le nombre de faces
            for(int k=0; k<12 ; k++)
            {
                Ville.maisons[i][j].Jonction[k].x = 0;
                Ville.maisons[i][j].Jonction[k].y = 0;
            }
        }
    }

    Ville.industrielle = (t_Utilitaire **)malloc(LIGNE*sizeof (t_Utilitaire*));

    for(int i=0; i < LIGNE; i++)
    {
        Ville.industrielle[i] = (t_Utilitaire*)malloc(COLONNE*sizeof (t_Utilitaire));
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.industrielle[i][j].statut = 0;
            Ville.industrielle[i][j].existe = 0;
            Ville.industrielle[i][j].capaciteTotale = 1000;
            Ville.industrielle[i][j].relie = 0;
            Ville.industrielle[i][j].compteur = 0;
        }
    }

    for(int i = 0; i < LIGNE; i++)
    {
        for(int j=0; j < COLONNE; j++)
        {
            Ville.industrielle[i][j].Jonction = (coord*)malloc(20*sizeof (coord)); /// Ici 20 est le nombre de faces
            for(int k=0; k<20 ; k++)
            {
                Ville.industrielle[i][j].Jonction[k].x = 0;
                Ville.industrielle[i][j].Jonction[k].y = 0;
            }
        }
    }



    return Ville;
}

void initialisation_allegro()
{
    printf("Initialisation d'allegro...\n");
    allegro_init(); /// Initialisation d'allegro
    allegro_message("\nInitialisation Ok\n");

    install_mouse();
    install_keyboard();
    install_timer();

    printf("Initialisation Couleur du fond...\n");
    set_color_depth(desktop_color_depth());
    allegro_message("\nInitalisation du fond Ok\n");

    printf("Initialisation Du mode graphique...\n");
    show_mouse(screen);

    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,670,0,0))!=0)
    {
        allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    allegro_message("\nInitalisation Du mode graphique Ok\n");
}
