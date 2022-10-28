#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct{
    int x, y;
} Ponto;

Ponto Aux, P, Q, A;
vector<Ponto> Casca;
vector<Ponto> Conjunto;
int N, X, Y, Virada, Contador;

bool Compara(Ponto a, Ponto b){
    if(a.x < b.x){
        return true;
    }else{
        return false;
    }
}

void ConvexHull(){
    P.x = Conjunto[0].x;
    P.y = Conjunto[0].y;

    Casca.push_back(P);

    Conjunto.push_back(P);
    Conjunto.erase(Conjunto.begin() + 0);

    while(true){
        Q.x = Conjunto[0].x;
        Q.y = Conjunto[0].y;

        vector<Ponto>::iterator Indice = Conjunto.begin();

        for(vector<Ponto>::iterator it = Conjunto.begin(); it != Conjunto.end(); it++){
            A.x = it->x;
            A.y = it->y;

            if(A.x != Q.x || A.y != Q.y){
                Virada = (A.x - P.x)*(Q.y - P.y) - (Q.x - P.x)*(A.y - P.y);

                if(Virada < 0){
                    Q.x = A.x;
                    Q.y = A.y;
                    Indice = it;
                }
            }
        }

        if(Q.x == Casca[0].x && Q.y == Casca[0].y){
            Conjunto.erase(Indice);

            break;
        }

        Casca.push_back(Q);

        Conjunto.erase(Indice);

        P.x = Q.x;
        P.y = Q.y;
    }
}

int main(){
    while(true){
        scanf("%d", &N);

        if(N == 0){
            break;
        }

        for(int i = 0; i < N; i++){
            scanf("%d%d", &X, &Y);

            Aux.x = X;
            Aux.y = Y;

            Conjunto.push_back(Aux);
        }

        sort(Conjunto.begin(), Conjunto.end(), Compara);

        Contador = 0;

        while(!Conjunto.empty()){
            Contador++;

            ConvexHull();

            Casca.clear();
        }

        if(Contador % 2 == 0){
            printf("menina");
        }else{
            printf("menino");
        }
        printf("\n");
    }

    return 0;
}
