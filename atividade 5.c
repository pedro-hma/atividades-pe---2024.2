#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 4

void preencherMatriz(int m[][N], int lin, int col);
void imprimirMatriz(int m[][N], int lin, int col);
void maiorCadaColuna(int m[][N], int lin, int col, int v[]);
void imprimirVetor(int v[], int tam);
void maiorRepetidos(int m[][N], int lin, int col);

int main() {
    int matriz[M][N];
    int vetor[N];
    int opcao;
    do {
        printf("\nMENU\n\n");
        printf("1 - preencher matriz com aleatorios\n");
        printf("2 - Maior cada coluna\n");
        printf("3 - Linha ou Coluna com mais repetidos\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            preencherMatriz(matriz, M, N);
            imprimirMatriz(matriz, M, N);
            break;
        case 2:
            maiorCadaColuna(matriz, M, N, vetor);
            imprimirVetor(vetor, N);
            break;
        case 3:
            maiorRepetidos(matriz, M, N);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void preencherMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorCadaColuna(int m[][N], int lin, int col, int v[]) {
    for (int j = 0; j < col; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < lin; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void maiorRepetidos(int m[][N], int lin, int col) {
    int maxRepetidos = 0;
    int indice = -1;
    char tipo = ' '; // 'L' para linha, 'C' para coluna

    // Verificar linhas
    for (int i = 0; i < lin; ++i) {
        int count[101] = {0}; // Supondo valores entre 1 e 100
        for (int j = 0; j < col; ++j) {
            count[m[i][j]]++;
        }
        int repetidos = 0;
        for (int k = 1; k <= 100; ++k) {
            if (count[k] > 1) {
                repetidos += count[k];
            }
        }
        if (repetidos > maxRepetidos) {
            maxRepetidos = repetidos;
            indice = i;
            tipo = 'L';
        }
    }

    // Verificar colunas
    for (int j = 0; j < col; ++j) {
        int count[101] = {0}; // Supondo valores entre 1 e 100
        for (int i = 0; i < lin; ++i) {
            count[m[i][j]]++;
        }
        int repetidos = 0;
        for (int k = 1; k <= 100; ++k) {
            if (count[k] > 1) {
                repetidos += count[k];
            }
        }
        if (repetidos > maxRepetidos) {
            maxRepetidos = repetidos;
            indice = j;
            tipo = 'C';
        }
    }

    if (maxRepetidos > 0) {
        printf("O %s com mais numeros repetidos e o indice: %d, com um total de %d repetidos.\n", 
               tipo == 'L' ? "linha" : "coluna", indice, maxRepetidos);
    } else {
        printf("Nao ha repeticoes na matriz.\n");
    }
}
