#include <iostream>
#ifndef CARRERAS_H
#define CARRERAS_H

using namespace std;

class carreras
{
    public:
        carreras();
        virtual ~carreras();
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

#endif // CARRERAS_H
