#include "bibli.h"

t_map Incrementation_compt_maison(t_map Ville) // Incrementation du compteur maison
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++) // Boucle for pour rentrer dans la matrice
        {
            if(Ville.maisons[i][j].existe == 1) // Si la maison existe
            {
                Ville.maisons[i][j].compteur++; // Alors On incremente le compteur
                //printf("Augmentation compteur maison en %d %d -> %d\n",i,j,Ville.maisons[i][j].compteur);
            }
        }
    }

    return Ville;
}

t_map Actualisation_Niveau_Maison_capitaliste(t_map Ville, t_jeu *J) // Mode capitaliste
{
    for(int i=0; i<LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            if(Ville.maisons[i][j].compteur % 15 == 0 && Ville.maisons[i][j].compteur != 0) // Verification du temps et de l'existence de la maison
            {
                if(Ville.maisons[i][j].niveau < 5) // Verification du niveau de la maison ( Incrementation si elle n'est pas au niveau maximum)
                {
                    Ville.maisons[i][j].niveau++;

                    if(Ville.maisons[i][j].niveau == 2) // Mise ajour des informations du batiment par niveau ( Nombre habitants, Electricité et eau)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 10;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+10;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 10;
                    }
                    if(Ville.maisons[i][j].niveau == 3) // Mise ajour des informations du batiment par niveau ( Nombre habitants, Electricité et eau)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 40;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+40;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 40;
                    }
                    if(Ville.maisons[i][j].niveau == 4) // Mise ajour des informations du batiment par niveau ( Nombre habitants, Electricité et eau)
                    {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 50;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite+50;
                        Ville.maisons[i][j].eau =  Ville.maisons[i][j].eau + 50;
                    }
                    if(Ville.maisons[i][j].niveau == 5) // Mise ajour des informations du batiment par niveau ( Nombre habitants, Electricité et eau)
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

t_map Actualisation_Niveau_Maison_communiste(t_map Ville, t_jeu *J) // Niveau communiste
{
    for (int i = 0; i < LIGNE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            if (Ville.maisons[i][j].compteur % 15 == 0 &&
                Ville.maisons[i][j].compteur != 0)  // Verification du temps ( 15 secondes)
            {

                if (Ville.maisons[i][j].niveau < 5 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille &&
                    J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille) {
                    // Verification de la capacité des chateau d'eau et electricté: Est elle superieure en quantité par rapport aux nombre d'habitants dans le batiment?
                    Ville.maisons[i][j].niveau++;

                    if (Ville.maisons[i][j].niveau == 2 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille &&
                        J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille) {
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 10;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite + 10;
                        Ville.maisons[i][j].eau = Ville.maisons[i][j].eau + 10;
                    }
                    if (Ville.maisons[i][j].niveau == 3 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille &&
                        J->capaciteTotaleCentralesElectriques >
                        J->nbtotalHabitantsVille) { // Verification de la capacité des chateau d'eau et electricté: Est elle superieure en quantité par rapport aux nombre d'habitants dans le batiment?
                        // Augmentation du nombre d'habitants, d'au et d'electricté
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 40;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite + 40;
                        Ville.maisons[i][j].eau = Ville.maisons[i][j].eau + 40;
                    }
                    if (Ville.maisons[i][j].niveau == 4 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille &&
                        J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille) {
                        // Verification de la capacité des chateau d'eau et electricté: Est elle superieure en quantité par rapport aux nombre d'habitants dans le batiment?
                        // Augmentation du nombre d'habitants, d'au et d'electricté
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 50;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite + 50;
                        Ville.maisons[i][j].eau = Ville.maisons[i][j].eau + 50;
                    }
                    if (Ville.maisons[i][j].niveau == 5 && J->capaciteTotaleChateauEau > J->nbtotalHabitantsVille &&
                        J->capaciteTotaleCentralesElectriques > J->nbtotalHabitantsVille) {
                        // Verification de la capacité des chateau d'eau et electricté: Est elle superieure en quantité par rapport aux nombre d'habitants dans le batiment?
                        // Augmentation du nombre d'habitants, d'au et d'electricté
                        J->nbtotalHabitantsVille = J->nbtotalHabitantsVille + 900;
                        Ville.maisons[i][j].electricite = Ville.maisons[i][j].electricite + 900;
                        Ville.maisons[i][j].eau = Ville.maisons[i][j].eau + 900;
                    }
                } else if (Ville.maisons[i][j].niveau >= 2 && J->capaciteTotaleChateauEau < J->nbtotalHabitantsVille &&
                           J->capaciteTotaleCentralesElectriques < J->nbtotalHabitantsVille) {
                    Ville.maisons[i][j].niveau--;
                }
                else
                {
                }
            }

        }
    }

    return Ville;
}

void Affichage_Niveau_Maison(BITMAP* buffer,t_map Ville, int screenx, int screeny) // BITMAPS DES MAISONS
{

    BITMAP* Maison1;
    Maison1 = load_bitmap("MAISON0.bmp", NULL); // Chargement des bitmaps des maisons

    if(!Maison1) // Test sur la validité de l'ouverture du bitmap (erreur d'allocation ?)
    {
        allegro_message("pas pu trouver/charger la maison 1");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison2;
    Maison2 = load_bitmap("MAISON1.bmp", NULL);
    // Chargement des bitmaps des maisons
    // Test sur la validité de l'ouverture du bitmap (erreur d'allocation ?)

    if(!Maison2)
    {
        allegro_message("pas pu trouver/charger la maison 2");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison3;
    Maison3 = load_bitmap("MAISON2.bmp", NULL);
    // Chargement des bitmaps des maisons
    // Test sur la validité de l'ouverture du bitmap (erreur d'allocation ?)

    if(!Maison3)
    {
        allegro_message("pas pu trouver/charger la maison 3");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison4;
    Maison4 = load_bitmap("MAISON3.bmp", NULL);
    // Chargement des bitmaps des maisons
    // Test sur la validité de l'ouverture du bitmap (erreur d'allocation ?)

    if(!Maison4)
    {
        allegro_message("pas pu trouver/charger la maison 4");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    BITMAP* Maison5;
    Maison5 = load_bitmap("MAISON4.bmp", NULL);
// Chargement des bitmaps des maisons
    // Test sur la validité de l'ouverture du bitmap (erreur d'allocation ?)

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
            if(Ville.maisons[i][j].existe==1) // Si la maison existe
            {
                //textprintf_centre_ex(buffer,font,j*20 + 1 - screenx + 10, i*20 + 1 - screeny + 10,makecol(255,255,255),-1,"%d",Ville.maisons[i][j].niveau);
                if(Ville.maisons[i][j].niveau == 1) // Affichage du BITMAP de la maison au niveau 1
                {
                    draw_sprite(buffer, Maison1, (j-1)*20 - screenx, (i-1)*20 - 11 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 2)
                    // Affichage du BITMAP de la maison au niveau 2
                {
                    draw_sprite(buffer, Maison2, (j-1)*20 - screenx, (i-1)*20 - 22 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 3)
                    // Affichage du BITMAP de la maison au niveau 3
                {
                    draw_sprite(buffer, Maison3, (j-1)*20 - screenx, (i-1)*20 -11 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 4)
                    // Affichage du BITMAP de la maison au niveau 4
                {
                    draw_sprite(buffer, Maison4, (j-1)*20 - screenx, (i-1)*20 -11 - screeny);
                }
                if(Ville.maisons[i][j].niveau == 5)
                {
                    // Affichage du BITMAP de la maison au niveau 5
                    draw_sprite(buffer, Maison5, (j-1)*20 - screenx, (i-1)*20 -47 - screeny);
                }
            }

        }
    }
}

void impots(t_jeu* J, t_map Ville, int compteur) ///Fonction impots
{
    if(compteur % 15 == 0)   //toutes les 15 secondes
    {
        if(Ville.reseau_connecte == 1) //si maison connéctée
        {
            J->budget = J->budget + J->nbtotalHabitantsVille*10; //On incrémente le budjet de la ville
        }

    }
}

t_map Recherche_Jonction_Maison(t_map Ville) /// Recherche De la jonction de la maison
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