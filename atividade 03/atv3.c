# include <stdio.h>
# include <stdlib.h>
# include <time.h>


# define QTD_LINHAS 100
# define QTD_COLUNAS 100

void lerMatriz(int mat [][QTD_COLUNAS],int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS],int lin,int col);
int lerDentrodaMatriz(int min, int max);

int contarImpares(int mat [][QTD_COLUNAS],int lin, int col);
void verificarElemento(int mat [][QTD_COLUNAS],int lin, int col,int elemento);
int somatorio(int mat [][QTD_COLUNAS],int lin, int col);
float mediaMatriz(int mat [][QTD_COLUNAS],int lin, int col);
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


    int qtdImpares = contarImpares(matriz,qtdLinhas,qtdColunas);
    printf("Quantidade de impares é : %d\n",qtdImpares);

    int elemento;
    printf("Digite o elemento para realizar a sua busca :");
    scanf("%d",&elemento);
    verificarElemento(matriz,qtdLinhas,qtdColunas,elemento);

    int soma = somatorio(matriz,qtdLinhas,qtdColunas);
    float media = mediaMatriz(matriz,qtdLinhas,qtdColunas);

    printf("Somatorio dos elementos : %d\n",soma);
    printf("Media dos elementos : %.2f\n",media);

    mediaporLinha(matriz,qtdLinhas,qtdColunas);

    return 0;
}
void lerMatriz(int mat[][QTD_COLUNAS],int lin,int col){
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

}
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS],int lin,int col){
    for(int i = 0; i < lin;i++){
        for(int j = 0; j < col;j++){
            mat [i][j] = rand() % 100 +1;
        }
    }
}
void imprimirMatriz(int mat[][QTD_COLUNAS],int lin,int col){
     for(int i = 0; i < lin;i++){
        for(int j = 0; j < col;j++){
            printf("%d\t",&mat[i][j]);
        }
        printf("\n");
    }    
}
int lerDentroDoIntervalo(int min, int max){
    int valor;
    scanf("%d",&valor);
    while(valor <  min|| valor < max){
        printf("Valor invalido! Digite valor entre %d e %d",min,max);
    }
    return valor;
}