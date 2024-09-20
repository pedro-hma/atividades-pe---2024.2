#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col);
int lerDentroDoIntervalo(int min, int max);
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col);
int contarImpares(int mat[][QTD_COLUNAS], int lin, int col);
void verificarElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento);
int somatorio(int mat[][QTD_COLUNAS], int lin, int col);
double mediaMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void mediaporLinha(int mat[][QTD_COLUNAS], int lin, int col);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    int opcao;

    srand(time(0));
    do {
        printf("\nMenu:\n");
        printf("1. Preencher matriz com valores aleatorios.\n");
        printf("2. Imprimir matriz : \n");
        printf("3. Contar impares : \n");
        printf("4. Consultar elemento : \n");
        printf("5. Calcular Somatorio: \n");
        printf("6. Calcular Media da Matriz\n");
        printf("7. Calcular a Media da Linha\n");
        printf("8. Sair\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade de linha (1 - %d): ", QTD_LINHAS);
                qtdLinhas = lerDentroDoIntervalo(1, QTD_LINHAS);
                printf("Digite a quantidade de colunas (1 - %d): ", QTD_COLUNAS);
                qtdColunas = lerDentroDoIntervalo(1, QTD_COLUNAS);
                preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
                printf("Matriz Preenchida com valores aleatorios\n");
                break;
            case 2:
                imprimirMatriz(matriz, qtdLinhas, qtdColunas);
                break;
            case 3:
                printf("Quantidade de impares é %d\n", contarImpares(matriz, qtdLinhas, qtdColunas));
                break;
            case 4: {
                int elemento;
                printf("Digite o valor do elemento para ser buscado: ");
                scanf("%d", &elemento);
                verificarElemento(matriz, qtdLinhas, qtdColunas, elemento);
                break;
            }
            case 5:
                printf("Somatorio dos valores da matriz: %d\n", somatorio(matriz, qtdLinhas, qtdColunas));
                break;
            case 6:
                printf("Média dos elementos: %.2f\n", mediaMatriz(matriz, qtdLinhas, qtdColunas));
                break;
            case 7:
                mediaporLinha(matriz, qtdLinhas, qtdColunas);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int lerDentroDoIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor invalido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}

int contarImpares(int mat[][QTD_COLUNAS], int lin, int col) {
    int contador = 0;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] % 2 != 0) {
                contador++;
            }
        }
    }
    return contador;
}

void verificarElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == elemento) {
                printf("O elemento %d foi encontrado na linha %d e coluna %d.\n", elemento, i + 1, j + 1);
                return;
            }
        }
    }
    printf("Elemento não encontrado.\n");
}

int somatorio(int mat[][QTD_COLUNAS], int lin, int col) {
    int soma = 0;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            soma += mat[i][j];
        }
    }
    return soma;
}

double mediaMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    double somatorio = 0;
    int totalElementos = lin * col;
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            somatorio += mat[i][j];
        }
    }
    return (totalElementos > 0) ? somatorio / totalElementos : 0;
}

void mediaporLinha(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        double somatorio = 0;

        for (int j = 0; j < col; j++) {
            somatorio += mat[i][j];
        }
        double mediaPorLinha = (col > 0) ? somatorio / col : 0;
        printf("A média da linha %d: %.2f\n", i + 1, mediaPorLinha);
    }
}
