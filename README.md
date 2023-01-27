# Jeu des allumettes
## Jeu des allumettes sur QT Creator 5.0.2 avec Interface Graphique 

Tous les programmes demandés sont à réaliser sous Qt (sous Linux).
  
**Exercice : Jeu des allumettes :**
  
### 1. Principe général du jeu :
<p>
  Le programme demandé doit permettre à 2 joueurs de jouer au jeu des allumettes.
  Les joueurs doivent saisir leur nom. Puis, l'ordinateur affiche aléatoirement une série de 5 à 35 allumettes.
  Chaque joueur choisit, à tour de rôle, de supprimer 1,2 ou 3 allumettes lorsque cela est possible.
  Le joueur perdant est celui qui a été forcé de supprimer la dernière allumette.
  Le programme affiche un message précisant le nom du vainqueur.

  Le but de cet exercice est de faire le programme du jeu des allumettes codé en C++ (classes) selon le diagramme de classes ci-dessous :

![image](https://user-images.githubusercontent.com/97070339/215148630-e1ea09cd-6056-4abb-bd2b-475d27ccb138.png)

</p>

#### Remarques:

<p>
  - Aucune méthode de la classe 'CUjeuAllumettes' ne doit contenir d'instructions accédant à l'écran ou au clavier (cout, cin, ...)
  - La fonction 'main ()' reste inchangée par rapport à la version précédente.
  - Chaque classe devra être composée d'un fichier source(.cpp) et d'un fichier header(.h). L'ensemble devra donc contenir 5 fichiers.
</p>

#### **Classe IHMJoueur :**

  - Aucun attribut
  • Méthode **'SaisirNom(int) : string'** : méthode qui prend en paramètre le numéro du joueur à qui on demande de saisir son nom. Elle renvoie une chaine qui contient le nom du joueur.
  • Méthode **'afficherjeuAllumettes(int) : void'** : méthode qui prend en paramètre le nombre d'allumettes à afficher, et qui affiche les allumettes à l'écran
  • Méthode **jouerUnCoup(int, string) : int'** : méthode qui prend en paramètre un entier correspond au nombre d'allumettes restantes et une chaine qui contient le nom du joueur qui va jouer. Elle renvoie un entier qui contient le nombre d'allumettes retirées par le joueur seulement après avoir testé si la saisie est correcte.
  • Méthode **'afficherVainqueur(string) : void'** : méthode qui prend en paramètre une chaine qui contient le nom du vainqueur pour l'afficher.
  

#### **Classe CUjeuAllumettes :**

  - **nom[2] : string** : tableau contenant 2 chaines qui stockent les noms des joueurs.
  - **nbreAllumettes : int** : entier qui contient le nombre d'allumettes restantes.
  - **joueurEnCours : int** : entier qui contient le numéro du joueur qui joue ou va jouer. (0 joueur n°1, 1 : joueur n°2, etc...)
  - **ihm : IHMjoueur:** objet de classe IHMJoueur qui permet d'afficher des messages à l'écran.
  • **CUjeuAllumettes()** : constructeur de la classe.
  • **tirageAleatoire(mini : int, maxi :int)** : void : méthode qui tire un nombre aléatoire entre 'mini' et 'maxi' et qui l'affecte à 'nbreAllumettes' (début du jeu)
  • **changerJoueur() : void** : méthode qui change de joueur en modifiant l'attribut 'joueurEnCours'
  • **JouerUnePartie() : void** : méthode principale du jeu qui est appelée pour lancer le jeu. Elle contient une boucle qui fait jouer les participants à tour de rôle tant qu'il n'y a pas de vainqueur.


Vous devrez utiliser des exceptions :
#### **Les Exceptions**
<p>
  Une exception est un dispositif qui permet de rompre avec le déroulement normal d'un programme pour exécuter une tâche particulière.
  L'exemple le plus classique est la détection d'erreur. Lorsqu'une erreur survient (erreur de lecture dans un fichier, erreur de frappe, ...), le programme va exécuter une partie de code qui va gérer l'erreur qui vient d'être détectée en affichant un message, ou en stoppant le programme, La structure qui permet d'implémenter
  les exceptions est la suivante :

```
try
{
...
if ( ... ) throw 1 ; // exception N°1
if ( ... ) throw 2 ; // exception N°2
...
}
...
catch (int NumeroException)
{
...
  switch (NumeroException)
  {
    case 1 : ... break; // code à effectuer si l'exception N°1 apparait
    case 2 : ... break; // code à effectuer si l'exception N°2 apparait
  }
};
```

  Le bloc 'try' contient toutes les instructions que l'on essaie d'exécuter et qui peuvent lever (provoquer) une exception. Il peut y avoir plusieurs cas d'exception possibles à qui on attribue un numéro par le mot clé 'throw'.
  Le bloc 'catch' contient l'ensemble des traitements à effectuer pour chaque exception.
</p>
