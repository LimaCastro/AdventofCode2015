/*
The first half of this puzzle is complete! It provides one gold star: *
A primeira metade deste quebra-cabeça(desafio) está completa! Isso fornece uma estrela dourada: *

--- Part Two ---
Parte Dois

Now, given the same instructions, find the position of the first character that causes him to enter the basement (floor -1). The first character in the instructions has position 1, the second character has position 2, and so on.
Agora, seguindo as mesmas instruções, encontre a posição do primeiro caractere que faz com que ele entre no subsolo (andar -1). O primeiro caractere nas instruções está na posição 1, o segundo caractere está na posição 2, e assim por diante.

For example:

) causes him to enter the basement at character position 1.
()()) causes him to enter the basement at character position 5.
What is the position of the character that causes Santa to first enter the basement?
*/

#include <stdio.h>
#include <stdlib.h>

int basementIden (FILE *fl);
void printRes (int a);

int main (){
    //variáveis que serão utilizadas
    FILE *instructions;
    int baseme;

    instructions = fopen ("a2015.txt", "r");

    baseme = basementIden (instructions);

    fclose (instructions);

    printRes (baseme);

    exit (0);
}

int basementIden (FILE *fl){
    //variáveis que serão utilizadas
    int floors = 0, fD = 0;
    char compare;

    while (fread(&compare, sizeof(char), 1, fl) == 1) {
        //somando a posição da instrução para saber em que instrução chegaremos ao subsolo
        fD += 1;
        // Operações para checar onde estou indo
        if (compare == '(')
            floors += 1;
        else if (compare == ')')
            floors -= 1;

        //se alcançar o subsolo saio do laço
        if (floors == -1)
            break;
    }

    //se eu nunca atingi o subsolo então retorno 0, pois nenhuma instrução me levou ao objetivo 
    if (floors != -1)
        return 0;
    
    //retorno a variável contendo a posição do caracter que me levou ao subsolo 
    else
        return fD;
}

void printRes (int a){
    //procedimento para printar o resultado
    if (a == 0)
        printf ("Santas never reached basement based on the instructions.");

    else
        printf ("Santas reached the basement in the instruction %d", a);

    return;

}