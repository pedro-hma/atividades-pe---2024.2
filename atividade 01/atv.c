#include <stdio.h>

void ordenacao(int v[], int qtd, int valor) {
    int i = qtd - 1;

    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }
    
    v[i + 1] = valor;
}

int main() {
    int qtd;

    printf("Digite a quantidade de valores: ");
    scanf("%d", &qtd);

    if (qtd <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    int v[qtd];
    int valor;

    for (int i = 0; i < qtd; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor);
        ordenacao(v, i, valor);
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}