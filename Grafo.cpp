//
// Created by ashley on 22/2/20.
//

#include "Grafo.h"


Grafo::Grafo () {		// Con CADENA + 1 podemos realmente almacenar el numero de caracteres que definimos en la constante, caracter nulo al final


    int i, j;
    int c;
    int z;
    m = new int;
    n = new int;
    *m=0;
    ElementoLista pos1,pos2;
    ifstream textfile;

    textfile.open ("graph");

    if (textfile.is_open ()) {

        textfile >> (int &) *n  ;
        LS.resize (*n);


        for (i = 0; i < *n; i++ ) {
            ady.push_back( vector<int>() );
            for (j = 0; j < *n; j++ )
            {
                textfile >> (int &) c ;
                ady[i].push_back (c);
            }
        }


        textfile.close ();


        for(int ind=0; ind<*n; ind++) {
            z = rand() % 100 + 10;
            longitud.push_back((int) z);
        }

        for(i=0;i<*n;i++)
            for(j=0;j<*n;j++)
            {
                if(ady.at(i).at(j) == 1 && j>i)
                {
                    cout << i+1 << " " << j+1 << "\n";
                    pos1.nodo = j;
                    pos1.peso = longitud.at(i);
                    pos1.residuo = longitud.at(i);
                    pos1.inv = LS[j].size();
                    LS[i].push_back (pos1);				//leo fila (i,j)  si (1,2) -> guardo (0,1)
                    pos2.nodo = i;
                    // Incializa los campos del arco virtual y capacidad residual a 0
                    pos2.peso = 0;
                    pos2.residuo = 0;
                    pos2.inv = LS[i].size() - 1;
                    LS[j].push_back(pos2);
                    *m++;
                }

            }
    }
    else
    {
        cout << "\nNo se encuentra el fichero.\n";
        exit(1);
    }
};

void Grafo::dfs (int i, vector<bool> &visitado)
{

    visitado[i] = true;
    cout << i + 1 << ",";
    for (int k = 0; k < LS[i].size(); k++) {

        if (visitado[LS[i][k].nodo] == false)							//  para todo nodo j en LS[i] no visitado
            dfs (LS[i][k].nodo, visitado);
    }

};

Grafo::~Grafo () {}		// Destructor



void Grafo::Dijkstra()
{

    vector<bool> PermanentementeEtiquetado; 			// == Su camino minimo ya ha sido calculado
    vector<int> d;												// vector de coste
    vector<int> pred;
    int s, candidato, minimo = maxint, aux = 0;
    int p;


    PermanentementeEtiquetado.resize (*n, false);				// etiquetados a false
    d.resize (*n, maxint);										// d es la etiqueta de distancia		(n) 		maxint = infinito
    pred.resize (*n, UERROR);									// Los predecesores son unicos, por lo que puedo usar un array


    cout << endl;
    cout << " - Introduzca el nodo de partida [1-" << *n << "]: ";
    cin >> s;
    cout << endl;

    cout << endl;
    cout << " - Introduzca el nodo final [1-" << *n << "]: ";
    cin >> p;
    cout << endl;

   s--;
   d[s]= 0;				// coste para llegar a el desde el = 0
   pred[s]= s;             //pred del nodo elegido (i) = i



    do {

        candidato = UERROR;

        while ((candidato == UERROR) && (aux < *n)) {
            if (PermanentementeEtiquetado[aux] == false)
                candidato = aux;
            else
                aux++;
        }		//Sea candidato el nodo no etiquetado permanentemente con menor etiqueta distancia;


        if (candidato != UERROR) {					// si me encuentro un nodo con una etiqueta no infinita

            minimo = d[candidato];

            for (unsigned j = 0; j < *n; j++) {

                if (d[j] < minimo) {
                    if (PermanentementeEtiquetado[j] == false) {

                        minimo = d[j];
                        candidato = j;
                    }
                }
            }

            PermanentementeEtiquetado[candidato] = true;

            for (int k = 0; k < LS[candidato].size (); k++) {		// para todo nodo k en LS[candidato]

                if (d[LS[candidato][k].nodo] > d[candidato] + LS[candidato][k].peso) {		// d[LS[candidato][k].j]			LS[candidato][k].c
                    d[LS[candidato][k].nodo] = d[candidato] + LS[candidato][k].peso;
                    pred[LS[candidato][k].nodo] = candidato;
                }
            }
        }
    } while (candidato != UERROR);
   // for (int i = 0; i < n; i++) {                // Para todo nodo i!= s
        int f = p-1;
        if ((f) != s) {
            if (pred[f] != UERROR) {
                MostrarCamino(s, f, pred, d);
            } else
                cout << " * No hay Camino desde " << s + 1 << " al nodo " << f + 1 << endl;
        }
   // }
}

void Grafo::MostrarCamino (int s, int f, vector <int> &pred) {

    if (f != s) {
        MostrarCamino (s, pred[f], pred);
    }
    cout << f+1 << " <- ";
}

void Grafo::MostrarCamino (int s, int i, vector<int> &pred, vector<int> &d) {

    int q = d[i];
    cout << " - El camino desde " << s + 1 << " al nodo " << i+1 << " es: " << i+1;

    do {
        cout << " <- " << pred[i] + 1;
        i = pred[i];
    } while (pred[i] != i);

    cout << " de longitud " << q << endl;
}