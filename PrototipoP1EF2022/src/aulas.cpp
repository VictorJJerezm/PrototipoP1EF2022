#include "aulas.h"
#include "menus.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

aulas::aulas()
{
    //ctor
}

aulas::~aulas()
{
    //dtor
}

void aulas::menu()
{
    int choice;
    char x;
    do

    {
    system("cls");
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t              | Catalogo de Aulas |           "<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t 1. Ingresar nueva Aula"<<endl;
    cout << "\t\t\t 2. Buscar Aula"<<endl;
    cout << "\t\t\t 3. Desplegar Aulas"<<endl;
    cout << "\t\t\t 4. Modificar Aula"<<endl;
    cout << "\t\t\t 5. Borrar Aula"<<endl;
    cout << "\t\t\t 6. Salir"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Ingresa tu opcion [1/2/3/4/5/6]"<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t Opcion: ";
    cin>>choice;
    menus punto;
    switch(choice)
        {
            case 1:
                insertar();
                break;
            case 2:
                buscar();
                break;
            case 3:
                desplegar();
                break;
            case 4:
                modificar();
                break;
            case 5:
                borrar();
                break;
            case 6:
                punto.catalogos();
                break;
            default:
                cout<<"\n\t\t\t Hubo un error, intentalo nuevamente"<<endl;

        }
        getch();
    }while(choice!= 5);
}
void aulas::insertar()
{
    string id, nombre, estatus;
    system("cls");
    fstream archivo, archivo2;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t                 | NUEVA AULA |              "<<endl;
    cout << "\t\t\t *********************************************"<<endl;

    cout << "\t\t\t Ingrese ID del Aula: ";
    cin >> id;
    cout << "\t\t\t Ingrese Nombre del Aula: ";
    cin >> nombre;
    cout << "\t\t\t Ingrese el Estatus del Aula: ";
    cin >> estatus;

    archivo.open("aula.dat", ios::binary | ios::app | ios::out);
    archivo2.open("aula2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< estatus <<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&id),
         sizeof( id ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&estatus),
         sizeof( estatus ) );
    }
}
void aulas::buscar()
{
    string id, nombre, estatus;
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                  | Aulas |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;

	archivo.open("aula.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\t No hay ninguna informacion en el sistema";
		archivo.close();
	}

	else
	{
		string participant_id;
		cout<<"\n\t\t\t Ingrese Id del aula que quiere buscar: ";
		cin>>participant_id;
        system("cls");

        archivo >> id >> nombre >> estatus;
		while(!archivo.eof())
	{
            if(participant_id==id)
		{

            cout << "\t\t\t *********************************************"<<endl;
            cout << "\t\t\t                  | Aulas |                  "<<endl;
            cout << "\t\t\t *********************************************"<<endl;
            cout << "\n\t\t\t Id del Aula : "<< id << endl;
            cout << "\t\t\t Nombre del Aula: "<< nombre <<endl;
            cout << "\t\t\t Estatus del Aula: "<< estatus <<endl;

			total++;

		}
		        archivo >> id >> nombre >> estatus;
	}

		if(total==0)
		{
			cout<<"\n\t\t\t No hay informacion almacenada";
		}
		archivo.close();
	}

}
void aulas::desplegar()
{
    system("cls");
    string id, nombre, estatus;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                  | Aulas |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("aula.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> estatus;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID del Aula: "<<id<<endl;
			cout<<"\t\t\t Nombre del Aula: "<<nombre<<endl;
			cout<<"\t\t\t Estatus del Aula: "<<estatus<<endl;

			archivo >> id >> nombre >> estatus;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}archivo.close();

	char ctrl;
	cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        menu();
    }
}
void aulas::modificar()
{
	system("cls");
	string id, nombre, estatus;
	fstream file,file1;
	string participant_id;
	int found=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t            | MODIFICACION DE AULAS |        "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	file.open("aula.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del Aula que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> estatus;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< estatus <<"\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id del Aula: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del Aula: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese el estatus del Aula: ";
				cin>>estatus;
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< estatus <<"\n";
				found++;
			}
			file >> id >> nombre >> estatus;

		}
		file1.close();
		file.close();
		remove("aula.dat");
		rename("registro.dat","aula.dat");
	}
}
void aulas::borrar()
{
    string id, nombre, estatus;
    system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t              | Borrar Aulas |"<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("aula.dat",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Aula que quiere borrar: ";
		cin>>id_persona;
		file1.open("registro.dat",ios::binary | ios::app | ios::out);
		file >> id >> nombre >> estatus;
		while(!file.eof())
		{
			if(id_persona!= id)
			{
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< estatus <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> estatus;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Aula no encontrado...";
		}
		file1.close();
		file.close();
		remove("aula.dat");
		rename("registro.dat","aula.dat");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}


void aulas::informe()
{
    system("cls");
    string id, nombre, estatus;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                  | Aulas |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("aula.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> estatus;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID del Aula: "<<id<<endl;
			cout<<"\t\t\t Nombre del Aula: "<<nombre<<endl;
			cout<<"\t\t\t Estatus del Aula: "<<estatus<<endl;

			archivo >> id >> nombre >> estatus;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}archivo.close();

	menus punto;
	char ctrl;
	cout<<"\n\t\t\t Ingresa cualquier caracter para continuar: ";
	cin >>ctrl;
	if(ctrl = 1)
    {
        punto.informes();
    }
}
