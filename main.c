#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Elisa Yamashita Rodrigues, Renan Alves de Almeida, Vitor Marchini Rolisola



//funcao para identificar numero primo de forma recursiva
/*int primo_recursivo(unsigned int valor, unsigned int divisor){ //os divisores comecam no valor da raiz do numero
    if(divisor <= 1){
        return 1; //Chegou ao fim da recursao sem encontrar divisores
    }
    if(valor % divisor == 0){
        return 0; //Encontrou um divisor, nao e primo
    }
    return primo_recursivo(valor, divisor - 1);
}*/

int primo_recursivo(unsigned int valor, unsigned int divisor){ //os divisores comecam em um e vao ate o valor da raiz do numero
    if(divisor*divisor > valor){ // o valor inicial e igual a 3 pois 2 ja foi testado na main
        return 1;
    }
    if(valor % divisor == 0){ 
        return 0; //Encontrou um divisor, nao e primo
    }
    return primo_recursivo(valor, divisor + 2); // acescenta 2 para que sejam testados somente numero impares
}

//funcao para identificar numero primo de forma iterativa
int primo_iterativo(unsigned int valor){
    for(unsigned  int i = 3 ; i*i <= valor ; i = i+2){ //a verificacao ocorre apenas com os numeros impares
        if(valor % i == 0){
            return 0; //Encontrou um divisor, nao e primo
        }
    }
    return 1; //Nao encontrou divisor, e primo
}

int main(){
    unsigned int valor;

    do{
        printf("Digite um numero inteiro positivo, 0 para sair:\n");
        scanf("%u", &valor);

        if(valor == 2){ // verificação se o valor é igual ao unico numero primo divisível por 2
            printf("%u e numero primo\n", valor);
        } else if((valor % 2 == 0) || (valor == 1)){ // verificando se o numero é par
            printf("%u nao e numero primo\n", valor);
        }else{
            /*modo iterativo*/
            if(primo_iterativo(valor)){
                printf("%u e um numero primo (iterativo)\n", valor);
            }else{
                printf("%u nao e um numero primo (iterativo)\n", valor);
            }

            /*modo recursivo*/
            //if(primo_recursivo(valor, sqrt(valor))){
            if(primo_recursivo(valor, 3)){
                printf("%u e um numero primo (recursivo)\n", valor);
            }else{
                printf("%u nao e um numero primo (recursivo)\n", valor);
            }
        }
    }while(valor != 0);

    return 0;
}
