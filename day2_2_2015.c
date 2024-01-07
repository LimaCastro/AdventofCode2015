/*
--- Part Two ---
/--- Parte Dois ---

The elves are also running low on ribbon.
/Os elfos também estão ficando sem fita.
Ribbon is all the same width, so they only have to worry about the length they need to order, which they would again like to be exact.
/A fita tem sempre a mesma largura, então eles só precisam se preocupar com o comprimento que precisam encomendar, o qual eles novamente gostariam que fosse exato.

The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter of any one face.
/A fita necessária para embrulhar um presente é a distância mais curta ao redor dos seus lados, ou o menor perímetro de qualquer uma das faces.
Each present also requires a bow made out of ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume of the present.
/Cada presente também requer um laço feito de fita; os pés de fita necessários para o laço perfeito são iguais aos pés cúbicos de volume do presente.
Don't ask how they tie the bow, though; they'll never tell.
/Não pergunte como eles amarram o laço, no entanto; eles nunca vão contar.

For example:

A present with dimensions 2x3x4 requires 2+2+3+3 = 10 feet of ribbon to wrap the present plus 2*3*4 = 24 feet of ribbon for the bow, for a total of 34 feet.
A present with dimensions 1x1x10 requires 1+1+1+1 = 4 feet of ribbon to wrap the present plus 1*1*10 = 10 feet of ribbon for the bow, for a total of 14 feet.
How many total feet of ribbon should they order?
*/

#include <stdio.h>
#include <stdlib.h>

int ribN (FILE *fl);
void printRes (int a);

int main (){
    //variáveis utilizadas
    FILE *measList;
    int resultF;

    //abertura do arquivo
    measList = fopen ("teste2.txt", "r");

    resultF = paperN (measList);

    fclose (measList);

    printRes (resultF);

    exit (0);
}

int ribN (FILE *fl){
    int ribMea = 0;
    char row[20];

    //l - length; w - width; h - height
    int l, w, h;

    while (fgets (row, sizeof (row), fl) != NULL){
        // Usar sscanf para processar a linha lida por fgets, o 3 é para específicar que estou pegando 3 valores
        if (sscanf(row, "%d %d %d", &l, &w, &h) == 3) {
            //comparações para achar o menor perímetro e efetuar o cálculo
            if ((l + w <= w + h) && (l + w <= l + h))
                ribMea += (2 * l) + (2 * w) + (l * w * h);
    
            else if ((l + h <= w + h) && (l + h <= l + w))
                ribMea += (2 * l) + (2 * h) + (l * w * h);

            else
                ribMea += (2 * w) + (2 * h) + (l * w * h);
        }
    }

    return ribMea;
}

void printRes (int a){
    printf ("Santa's needs a total of %d feet ribbon.", a);

    return;
}