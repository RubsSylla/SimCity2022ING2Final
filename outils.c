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
}

int renvoi_YC(int YC, int mouseY)
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
}

coord test(int coordX, int coordY) {
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

}

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
}
