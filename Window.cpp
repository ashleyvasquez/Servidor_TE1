//
// Created by ashley on 29/2/20.
//
#include <QtWidgets/QMessageBox>

#include "Window.h"

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


Window::Window(QWidget *parent) {


    // create the scene
    scene = new QGraphicsScene();
    setScene(scene);
    setFixedSize(900,600);
    scene->setBackgroundBrush(QColor(72,37,37));

    server = new Servidor;
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);


    titulo=new QLabel(this);
    titulo->setGeometry(400,20,300,100);
    titulo->setText("Grafo-Dijkstra");
    titulo->font();

    enviar = new QPushButton(this);
    enviar->setGeometry(700,400,100,50);
    enviar->setText("Enviar");
    connect(enviar ,&QPushButton::clicked, this, &Window::saveTheText);

    info=new QLineEdit(this);
    info->setGeometry(250,380,400,100);
}

void Window::mousePressEvent(QMouseEvent *event) {
    QGraphicsView::mousePressEvent(event);
}

void Window::saveTheText()
{

    QString text = info->text();
    string textStd = text.toStdString();
    server->setMensaje(textStd.c_str());

}

Window::~Window() {

}