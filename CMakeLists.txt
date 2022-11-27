cmake_minimum_required(VERSION 3.23)
project(Tout C)

set(CMAKE_C_STANDARD 99)

add_executable(Tout main.c bibli.h fonctions.c Fonction_Menu_choix_Action.c Clock_fonction.c Menu.c Initialisation.c outils.c "Centrale eletrique.c" "Centrale Hydrolique.c" Sauvegarde.c Maison_evolution.c AffichageRoute_Industriel.c Affichage_legende.c Routes.c)

target_link_libraries(Tout -lmingw32 -lalleg44)
