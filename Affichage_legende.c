#include "bibli.h"

void affichage_legende_eau(BITMAP* buffer)
{


    BITMAP* cadre;

    cadre = load_bitmap("cadre.bmp", NULL);

    int x_cadre = 20;
    int y_cadre = 370;
    int tx_cadre = 360;
    int ty_cadre = 280;

    rectfill(buffer,20+20,370+20,380-20,650-20,makecol(0,0,0));
    masked_stretch_blit(cadre, buffer, 0, 0, 1194,739, x_cadre, y_cadre, tx_cadre, ty_cadre);

    int x_maison_seule = 50;
    int y_maison_seule = 420;
    char message_maison_seule[50] = { 'M', 'a', 'i', 's', 'o', 'n', ' ', 'I', 's', 'o', 'l', 'e','e'};
    int col_maison_seule = makecol(255,0,0);

    int x_maison = 50;
    int y_maison = 450;
    char message_maison[50] = { 'M', 'a', 'i', 's', 'o', 'n', ' ', 'C', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'e'};
    int col_maison_connecte = makecol(0,255,0);

    int x_chateau = 50;
    int y_chateau = 480;
    char message_chateau[50] = { 'C', 'h', 'a', 't', 'e', 'a', 'u', ' ', 'd', ' ', 'e', 'a', 'u'};
    int col_chateau = makecol(255,255,0);

    int x_liaison = 50;
    int y_liaison = 510;
    char message_liaison[50] = { 'L', 'i', 'a', 'i', 's', 'o', 'n'};
    int col_liaison = makecol(255,255,255);

    int x_eau_vide = 215;
    int y_eau_vide = 420;
    char message_eau_vide[50] = { 't', 'u', 'y', 'a', 'u', ' ', 'v', 'i', 'd', 'e'};
    int col_eau_vide = makecol(255,255,255);

    int x_eau_plein = 215;
    int y_eau_plein = 450;
    char message_eau_plein[50] = { 't', 'u', 'y', 'a', 'u', ' ', 'p', 'l', 'e', 'i','n'};
    int col_eau_plein = makecol(85,162,215);

    rectfill(buffer,x_maison,y_maison,x_maison+20,y_maison+20,col_maison_connecte);
    textprintf_ex(buffer, font, x_maison+30, y_maison+7, makecol(255,255,255), -1, message_maison);

    rectfill(buffer,x_maison_seule,y_maison_seule,x_maison_seule+20,y_maison_seule+20,col_maison_seule);
    textprintf_ex(buffer, font, x_maison_seule+30, y_maison_seule+7, makecol(255,255,255), -1, message_maison_seule);

    rectfill(buffer,x_chateau,y_chateau,x_chateau+20,y_chateau+20,col_chateau);
    textprintf_ex(buffer, font, x_chateau+30, y_chateau+7, makecol(255,255,255), -1, message_chateau);

    rectfill(buffer,x_liaison,y_liaison,x_liaison+20,y_liaison+20,col_liaison);
    textprintf_ex(buffer, font, x_liaison+30, y_liaison+7, makecol(255,255,255), -1, message_liaison);

    rectfill(buffer,x_eau_vide,y_eau_vide,x_eau_vide+20,y_eau_vide+20,col_eau_vide);
    textprintf_ex(buffer, font, x_eau_vide+30, y_eau_vide+7, makecol(255,255,255), -1, message_eau_vide);

    rectfill(buffer,x_eau_plein,y_eau_plein,x_eau_plein+20,y_eau_plein+20,col_eau_plein);
    textprintf_ex(buffer, font, x_eau_plein+30, y_eau_plein+7, makecol(255,255,255), -1, message_eau_plein);

}

void affichage_legende_elec(BITMAP* buffer)
{


    BITMAP* cadre;

    cadre = load_bitmap("cadre.bmp", NULL);

    int x_cadre = 20;
    int y_cadre = 370;
    int tx_cadre = 360;
    int ty_cadre = 280;

    rectfill(buffer,20+20,370+20,380-20,650-20,makecol(0,0,0));
    masked_stretch_blit(cadre, buffer, 0, 0, 1194,739, x_cadre, y_cadre, tx_cadre, ty_cadre);

    int x_maison_seule = 50;
    int y_maison_seule = 420;
    char message_maison_seule[50] = { 'M', 'a', 'i', 's', 'o', 'n', ' ', 'I', 's', 'o', 'l', 'e', 'e'};
    int col_maison_seule = makecol(255,0,0);

    int x_maison = 50;
    int y_maison = 450;
    char message_maison[50] = { 'M', 'a', 'i', 's', 'o', 'n', ' ', 'C', 'o', 'n', 'n', 'e', 'c', 't', 'e', 'e'};
    int col_maison_connecte = makecol(0,255,0);

    int x_centrale = 50;
    int y_centrale = 480;
    char message_centrale[50] = { 'C', 'e', 'n', 't', 'r', 'a', 'l', 'e', ' ', 'e', 'l', 'e', 'c', 't', 'r', 'i', 'q', 'u', 'e',};
    int col_centrale = makecol(255,255,0);

    int x_liaison = 50;
    int y_liaison = 510;
    char message_liaison[50] = { 'L', 'i', 'a', 'i', 's', 'o', 'n'};
    int col_liaison = makecol(230,230,230);

    int x_fil = 215;
    int y_fil = 420;
    char message_fil[50] = { 'f', 'i', 'l'};
    int col_fil = makecol(255,140,0);

    rectfill(buffer,x_maison,y_maison,x_maison+20,y_maison+20,col_maison_connecte);
    textprintf_ex(buffer, font, x_maison+30, y_maison+7, makecol(255,255,255), -1, message_maison);

    rectfill(buffer,x_maison_seule,y_maison_seule,x_maison_seule+20,y_maison_seule+20,col_maison_seule);
    textprintf_ex(buffer, font, x_maison_seule+30, y_maison_seule+7, makecol(255,255,255), -1, message_maison_seule);

    rectfill(buffer,x_centrale,y_centrale,x_centrale+20,y_centrale+20,col_centrale);
    textprintf_ex(buffer, font, x_centrale+30, y_centrale+7, makecol(255,255,255), -1, message_centrale);

    rectfill(buffer,x_liaison,y_liaison,x_liaison+20,y_liaison+20,col_liaison);
    textprintf_ex(buffer, font, x_liaison+30, y_liaison+7, makecol(255,255,255), -1, message_liaison);

    rectfill(buffer,x_fil,y_fil,x_fil+20,y_fil+20,col_fil);
    textprintf_ex(buffer, font, x_fil+30, y_fil+7, makecol(255,255,255), -1, message_fil);
}