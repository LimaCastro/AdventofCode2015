/*
--- Part Two ---
/Parte Dois
The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.
/No próximo ano, para acelerar o processo, o Papai Noel cria uma versão robô de si mesmo, o Robo-Papai Noel, para entregar presentes junto com ele.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.
/O Papai Noel e o Robo-Papai Noel começam no mesmo local (entregando dois presentes para a mesma casa de partida), depois se revezam movendo-se com base nas instruções do elfo, que está teimosamente lendo do mesmo roteiro do ano anterior.

This year, how many houses receive at least one present?
/Este ano, quantas casas recebem pelo menos um presente?

For example:

^v delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
^>v< now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
^v^v^v^v^v now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.
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
void resetArray (int coordinateArray[2]);
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

void resetArray (int coordinateArray[2]){
    for (int i = 0; i < 2; i++)
        coordinateArray[i] = 0;

    return;
}

int processInstructions (houseCoordinates *listHouse, FILE *directionsInstructions){
    int houses = 1, positionX [2], positionY [2], flagInsertion, countInstruction = 0, verifyDeliver;
    char instructionCharacter;

    resetArray(positionX);
    resetArray(positionY);

    while (fread (&instructionCharacter, sizeof (char), 1, directionsInstructions)){
        verifyDeliver = countInstruction % 2;

        if (instructionCharacter == '^')
            positionY[verifyDeliver] += 1;
        
        else if (instructionCharacter == 'v')
            positionY[verifyDeliver] -= 1;

        else if (instructionCharacter == '>')
            positionX[verifyDeliver] += 1;

        else
            positionX[verifyDeliver] -= 1;

        flagInsertion = locateHouse (listHouse, positionX[verifyDeliver], positionY[verifyDeliver]);

        if (flagInsertion == 0){
            listHouse = insertNodeAtStart (listHouse, positionX[verifyDeliver], positionY[verifyDeliver]);
            houses += 1;
        }

        countInstruction += 1;
    }

    return houses;
}

void printRes (int answer){
    printf ("Santa and Robo-Santa visited %d houses.", answer);

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