#include "carreras.h"
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

carreras::carreras()
{
    //ctor
}

carreras::~carreras()
{
    //dtor
}

void carreras::menu()
{
    int choice;
    char x;
    do

    {
    system("cls");
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t           | Catalogo de Carreras |           "<<endl;
    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t 1. Ingresar nueva Carrera"<<endl;
    cout << "\t\t\t 2. Buscar Carrera"<<endl;
    cout << "\t\t\t 3. Desplegar Carreras"<<endl;
    cout << "\t\t\t 4. Modificar Carrera"<<endl;
    cout << "\t\t\t 5. Borrar Carrera"<<endl;
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
void carreras::insertar()
{
    string id, nombre, idf, estatus;
    system("cls");
    fstream archivo, archivo2;

    cout << "\t\t\t *********************************************"<<endl;
    cout << "\t\t\t               | NUEVA CARRERA |              "<<endl;
    cout << "\t\t\t *********************************************"<<endl;

    cout << "\t\t\t Ingrese ID de la Carrera: ";
    cin >> id;
    cout << "\t\t\t Ingrese Nombre de la Carrera: ";
    cin >> nombre;
    cout << "\t\t\t Ingrese Codigo de la Facultad: ";
    cin >> idf;
    cout << "\t\t\t Ingrese el Estatus de la Carrera: ";
    cin >> estatus;

    archivo.open("carre.dat", ios::binary | ios::app | ios::out);
    archivo2.open("carre2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< idf <<std::left<<std::setw(15)<< estatus <<"\n";

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
         reinterpret_cast<const char*>(&idf),
         sizeof( idf ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&estatus),
         sizeof( estatus ) );
    }
}
void carreras::buscar()
{
    string id, nombre, idf, estatus;
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                | Carreras |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;

	archivo.open("carre.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t\t\t No hay ninguna informacion en el sistema";
		archivo.close();
	}

	else
	{
		string participant_id;
		cout<<"\n\t\t\t Ingrese Id de la carrera que quiere buscar: ";
		cin>>participant_id;
        system("cls");

        archivo >> id >> nombre >> idf >> estatus;
		while(!archivo.eof())
	{
            if(participant_id==id)
		{

            cout << "\t\t\t *********************************************"<<endl;
            cout << "\t\t\t              | Facultades |                  "<<endl;
            cout << "\t\t\t *********************************************"<<endl;
            cout << "\n\t\t\t Id de la Carrera: "<< id << endl;
            cout << "\t\t\t Nombre de la Carrera: "<< nombre <<endl;
            cout << "\t\t\t Id de la Facultad: "<< idf << endl;
            cout << "\t\t\t Estatus de la Carrera: "<< estatus <<endl;

			total++;

		}
		        archivo >> id >> nombre >> idf >> estatus;
	}

		if(total==0)
		{
			cout<<"\n\t\t\t No hay informacion almacenada";
		}
		archivo.close();
	}

}
void carreras::desplegar()
{
    system("cls");
    string id, nombre, idf, estatus;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                | Carreras |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("carre.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> idf >> estatus;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID de la Carrera: "<<id<<endl;
			cout<<"\t\t\t Nombre de la Carrera: "<<nombre<<endl;
			cout<<"\t\t\t ID de la Facultad: "<<idf<<endl;
			cout<<"\t\t\t Estatus de la Carrera: "<<estatus<<endl;

			archivo >> id >> nombre >> idf >> estatus;
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
void carreras::modificar()
{
	system("cls");
	string id, nombre, idf, estatus;
	fstream file,file1;
	string participant_id;
	int found=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t           | MODIFICACION DE CARRERA |        "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	file.open("carre.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la Carrera que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> idf >> estatus;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< idf <<std::left<<std::setw(10)<< estatus <<"\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id de la Carrera: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre de la Carrera: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Id de la Facultad: ";
				cin>>idf;
				cout<<"\t\t\tIngrese el estatus de la Carrera: ";
				cin>>estatus;
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< idf <<std::left<<std::setw(10)<< estatus <<"\n";
				found++;
			}
			file >> id >> nombre >> idf >> estatus;

		}
		file1.close();
		file.close();
		remove("carre.dat");
		rename("registro.dat","carre.dat");
	}
}
void carreras::borrar()
{
    string id, nombre, idf, estatus;
    system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t           | Borrar Carrera |"<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("carre.dat",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Carrera que quiere borrar: ";
		cin>>id_persona;
		file1.open("registro.dat",ios::binary | ios::app | ios::out);
		file >> id >> nombre >> idf >> estatus;
		while(!file.eof())
		{
			if(id_persona!= id)
			{
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< idf <<std::left<<std::setw(10)<< estatus <<"\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> idf >> estatus;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id de la carrera no encontrado...";
		}
		file1.close();
		file.close();
		remove("carre.dat");
		rename("registro.dat","carre.dat");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}

void carreras::informe()
{
    system("cls");
    string id, nombre, idf, estatus;
	fstream archivo;
	int total=0;
	cout << "\t\t\t *********************************************"<<endl;
	cout << "\t\t\t                | Carreras |                  "<<endl;
	cout << "\t\t\t *********************************************"<<endl;
	archivo.open("carre.dat",ios::binary|ios::in);
	if(!archivo)
	{
		cout<<"\n\t\t\tNo hay información...";
		archivo.close();
	}
	else
	{
		archivo >> id >> nombre >> idf >> estatus;
		while(!archivo.eof())
		{
			total++;
			cout<<"\n\t\t\t ID de la Carrera: "<<id<<endl;
			cout<<"\t\t\t Nombre de la Carrera: "<<nombre<<endl;
			cout<<"\t\t\t ID de la Facultad: "<<idf<<endl;
			cout<<"\t\t\t Estatus de la Carrera: "<<estatus<<endl;

			archivo >> id >> nombre >> idf >> estatus;
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
