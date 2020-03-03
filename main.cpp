#include <iostream>
#include <QApplication>
#include "Servidor.h"
#include "Grafo.h"

using namespace std;
Servidor *server;

void * serverRun(void *)
{
    try{
        server->run();
    }catch(string ex)
    {
        cout << ex;
    }

    pthread_exit(NULL);
}

    int main(int argc, char *argv[]) {

        server = new Servidor;
        pthread_t hiloServer;
        pthread_create(&hiloServer,0,serverRun,NULL);
        pthread_detach(hiloServer);


        while (1) {
            server->setMensaje(" - Introduzca el nodo de partida - ");
            string mensaje;
            cin >> mensaje;

        }

        delete server;
        return 0;
       // Grafo Ografo;
        //Ografo.Dijkstra();


    }
