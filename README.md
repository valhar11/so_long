# so_long

## Description

`so_long` est un projet de l'école 42 visant à créer un petit jeu en 2D à l'aide de la bibliothèque graphique MiniLibX. Le joueur contrôle un personnage qui doit récupérer des objets et atteindre une sortie dans un labyrinthe tout en évitant les ennemis.

## Table des matières

- [Installation](#installation)
- [Utilisation](#utilisation)
- [Fonctionnalités](#fonctionnalités)
- [Aperçu](#aperçu)
- [Ressources](#ressources)
- [Auteurs](#auteurs)

## Installation

1. Clonez ce dépôt sur votre machine locale :

   ```bash
   git clone https://github.com/valhar11/so_long.git
   cd so_long

2. Compilez le projet avec make :
    
    ```bash
    make

3. Exécutez le jeu avec le fichier généré :

    ```bash
    ./so_long maps/map1.ber

## Utilisation

Le jeu se lance avec une carte spécifiée en argument. Par exemple :

    ```bash
    ./so_long maps/map1.ber


## Fonctionnalités

Chargement des cartes depuis des fichiers .ber
Déplacement du personnage principal
Collecte des objets
Gestion des ennemis
Sortie du labyrinthe une fois tous les objets collectés
Affichage du nombre de mouvements
