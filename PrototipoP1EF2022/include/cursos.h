#include <iostream>
#ifndef CURSOS_H
#define CURSOS_H

using namespace std;

class cursos
{
    public:
        cursos();
        virtual ~cursos();
        void menu();
        void insertar();
        void desplegar();
        void buscar();
        void modificar();
        void borrar();

    protected:

    private:
};

#endif // CURSOS_H
