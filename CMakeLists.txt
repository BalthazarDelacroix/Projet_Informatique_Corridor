cmake_minimum_required(VERSION 3.26)
project(projet_info_je_vais_baiser_austin_ C)

set(CMAKE_C_STANDARD 23)

add_executable(projet_info_je_vais_baiser_austin_ main.c
        menu.c
        plateau.c
        "partie.h"
        "Logique IA.c"
        partie.c
        Fichier_texte.c
        menu.h
        plateau.h
        Fichier_texte.h
        "Logique IA.h"
        Tour.h
        Tour.c
        Joueur.h
)
