# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define QTD_LINHAS 100
# define QTD_COLUNAS 100

void multiplicarMatrizes(int matrizA[][QTD_COLUNAS], int linA, int colA, int matrizB[QTD_LINHAS][QTD_COLUNAS],int linB,int colB, int matrizMult[QTD_LINHAS][QTD_COLUNAS]);
void imprimirMatriz(int mat[][QTD_COLUNAS],int lin,int col);
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS],int lin,int col);

int main(){
    int linA,colA,linB,colB;
    printf("Digite o número de linhas e colunas da Matriz A: ");
    scanf("%d %d ",&linA,colA);
    int matrizA[QTD_LINHAS][QTD_COLUNAS];

    printf("Digite o número de linhas e colunas da Matriz B: ");
    scanf("%d %d ",&linB,colB);
    if(colA != linB){
        printf("A multiplicação não é possivel\n.");
        return 1;
    }
    int matrizB[QTD_LINHAS][QTD_COLUNAS];
    int matrizMulti [QTD_LINHAS][QTD_COLUNAS];
    
    
    multiplicarMatrizes(matrizA,linA,colA,matrizB,linB,colB,matrizMulti);
    preencherMatrizAleatoria(matrizA,linA,colA);
    preencherMatrizAleatoria(matrizB,linB,colB);

    printf("\n Matriz A :\n");
    imprimirMatriz(matrizA,linA,colA);
    printf("\n Matriz B :\n");
    imprimirMatriz(matrizB,linB,colB);
    printf("\n Matriz Resultado :\n");
    imprimirMatriz(matrizMulti,linA,colB);

    return 0;
    
}
void multiplicarMatrizes(int matrizA[][QTD_COLUNAS], int linA, int colA, int matrizB[QTD_LINHAS][QTD_COLUNAS],int linB, int colB, int matrizMult[QTD_LINHAS][QTD_COLUNAS]){
    if(colA != linB){
        printf("A multiplicação não é possivel\n.");
        return;
    }
    for(int i = 0; i < linA;i++){
        for(int j = 0; j < colB;j++){
            matrizMult[i][j] = 0;
        }
    }
    for(int i = 0; i < linA;i++){
        for(int j = 0; j < colB;j++){
            for(int k = 0; k < colA;k++){
                matrizMult [i][j] += matrizMult[i][k] * matrizMult[k][j];
            }
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
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS],int lin,int col){
    for(int i = 0; i < lin;i++){
        for(int j = 0; j < col;j++){
            mat [i][j] = rand() % 100 +1;
        }
    }
}