#include <stdio.h> 


//Definir os valores da Matriz
void leMatriz (int mat [][4]) {
int i , j ;
    for ( i = 0; i < 4; i ++) {
        for ( j = 0; j < 4; j ++)
            scanf ("%d", & mat [ i ][ j ]) ;
    }
}

//Exibir
void exibeMatrizOriginal (int mat [][4]) {
    int i , j ;
    for ( i = 0; i < 4; i ++) {
        for ( j = 0; j < 4; j ++)
            printf ("%d\t", mat [i ][ j ]) ;
            printf ("\n");
    }
}

//Somar e mostrar o resultado
 void exibeMatrizResultante (int mat [][4]) {
    int i ,j;
    for ( i = 0; i < 4; i ++) {
        for ( j = 0; j < 4; j ++) {
            if ((( i+ j) % 2 ==0 ))
                printf ("%d\t", mat [i ][ j ]) ;
        }
        printf ("\n");
    }
 }
int main () {
    int matriz [4][4];
    int i , j ;

    leMatriz ( matriz );

    printf (" Imprimindo a matriz original : \n");
        exibeMatrizOriginal ( matriz );

    printf (" Imprimindo a matriz resultante : \n");
        exibeMatrizResultante ( matriz ) ;

    return 0;
}