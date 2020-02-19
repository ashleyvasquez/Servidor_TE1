//
// Created by ashley on 18/2/20.
//

#ifndef T_EXTRACLASE_IS2020_SERVIDOR_H
#define T_EXTRACLASE_IS2020_SERVIDOR_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>


using namespace std;

struct dataSocket{
    int descriptor;
    sockaddr_in info;
};
class Servidor {
public:
    Servidor();
    void run();
    void setMensaje(const char *msn);
private:
    int descriptor;
    sockaddr_in info;
    bool crear_Socket();
    bool ligar_kernel();
    static void * controladorCliente(void *obj);
    vector<int> clientes;
};


#endif //T_EXTRACLASE_IS2020_SERVIDOR_H
