# include <stdio.h>
# include <stdlib.h>

# define CAPACIDADE_VETOR 50

void imprimir_vetor(int v[],int qtd);
void insertionSort(int v[],int qtd);

int main(){
    char opcao;
    int qtd,num,pos;
    int v[CAPACIDADE_VETOR];
    // solicita para o usuario inserir o tamanho do vetor
    do{
        printf("Qual o tamanho do vetor ?(valor entre 3t e %d) ",CAPACIDADE_VETOR);
        scanf("%d",&qtd);
    } while(qtd < 1 || qtd > CAPACIDADE_VETOR);
    // solicita para o digitar os valores do vetor
    printf("Digitação dos valores no vetor\n :");
    for(int i = 0; i < qtd; i++){
        printf("Digite o %dº numero :",i+1);
        scanf("%d",&v[i]);
    }
    printf("\n Impressão do vetor original\n :");
    printf("V =");

    // chamada das funções 
    imprimir_vetor(v,qtd);

    insertionSort(v,qtd);

    // impressao do vetor de formar ordenada
    printf("V =");
    imprimir_vetor(v,qtd);

}