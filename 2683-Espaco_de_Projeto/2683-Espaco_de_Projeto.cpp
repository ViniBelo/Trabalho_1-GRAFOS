//Equipe: Piazada, Alunos: Vinicius Alves Beló, Willian Penteado e Felipe Zorzo

#include <iostream>
#include <queue>

using namespace std;

void Make_Set (int *A, int i) {
    A[i] = i;
}

int MST_Kruskal (priority_queue<pair<int, pair<int, int>>> aresta) {
    int contador = 0, aux, A[1000];
    for (int i = 0; i < 1000; i++) {
        Make_Set(A, i);
    }

    while (!aresta.empty()) {
        if (A[aresta.top().second.first] != A[aresta.top().second.second]) {
            contador += aresta.top().first;
            aux = A[aresta.top().second.first];
            A[aresta.top().second.first] = A[aresta.top().second.second];
            for (int i = 0; i < 1000; i++) {
                if (A[i] == aux) {
                    A[i] = A[aresta.top().second.second];
                }
            }
        }
        aresta.pop();
    }
    return contador;
}

main () {
    int n, u, v, w, contador = 0;
    
    priority_queue<pair<int, pair<int, int>>> caminhoMaximo;
    priority_queue<pair<int, pair<int, int>>> caminhoMinimo;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        caminhoMaximo.push(make_pair(w, make_pair(u, v)));
        caminhoMinimo.push(make_pair(w * -1, make_pair(u, v)));
    }

    contador = MST_Kruskal(caminhoMaximo);
    cout << contador << endl;

    contador = MST_Kruskal(caminhoMinimo);
    cout << contador * -1 << endl;
}