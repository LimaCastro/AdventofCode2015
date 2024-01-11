//teste 1 = ">"ok 
//teste 2 = "^>v<" ok
//teste 3 = "^v^v^v^v^v"

/*
--- Day 3: Perfectly Spherical Houses in a Vacuum ---
/--- Dia 3: Casas Perfeitamente Esféricas em um Vácuo ---

Santa is delivering presents to an infinite two-dimensional grid of houses.
/Papai Noel está entregando presentes a uma malha bidimensional infinita de casas.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next.
/Ele começa entregando um presente à casa em sua localização inicial, e depois um elfo no Polo Norte o chama via rádio e diz a ele para onde se mover em seguida.
Moves are always exactly one house to the north (^), south (v), east (>), or west (<).
/Os movimentos são sempre exatamente uma casa para o norte (^), sul (v), leste (>), ou oeste (<).
After each move, he delivers another present to the house at his new location.
/Após cada movimento, ele entrega outro presente à casa em sua nova localização.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once.
/No entanto, o elfo no Pólo Norte bebeu gemada demais e, portanto, suas instruções estão um pouco erradas, e o Papai Noel acaba visitando algumas casas mais de uma vez.
How many houses receive at least one present?
/Quantas casas receberam pelo menos um presente?

For example:

> delivers presents to 2 houses: one at the starting location, and one to the east.
^>v< delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
^v^v^v^v^v delivers a bunch of presents to some very lucky children at only 2 houses.
To begin, get your puzzle input.
*/

#include <stdio.h>
#include <stdlib.h>

//struct para suportar as instruções que serão tratadas e para criação da lista contendo as casas que receberam presente pelo menos um presente

typedef struct houseCoordinates{
    //coordenadas
    int x;
    int y;

    struct houseCoordinates *proxHouse;
}houseCoordinates;

houseCoordinates * createNode ();
houseCoordinates * insertNodeAtStart (houseCoordinates *listHouse, int x, int y);
int locateHouse (houseCoordinates *listHouse, int x, int y);
int processInstructions (houseCoordinates *listHouse, FILE *directionsInstructions);
void printRes (int answer);
void freeList (houseCoordinates *listHouse);

int main (){
    houseCoordinates *listHouse = NULL;
    int x1, y1, numberOfHouses;
    FILE *directionsInstructions;

    x1 = 0;
    y1 = 0;

    listHouse = insertNodeAtStart (listHouse, x1, y1);

    directionsInstructions = fopen ("c2015.txt", "r");

    numberOfHouses = processInstructions (listHouse, directionsInstructions);

    fclose (directionsInstructions);

    printRes (numberOfHouses);

    freeList (listHouse);

    exit (0);
}

houseCoordinates * createNode (){
    houseCoordinates *newNode = (houseCoordinates *) malloc (sizeof (houseCoordinates));

    return newNode;
}

houseCoordinates * insertNodeAtStart (houseCoordinates *listHouse, int x, int y){
    houseCoordinates * newNode = createNode ();

    newNode->x = x;
    newNode->y = y;

    if (listHouse == NULL){
        listHouse = newNode;
        newNode->proxHouse = NULL;
    }

    else{
        newNode->proxHouse = listHouse;
        listHouse = newNode;
    }

    return listHouse;
}

int locateHouse (houseCoordinates *listHouse, int x, int y){
    houseCoordinates *auxiliarSearch = listHouse;

    while (auxiliarSearch != NULL){
        if (auxiliarSearch->x == x){
            if (auxiliarSearch->y == y)
                return 1;
        }

        auxiliarSearch = auxiliarSearch->proxHouse;
    }
    
    return 0;
}

int processInstructions (houseCoordinates *listHouse, FILE *directionsInstructions){
    int houses = 1, positionX = 0, positionY = 0, flagInsertion;
    char instructionCharacter;

    while (fread (&instructionCharacter, sizeof (char), 1, directionsInstructions)){
        if (instructionCharacter == '^')
            positionY += 1;
        
        else if (instructionCharacter == 'v')
            positionY -= 1;

        else if (instructionCharacter == '>')
            positionX += 1;

        else
            positionX -= 1;

        flagInsertion = locateHouse (listHouse, positionX, positionY);

        if (flagInsertion == 0){
            listHouse = insertNodeAtStart (listHouse, positionX, positionY);
            houses += 1;
        }
    }

    return houses;
}

void printRes (int answer){
    printf ("Santa visited %d houses.", answer);

    return;
}

void freeList(houseCoordinates *listHouse) {
    houseCoordinates *auxiliarFree = listHouse;
    houseCoordinates *nextNode;

    while (auxiliarFree != NULL) {
        nextNode = auxiliarFree->proxHouse;
        free(auxiliarFree);
        auxiliarFree = nextNode;
    }

    return;
}