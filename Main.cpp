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
				int opcion2;
				cout<<"1- Departamento\n2- Empleado\nOpcion: ";
				cin>>opcion2;
				switch(opcion2){
					case 1:{
						//listar		
						error=sqlite3_open("oracle-sample.db",&conn);
						error=sqlite3_prepare_v2(conn,"select * from dept",1000,&res,&tail);
						while(sqlite3_step(res) == SQLITE_ROW){
							cout<<"Deptno: "<<sqlite3_column_text(res,0)<<endl;
							cout<<"Dname: "<<sqlite3_column_text(res,1)<<endl;
							cout<<"Loc: "<<sqlite3_column_text(res,2)<<endl<<endl<<endl;
						}	
						sqlite3_close(conn);
						break;
					}
					case 2:{
						//listar		
						error=sqlite3_open("oracle-sample.db",&conn);
						error=sqlite3_prepare_v2(conn,"select * from emp",1000,&res,&tail);
						while(sqlite3_step(res) == SQLITE_ROW){
							cout<<"Empno: "<<sqlite3_column_text(res,0)<<endl;
							cout<<"Ename: "<<sqlite3_column_text(res,1)<<endl;
							cout<<"Job: "<<sqlite3_column_text(res,2)<<endl;
							cout<<"Mgr: "<<sqlite3_column_text(res,3)<<endl;
							cout<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl;
							cout<<"Sal: "<<sqlite3_column_text(res,5)<<endl;
							cout<<"Comm: "<<sqlite3_column_text(res,6)<<endl;
							cout<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl<<endl;
						}	
						sqlite3_close(conn);
						break;
					}
				}
				break;
			}
			case 2:{
				int opcion3;
				cout<<"1- Empleados\n2- Departamentos\nOpcion: ";
				cin>>opcion3;
				switch(opcion3){
					case 1:{
						//agregar
						string empno, ename, job, mgr, hiredate, sal, comm, deptno;
						cout<<"Ingrese empno: ";
						cin>>empno;
						cout<<"Ingrese ename: ";
						cin>>ename;
						cout<<"Ingrese job: ";
						cin>>job;
						cout<<"Ingrese mgr: ";
						cin>>mgr;
						cout<<"Ingrese hiredate: ";
						cin>>hiredate;
						cout<<"Ingrese sal: ";
						cin>>sal;
						cout<<"Ingrese comm: ";
						cin>>comm;
						cout<<"Ingrese deptno: ";
						cin>>deptno;
						string x = "insert into emp values('"+empno+"','"+ename+"','"+job+"','"+mgr+"','"+hiredate+"','"+sal+"','"+comm+"','"+deptno+"')";
						error=sqlite3_open("oracle-sample.db",&conn);
						error=sqlite3_exec(conn,
						x.c_str()
						,0,0,0);
						sqlite3_close(conn);
						break;
					}
					case 2:{
						//agregar
						string deptno, dname, loc;
						cout<<"Ingrese deptno: ";
						cin>>deptno;
						cout<<"Ingrese dname: ";
						cin>>dname;
						cout<<"Ingrese loc: ";
						cin>>loc;
						
						string x = "insert into dept values('"+deptno+"','"+dname+"','"+loc+"')";
						error=sqlite3_open("oracle-sample.db",&conn);
						error=sqlite3_exec(conn,
						x.c_str()
						,0,0,0);
						sqlite3_close(conn);
						break;
					}
				}
				break;
			}
			case 3:{
				int opcion4;
				cout<<"1- Empleados\n2- Departamentos\nOpcion: ";
				cin>>opcion4;
				switch(opcion4){
					case 1:{
						string id;
						cout<<"Ingrese la id: ";
						cin>>id;
						string comando;
						comando = "delete from emp where empno='"+id+"'";
						//eliminar
						error=sqlite3_open("oracle-sample.db",&conn);
						error=sqlite3_exec(conn,
						comando.c_str()
						,0,0,0);
						sqlite3_close(conn);
						break;
					}
					case 2:{
						string id;
						cout<<"Ingrese la id: ";
						cin>>id;
						string comando;
						comando = "delete from dept where deptno='"+id+"'";
						//eliminar
						error=sqlite3_open("oracle-sample.db",&conn);
						error=sqlite3_exec(conn,
						comando.c_str()
						,0,0,0);
						sqlite3_close(conn);
						break;	
						break;
					}
				}
				break;
			}
			case 4:{
				string id;
				cout<<"Ingrese su id: ";
				cin>>id;
				
				string comando;
				comando = "select mgr from emp where empno = '"+id+"'" ;		
				//listar		
				error=sqlite3_open("oracle-sample.db",&conn);
				error=sqlite3_prepare_v2(conn,comando.c_str(),1000,&res,&tail);
				string comando2, comando3;
				if(sqlite3_step(res) == SQLITE_ROW){
					string temp = (char*)sqlite3_column_text(res,0);
					comando2 = "select * from emp where mgr = '"+temp+"'";
					
					comando3 = "select * from emp where empno = '"+temp+"'";
					
				}else{
					cout<<"No existe!"<<endl;	
				}
				sqlite3_close(conn);
				
				
				cout<<endl<<"El manager es"<<endl;
				//listar		
				error=sqlite3_open("oracle-sample.db",&conn);
				error=sqlite3_prepare_v2(conn,comando3.c_str(),1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<"Empno: "<<sqlite3_column_text(res,0)<<endl;
					cout<<"Ename: "<<sqlite3_column_text(res,1)<<endl;
					cout<<"Job: "<<sqlite3_column_text(res,2)<<endl;
					cout<<"Mgr: "<<sqlite3_column_text(res,3)<<endl;
					cout<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl;
					cout<<"Sal: "<<sqlite3_column_text(res,5)<<endl;
					cout<<"Comm: "<<sqlite3_column_text(res,6)<<endl;
					cout<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl<<endl;
				}
				
				cout<<"Los empleados del manager son"<<endl;
				//listar		
				error=sqlite3_open("oracle-sample.db",&conn);
				error=sqlite3_prepare_v2(conn,comando2.c_str(),1000,&res,&tail);
				while(sqlite3_step(res) == SQLITE_ROW){
					cout<<"Empno: "<<sqlite3_column_text(res,0)<<endl;
					cout<<"Ename: "<<sqlite3_column_text(res,1)<<endl;
					cout<<"Job: "<<sqlite3_column_text(res,2)<<endl;
					cout<<"Mgr: "<<sqlite3_column_text(res,3)<<endl;
					cout<<"Hiredate: "<<sqlite3_column_text(res,4)<<endl;
					cout<<"Sal: "<<sqlite3_column_text(res,5)<<endl;
					cout<<"Comm: "<<sqlite3_column_text(res,6)<<endl;
					cout<<"Deptno: "<<sqlite3_column_text(res,7)<<endl<<endl<<endl;
				}	
				sqlite3_close(conn);
				break;
			}
			case 5:{
				string id;
				cout<<"Ingrese id: ";
				cin>>id;
				
				string comando;
				comando = "select sal from emp where mgr ='"+id+"'";
				error=sqlite3_open("oracle-sample.db",&conn);
				error=sqlite3_prepare_v2(conn,comando.c_str(),1000,&res,&tail);
				int totalsalario;
				totalsalario = 0;
				int cont;
				cont = 0;
				int newsalario;
				if(sqlite3_step(res) == SQLITE_ROW){
					do{
						cont++;
						totalsalario += atoi((char*)sqlite3_column_text(res,0));
					}while(sqlite3_step(res) == SQLITE_ROW);
				}else{
					
				}
				sqlite3_close(conn);
				newsalario = (totalsalario/cont)*2;

								
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
