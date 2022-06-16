#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};

void openFile(){

	string line;
	ifstream myfile ("Empleados.txt");
	
	if(myfile.is_open()){
		
		int x = 0;
		
		while (getline(myfile, line)){
			
		int l = line.length();
		
		EmpID[x] = line.substr(0,3);
		EmpName[x] = line.substr(4, 1 - 4);	
		
		x++;	
			
		}
		
	}else{
		
		cout << "Unable to open the file" << endl;
		
	}
	
}

void addRecord(){
	
	char name[50];
	char empno[5];	
	
	cin.ignore();
		
	cout << "Employee ID: ";
	cin.getline(empno,5);
		
	cout <<	"Employee name: ";
	cin.getline(name,50);
	
	for(int x = 0; x < maxrow; x++){
		
		/*
		\0 is the NULL character, you can find it in your 
		ASCII table, it has the value 0.
		It is used to determinate the end of C-style strings.
		
		si esta vacia
		*/
		if(EmpID[x] == "\0"){
			
			EmpID[x] = empno;
			EmpName[x] = name;
			
			break;
			
		}
		
		
	}
	
}

void ListRecord(){
	
	system("CLS");
	cout << "Current records" << endl;
	cout << "-----------------" << endl;
	
	int counter = 0;
	
	cout << "No.   |    ID   |          NAME  " << endl << "------------\n";
	
	for( int x = 0; x < maxrow; x++){
		
		if(EmpID[x] != "\0"){
			
			counter++;
			cout << " " << counter << "   " << EmpID[x] << "         " << EmpName[x] << endl;
			
		}
		
		
	}
	
	if(counter == 0){
		
		cout << "No record found!!" << endl; 
		
	}
	
	
	cout << "***************************" << endl;
	
}

void searchRecord(string search){
	
	system("CLS");
	
	cout << "Current records(s)" << endl;
	cout << "=========================" << endl;

	int counter = 0;
	
	for(int x = 0; x < maxrow; x++){
		

		
		if(EmpID[x] == search){
			
			counter++;
			cout << "   " << counter << "    " << EmpID[x] << "        " << EmpName[x] << endl;
			break;
		}
		
		
	}
	
	if(counter == 0){
		
		cout << "No record Found !" << endl;
	}
	
	
	cout << "=========================" << endl;
	
}

void updateRecord(string search){
	
	char name[50];
	char empno[5];
	
	int counter = 0;
	
	for(int x = 0; x < maxrow; x++){
		
		if(EmpID[x] == search){
			
		counter++;
			
		cout << "Employee Name: ";	
		cin.getline(name, 50);
		
		EmpName[x] = name;
		
		cout << "Update Successfull ! " << endl;
		
		break;	
			
		}
		
		
	}
	
		if(counter == 0){
		
		cout << "No record Found !" << endl;
	}
	
}

void deleteRecord(string search){

	int counter = 0;
	
	for(int x = 0; x < maxrow; x++){
		
		if(EmpID[x] == search){
			
			counter++;
			
			EmpName[x]= "";
			EmpID[x] ="";
			
			cout << "Successfully deleted " << endl;
			break;
		}
		
		
	}
	
	if(counter == 0){
		
		cout << "ID number does not exist! " << endl;
	}
	
}
	
void saveToFile(){
	
	ofstream myfile;
	myfile.open("Empleado.txt");
	
	for (int x = 0; x < maxrow; x++){
		
		if(EmpID[x] == "\0"){
			
			break;
			
		}else{
			
		myfile << EmpID[x] + "," + EmpName[x] << endl; 	
			
		}
		
		
		
		
	}
	
}	

int main(){
	
	cout << "Menu\n";
	int option;
	string empID;
	system("CLS");
	openFile();
	
	do {
		
		cout << "1 - Create Records" << endl;
		cout << "2 - Update Records" << endl;
		cout << "3 - Delete Records" << endl;		
		cout << "4 - Search Records" << endl;
		cout << "5 - Display all Records" << endl;
		cout << "6 - Exit and Save to textFile" << endl;	
	
		cout << "Select option: ";
		cin >> option;
	
		switch(option){
		case 1: 
			addRecord();
			system("CLS");
			break;
		case 2:
			cin.ignore();
			cout << "Search by id: ";
			getline(cin, empID);	
			updateRecord(empID);
			system("CLS");
			break;
		case 3:
			cin.ignore();
			cout << "Delete by id: ";
			getline(cin, empID);	
			deleteRecord(empID);
			cin.ignore();
			system("CLS");
			break;
		case 4:
			cin.ignore();
			cout << "Search by id: ";
			getline(cin, empID);	
			searchRecord(empID);
			break;
		case 5:
			ListRecord();
			break;
		
	}
	
	
		
	}while( option != 6);
	
	saveToFile();
	cout << "Exit.. Saving to file!" << endl;
	
	return 0; 
	
	
}	
