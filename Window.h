//
// Created by ashley on 29/2/20.
//

#ifndef T_EXTRACLASE_IS2020_WINDOW_H
#define T_EXTRACLASE_IS2020_WINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "iostream"
#include "Window.h"
#include "Servidor.h"

using namespace std;


class Window : public QGraphicsView{
public:
    Window(QWidget * parent=0);
    QGraphicsScene* scene;
    QLabel *titulo;
    QLineEdit *info;
    void mousePressEvent(QMouseEvent *event);
    QPushButton *enviar;



    ~Window();

    void saveTheText();
};


#endif //T_EXTRACLASE_IS2020_WINDOW_H
