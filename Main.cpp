#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <typeinfo>
#include <string>
#include <fstream>
#include <sqlite3.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	sqlite3 *conn;
	sqlite3_stmt *res;
	int error=0;
	int rec_count =0;
	const char *tail;
	while(true){
		int opcion;
		cout<<"1- Listar\n2- Agregar\n3- Eliminar\n4- Listar Jefe y Empleado\n5- Listar Salarb\n6- Empleados de departamento\n7- Salir\nIngrese opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1:{
				
				break;
			}
			case 2:{
				
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
			case 6:{
				
				break;
			}
			case 7:{
				exit(0);
				break;
			}
		}
	}
	system("pause");
	return 0;
}
