#include <iostream>
#include <queue>

using namespace std;

void Make_Set (int *A, int i) {
    A[i] = i;
}

int MST_Kruskal (priority_queue<pair<int, pair<int, int>>> aresta) {
    int contador = 0, aux, A[1000] = {};
    for (int i = 0; i < 1000; i++) {
        Make_Set(A, i);
    }

    while (!aresta.empty()) {
        if (A[aresta.top().second.first] != A[aresta.top().second.second]) {
            contador += aresta.top().first;
            aux = A[aresta.top().second.first];
            A[aresta.top().second.first] = A[aresta.top().second.second];
            for (int j = 0; j < 1000; j++) {
                if (A[j] == aux) {
                    A[j] = aresta.top().second.second;
                }
            }
        }
        aresta.pop();
    }
    return contador;
}

int main () {
    int n, u, v, w, contador = 0;
    
    priority_queue<pair<int, pair<int, int>>> caminhoMinimo;
    priority_queue<pair<int, pair<int, int>>> caminhoMaximo;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        caminhoMinimo.push(make_pair(w, make_pair(u, v)));
        caminhoMaximo.push(make_pair(w * -1, make_pair(u, v)));
    }

    contador = MST_Kruskal(caminhoMinimo);
    cout << contador << endl;

    contador = MST_Kruskal(caminhoMaximo);
    cout << contador * -1 << endl;

    return 0;
}