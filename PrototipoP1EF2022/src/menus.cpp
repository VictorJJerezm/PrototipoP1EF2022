#include "menus.h"
#include "Facultad.h"
#include "carreras.h"
#include "cursos.h"
#include "aulas.h"
#include "sedes.h"
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
		informes();
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
        cout << "\t\t\t  5. Catalogo de Sedes"<<endl;
        cout << "\t\t\t  6. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: ";
        cin>>choice;

        Facultad entrada;
        carreras ingreso;
        cursos persona;
        aulas espacio;
        sedes lugar;

        switch(choice)
        {
    case 1:
    	entrada.menu();
		break;
    case 2:
		ingreso.menu();
		break;
	case 3:
		persona.menu();
		break;
	case 4:
		espacio.menu();
		break;
	case 5:
		lugar.menu();
		break;
	case 6:
		menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 7);

}

void menus::informes(){
    int choice;
    char s;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t                 | Informes |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Informes de Facultad"<<endl;
        cout << "\t\t\t  2. Informes de Carreras"<<endl;
        cout << "\t\t\t  3. Informes de Cursos"<<endl;
        cout << "\t\t\t  4. Informes de Aulas"<<endl;
        cout << "\t\t\t  5. Informes de Sedes"<<endl;
        cout << "\t\t\t  6. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: ";
        cin>>choice;

        Facultad entrada;
        carreras ingreso;
        cursos persona;
        aulas espacio;
        sedes lugar;

        switch(choice)
        {
    case 1:
    	entrada.informe();
		break;
    case 2:
		ingreso.informe();
		break;
	case 3:
		persona.informe();
		break;
	case 4:
		espacio.informe();
		break;
	case 5:
		lugar.informe();
		break;
	case 6:
		menuGeneral();
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
    }while(choice!= 7);

}
