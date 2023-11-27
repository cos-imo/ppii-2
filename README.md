# Projet Pluridisciplinaire d'Informatique Intégrative - Semestre 2

![Static Badge](https://img.shields.io/badge/Télécom-Projet_scolaire-purple)
![Static Badge](https://img.shields.io/badge/Langage-C-blue)
![Static Badge](https://img.shields.io/badge/Langage-Makefile-green)
![Static Badge](https://img.shields.io/badge/Interface_web-PHP-purple)

**Note**: This readme is also available in [english](https://github.com/cos-imo/ppii-2/blob/main/README-EN.md) version

## Sommaire
1. Sommaire
2. Présentation
3. Installation
4. Organisation du dépôt et informations complémentaires

## Présentation
Projet développé dans le cadre de ma scolarité à [Télécom Nancy](https://telecomnancy.univ-lorraine.fr) (1ère année - 2ème semestre)
Extrait du sujet:

> [C]onstruire en langage "C" un programme qui permet de proposer [...] un parcours de charge de véhicule électrique
La présente application est constituée d'un executable C, mais une interface web (PHP) a également été codée afin de simplifier l'utilisation 

**Membres du groupe** :
- Kieran DALIGAUD
- Arthur GÔMES
- Thomas LERUEZ
- Cosimo UNGARO

## Installation

## Installation
##### Téléchargement
###### Par SSH
```
git clone git@github.com:cos-imo/ppii-2.git
```
###### Par HTTP
```
git clone https://github.com/cos-imo/ppii-2.git
```

##### Compilation
Depuis la racine du projet (dossier ppii-2), lancer make:
```
make
```


##### Lancement
Depuis la racine du projet (dossier ppii-2) exécuter le programme main_output se trouvant dans build:
```
./build/main_output [OPTIONS]
```

## Organisation du dépôt et informations complémentaires

Ce projet contient les fichiers du PPII second semestre.
- Le dossier src contient les fichiers .c,
- le dosser include contient les en-têtes .h,
- le dossier assets contient les fichiers CSV servant de données,
- le dossier Web contient l'interface utilisateur,
- le dossier tests contient les fichiers de tests.

