#include <iostream>
#include<fstream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include<string>
using namespace std;
class Phonebook
{
private:
 string name;
 string phn;
public:
 void menu();
 void getInput();
 void searchname();
 void updatenumber();
 void showAll();
 void removeid();
};
class ExtraDetails
{
private:
 string adr;
 string eml;
 string temp, temp2="*";
 int found = 0;
public :
 void searching();
 void assignaddress();
 void assignemail();
};
void ExtraDetails::searching()
{
 cout<<endl<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Enter Name : ";
 cin>>temp;
 ifstream in (temp+".txt",ios::app) ;
 in>>temp2;
 if(temp2!="*")
 {
 cout<<endl<<"Contact Found : "<<endl;
 found++;
 }
}
void ExtraDetails ::assignaddress()
{
 searching();
 if(!found)
 {
 cout << "Contact Not Found"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
 else
 {
 fstream addresses;
 addresses.open(temp+" address.txt",ios::out);
 cout << "Enter Address :"<<endl;
 cin>>adr;
 addresses << adr;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
}
void ExtraDetails::assignemail()
{
 searching();
 if(!found)
 {
 cout << "Contact Not Found"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
 else
 {
 fstream addresses;
 addresses.open(temp+" email.txt",ios::out);
 cout << "Enter Email :"<<endl;
 cin>>eml;
 addresses << eml;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
}
void Phonebook::menu() //TO SHOW MENU
 {
 cout<<endl<<"MENU:)";
cout<<endl<<"________________________"<<endl;
cout<<endl<<" 1.Add a Contact "<<endl
 <<" 2.Search "<<endl
 <<" 3.Update a Contact "<<endl
 <<" 4.All Contacts "<<endl
 <<" 5.Delete Account "<<endl
 <<" 6.Add Extra Details "<<endl
 <<" 7.Exit "<<endl
 <<" 0.LogOut "<<endl;
 cout<<"________________________";
 }
void Phonebook::getInput() //TO TAKE INPUT OF CONTACT NAME AND NUMBER
 {
 system("cls");
 cout<<endl<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"ENTER NAME : ";
 cin>>name;
 cout<<"ENTER NUMBER : ";
 cin>>phn;
 ofstream out (name+".txt");
 out<<phn;
 out.close();
 ofstream out1 ("All.txt", ios::app);
 out1<<name;
 out1<<endl;
 out1.close();
 int count=0;
 ifstream ina("Total.txt");
 ina>>count;
 ina.close();
 ofstream inb("Total.txt");
 inb<<(count+1);
 inb.close();
 cout<<endl<<endl<<"Contact Added ;)"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
void Phonebook::searchname() //TO SEARCH CONTACT
 {
 system("cls");
 cout<<endl<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 string temp, temp2="*",ad_temp,eml_temp;
 char choice3;
 cout<<"Enter Name : ";
 cin>>temp;
 ifstream in (temp+".txt",ios::app) ;
 ifstream ad_in (temp+" address.txt");
 ifstream eml_in (temp+" email.txt");
 in>>temp2;
 if(temp2!="*")
 {
 cout<<endl<<"Contact Found : "<<endl;
 cout<<"_________________________"<<endl;
 cout<<temp<<"\t"<<temp2<<endl;
 cout<<"Address : ";
 ad_in>>ad_temp;
 cout<<ad_temp<<endl;
 cout<<"Email : ";
 eml_in>>eml_temp;
 cout<<eml_temp<<endl;
 cout<<"_________________________"<<endl;
 cout<<endl<<"Do you want to edit this number? y/n : ";
 cin>>choice3;
 switch(choice3)
 {
 case 'y':
 updatenumber();
 break;
 case 'n':
 cout<<endl<<endl<<"Alright!! :)"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 break;
 default:
 cout<<"Oops!!Invalid Input"<<endl;
 }
 }
 else
 {
 cout<<"SORRY:( Contact not found!"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
 in.close();
 eml_in.close();
 ad_in.close();
 }
void Phonebook::updatenumber() //TO UPDATE A CONTACT
 {
 system("cls");
 cout<<endl<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 string temp, temp1="*", temp2;
 cout<<"Enter CONTACT NAME to be updated : ";
 cin>>temp;
 ifstream inin(temp+".txt");
 inin>>temp1;
 if(temp1!="a")
 {
 cout<<"The Previous Number is : "<<temp1<<endl;
 inin.close();
 cout<<"Please Enter the New Number : ";
 cin>>temp2;
 ofstream outout(temp+".txt");
 outout<<temp2;
 outout.close();
 cout<<endl<<endl<<"Contact Updated :)"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
 else
 {
 cout<<"SORRY :( Number is not present"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
 }
void Phonebook :: showAll()//TO SHOW ALL CONTACTS
 {
 cout<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 int count, num;
 string temp, temp2;
 ifstream ins("Total.txt");
 ins>>count;
 ins.close();
 ifstream osd("All.txt");
 for(int i=1;i<=count;i++)
 {
 osd>>temp;
 ifstream qwe(temp+".txt");
 qwe>>temp2;
 cout<<temp<<"\t"<<temp2<<endl;
 }
 ifstream no("Total.txt");
 no>>num;
 cout<<"________________________________________"<<endl;
 cout<<endl<<"Total number of contacts are : " <<num<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 }
void Phonebook :: removeid() //TO DELETE ACCOUNT
{
 string naam,temp="*",temp2,fav,temp3;
 cout<<"Enter username : ";
 cin>>naam;
 ifstream m(naam+".txt" ,ios::app);
 m>>temp;
 m>>temp2;
 m.close();
 if(temp!="*")
 {
 cout<<"Answer to you security question to delete."<<endl;
 cout<<endl<<"YOUR FAVORITE COLOUR??? : ";
 cin>>fav;
 ifstream s(fav+".txt" ,ios::app);
 s>>temp3;
 s.close();
 if(temp3 !="*")
 {
 if(fav==temp3)
 {
 system("cls");
 cout<<endl<<"Alright!!"<<endl;
 int count;
 string te,tm,temp1, temp4="1",temp_address,temp_email;
 ifstream tu("Total.txt");
 tu>>count;
 tu.close();
 ifstream t("All.txt");
 for(int i=0;i<=count;i++)
 {
 t>>temp;
 temp1=temp+".txt";
 temp_address=temp+" address.txt";
 temp_email=temp+" email.txt";
 remove(temp1.c_str());
 remove(temp_address.c_str());
 remove(temp_email.c_str());
 }
 t.close();
 string temp3="All.txt";
 remove(temp3.c_str());
 ofstream tus("Total.txt");
 tus<<0;
 tus.close();
 remove("Total.txt");
 ofstream tush("SoL.txt");
 tush<<1;
 tush.close();
 remove("SoL.txt");
 te=naam+".txt";
 remove(te.c_str());
 tm=fav+".txt";
 remove(tm.c_str());
 cout<<"DELETED SUCCESSFULLY"<<endl;
 getch();
 system("cls");
 }
 }
 else
 {
 cout<<endl<<"Wrong answer to security question!!"<<endl;
 cout<<endl<<" Can't Delete!!"<<endl;
 getch();
 system("cls");
 }
 }
else
 {
 cout<<"WRONG USERNAME ENTERED"<<endl;
 cout<<endl<<"Can't Delete!!"<<endl;
 getch();
 system("cls");
 }
 return;
}
int registerid() //FUNCTION TO REGISTER
 {
 string username;
 string password;
 string security;
 cout<<endl<<"----------------"
 <<"SIGNUP;)";
 cout<<"----------------"<<endl;
 cout<<"Enter USERNAME : ";
 cin>>username;
 cout<<"Set PASSWORD : ";
 cin>>password;
 cout<<"PLEASE ANSWER A SECURITY QUESTION"<<endl;
 cout<<"YOUR FAVORITE COLOUR? : ";
 cin>>security;
 ofstream obj3(username+".txt");
 obj3<<username;
 obj3<<endl;
 obj3<<password;
 obj3.close();
 ofstream s(security+".txt");
 s<<security;
 s.close();
 cout<<endl<<"Your Are Successfully Signed Up:)"<<endl;
 ofstream w("SoL.txt");
 w<<2;
 getch();
 system("cls");
 return 2;
 }
int forgot() //TO RESET THE PASSWORD
{
 system("cls");
 string name;
 string pass;
 string temp2;
 string temp3="*";
 string temp="*";
 string fav;
 cout<<"RESETING PASSWORD "<<endl;
 cout<<endl<<"Enter Username:";
 cin>>name;
 ifstream m(name+".txt" ,ios::app);
 m>>temp;
 m>>temp2;
if(temp!="*")
 {
 cout<<"Answer to you security question to reset password..."<<endl;
 cout<<endl<<"YOUR FAVORITE COLOUR??? : ";
 cin>>fav;
 ifstream s(fav+".txt" ,ios::app);
 s>>temp3;
 if(temp3 !="*")
 {
 system("cls");
 cout<<endl<<"Alright!!"<<endl;
 cout<<endl<<"Hy "<<temp<<" Remember your password this time"<<endl;
 cout<<endl<<"ENTER NEW PASSWORD:";
 cin>>pass;
 ofstream o(name+".txt");
 o<<name;
 o<<endl;
 o<<pass;
 /*ofstream out1 ("All.txt", ios::app);
 out1<<name;
 out1<<endl;
 out1.close();*/
 cout<<"PASSWORD CHANGE SUCCESSFULLY"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 return 1;
 }
 else
 {
 cout<<endl<<"Wrong answer to security question!!"<<endl;
 cout<<endl<<"SUSPICIOUS LOGIN ATTEMPT!!"<<endl;
 getch();
 system("cls");
 return 2;
 }
 }
else
 {
 cout<<"WRONG USERNAME ENTERED"<<endl;
 cout<<endl<<"SUSPICIOUS LOGIN ATTEMPT!!"<<endl;
 getch();
 system("cls");
 return 3;
 }
}
int main()
{
 system("Color 02");
 Phonebook ph;
 ExtraDetails E;
 int SorL=1;
 cout<<endl;
 cout<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 ifstream q("SoL.txt");
 q>>SorL;
 q.close();
 if(SorL == 1)
 {
 SorL=registerid();
 system("cls");
 }
 if(SorL == 2)
 {
 START:
 string name,password;
 char pass[32];
 char a;
 int i=0;
 string checkname,checkpass;
 int num;
 int choice,choice2;
 int x;
 cout<<endl<<"----------------"
 <<"LOGIN;)";
 cout<<"----------------"<<endl;
 cout<<"Enter USERNAME : ";
 cin>>name;
 cout<<"Enter PASSWORD : ";
 for(i=0;;)
 {
 a=getch();

if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9')||(a=='#')||(a=='@'))
 {
 pass[i]=a;
 ++i;
 cout<<"*";
 }
 if(a=='\b')
 {
 while(i>0)
 {
 cout<<"\b \b";
 --i;
 break;
 }
 }
 if(a=='\r')
 {
 pass[i]='\0';
 break;
 }
 }
 ifstream s(name+".txt");
 s>>checkname;
 s>>checkpass;
 s.close();
 if(checkname==name && checkpass==pass)
 {
 cout<<endl<<endl<<"You Are Successfully Logged In :)"<<endl;
 cout<<"________________________________________"<<endl;
 cout<<"Press Enter....:) ";
 getch();
 system("cls");
 do
 {
 cout<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;
 cout<<"________________________________________"<<endl;
 ifstream no("Total.txt");
 no>>num;
 no.close();
 cout<<endl<<"TOTAL CONTACTS : " <<num<<endl;
 ph.menu();
 cout<<endl<<endl<<"ENTER YOUR CHOICE : ";
 cin>>choice;
 system("cls");
 if(choice ==0)
 {
 goto START;
 }
 switch(choice)
 {
 case 1:
 ph.getInput();
 break;
 case 2:
 ph.searchname();
 break;
 case 3:
 ph.updatenumber();
 break;
 case 4:
 ph.showAll();
 break;
 case 5:
 ph.removeid();
 break;
 case 6:
 system("cls");
 int ch;
 cout<<" PHONEBOOK MANAGEMENT SYSTEM"<<endl;

cout<<"________________________________________"<<endl;
 cout<<" 1.Add address "<<endl;
 cout<<" 2.Add email "<<endl;
 cin>>ch;
 switch(ch)
 {
 case 1 : E.assignaddress();
 break;
 case 2 : E.assignemail();
 break;
 default : cout << "Invalid Input";
 }
 break;
 case 7:
 exit(0);
 return 0;
 default:
 cout<<"Invalid Choice"<<endl;
 }
 }while (choice != 0 && choice != 5);
 }
 else
 {
 system("cls");
 cout<<endl<<"OOPS!!!Username or Password is Incorrect :( "<<endl;
 do
 {
 cout<<endl<<"PRESS 1 LOGIN AGAIN"<<endl;
 cout<<"PRESS 2 RESET PASSWORD!"<<endl;
 cin>>choice2;
 switch(choice2)
 {
 case 1:
 system("cls");
 goto START;
 break;
 case 2:
 x=forgot();
 if(x==1 || x==2 || x==3)
 {
 goto START;
 }
 break;
 default:
 cout<<"INVALID CHOICE"<<endl;
 system("cls");
 }
 } while(choice2!=1 && choice2 !=2);
 }
 }
 return 0;
}
