//
// Created by solix on 03/11/2022.
//

#include "bibli.h"

int acheterBatiment (t_depenses prix, t_jeu *jeu, int choix){
    int condition = 0;
    /*printf("[ 1 ] Centrale\n");
    printf("[ 2 ] Chateau d eau\n");
    printf("[ 3 ] Route\n");
    printf("[ 4 ] Terrain vague\n");
    printf("[ 5 ] Caserne\n\n");*/

    /*do{
        //printf("Selectionner le batiment: ");
        scanf("%d",&choix);
    }while (choix > 5 || choix < 1);*/

    if ( choix == 6){
        if (jeu->budget > prix.terrainvague)
        {
            jeu->budget = jeu->budget - prix.terrainvague;
            prix.nbterrainvague++;
            jeu->nbMaison = jeu->nbMaison + 1;
            condition = 1;
            return condition;

            //printf("Le lieu apres quand on aura fini la map");
        }
        else{
            printf("Pas assez argent");
            condition = 0;
            return condition;
        }
    }
    else if ( choix == 5){
        if (jeu->budget > prix.centralesElectrique){
            jeu->budget = jeu->budget - prix.centralesElectrique;
            jeu->nbCentrales ++;
            jeu->capaciteTotaleCentralesElectriques = jeu->capaciteTotaleCentralesElectriques + 5000;
            condition = 1;
            return condition;
            //printf("Le lieu apres quand on aura fini la map");
        }
        else{
            printf("Pas assez argent");
            condition = 0;
            return condition;
        }
    }
    else if ( choix == 4){
        if (jeu->budget > prix.chateauEau){
            jeu->budget = jeu->budget - prix.chateauEau;
            jeu->nbChateau_Eau++; /// A VOIR POUR AJOUTEZ LES CAPACITES EN EAUX ET ELECTRIQUE LOCALES ET GLOBALES APRES
            jeu->capaciteTotaleChateauEau = jeu->capaciteTotaleChateauEau + 5000;
            condition = 1;
            return condition;
            //printf("Le lieu apres quand on aura fini la map");
        }
        else{
            printf("Pas assez argent");
            condition = 0;
            return condition;
        }
    }
    else if ( choix == 1){
        if (jeu->budget > prix.route){
            jeu->budget = jeu->budget - prix.route;
            jeu->nbRoutes++;
            condition = 1;
            return condition;
            //printf("Le lieu apres quand on aura fini la map");
        }
        else{
            printf("Pas assez argent");
            condition = 0;
            return condition;
        }
    }
    /*else if ( choix == 3){
        if (jeu->budget > prix.caserne){
            jeu->budget = jeu->budget - prix.caserne;
            jeu->nbCasernes++;
            condition = 1;
            return condition;
            //printf("Le lieu apres quand on aura fini la map");
        }
        else{
            printf("Pas assez argent");
            condition = 0;
            return condition;
        }
    }*/
}

