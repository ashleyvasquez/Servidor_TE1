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
/**
 * @brief Clase que crea al servidor
 *
 */

class Servidor {
public:
    /**
     * Constructor
     */
    Servidor();
    /**
     * @brief Realiza la coneccion con el cliente
     */
    void run();
    /**
     * @brief envìa el mensaje al cliente
     * @param msn
     */
    void setMensaje(const char *msn);
private:
    int descriptor;
    sockaddr_in info;
    /**
     * @brief crea el socket
     */
    bool crear_Socket();
    /**
     * @brief liga el kernel para la conecciòn
     */
    bool ligar_kernel();
    /**
     * @brief recibe los msjs del cliente
     */
    static void * controladorCliente(void *obj);
    vector<int> clientes;
};


#endif //T_EXTRACLASE_IS2020_SERVIDOR_H
