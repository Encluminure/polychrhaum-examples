# Exemples pour PolychrHAUM

## Dépôt

Ce dépôt contient quelques exemples d'utilisation de la bibliothèque Arduino pour l'appareil PolychrHAUM. Voir le dépôt "polychrhaum" correspondant.

## Compilation

Lorsque le dépôt est cloné, il faut penser à charger les submodules pour avoir les dépendances permettant de construire le programme pour Arduino.

```
git submodule init
git submodule update
```

Un Makefile existe pour chaque exemple et permet de le construire pour l'émulateur PC ou le programme Arduino.


Pour construire l'émulateur (bibliothèques pthread et SDL2 requises) :
```
make pc
```

Pour construire le programme Arduino et l'envoyer sur la cible :
```
make upload
```

## Licence

Le projet est fourni sous licence MIT.

C'est une licence libre qui vous permet par exemple :
 - de le copier,
 - de l'étudier,
 - de l'adapter à vos besoins,
 - de le redistribuer

Nous vous encourageons vivement à forker et partager !
