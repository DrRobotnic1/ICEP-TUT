#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void login();
void registr();
void status();
void adminLogIn();
void viewAll();
void approve();

main()
{
        int choice;
        cout<<"***********************************************************************\n\n\n";
        cout<<"===================TSHWANE UNIVERSITY OF TECHNOLOGY=======================\n\n";
        cout<<"                   Welcome to WIL login page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        
        cout<<"1.Application"<<endl;
        cout<<"2.View Application status"<<endl;
        cout<<"3.Admin LogIn"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        registr();
                        break;
                case 2:
                        status();
                        break;
                case 3:
                        adminLogIn();
                        viewAll();
						approve();
                case 4: 
				cout<<"TSHWANE UNIVERSITY OF TECHNOLOGY WIL PLATFORM";
                        break;
				        
                default:
                        system("cls");
                        cout<<"You've made a mistake Try again..\n"<<endl;
                        main();
        }

}

void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
                cin.get();
                cin.get();
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}

void registr()
{

        string reguser,regpass,fname,lname,regMail,regCompany;
        system("cls");
        cout<<"Enter the student number :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        cout<<"\nEnter firstname :";
        cin>>fname;
        cout<<"\nEnter lastname :";
        cin>>lname;
        cout<<"\nEnter company or type none :";
        cin>>regCompany;
        cout<<"\nEnter TUT email eg. @tut4life.ac.za :";
        cin>>regMail;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<' '<<fname<<' '<<lname<<' '<<regCompany<<' '<<regMail<<' '<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();


}

void status()
{
        int ch;
        system("cls");
        cout<<"Need your application status ? We're here for help\n";
        cout<<" 1.Search your id by username "<<endl;
        cout<<" 2.Main menu "<<endl;
        cout<<" Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp,fname,lname,comp,crsCod,status= "pending";
                        cout<<"\nSearch  your status by username : ";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp>>fname>>lname>>comp>>crsCod>>status)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\ account found\n";
                                cout<<"\nYour status is  "<<status;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease contact your system administrator for more details \n (018 445 88)";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                

                case 2:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Please try again"<<endl;
                        void status();
        }
}

void adminLogIn()
{
        int count;
        int option;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("admDatabase.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\n<LOGIN SUCCESSFUL>\nThank you for logging in..\n";
                cin.get();
                cin.get();
                cout<<"1. to view student details and\n 2 to aprove or reject";
                cin >> option;
                
                if(option == 1){
                	
                viewAll();	
                	
				}else if(option == 2){
				
					approve();
				
				}
                
                main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }

}


void viewAll(){

ifstream theFile("database.txt");	

string id, password,fname,lname,regCompany,regCrsCode;

while(theFile>>id>>password>>fname>>lname>>regCompany>>regCrsCode)
{
	
	cout<<id<<" "<<password<<" "<<fname<<" "<<lname<<" "<<regCompany<<" "<<regCrsCode<<endl;
}
	
	
}

void approve(){
	
   string reguser,regpass,fname,lname,regMail,regCompany;
        system("cls");
       
        cout<<"Enter A for approve or R to Reject student : "<<reguser;
        cin>>regCompany;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<' '<<fname<<' '<<lname<<' '<<regCompany<<' '<<regMail<<endl;
        system("cls");
        cout<<"\nStatus Sucessfully Updated\n";
        main();	
	
	
	
	
}
