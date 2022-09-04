//Equipe: Piazada, Alunos: Vinicius Alves Beló, Willian Penteado e Felipe Zorzo

#include <iostream>
#include <list>

using namespace std;

struct Grafo{
    list<int> aresta;
    char torre;
    string color;
};

int DFS_Visit(Grafo vertices[], int n) {
    int contador = 0;
    vertices[n].color = "gray";
    while (vertices[n].aresta.size() > 0) {
        if (vertices[vertices[n].aresta.front()].color == "white") {
            //cout << n << " -> " << vertices[n].aresta.front() << endl;
            contador += DFS_Visit(vertices, vertices[n].aresta.front());
        }
        vertices[n].aresta.pop_front();
    }
    vertices[n].color = "black";
    if(vertices[n].torre == 'B'){
        return contador + 1;
    } else{
        return contador;
    }
}

bool DFS (Grafo vertices[], int tamanho) {
    int somatorio;
    for (int i = 1; i <= tamanho; i++) {
        vertices[i].color = "white";
    }
    for (int i = 1; i <= tamanho; i++) {
        if (vertices[i].color == "white") {
            somatorio = DFS_Visit(vertices, i);
            //cout << somatorio << endl;
            if (somatorio % 2 != 0) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m, a, b;
    char torre;

    while (cin >> n >> m) {
        Grafo vertices[n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> torre;
            vertices[i].color = "white";
            vertices[i].torre = torre;
        }

        for (int i = 1; i <= m; i++) {
            cin >> a;
            cin >> b;
            vertices[a].aresta.push_front(b);
            vertices[b].aresta.push_front(a);
        }

        if (DFS(vertices, n)) {
            cout << 'Y' << endl;
        } else{
            cout << 'N' << endl;
        }
    }
    return 0;
}