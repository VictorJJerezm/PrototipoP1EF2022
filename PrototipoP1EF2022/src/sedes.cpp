#include "sedes.h"
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


sedes::sedes()
{
    //ctor
}

sedes::~sedes()
{
    //dtor
}

void sedes::menu()
{
    int choice;
    char x;
    do

    {
    system("cls");
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t              | Catalogo de Sedes |           "<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t 1. Ingresar nueva Sede"<<endl;
    cout << "\t\t\t 2. Buscar Sede"<<endl;
    cout << "\t\t\t 3. Desplegar Sedes"<<endl;
    cout << "\t\t\t 4. Modificar Sede"<<endl;
    cout << "\t\t\t 5. Borrar Sede"<<endl;
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
void sedes::insertar()
{
    string id, nombre, estatus;
    system("cls");
    fstream archivo, archivo2;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t                 | NUEVA SEDE |              "<<endl;
    cout << "\t\t\t *********************************************"<<endl;

    cout << "\t\t\t Ingrese ID de la Sede ";
    cin >> id;
    cout << "\t\t\t Ingrese Nombre de la Sede: ";
    cin >> nombre;
    cout << "\t\t\t Ingrese el Estatus de la Sede: ";
    cin >> estatus;

    archivo.open("sede.dat", ios::binary | ios::app | ios::out);
    archivo2.open("sede2.dat", ios::binary | ios::app | ios::out);


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
void sedes::buscar()
{
    string id, nombre, estatus;
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                  | Sedes |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;

	archivo.open("sede.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\t No hay ninguna informacion en el sistema";
		archivo.close();
	}

	else
	{
		string participant_id;
		cout<<"\n\t\t\t Ingrese Id de la sede que quiere buscar: ";
		cin>>participant_id;
        system("cls");

        archivo >> id >> nombre >> estatus;
		while(!archivo.eof())
	{
            if(participant_id==id)
		{

            cout << "\t\t\t *********************************************"<<endl;
            cout << "\t\t\t                  | Sedes |                  "<<endl;
            cout << "\t\t\t *********************************************"<<endl;
            cout << "\n\t\t\t Id de la Sede : "<< id << endl;
            cout << "\t\t\t Nombre de la Sede: "<< nombre <<endl;
            cout << "\t\t\t Estatus de la Sede: "<< estatus <<endl;

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
void sedes::desplegar()
{
    system("cls");
    string id, nombre, estatus;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                   | Sedes |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("sede.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay informaci???n...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> estatus;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID de la Sede: "<<id<<endl;
			cout<<"\t\t\t Nombre de la Sede: "<<nombre<<endl;
			cout<<"\t\t\t Estatus de la Sede: "<<estatus<<endl;

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
void sedes::modificar()
{
	system("cls");
	string id, nombre, estatus;
	fstream file,file1;
	string participant_id;
	int found=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t            | MODIFICACION DE SEDES |        "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	file.open("sede.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la Sede que quiere modificar: ";
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
				cout<<"\t\t\tIngrese Id de la Sede: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre de la Sede: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese el estatus de la Sede: ";
				cin>>estatus;
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< estatus <<"\n";
				found++;
			}
			file >> id >> nombre >> estatus;

		}
		file1.close();
		file.close();
		remove("sede.dat");
		rename("registro.dat","sede.dat");
	}
}
void sedes::borrar()
{
    string id, nombre, estatus;
    system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t              | Borrar Sede |"<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("sede.dat",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Sede que quiere borrar: ";
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
			cout<<"\n\t\t\t Id de la sede no encontrado...";
		}
		file1.close();
		file.close();
		remove("sede.dat");
		rename("registro.dat","sede.dat");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}



void sedes::informe()
{
    system("cls");
    string id, nombre, estatus;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                   | Sedes |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("sede.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay informaci???n...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> estatus;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID de la Sede: "<<id<<endl;
			cout<<"\t\t\t Nombre de la Sede: "<<nombre<<endl;
			cout<<"\t\t\t Estatus de la Sede: "<<estatus<<endl;

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

