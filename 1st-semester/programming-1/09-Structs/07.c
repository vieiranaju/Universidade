#include <stdio.h>

struct produtos {

	int ID;
	char descricao[50];
    float preco;
    int quantItem;

};

int verifica(int id, struct produtos *C, int n){
   
    for (int i = 0; i < n; i++){
        if(id == C[i].ID){
            return 1;
            break;
        }
    }

    return 0;

}

void compra(struct produtos *C, int quant, int n, int id, float *pagar, int *quantidade){
    for (int i = 0; i < n; i++){
        if(id == C[i].ID){
            *quantidade += quant;
            *pagar += quant * C[i].preco;
            C[i].quantItem += quant;
            break;
        }
    }
}




int main(){

    int n, id, quant, quantidade = 0;
    float pagar;
    
    printf("\nQuantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    struct produtos C[n];

    for (int i = 0; i < n; i++) {
        printf("\n============ Produto %d ============", i + 1);

        printf("\n-> Insira o codigo de itentificacao:\n");  
        scanf("%d", &C[i].ID);

        setbuf(stdin, NULL);
        printf("\n-> Insira a descricao: \n");
        fgets(C[i].descricao, 50, stdin);

        printf("\n-> Insira o preco:\n");  
        scanf("%f", &C[i].preco);

        C[i].quantItem = 0;

        }


    
     printf("\nFaca seu pedido !\n");

    do {
        printf("\n__________________________________");
        printf("\nInsira o ID do produto: ");
        scanf("%d", &id);

        if (verifica(id, C, n) == 1) {

            printf("\nInsira a quantidade: ");
            scanf("%d", &quant);

            if (quant > 0) {
                
                    compra(C, quant, n, id, &pagar, &quantidade);

            } 

            else { 

                printf("Quantidade invalida !"); 

            }
        } 

            else {
                printf("Produto invalido !");
            }

    } while (id != 0);
	
	printf("\nO valor total da compra foi %.1f e a quantia total de produtos foi %d!", pagar, quantidade);
    printf("\nA quantidade por produto foi: ");

    for (int i = 0; i < n; i++){
        printf("\nProduto de ID %d: %d", C[i].ID, C[i].quantItem);
    }

return 0;
}