42sh
===================

Ce dépôt contient les sources du 42sh de mon groupe pour le module Système Unix de 1ere année à Epitech.
Il a été réalisé à Moulins en 2023.

----------

Fonctionnalités
-------------

> - Gestion de la ligne d'exécution avec un parsing qui gère notamment les "double-quotes"
> - Pipes et multi-pipes
> - Redirections (simples et doubles, gauches et droites)
> - Séparateurs && et ||
> - Commandes "buit-in" : cd, env, set, unset, exit, history
> - Prompt élaboré

Utilisation
-------------

> - Compilation : `make`
> - Lancement : `./42sh`
> - Commandes : `help`

Problèmes connus
-------------

> - Le built-in "echo" renvoie 1 au lieu de 0 et inversement
> - La gestion des && et || n'est pas tout à fait complète, certains cas complexes ne sont pas gérés correctement

Disclaimer
-------------

Si vous êtes étudiant à Epitech, servez vous des concepts utilisés, pas du code, ou la moulinette de triche vous trouvera et vous mettra un -42.
