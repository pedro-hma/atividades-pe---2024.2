# include <stdio.h>
# include <stdlib.h>
# include <time.h>


# define QTD_LINHAS 100
# define QTD_COLUNAS 100

void lerMatriz(int mat [][QTD_COLUNAS],int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS],int lin,int col);
int lerDentrodaMatriz(int min, int max);

int contarImpares(int mat [][QTD_COLUNAS],int lin, int col);
void verificarElento(int mat [][QTD_COLUNAS],int lin, int col,int elemento);
void somatorio(int mat [][QTD_COLUNAS],int lin, int col);
void mediaMatriz(int mat [][QTD_COLUNAS],int lin, int col);
void mediaporLinha(int mat [][QTD_COLUNAS],int lin, int col);

int main(){
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];

    srand(time(0));
    printf("Digite a quantidade de linhas (1-%d)",QTD_LINHAS);
    qtdLinhas = lerDentroDoIntervalo(1,QTD_LINHAS);
    printf("Digite a quantidade de linhas (1-%d)",QTD_COLUNAS);
    qtdColunas = lerDentroDoIntervalo(1,QTD_COLUNAS);

    preencherMatrizAleatoria(matriz,qtdLinhas,qtdColunas);
    printf("\n-----------------------\n");
    imprimirMatriz(matriz,qtdLinhas,qtdColunas);
    return 0;
}