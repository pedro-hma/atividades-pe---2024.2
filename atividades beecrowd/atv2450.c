#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int matriz[N][M];

    // Leitura da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Verificação se a matriz está na forma escada
    char resultado = 'S'; // Inicialmente assumimos que está na forma escada

    for (int i = 0; i < N; i++) {
        int encontrado = 0; // Flag para indicar se foi encontrado um elemento diferente de zero
        for (int j = 0; j < M; j++) {
            if (matriz[i][j] != 0) {
                encontrado = 1; // Elemento diferente de zero encontrado
                // Verifica se todos os elementos à esquerda de matriz[i][j] são zero
                for (int k = 0; k < j; k++) {
                    if (matriz[i][k] != 0) {
                        resultado = 'N'; // Não está na forma escada
                        break;
                    }
                }
                for (int k = i + 1; k < N; k++) {
                    if (matriz[k][j] != 0) {
                        resultado = 'N';
                        break;
                    }
                }
                break;
            }
        }
        if (!encontrado) {
            for (int k = i + 1; k < N; k++) {
                for (int l = 0; l < M; l++) {
                    if (matriz[k][l] != 0) {
                        resultado = 'N';
                        break;
                    }
                }
            }
        }
        if (resultado == 'N') {
            break;
        }
    }

    printf("%c\n", resultado);

    return 0;
}
