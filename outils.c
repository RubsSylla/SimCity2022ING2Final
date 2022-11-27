//
// Created by solix on 07/11/2022.
//

#include "bibli.h"

int renvoi_XC(int XC, int mouseX)
{
    if(mouseX >= 1000)
    {
        XC = XC + 2;
        if(XC >= 896)
        {
            XC = 896;
        }
    }
    else if (mouseX <= 20)
    {
        XC = XC - 2;
        if(XC <= 0)
        {
            XC = 0;
        }
    }

    return XC;
} /// Fonction utile pour le scrolling : coord x de la souris

int renvoi_YC(int YC, int mouseY) ///renvoi de y pour le scrolling
{
    if (mouseY <= 20)
    {
        YC = YC - 2;
        if(YC <= 0)
        {
            YC = 0;
        }

    }
    else if (mouse_y >= 600)
    {
        YC = YC + 2;
        if(YC >= 930)
        {
            YC = 930;
        }
    }

    return YC;
} /// Fonction utile pour le scrolling : coord y de la souris

coord test(int coordX, int coordY) ///
{
    int ligne = 0;
    int colonne = 0;
    int i;
    int j;

    coord renvoi;

    for (i = 0; i < 1920; i = i + CARRE) {
        colonne++;
        if (coordX >= i && coordX <= i + CARRE) {
            break;
        }

    }
    for (j = 0; j < 1600; j = j + CARRE) {
        ligne++;
        if (coordY >= j && coordY <= j + CARRE) {
            break;
        }

    }

    if(ligne >= 79)
    {
        ligne = 78;
    }
    if(colonne >= 95)
    {
        colonne = 1;
    }

    //printf("%d / %d\n", colonne, ligne);

    renvoi.x = colonne * CARRE;
    renvoi.y = ligne * CARRE;

    return renvoi;

} /// Fonction de bordure pour le scrolling

void scroll(int playX, int playY, int *cameraX, int *cameraY)
{
    *cameraX = playX;
    *cameraY = playY;

    if(*cameraX < 0)
    {
        *cameraX = 0;
    }
    if(*cameraY < 0)
    {
        *cameraY = 0;
    }
} /// Fonction de scrolling

void enfilage(t_file*f, int numero) /// Fonction d'enfilage d'un entier dans la file
{
    t_maillon *element = (t_maillon*)malloc(sizeof(t_maillon)); /// Création d'un nouveau maillon

    if(f == NULL || element == NULL) /// Test si la file est nulle ou si l'élément ne pointe sur rien
    {
        exit(0);
    }

    element->numero = numero; /// Numero est mis dans le nouvel élément créé
    element->next = NULL;     /// Le nouveau maillon ne pointe sur rien

    if(f->debut != NULL)                    /// Si la file n'est pas vide alors
    {
        t_maillon *actuel = f->debut;       /// création d'un nouveau maillon
        while(actuel->next != NULL)         /// boucle de parcours de la file
        {
            actuel = actuel->next;          /// passage au maillon suivant
        }
        actuel->next = element;             /// Numero est mis dans le maillon
    }
    else                                    /// Si la file est vide
    {
        f->debut = element;
    }
}

int defiler(t_file*f) /// Fonction de défilage d'une file
{
    if(f == NULL)     /// test si la file est nulle
    {
        exit(0);
    }

    int nombreSortant = 0;

    if(f->debut != NULL) /// Si le début de la file existe
    {
        t_maillon* elementAdefiler = f->debut;   /// Création d'un nouveau maillon et récupere la valeur du début

        nombreSortant = elementAdefiler->numero; /// Récupération du nombre a defiler
        f->debut = elementAdefiler->next;        /// Le début de la file pointe maintenant sur l'élément suivant
        free(elementAdefiler);           /// Liberation de la memoire
    }

    return nombreSortant; /// renvoie du nombre
}

void afficherfile(t_file *file)
{
    printf("Affichage Etat file : "); // Affichage de la file
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //Si la file est vide

    t_maillon *actuel = file->debut;

    while (actuel != NULL)
    {
        printf("%d ", actuel->numero);
        actuel = actuel->next;
    }

    printf("\n");
} /// Fonction d'affichage d'une file