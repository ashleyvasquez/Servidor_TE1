#include <iostream>
#include <QApplication>
#include "Servidor.h"
#include "Grafo.h"
#include "Window.h"

using namespace std;
Window * window;


    int main(int argc, char *argv[]) {

        QApplication a(argc, argv);
        window = new Window();
        window->show();

       // Grafo Ografo;
        //Ografo.Dijkstra();


        return a.exec();
    }