int retourBarreOutil_Gauche(BITMAP* buffer, t_jeu* j, int retour, int* cote) /// fonction de selection de batiments
{

    ///Image Outil 144x324
    /// 324h et 144l
    /// avec outil x = 0 et outil y = 20
///RETOURNE 1 POUR ROUTE, 2 POUR RESEAU D'EAU, 3 POUR RESEAU ELECTRIQUE, 4 POUR CHATEAU D'EAU, 5 POUR CENTRALE, 6 POUR MAISON ET 7 POUR ANNULER
    *cote = 1;

    BITMAP* fleche_G; //Taille 265x357
    fleche_G = load_bitmap("fleche_G.bmp", NULL);
    int fleche_G_x = 0;
    int fleche_G_y = 300;
    int fleche_G_tx = 20;
    int fleche_G_ty = 30;
    char message_fleche_G[50] = { 'D', 'r', 'o', 'i', 't', 'e'};

    BITMAP* outil;
    outil = load_bitmap("barreOutil.bmp", NULL);

    int outil_x = 0;
    int outil_y = 20;
    int outil_tx = 144;
    int outil_ty = 324;

    BITMAP* annuler;
    annuler = load_bitmap("annuler.bmp", NULL);
    int annuler_x = 40;
    int annuler_y = 400;
    int annuler_tx = 50;
    int annuler_ty = 57;
    char message_annuler[50] = { 'A', 'n', 'n', 'u', 'l','e','r'};


    BITMAP* route;
    route = load_bitmap("boutonRoute.bmp", NULL);
    int route_x = 40;
    int route_y = 150;
    int route_tx = 48;
    int route_ty = 70;
    char message_epe[50] = { 'R', 'o', 'u', 't', 'e'};


    BITMAP* eau;
    eau = load_bitmap("eau.bmp", NULL);

    int eau_x = 98;
    int eau_y = 150;
    int eau_tx = 48;
    int eau_ty = 70;
    char message_eau[50] = {  'e', 'a','u'};

    BITMAP* electricite;
    electricite = load_bitmap("eclair.bmp", NULL);

    int electricite_x = 156;
    int electricite_y = 150;
    int electricite_tx = 48;
    int electricite_ty = 70;
    char message_electricite[50] = {'e', 'l', 'e', 'c', 't', 'r', 'i', 'c', 'i', 't', 'e'};

    BITMAP* chateauEau;
    chateauEau = load_bitmap("chateauEau.bmp", NULL);

    int chateauEau_x = 40;
    int chateauEau_y = 300;
    int chateauEau_tx = 48;
    int chateauEau_ty = 70;
    char message_chateauEau[50] = { 'C', 'h', 'a', 't', 'e', 'a', 'u', ' ', 'd', ' ', 'e', 'a','u'};

    BITMAP* centrale;
    centrale = load_bitmap("centrale.bmp", NULL);

    int centrale_x = 98;
    int centrale_y = 300;
    int centrale_tx = 48;
    int centrale_ty = 70;
    char message_centrale[50] = { 'C', 'e', 'n', 't', 'r', 'a', 'l', 'e', ' ', 'e', 'l', 'e', 'c', 't', 'r', 'i', 'q', 'u', 'e'};

    BITMAP* maison;
    maison = load_bitmap("maison.bmp", NULL);

    int maison_x = 156;
    int maison_y = 300;
    int maison_tx = 48;
    int maison_ty = 70;
    char message_maison[50] = { 'M', 'a', 'i', 's', 'o', 'n'};

    //int retour =0;
    //clear(buffer);

    masked_stretch_blit(outil, buffer, 0,0,outil_tx, outil_ty, outil_x,outil_y, 250,600);
    textprintf_ex(buffer, font, outil_x+20, outil_y+20, makecol(255,255,255), -1, "Barre d'outil");
    textprintf_ex(buffer, font, outil_x+50, outil_y+110, makecol(255,255,255), -1, "Afficher :");
    textprintf_ex(buffer, font, outil_x+50, outil_y+260, makecol(255,255,255), -1, "Construire :");
    textprintf_ex(buffer, font, outil_x+50, outil_y+470, makecol(255,255,255), -1, "Information :");
    textprintf_ex(buffer, font, outil_x+50, outil_y+490, makecol(255,255,255), -1, "Budjet : %d flouz", j->budget);
    textprintf_ex(buffer, font, outil_x+50, outil_y+510, makecol(255,255,255), -1, "Mode : %d", j->mode);

    // MARGEEEEEEEEEEEEEEEEEEEEEEEEEEEE

    BITMAP* capitaliste;
    BITMAP* communisme;

    capitaliste = load_bitmap("CAPITALISTE.bmp", NULL);
    communisme = load_bitmap("COMMU40X40.bmp",NULL);
    if (capitaliste == NULL || communisme == NULL) {
        printf("ERREUR OUVERTURE COMMU OU CAPI");
    }

    if (j->mode== 1){

        draw_sprite(buffer, capitaliste, outil_x + 50, outil_y + 530);

    }

    else if (j->mode == 2){
        draw_sprite(buffer, communisme, outil_x + 50, outil_y + 530);

    }

    //textprintf_ex(buffer, font, 410, 535, makecol(255,255,255), makecol(0,0,0), "%d/%d", pv, maxPv);

    if(mouse_x>=route_x && mouse_x<=route_x + route_tx && mouse_y>=route_y && mouse_y<=route_y + route_ty)
    {
        route_tx += 10;
        route_ty += 10;
        textprintf_ex(buffer, font, route_x, route_y+route_ty, makecol(255,255,255), -1, message_epe);



        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            route_tx = 48;
            route_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=1;
        }
    }
    else {

        route_tx = 48;
        route_ty = 70;



    }
    masked_stretch_blit(route, buffer, 0, 0, 245,360, route_x, route_y, route_tx, route_ty);

    if(mouse_x>=eau_x && mouse_x<=eau_x + eau_tx && mouse_y>=eau_y && mouse_y<=eau_y + eau_ty)
    {
        eau_tx += 10;
        eau_ty += 10;
        textprintf_ex(buffer, font, eau_x, eau_y+eau_ty, makecol(255,255,255), -1, message_eau);


        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            eau_tx = 48;
            eau_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=2;
        }
    }
    else {

        eau_tx = 48;
        eau_ty = 70;



    }
    masked_stretch_blit(eau, buffer, 0, 0, 245,360, eau_x, eau_y, eau_tx, eau_ty);

    if(mouse_x>=electricite_x && mouse_x<=electricite_x + electricite_tx && mouse_y>=electricite_y && mouse_y<=electricite_y + electricite_ty)
    {
        electricite_tx += 10;
        electricite_ty += 10;
        textprintf_ex(buffer, font, electricite_x, electricite_y+electricite_ty, makecol(255,255,255), -1, message_electricite);


        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            electricite_tx = 48;
            electricite_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=3;
        }
    }
    else {

        electricite_tx = 48;
        electricite_ty = 70;



    }
    masked_stretch_blit(electricite, buffer, 0, 0, 245,360, electricite_x, electricite_y, electricite_tx, electricite_ty);

    if(mouse_x>=chateauEau_x && mouse_x<=chateauEau_x + route_tx && mouse_y>=chateauEau_y && mouse_y<=chateauEau_y + chateauEau_ty)
    {
        chateauEau_tx += 10;
        chateauEau_ty += 10;
        textprintf_ex(buffer, font, chateauEau_x, chateauEau_y+chateauEau_ty, makecol(255,255,255), -1, message_chateauEau);
        textprintf_ex(buffer, font, outil_x+50, outil_y+500, makecol(255,255,255), -1, "Prix : 100 000 flouz");


        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            chateauEau_tx = 48;
            chateauEau_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=4;
        }
    }
    else {

        chateauEau_tx = 48;
        chateauEau_ty = 70;



    }
    masked_stretch_blit(chateauEau, buffer, 0, 0, 245,360, chateauEau_x, chateauEau_y, chateauEau_tx, chateauEau_ty);

    if(mouse_x>=centrale_x && mouse_x<=centrale_x + centrale_tx && mouse_y>=centrale_y && mouse_y<=centrale_y + centrale_ty)
    {
        centrale_tx += 10;
        centrale_ty += 10;
        textprintf_ex(buffer, font, centrale_x, centrale_y+centrale_ty, makecol(255,255,255), -1, message_centrale);
        textprintf_ex(buffer, font, outil_x+50, outil_y+500, makecol(255,255,255), -1, "Prix : 100 000 flouz");

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            centrale_tx = 48;
            centrale_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=5;
        }
    }
    else {

        centrale_tx = 48;
        centrale_ty = 70;



    }
    masked_stretch_blit(centrale, buffer, 0, 0, 245,360, centrale_x, centrale_y, centrale_tx, centrale_ty);

    if(mouse_x>=maison_x && mouse_x<=maison_x + maison_tx && mouse_y>=maison_y && mouse_y<=maison_y + maison_ty)
    {
        maison_tx += 10;
        maison_ty += 10;
        textprintf_ex(buffer, font, maison_x, maison_y+maison_ty, makecol(255,255,255), -1, message_maison);
        textprintf_ex(buffer, font, outil_x+50, outil_y+500, makecol(255,255,255), -1, "Prix : 1 000 flouz");

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            maison_tx = 48;
            maison_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=6;
        }
    }
    else {

        maison_tx = 48;
        maison_ty = 70;



    }
    masked_stretch_blit(maison, buffer, 0, 0, 245,360, maison_x, maison_y, maison_tx, maison_ty);

    if(mouse_x>=annuler_x && mouse_x<=annuler_x + annuler_tx && mouse_y>=annuler_y && mouse_y<=annuler_y + annuler_ty)
    {
        annuler_tx += 10;
        annuler_ty += 10;
        textprintf_ex(buffer, font, annuler_x, annuler_y+annuler_ty, makecol(255,255,255), -1, message_annuler);

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            annuler_tx = 50;
            annuler_ty = 57;

            // On renvoie un 1 si le bouton est enfoncé
            retour=7;
        }
    }
    else {

        annuler_tx = 50;
        annuler_ty = 57;



    }
    masked_stretch_blit(annuler, buffer, 0, 0, 354,404, annuler_x, annuler_y, annuler_tx, annuler_ty);

    if(mouse_x>=fleche_G_x && mouse_x<=fleche_G_x + fleche_G_tx && mouse_y>=fleche_G_y && mouse_y<=fleche_G_y + fleche_G_ty)
    {
        fleche_G_tx += 5;
        fleche_G_ty += 5;
        textprintf_ex(buffer, font, fleche_G_x, fleche_G_y+fleche_G_ty, makecol(255,255,255), -1, message_fleche_G);

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            fleche_G_tx = 20;
            fleche_G_ty = 30;

            *cote = 2;   //on vas a droite

            //clear(buffer);

        }
    }
    else {

        fleche_G_tx = 20;
        fleche_G_ty = 30;

    }
    masked_stretch_blit(fleche_G, buffer, 0, 0, 265,357, fleche_G_x, fleche_G_y, fleche_G_tx, fleche_G_ty);


    return retour;
}

