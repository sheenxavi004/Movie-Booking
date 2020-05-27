#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
int back=0;
void book(char name[50]);
void moviestats();
void display();
void cancell();
void add();
void startup();
void login();
void admin();
fstream x,y;
class moviel
{
int eno;
char namel[50];
public:
void get()
{
cin>>eno;
gets(namel);
}
void displ()
{
cout<<eno<<". ";
puts(namel);
}
int ret()
{
return eno;
}
char* rety()
{
return namel;
}
}obj1;
class user
{
char name[50];
char user[50];
char passw[50];
int tno;
char fname[50];
char time[8];
char date[9];
int noseat;
char seatno[100];
char classi[20];
float price;
public:
void details(char movie[50])
{
cout<<"Enter Ticket No\n";
cin>>tno;
strcpy(fname,movie);
cout<<"Enter the date (dd-mm-yyyy)\n";
gets(date);
cout<<"Choose Timing(12:00pm/3:00pm/6:00pm/9:00pm/12:00am)\n";
gets(time);
cout<<"Enter the no of seats\n";
cin>>noseat;
cout<<"Enter the Seat No(s).(<Row No(A-G)><Seat No(1-9)>eg.A1)\n";
gets(seatno);
cout<<"Enter the Class(Normal/Executive/Premium/VIP)\n";
gets(classi);
if(strcmpi(classi,"Normal")==0)
price=100*noseat*1.145;
if(strcmpi(classi,"Executive")==0)
price=150*noseat*1.145;
if(strcmpi(classi,"Premium")==0)
price=200*noseat*1.145;
if(strcmpi(classi,"VIP")==0)
price=299*noseat*1.145;
}
void signup()
{
cout<<"Full Name : ";
gets(name);
cout<<"Username : ";
gets(user);
cout<<"Password : ";
gets(passw);
}
void disp()
{
cout<<"\nTicket No : ";
cout<<tno<<endl;
puts(fname);
cout<<"Date: ";
puts(date);
cout<<"Timing:";
puts(time);
cout<<noseat<<" "<<classi<<"( "<<seatno<<" )"<<"\n";
cout<<"Price :Rs "<<price<<endl<<endl;
}
char* ret_name()
{
return name;
}
char* ret_user()
{
return user;
}
int ret_no()
{
return tno;
}
void dis()
{
price=price-150;
}
char* ret_password()
{
return passw;
}
}obj,temp;
void main()
{
clrscr();
char ch;
int cho;
startup();
do
{
clrscr();
cout<<"Welcome "<<obj.ret_name()<<"( "<<obj.ret_user()<<" )\n";
cout<<"(1)Book a Movie\n";
cout<<"(2)Display the current booking status\n";
cout<<"(3)Display all the movies you have booked\n";
cout<<"(4)Cancel a movie\n";
cout<<"(5)Add a coupon to the movie\n";
cout<<"(6)Logout\n";
cout<<"Enter your Choice\n";
cin>>cho;
switch(cho)
{
case 1:clrscr();
       cout<<"Choose Movie from below\n";
       int eno1;
       char n[50];
       x.open("Moviel.dat",ios::in|ios::binary);
       while(x.read((char*)&obj1,sizeof(obj1)))
       obj1.displ();
       x.close();
       cout<<"Enter your choice\n";
       cin>>eno1;
       x.open("Moviel.dat",ios::in|ios::binary);
       while(x.read((char*)&obj1,sizeof(obj1)))
       {
       if(eno1==obj1.ret())
       strcpy(n,obj1.rety());
       }
       x.close();
       book(n);
       break;
case 2:clrscr();
       moviestats();
       break;
case 3:clrscr();
       display();
       break;
case 4:clrscr();
       cancell();
       break;
case 5:clrscr();
       add();
       break;
case 6:startup();
}
}
while(back==1);
getch();
}
void book(char name[50])
{
x.open("Moviecn.dat",ios::app|ios::binary);
obj.details(name);
x.write((char*)&obj,sizeof(obj));
x.close();
cout<<"Previous Menu(1)\n";
cin>>back;
}
void cancell()
{
int no;
cout<<"Enter the Ticket no to be cancelled\n";
cin>>no;
x.open("Moviecn.dat",ios::in|ios::binary);
y.open("temp.dat",ios::out|ios::binary);
while(x.read((char*)&obj,sizeof(obj)))
{
if(obj.ret_no()!=no)
y.write((char*)&obj,sizeof(obj));
}
x.close();
y.close();
remove("Moviecn.dat");
rename("temp.dat","Moviecn.dat");
}
void add()
{
int eno;
cout<<"Enter the Ticket no\n";
cin>>eno;
x.open("Moviecn.dat",ios::in|ios::out|ios::binary);
while(x.read((char*)&obj,sizeof(obj)))
{
if(obj.ret_no()==eno);
{
obj.dis();
x.seekp(-1*sizeof(obj),ios::cur);
x.write((char*)&obj,sizeof(obj));
break;
}
}
x.close();
cout<<"Previous Menu(1)\n";
cin>>back;
}
void moviestats()
{
int tc;
cout<<"Enter the Ticket no\n";
cin>>tc;
x.open("Moviecn.dat",ios::in|ios::binary);
while(x.read((char*)&obj,sizeof(obj)))
{
if(tc==obj.ret_no())
obj.disp();
}
cout<<"\nBooking Confirmed!\n";
cout<<"Pay cash at movie counter with your reference no "<<obj.ret_no()<<endl;
x.close();
cout<<"Previous Menu(1)\n";
cin>>back;
}
void display()
{
char all[50];
strcpy(all,obj.ret_user());
cout<<"All Tickets:\n";
x.open("Moviecn.dat",ios::in|ios::binary);
while(x.read((char*)&obj,sizeof(obj)))
{
if(strcmpi(obj.ret_user(),all)==0)
obj.disp();
}
x.close();
cout<<"Previous Menu(1)\n";
cin>>back;
}
void login()
{
char us[50],pas[50],pass[50];
cout<<"Username : ";
gets(us);
cout<<"Password : ";
gets(pas);
x.open("Moviecn.dat",ios::in|ios::binary);
while(x.read((char*)&obj,sizeof(obj)))
{
if(strcmp(us,obj.ret_user())==0)
{
strcpy(pass,obj.ret_password());
break;
}
}
x.close();
if(strcmp(pas,pass)==0)
cout<<"Welcome\n";
else
startup();
}
void startup()
{
clrscr();
int choice;
cout<<"Syncopy Inc.\n";
cout<<"1.Signin\n";
cout<<"2.Login\n";
cout<<"3.Admin\n";
cout<<"4.Exit\n";
cout<<"Enter code CN150 for a discount of Rs150 on tickets over Rs300\n";
cout<<"Enter the choice\n";
cin>>choice;
switch(choice)
{
case 1:obj.signup();
       break;
case 2:login();
       break;
case 3:admin();
       break;
case 4:exit(0);

}
}
void admin()
{
int extmn;
cout<<"Enter 10 movies\n";
y.open("Moviels.dat",ios::app,ios::binary);
for(int i=0;i<10;i++)
{
obj1.get();
y.write((char*)&obj1,sizeof(obj1));
}
x.close();
exit(0);
}