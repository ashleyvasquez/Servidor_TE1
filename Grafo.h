//
// Created by ashley on 22/2/20.
//

#ifndef T_EXTRACLASE_IS2020_GRAFO_H
#define T_EXTRACLASE_IS2020_GRAFO_H
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const int UERROR = 65000;
const int maxint = 1000000;

typedef struct
{
    int nodo; // nodo
    int peso; // peso, longitud, etc...
    int residuo;                    // capacidad residual del arco
    int  inv;                  // nos idica la posicion del arco (j,i) en LS[j]
}
ElementoLista;

typedef vector<ElementoLista> LA_nodo;


class Grafo {

    int dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
    int *n;         /* numero de NODOS */
    int *m;         /* numero de ARCOS */


    vector<LA_nodo> LS;
    vector<vector<int> > ady;
    vector<int> longitud;
public:
    /**
     * Crea el grafo a partir de una matriz binaria
     */
    Grafo();
    /**
     * @brief verifica los nodos que han sido visitados
     */
    void dfs(int i, vector<bool> &visitado);
    /**
     * Recorre el camino y arma la respuesta con ->
     */
    void MostrarCamino(int s, int i, vector<int> &pred);
    void MostrarCamino(int s, int i, vector<int> &pred, vector<int> &d);
    /**
     * Busca el caino mas corto o con menos longitud de un nodo a otro.
     */
    void Dijkstra();

    ~Grafo();  //destructor

};

#endif //T_EXTRACLASE_IS2020_GRAFO_H
