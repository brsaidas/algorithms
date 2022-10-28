#include <stdio.h>

#define MAX 10

int dispo = 0;
int listaEstSeq[MAX];

typedef enum{false, true} bool;

int primeiroListaEstSeq(){
    if(dispo == 0){
        return -1;
    }else{
        return listaEstSeq[0];
    }
}

int ultimoListaEstSeq(){
    if(dispo == 0){
        return -1;
    }else{
        return listaEstSeq[dispo-1];
    }
}

int quantidadeListaEstSeq(){
    return dispo;
}

bool insereListaEstSeq(int valor){
    int i = dispo;
    if(i >= MAX){
        return false;
    }else{
        while((i > 0) && (listaEstSeq[i-1] > valor)){
            listaEstSeq[i] = listaEstSeq[i-1];
            i--;
        }
        listaEstSeq[i] = valor;
        dispo++;
        return true;
    }
}

bool removeListaEstSeq(int valor){
    int i = 0;
    while((i < dispo) && (listaEstSeq[i] < valor)){
        i++;
    }
    if((i < dispo) && (listaEstSeq[i] == valor)){
        while(i < dispo){
            listaEstSeq[i] = listaEstSeq[i+1];
            i++;
        }
        dispo--;
        return true;
    }else{
        return false;
    }
}

int pesqSeqListaEstSeq(int chave){
    int i = 0;
    while((i < dispo) && (listaEstSeq[i] < chave)){
        i++;
    }

    if((i < dispo) && (listaEstSeq[i] == chave)){
        return i;
    }else{
        return -1;
    }
}

void imprimeListaEstSeq(void){
    printf(" 0  1  2  3  4  5  6  7  8  9\n");
    for(int i = 0; i < MAX; i++){
        printf("[%d]", listaEstSeq[i]);
    }
    printf("\n");
}

int pesqBinListaEstSeq(int chave){
    int meio, inf = 0, sup = dispo-1;

    while(inf <= sup){
        meio = (inf + sup)/2;

        if(listaEstSeq[meio] == chave){
            return meio;
        }else if(listaEstSeq[meio] > chave){
            sup = meio-1;
        }else{
            inf = meio+1;
        }
    }

    return -1;
}

int main(int argc, char *argv[]){
    int op, aux;
    bool sair = false, status;

    for(int i = 0; i < MAX; i++){
        listaEstSeq[i] = 0;
    }

    do{
        system("cls");

        printf("(1) - PRIMEIRO ELEMENTO\n");
        printf("(2) - ULTIMO ELEMENTO\n");
        printf("(3) - QUANTIDADE DE ELEMENTOS\n");
        printf("(4) - INSERE ELEMENTO\n");
        printf("(5) - REMOVE ELEMENTO\n");
        printf("(6) - IMPRIME LISTA\n");
        printf("(7) - PESQUISA SEQUENCIAL\n");
        printf("(8) - BUSCA BINARIA\n");
        printf("(9) - SAIR\n");

        printf("OPICAO: ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                aux = primeiroListaEstSeq();
                if(aux != -1){
                    printf("Primeiro elemento: %d\n", aux);
                }else{
                    printf("A lista esta vazia\n");
                }
                break;
            case 2:
                aux = ultimoListaEstSeq();
                if(aux != -1){
                    printf("Ultimo elemento: %d\n", aux);
                }else{
                    printf("A lista esta vazia\n");
                }
                break;
            case 3:
                aux = quantidadeListaEstSeq();
                printf("Quantidade de elementos: %d\n", aux);
                break;
            case 4:
                printf("Valor: ");
                scanf("%d", &aux);
                getchar();

                if((pesqSeqListaEstSeq(aux) == -1) && (aux > 0)){
                    status = insereListaEstSeq(aux);

                    if(status == true){
                        printf("Elemento inserido com sucesso\n");
                    }else{
                        printf("Falha ao inserir elemento\n");
                    }
                }else{
                    printf("Elemento nao pode ser inserido na lista\n");
                }
                break;
            case 5:
                printf("Valor: ");
                scanf("%d", &aux);
                getchar();

                if(pesqSeqListaEstSeq(aux) == -1){
                    printf("Elemento nao exite\n");
                }else{
                    status = removeListaEstSeq(aux);

                    if(status == true){
                        printf("Elemento removido com sucesso\n");
                    }else{
                        printf("Falha ao remover elemento\n");
                    }
                }
                break;
            case 6:
                imprimeListaEstSeq();
                break;
            case 7:
                printf("Chave: ");
                scanf("%d", &aux);
                getchar();

                aux = pesqSeqListaEstSeq(aux);

                if(aux == -1){
                    printf("Elemento nao esta na lista\n");
                }else{
                    printf("Elemento encontrado na posicao %d\n", aux);
                }
                break;
            case 8:
                printf("Chave: ");
                scanf("%d", &aux);
                getchar();

                aux = pesqBinListaEstSeq(aux);

                if(aux == -1){
                    printf("Elemento nao esta na lista\n");
                }else{
                    printf("Elemento encontrado na posicao %d\n", aux);
                }
                break;
            default:
                sair = true;
                break;
        }

        if(sair == false){
            printf("\n");
            system("pause");
        }

    }while(sair == false);

    return 0;
}
