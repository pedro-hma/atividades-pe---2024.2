# include <stdio.h>
# include <stdlib.h>

# define CAPACIDADE_VETOR 50

void imprimir_vetor(int v[],int qtd);
void insertionSort(int v[],int qtd);
int buscaBinaria(int v[], int qtd, int valor);
void remover_elemento(int v[],int * qtd, int valor);
void inserir_elemento(int v[],int * qtd, int valor);

int main(){
    char opcao;
    int qtd,num,pos;
    int v[CAPACIDADE_VETOR];
    // solicita para o usuario inserir o tamanho do vetor
    do{
        printf("Qual o tamanho do vetor ?(valor entre 3 e %d) ",CAPACIDADE_VETOR);
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

    printf("\n Impressao do vetor ordenado\n :");
    printf("V =");
    imprimir_vetor(v,qtd);

    do {
        printf("\nMenu:\n");
        printf("1. Imprimir o vetor\n");
        printf("2. Consultar (buscar elemento)\n");
        printf("3. Remover elemento\n");
        printf("4. Inserir elemento\n");
        printf("5. Sair\n");
        printf("Escolha uma das opções: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                printf("Vetor: ");
                imprimir_vetor(v, qtd);
                break;

            case '2':
                printf("Digite um valor a ser consultado: ");
                scanf("%d", &num);
                pos = buscaBinaria(v, qtd, num);
                if (pos != -1) {
                    printf("Valor encontrado na posição %d\n", pos);
                } else {
                    printf("Valor não encontrado\n");
                }
                break;

            case '3':
                printf("Digite um valor a ser removido: ");
                scanf("%d", &num);
                remover_elemento(v, &qtd, num);
                break;

           case '4':
                if (qtd < CAPACIDADE_VETOR) {
                    printf("Digite um valor a ser inserido: ");
                    scanf("%d", &num);
                    inserir_elemento(v, &qtd, num);
                } else {
                    printf("O vetor está cheio, não é possível inserir mais elementos.\n");
                }
                break;

            case '5':
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida\n");
         }
    } while (opcao != '5');

    return 0;
}

void imprimir_vetor(int v[], int qtd){
    printf("[");
    if(qtd > 0){
        printf("%d",v[0]);
        for(int i = 1; i < qtd; i++){
            printf(",%d",v[i]);
        }
    }
    printf("]\n");

}

void insertionSort(int v[], int qtd){
    for(int i = 1; i < qtd;i++){
        int aux = v[i];
        int j = i -1;
        // esse while percorre o vetor e o ordena 
        while(j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1]= aux;
    }
}

void remover_elemento(int v[], int *qtd, int valor){
    int pos = buscaBinaria(v,*qtd,valor);
    if (pos != 1){
        for(int i = 0; i < *qtd; i++){
            v[i] = v[i+1];
        }
        (*qtd)--;
    }
}

void inserir_elemento(int v[], int *qtd, int valor){
    if(*qtd == 0 || valor >= v[*qtd -1]){
        v[*qtd] = valor;
        (*qtd) ++;
        return;
    }
    int i;
    for(i = * qtd -1; i >= 0 && v[i] > valor;i--){
        v[i+1] = v[i];
    }
    v[i+1] = valor;
    (*qtd)++;
}

int buscaBinaria(int v[], int qtd, int valor){
    int esq = 0;
    int dir = qtd-1;

    while(esq <= dir){
        int meio = (esq + dir)/2;
        if(v[meio] == valor){
            return meio;
        } else if(v[meio] < valor){
            esq = meio +1;
        }else{
            dir = meio -1;
        }
    }
    return 0;
}