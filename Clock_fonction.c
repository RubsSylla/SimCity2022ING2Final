//
// Created by solix on 03/11/2022.
//

#include "bibli.h"

int myClock(int diffAfterReset) // Le moment du dernier reset)
{
    return clock() - diffAfterReset; // Retourne le temps depuis le dernier reset
}

int ResetClock(int diffAfterReset) // Le moment du dernier reset)
{
    diffAfterReset = clock(); // Met le compteur au véritable temps
    return diffAfterReset;
}

int Signal(int t1, int *memoire)
{
    int valeur;
    int oui;
    int renvoie;

    oui = t1;

    if(*memoire != oui)
    {
        *memoire = oui;
        renvoie = 1;
        return renvoie;
    }
    else
    {
        renvoie = 0;
        return renvoie;
    }
}