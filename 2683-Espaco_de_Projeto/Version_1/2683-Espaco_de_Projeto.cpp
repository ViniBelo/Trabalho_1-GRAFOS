#include <iostream>
#include <list>

using namespace std;

struct Grafo{
    list<int> aresta;
    int custo;
};

void Make_Set(Grafo verticesA[], int i){
    verticesA[i].aresta.push_front(i);
    verticesA[i].custo = -1;
}

bool Find_Set(Grafo verticesA[], int primeiroValor, int segundoValor) {
    bool primeiraChecagem = false, segundaChecagem = false;
    for (int i = 0; verticesA + 1; i++) {
        if (verticesA[i].aresta.front() == primeiroValor) {
            primeiraChecagem = true;
        }
        if (verticesA[i].aresta.front() == segundoValor) {
            segundaChecagem = true;
        }
    }
    if (primeiraChecagem && segundaChecagem) {
        return true;
    } else {
        return false;
    }
}

Grafo MST_Kruskal (Grafo vertices[], int galerias) {
    Grafo verticesA[galerias + 1];
    Grafo auxiliar[galerias + 1];
    int indiceSalvo;
    for (int i = 0; i < galerias; i++) {
        Make_Set(verticesA, i);
        cout << " verticesA: " << verticesA[i].aresta.front();
    }
    for (int i = 0; i < galerias; i++) {
        for (int j = 0; j < galerias; j++) {
            if (vertices[j].custo < auxiliar[i].custo) {
                indiceSalvo = j;
                cout << "Indice salvo: " << indiceSalvo;
            }
            auxiliar[i] = vertices[indiceSalvo];
            if (!Find_Set(verticesA, auxiliar[i].aresta.front(), auxiliar[i + 1].aresta.front())) {
                auxiliar[i].aresta.push_front(i + 1);
                auxiliar[i + 1].aresta.push_front(i);
            }
        }
    }
    for (int i = 0; i < galerias; i++) {
        cout << "AUXILIAR: " << auxiliar[i].aresta.front();
    }
}

main(){
    int galerias, entrada, saida, custo;

    cin >> galerias;

    Grafo vertices[galerias + 1];

    for (int i = 0; i < galerias; i++) {
        cin >> entrada >> saida >> custo;
        
        vertices[entrada].aresta.push_front(saida);
        vertices[saida].aresta.push_front(entrada);
        vertices[i].custo = custo;
    }
    MST_Kruskal(vertices, galerias);
}