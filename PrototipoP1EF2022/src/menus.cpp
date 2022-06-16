#include "menus.h"
#include "Facultad.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

menus::menus()
{
    //ctor
}

menus::~menus()
{
    //dtor
}
void menus::menuGeneral(){
    system("cls");
    int choice;
	//char x;
	do
    {
	system("cls");
	cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t | Menu General - Victor Jerez / 9959-21-2081 |"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t  1. Catalogos"<<endl;
    cout << "\t\t\t  2. Informes"<<endl;
    cout << "\t\t\t  3. Salir"<<endl;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion a escoger : [1/2/3]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Selecciona tu opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	/*do
    	{*/
    		catalogos();
    		/*cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');*/
		break;
	case 2:
		//genera.menuprincipalgeneracionnomina();
		break;
    case 3:
	    exit(0);
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 7);
}
void menus::catalogos(){
    int choice;
    char s;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t                 | Catalogos |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Catalogo de Facultad"<<endl;
        cout << "\t\t\t  2. Catalogo de Carreras"<<endl;
        cout << "\t\t\t  3. Catalogo de Cursos"<<endl;
        cout << "\t\t\t  4. Catalogo de Aulas"<<endl;
        cout << "\t\t\t  5. Catalodo de Sedes"<<endl;
        cout << "\t\t\t  6. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: ";
        cin>>choice;

        Facultad entrada;

        switch(choice)
        {
    case 1:
    	entrada.menu();
		break;
    case 2:
		//po.menu();
		break;
	case 3:
		//coma.menu2();
		break;
	case 4:
		//punto.escribirOpcion();
		break;
	case 5:
		//mar.menu();
		break;
	case 6:
		menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 7);

}
