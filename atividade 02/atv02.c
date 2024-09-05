# include <stdio.h>
# include <stdlib.h>

# define CAPACIDADE_VETOR 10

void imprimir_vetor(int v[],int qtd);
void insertionSort(int v[],int qtd);

int main(){
    char opcao;
    int qtd,num,pos;
    int v[CAPACIDADE_VETOR];

    do{
        printf("Qual o tamanho do vetor ?(valor entre 1 e %d) ",CAPACIDADE_VETOR);
        scanf("%d",&qtd);
    } while(qtd < 1 || qtd > CAPACIDADE_VETOR);
}