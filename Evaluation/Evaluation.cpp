// Evaluation.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>

// Déclaration des variables
const int GRID_SIZE = 5;
const char PLAYER = '@';
const char TREASURE = 'T';
const char OBSTACLE = '#';
const char EMPTY = '.';





// Déclaration des fonctions
//////////////////////////////////////////////
// Fonction qui va initialiser la grille de départ
// Parametre d'entrée : auncun
// Parametre de sorti : rien
//////////////////////////////////////////////

void iniGrid(int grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY)
{
    // Pour toutes les lignes de la matrice
    for (int i = 0; i < GRID_SIZE - 1; i++) 
    {
        // Pour toutes les colonnes de la matrice
        for (int j = 0; j < GRID_SIZE - 1; j++) 
        {
            // Affichage de l'élément de la matrice
            grid[i][j] = EMPTY;
            

        }
    }


    // PLAYER en 0, 0
    grid[0][0] = PLAYER;
     

   // TREASURE pointe sur la fin du tableau en bas à droite
     grid[4][4] = TREASURE;

   // OBSTACLE
     grid[2][2] = OBSTACLE;
     grid[3][4] = OBSTACLE;
     grid[3][3] = OBSTACLE;



}

//////////////////////////////////////////////
// Fonction qui va afficher la grille de départ
// Parametre d'entrée : un tableau GRID_SIZE * GRID_SIZE
// Parametre de sorti : rien
//////////////////////////////////////////////

void affichageGrid(int grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY)
{
    // Pour toutes les lignes de la matrice
    for (int i = 0; i < GRID_SIZE - 1; i++) 
    {
        // Pour toutes les colonnes de la matrice
        for (int j = 0; i < GRID_SIZE - 1; j++) 
        {
            // Afficher grid[i][j]
            printf("%d ", grid[i][j]);

            // Afficher une nouvelle ligne
            printf("\n");


        }


    }

}

//////////////////////////////////////////////
// Fonction qui va incrémenter la position du joueur dans la grille de départ
// Parametre d'entrée : auncun
// Parametre de sorti : rien
//////////////////////////////////////////////
int movePlayer(int grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY, int direction)
{
    // Déclaration de la nouvelle position du joueur
    int nouvelleX = *playerX;
    int nouvelleY = *playerY;

    // Verticale

    // Si direction = 1 et que positionPlayer > 0 ---- > HAUT
    if ((direction == 1) && (nouvelleY > 0))
    {
        nouvelleY = nouvelleY + 1;

    } // Sinon si direction = 2 et que positionPlayer < GRIDSIZE -1 ----- > BAS
    else if ((direction == 2) && (nouvelleY < GRID_SIZE - 1))
    {
        nouvelleY = nouvelleY - 1;

    }

    // Horizontal

    // Sinon si direction = 3 et positionbPlayer > 0 ----> GAUCHE
    else if ((direction == 3) && (nouvelleX > 0))
    {
        nouvelleX = nouvelleX - 1;
    }
    // Sinon si direction = 4 et que positionPlayer < GRIDSIZE -1 ----- > DROITE
    else if ((direction == 4) && (nouvelleX < GRID_SIZE - 1))
    {
        nouvelleX = nouvelleX + 1;
    }

    // Si positionPlayer et égal à obstacle
    if (grid[nouvelleX][nouvelleY] = OBSTACLE) 
    {
        return false;
    }

    // Si positionPlayer et égal à TREASURE
    if (grid[nouvelleX][nouvelleY] = TREASURE)
    {
        return true;
    }

    // Si positionPlayer et égal à positionPlayer
    if (grid[nouvelleX][nouvelleY] = PLAYER)
    {

        return false;
    }

}



int main()
{
    // Déclaration des pointeurs 
    int* playerX = NULL;
    int* playerY = NULL;

    // Définition d'une variable globale matrice[5,5]
    int iGrid[GRID_SIZE][GRID_SIZE];

    // Déclaration de direction
    int direction;

    iniGrid(iGrid, playerX, playerY);
    do
    {
        affichageGrid(iGrid, playerX, playerY);
        printf("Deplacement : 1: haut, 2:bas, 3:gauche, 4:droite");
        scanf_s("%d", &direction);

        if (movePlayer(iGrid, playerX, playerY, direction))
        {
            printf("Vous avez trouver le treasur ! \n");
            break;
        }
           
    } while (1);




}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
