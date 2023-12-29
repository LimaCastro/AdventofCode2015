/*
--- Day 2: I Was Told There Would Be No Math ---
/--- Dia 2: Me Disseram Que Não Haveria Matemática ---

The elves are running low on wrapping paper, and so they need to submit an order for more.
/Os duendes estão ficando sem papel de embrulho, então eles precisam fazer um pedido de mais.

They have a list of the dimensions (length l, width w, and height h) of each present, and only want to order exactly as much as they need.
/Eles têm uma lista das dimensões (comprimento l, largura w e altura h) de cada presente e querem fazer um pedido exatamente na quantidade necessária.

Fortunately, every present is a box (a perfect right rectangular prism), which makes calculating the required wrapping paper for each gift a little easier: find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l.
/Felizmente, cada presente é uma caixa (um prisma retangular perfeito), o que torna o cálculo do papel de embrulho necessário para cada presente um pouco mais fácil: encontre a área da superfície da caixa, que é 2lw + 2wh + 2hl.

The elves also need a little extra paper for each present: the area of the smallest side.
/Os duendes também precisam de um pouco de papel extra para cada presente: a área do lado mais pequeno.

For example:

A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.
A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping paper plus 1 square foot of slack, for a total of 43 square feet.
All numbers in the elves' list are in feet. How many total square feet of wrapping paper should they order?

To begin, get your puzzle input.
*/

#include <stdio.h>
#include <stdlib.h>

void editFil (FILE *fl, FILE *fm);
int paperN (FILE *fl);
void printRes (int a);

int main (){
    //variáveis utilizadas
    FILE *measList, *measList2;
    int resultF;

    //abertura do arquivo
    measList = fopen ("b2015.txt", "r");
    measList2 = fopen ("teste2.txt", "w+");
    //xxxx = fopen ("xdcd.txt", "r");

    //edição do arquivo
    editFil (measList, measList2);

    fclose (measList);

    //reposicionamento do arquivo para o início
    rewind (measList2);

    resultF = paperN (measList2);

    fclose (measList2);

    printRes (resultF);

    exit (0);
}

void editFil (FILE *fl, FILE *fm){
    //variável buffer
    char compare;

    //laço para leitura e atualização do arquivo
    while (fread(&compare, sizeof(char), 1, fl) == 1) {
        //setando o arquivo texto dessa maneira para ser mais fácil o fscanf que sera utilizado na prox funcao.
        if (compare == 'x'){
            fputs (" ", fm);
        }

        else
            fprintf (fm, "%c", compare);
    }

    return;
}

int paperN (FILE *fl){
    int papMea = 0;
    char row[20];

    //l - length; w - width; h - height
    int l, w, h;

    while (fgets (row, sizeof (row), fl) != NULL){
        // Usar sscanf para processar a linha lida por fgets, o 3 é para específicar que estou pegando 3 valores
        if (sscanf(row, "%d %d %d", &l, &w, &h) == 3) {
            //comparações para achar a menor área e efetuar o código
            if ((l * w <= w * h) && (l * w <= l * h))
                papMea += (l * w) + ((2 * l * w) + (2 * w * h) + (2 * h * l));
            else if ((l * h <= w * h) && (l * h <= l * w))
                papMea += (l * h) + ((2 * l * w) + (2 * w * h) + (2 * h * l));
            else
                papMea += (w * h) + ((2 * l * w) + (2 * w * h) + (2 * h * l));
        }
    }

    return papMea;
}

void printRes (int a){
    printf ("Santas needs a total of %d square feet.", a);

    return;
}