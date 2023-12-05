/*
--- Day 1: Not Quite Lisp ---
//Não é exatamente lisp(pode ser de sla falar errado)

/Dia 1: 

Santa was hoping for a white Christmas, but his weather machine's "snow" function is powered by stars, and he's fresh out! To save Christmas, he needs you to collect fifty stars by December 25th.
/Papai Noel estava esperando por um Natal branco(que neve), mas a função de 'neve' de sua máquina climática é alimentada por estrelas, e ele está sem estoque! Para salvar o Natal, ele precisa que você colete cinquenta estrelas até o dia 25 de dezembro.

Collect stars by helping Santa solve puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!
/Colete estrelas ajudando o Papai Noel a resolver quebra-cabeças. Dois quebra-cabeças serão disponibilizados a cada dia no calendário do Advento(contagem regressiva para o natal); Cada quebra-cabeça concede uma estrela. Boa sorte!

Here's an easy puzzle to warm you up.
/Aqui está um quebra-cabeça fácil para te aquecer.

Santa is trying to deliver presents in a large apartment building, but he can't find the right floor - the directions he got are a little confusing. He starts on the ground floor (floor 0) and then follows the instructions one character at a time.
/Papai Noel está tentando entregar presentes em um grande prédio de apartamentos, mas ele não consegue encontrar o andar certo - as direções que ele recebeu estão um pouco confusas. Ele começa no térreo (andar 0) e em seguida segue as instruções um caractere de cada vez.

An opening parenthesis, (, means he should go up one floor, and a closing parenthesis, ), means he should go down one floor.
/Um parêntese de abertura, (, significa que ele deve subir um andar, e um parêntese de fechamento, ), significa que ele deve descer um andar.

The apartment building is very tall, and the basement is very deep; he will never find the top or bottom floors.
/O prédio de apartamentos é muito alto, e o subsolo é muito profundo; ele nunca encontrará os andares mais altos nem os mais baixos.

For example:

(()) and ()() both result in floor 0.
((( and (()(()( both result in floor 3.
))((((( also results in floor 3.
()) and ))( both result in floor -1 (the first basement level).
))) and )())()) both result in floor -3.
To what floor do the instructions take Santa?

To begin, get your puzzle input.
*/

#include <stdio.h>
#include <stdlib.h>

int floorX (FILE *fl);
void printRes (int a);

int main (){
    //variáveis que serão utilizadas
    FILE *instructions;
    int resultF;

    //abertura do arquivo e setagem de leitura, esse arquivo contém as instruções para se locomover no prédio.
    instructions = fopen ("a2015.txt", "r");

    resultF = floorX (instructions);

    fclose (instructions);

    printRes (resultF);

    //após a execução estou saindo do programa com sucesso
    exit (0);
}

int floorX (FILE *fl){
    //váriavel que será utilizada para contar os os andares e descobrir onde ele se encontra no momento e a variavel que vai receber o caractere
    int count = 0;
    char compare;

    //laco para leitura do arquivo enquanto tiver caracter
    while (fread(&compare, sizeof(char), 1, fl) == 1) {
        // Operações para checar onde estou indo
        if (compare == '(')
            count += 1;
        else if (compare == ')')
            count -= 1;
    }

    return count;
}

void printRes (int a){
    //procedimento para printar o resultado
    printf ("Santas is on the floor %d", a);

    return;
}