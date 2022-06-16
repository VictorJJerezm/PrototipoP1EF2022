#include <iostream>
#ifndef AULAS_H
#define AULAS_H

using namespace std;

class aulas
{
    public:
        aulas();
        virtual ~aulas();
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

#endif // AULAS_H
