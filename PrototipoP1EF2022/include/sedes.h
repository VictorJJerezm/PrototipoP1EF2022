#include <iostream>
#ifndef SEDES_H
#define SEDES_H

using namespace std;

class sedes
{
    public:
        sedes();
        virtual ~sedes();
        void menu();
        void insertar();
        void desplegar();
        void buscar();
        void modificar();
        void borrar();
        void informe();

    protected:

    private:
};

#endif // SEDES_H
