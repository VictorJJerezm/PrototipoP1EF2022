#include <iostream>
#ifndef FACULTAD_H
#define FACULTAD_H

using namespace std;

class Facultad
{
    public:
        Facultad();
        virtual ~Facultad();
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

#endif // FACULTAD_H
