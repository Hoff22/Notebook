#include <bits/stdc++.h>

#define N 100000

using namespace std;

vector<int> g[N];
bool seen[N];
int dist[N];

void bfs(int root, int target){
    queue<int> fila;
// inicia o primeiro da fila (distancia 0) //
// Se eu quiser por mais de um 0 aqui eu posso e os nós
// tem valores relativos com o mais proximo //
    seen[root] = true;
    dist[root] = 0;
    fila.push(root);
// loop dos proximos na sequencia de profundidade//
    while(!fila.empty()){

        int atual = fila.front();
        fila.pop();
            
        for(int next : g[atual]){
            if(!seen[next]){
                seen[next] = true;
                dist[next] = dist[atual] + 1;
                fila.push(next);     
            }
        }
    }
    /* no fim do while loop o array de dist vai estar populado
    com dist[nodeIndex] = distanceFromRoot
    */
}