int retourBarreOutil_Droite(BITMAP* buffer, t_jeu* j, int retour, int* cote){

    ///Image Outil 144x324 -> 250x600
    /// 324h et 144l
    /// avec outil x = 0 et outil y = 20
///RETOURNE 1 POUR ROUTE, 2 POUR RESEAU D'EAU, 3 POUR RESEAU ELECTRIQUE, 4 POUR CHATEAU D'EAU, 5 POUR CENTRALE, 6 POUR MAISON ET 7 POUR ANNULER
    *cote = 2;

    BITMAP* outil;
    outil = load_bitmap("barreOutil.bmp", NULL);

    int outil_x = 774;
    int outil_y = 20;
    int outil_tx = 144;
    int outil_ty = 324;

    BITMAP* fleche_D;
    fleche_D = load_bitmap("fleche_D.bmp", NULL);
    int fleche_D_x = 1004;
    int fleche_D_y = 300;
    int fleche_D_tx = 20;
    int fleche_D_ty = 30;
    char message_fleche_D[50] = { 'G', 'a', 'u', 'c', 'h', 'e'};

    BITMAP* annuler;
    annuler = load_bitmap("annuler.bmp", NULL);
    int annuler_x = outil_x + 40;
    int annuler_y = 400;
    int annuler_tx = 50;
    int annuler_ty = 57;
    char message_annuler[50] = { 'A', 'n', 'n', 'u', 'l','e','r'};


    BITMAP* route;
    route = load_bitmap("boutonRoute.bmp", NULL);
    int route_x = outil_x +40;
    int route_y = 150;
    int route_tx = 48;
    int route_ty = 70;
    char message_epe[50] = { 'R', 'o', 'u', 't', 'e'};


    BITMAP* eau;
    eau = load_bitmap("eau.bmp", NULL);

    int eau_x = outil_x +98;
    int eau_y = 150;
    int eau_tx = 48;
    int eau_ty = 70;
    char message_eau[50] = {  'e', 'a','u'};

    BITMAP* electricite;
    electricite = load_bitmap("eclair.bmp", NULL);

    int electricite_x =outil_x + 156;
    int electricite_y = 150;
    int electricite_tx = 48;
    int electricite_ty = 70;
    char message_electricite[50] = {'e', 'l', 'e', 'c', 't', 'r', 'i', 'c', 'i', 't', 'e'};

    BITMAP* chateauEau;
    chateauEau = load_bitmap("chateauEau.bmp", NULL);

    int chateauEau_x = outil_x + 40;
    int chateauEau_y = 300;
    int chateauEau_tx = 48;
    int chateauEau_ty = 70;
    char message_chateauEau[50] = { 'C', 'h', 'a', 't', 'e', 'a', 'u', ' ', 'd', ' ', 'e', 'a','u'};

    BITMAP* centrale;
    centrale = load_bitmap("centrale.bmp", NULL);

    int centrale_x =outil_x + 98;
    int centrale_y = 300;
    int centrale_tx = 48;
    int centrale_ty = 70;
    char message_centrale[50] = { 'C', 'e', 'n', 't', 'r', 'a', 'l', 'e', ' ', 'e', 'l', 'e', 'c', 't', 'r', 'i', 'q', 'u', 'e'};

    BITMAP* maison;
    maison = load_bitmap("maison.bmp", NULL);

    int maison_x =outil_x + 156;
    int maison_y = 300;
    int maison_tx = 48;
    int maison_ty = 70;
    char message_maison[50] = { 'M', 'a', 'i', 's', 'o', 'n'};

    //int retour =0;
    //clear(buffer);

    masked_stretch_blit(outil, buffer, 0,0,outil_tx, outil_ty, outil_x,outil_y, 250,600);
    textprintf_ex(buffer, font, outil_x+20, outil_y+20, makecol(255,255,255), -1, "Barre d'outil");
    textprintf_ex(buffer, font, outil_x+50, outil_y+110, makecol(255,255,255), -1, "Afficher :");
    textprintf_ex(buffer, font, outil_x+50, outil_y+260, makecol(255,255,255), -1, "Construire :");
    textprintf_ex(buffer, font, outil_x+50, outil_y+470, makecol(255,255,255), -1, "Information :");
    textprintf_ex(buffer, font, outil_x+50, outil_y+490, makecol(255,255,255), -1, "Budjet : %d flouz", j->budget);

    //textprintf_ex(buffer, font, 410, 535, makecol(255,255,255), makecol(0,0,0), "%d/%d", pv, maxPv);

    BITMAP* capitaliste;
    BITMAP* communisme;

    capitaliste = load_bitmap("CAPITALISTE.bmp", NULL);
    communisme = load_bitmap("COMMU40X40.bmp",NULL);
    if (capitaliste == NULL || communisme == NULL) {
        printf("ERREUR OUVERTURE COMMU OU CAPI");
    }

    if (j->mode== 1){
        draw_sprite(buffer, capitaliste, outil_x + 50, outil_y + 500);
    }

    else if (j->mode == 2){
        draw_sprite(buffer, communisme, outil_x + 50, outil_y + 510);
    }

    if(mouse_x>=route_x && mouse_x<=route_x + route_tx && mouse_y>=route_y && mouse_y<=route_y + route_ty)
    {
        route_tx += 10;
        route_ty += 10;
        textprintf_ex(buffer, font, route_x, route_y+route_ty, makecol(255,255,255), -1, message_epe);



        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            route_tx = 48;
            route_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=1;
        }
    }
    else {

        route_tx = 48;
        route_ty = 70;



    }
    masked_stretch_blit(route, buffer, 0, 0, 245,360, route_x, route_y, route_tx, route_ty);

    if(mouse_x>=eau_x && mouse_x<=eau_x + eau_tx && mouse_y>=eau_y && mouse_y<=eau_y + eau_ty)
    {
        eau_tx += 10;
        eau_ty += 10;
        textprintf_ex(buffer, font, eau_x, eau_y+eau_ty, makecol(255,255,255), -1, message_eau);


        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            eau_tx = 48;
            eau_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=2;
        }
    }
    else {

        eau_tx = 48;
        eau_ty = 70;



    }
    masked_stretch_blit(eau, buffer, 0, 0, 245,360, eau_x, eau_y, eau_tx, eau_ty);

    if(mouse_x>=electricite_x && mouse_x<=electricite_x + electricite_tx && mouse_y>=electricite_y && mouse_y<=electricite_y + electricite_ty)
    {
        electricite_tx += 10;
        electricite_ty += 10;
        textprintf_ex(buffer, font, electricite_x, electricite_y+electricite_ty, makecol(255,255,255), -1, message_electricite);


        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            electricite_tx = 48;
            electricite_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=3;
        }
    }
    else {

        electricite_tx = 48;
        electricite_ty = 70;



    }
    masked_stretch_blit(electricite, buffer, 0, 0, 245,360, electricite_x, electricite_y, electricite_tx, electricite_ty);

    if(mouse_x>=chateauEau_x && mouse_x<=chateauEau_x + route_tx && mouse_y>=chateauEau_y && mouse_y<=chateauEau_y + chateauEau_ty)
    {
        chateauEau_tx += 10;
        chateauEau_ty += 10;
        textprintf_ex(buffer, font, chateauEau_x, chateauEau_y+chateauEau_ty, makecol(255,255,255), -1, message_chateauEau);
        textprintf_ex(buffer, font, outil_x+50, outil_y+500, makecol(255,255,255), -1, "Prix : 100 000 flouz");


        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            chateauEau_tx = 48;
            chateauEau_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=4;
        }
    }
    else {

        chateauEau_tx = 48;
        chateauEau_ty = 70;



    }
    masked_stretch_blit(chateauEau, buffer, 0, 0, 245,360, chateauEau_x, chateauEau_y, chateauEau_tx, chateauEau_ty);

    if(mouse_x>=centrale_x && mouse_x<=centrale_x + centrale_tx && mouse_y>=centrale_y && mouse_y<=centrale_y + centrale_ty)
    {
        centrale_tx += 10;
        centrale_ty += 10;
        textprintf_ex(buffer, font, centrale_x, centrale_y+centrale_ty, makecol(255,255,255), -1, message_centrale);
        textprintf_ex(buffer, font, outil_x+50, outil_y+500, makecol(255,255,255), -1, "Prix : 100 000 flouz");

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            centrale_tx = 48;
            centrale_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=5;
        }
    }
    else {

        centrale_tx = 48;
        centrale_ty = 70;



    }
    masked_stretch_blit(centrale, buffer, 0, 0, 245,360, centrale_x, centrale_y, centrale_tx, centrale_ty);

    if(mouse_x>=maison_x && mouse_x<=maison_x + maison_tx && mouse_y>=maison_y && mouse_y<=maison_y + maison_ty)
    {
        maison_tx += 10;
        maison_ty += 10;
        textprintf_ex(buffer, font, maison_x, maison_y+maison_ty, makecol(255,255,255), -1, message_maison);
        textprintf_ex(buffer, font, outil_x+50, outil_y+500, makecol(255,255,255), -1, "Prix : 1 000 flouz");

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            maison_tx = 48;
            maison_ty = 70;

            // On renvoie un 1 si le bouton est enfoncé
            retour=6;
        }
    }
    else {

        maison_tx = 48;
        maison_ty = 70;



    }
    masked_stretch_blit(maison, buffer, 0, 0, 245,360, maison_x, maison_y, maison_tx, maison_ty);

    if(mouse_x>=annuler_x && mouse_x<=annuler_x + annuler_tx && mouse_y>=annuler_y && mouse_y<=annuler_y + annuler_ty)
    {
        annuler_tx += 10;
        annuler_ty += 10;
        textprintf_ex(buffer, font, annuler_x, annuler_y+annuler_ty, makecol(255,255,255), -1, message_annuler);

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            annuler_tx = 50;
            annuler_ty = 57;

            // On renvoie un 1 si le bouton est enfoncé
            retour=7;
        }
    }
    else {

        annuler_tx = 50;
        annuler_ty = 57;



    }
    masked_stretch_blit(annuler, buffer, 0, 0, 354,404, annuler_x, annuler_y, annuler_tx, annuler_ty);

    if(mouse_x>=fleche_D_x && mouse_x<=fleche_D_x + fleche_D_tx && mouse_y>=fleche_D_y && mouse_y<=fleche_D_y + fleche_D_ty)
    {
        fleche_D_tx += 5;
        fleche_D_ty += 5;
        textprintf_ex(buffer, font, fleche_D_x, fleche_D_y+fleche_D_ty, makecol(255,255,255), -1, message_fleche_D);

        // Si l'utilisateur clique sur le bouton
        if(mouse_b & 1)
        {
            fleche_D_tx = 20;
            fleche_D_ty = 30;

            *cote = 1;  // on vas a gauche

            //clear(buffer);

        }
    }
    else {

        fleche_D_tx = 20;
        fleche_D_ty = 30;

    }
    masked_stretch_blit(fleche_D, buffer, 0, 0, 265,357, fleche_D_x, fleche_D_y, fleche_D_tx, fleche_D_ty);

    return retour;
}