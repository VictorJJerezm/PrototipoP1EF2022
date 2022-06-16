#include <iostream>
#include <conio.h>
#include <fstream>
#include "login.h"

using namespace std;

int main(int argc, char *argv[])
{
    menus menuG;

    bool accesoUsuarios;
    ingreso usuarioRegistrado;
    accesoUsuarios=usuarioRegistrado.loginUsuarios();
        if (accesoUsuarios){menuG.menuGeneral();}
    system("cls");
    cout<<"\n\t\t\t          ** Hasta la proxima **"<<endl;

   return 0;
}
