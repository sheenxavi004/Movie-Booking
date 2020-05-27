//Header Files required
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
int back=0;
void painting();
void book(char name[50],int scno);
void display();
void cancell();
void add();
void startup();
void login();
void admin();
fstream x,y;
//Class for Movies list
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
	void displ();
	int ret()
	{
		return eno;
	}
	char* rety()
	{
		return namel;
	}
}obj1;
//class for movie ticket records
class user
{
	char name[50];
	char user[50];
	char passw[50];
	int tno;
	int screen;
	char fname[50];
	char time[8];
	char date[12];
	int noseat;
	char seatno[100];
	char classi[20];
	float price;
	public:
	void details(char movie[50],int count,char n[50],char u[50],char p[50],int sno);
	void signup();
	void disp();
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
	if(price>300)
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
	painting();
	cout<<"\n                            Press any key to continue\n";
	cout<<"\n\t\t\t        BY SHEEN XAVIER A\n";
	getch();
	char ch;
	int n,cho;
	startup();
	do
	{
		clrscr();
		cout<<"\n\n\n           ";
		char k=char(205);
		char l=char(186);
		cout<<char(201);
		for(int i=0;i<56;i++)
		cout<<k;
		cout<<char(187)<<endl;
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"  WELCOME "<<obj.ret_name()<<"("<<obj.ret_user()<<") !";
		n=42-strlen(obj.ret_name())-strlen(obj.ret_user());
		for(i=0;i<n;i++)
		cout<<" ";
		cout<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"                     (1) BOOK                           "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"                     (2) ALL TICKETS                    "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"                     (3) CANCELL                        "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"                     (4) COUPONS                        "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"                     (5) LOGOUT                         "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<"                 CHOICE :                               "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<l<<" USE COUPON CODE CN150 FOR RS150 OFF ON TICKETS  RS300  "<<l<<"\n";
		cout<<"           "<<l<<"                                                        "<<l<<"\n";
		cout<<"           "<<char(200);
		for(i=0;i<56;i++)
		cout<<k;
		cout<<char(188);
		gotoxy(40,18);
		cin>>cho;
		switch(cho)
		{
			case 1:clrscr();    //Getting Movie names from the list
			cout<<"\n\n\n";
			char k=char(205);
			char l=char(186);
			cout<<"                    ";
			cout<<char(201);
			for(int i=0;i<40;i++)
			cout<<k;
			cout<<char(187)<<endl;
			cout<<"                    "<<l<<"        Choose Movie from below         "<<l<<"\n";
			cout<<"                    "<<l<<"                                        "<<l<<"\n";
			int eno1;
			int no;
			char n[50];
			x.open("Moviel.dat",ios::in|ios::binary);
			while(x.read((char*)&obj1,sizeof(obj1)))
			obj1.displ();
			x.close();
			cout<<"                    "<<l<<"             CHOICE :                   "<<l<<"\n";
			cout<<"                    "<<char(200);
			for(i=0;i<40;i++)
			cout<<k;
			cout<<char(188);
			gotoxy(44,24);
			cin>>eno1;
			x.open("Moviel.dat",ios::in|ios::binary);
			while(x.read((char*)&obj1,sizeof(obj1)))
			{
				if(eno1==obj1.ret())
				strcpy(n,obj1.rety());
			}
			x.close();
			no=(eno1+1)/2;
			book(n,no);
			break;
			case 2:clrscr();
			       display();
			       break;
			case 3:clrscr();
			       cancell();
			       break;
			case 4:clrscr();
			       add();
			       break;
			case 5:startup();
		}
	}
	while(back==1);
	getch();
}
//For Booking Ticket i.e. for writing records
void book(char name[50],int scno)
{
	char n[50],u[50],p[50];
	strcpy(n,obj.ret_name());
	strcpy(u,obj.ret_user());
	strcpy(p,obj.ret_password());
	int t=10000;
	x.open("Moviecn.dat",ios::in|ios::binary);
	while(x.read((char*)&obj,sizeof(obj)))
	t++;
	x.close();
	x.open("Moviecn.dat",ios::app|ios::binary);
	obj.details(name,t,n,u,p,scno);
	x.write((char*)&obj,sizeof(obj)); //Writing to the file Moviecn.dat
	x.close();
	cout<<"Booking Confirmed!\n";
	cout<<"Previous Menu(1)\n";
	cin>>back;
}
void cancell()
{       //For Deleting or Cancelling Tickets
	int no;
	cout<<"\n\n\n\n";
	char k=char(205);
	char l=char(186);
	cout<<"                  ";
	cout<<char(201);
	for(int i=0;i<42;i++)
	cout<<k;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"               CANCELLATION               "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Ticket No  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<char(200);
	for(i=0;i<42;i++)
	cout<<k;
	cout<<char(188);
	gotoxy(42,9);
	cin>>no;
	x.open("Moviecn.dat",ios::in|ios::binary);
	y.open("temp.dat",ios::out|ios::binary);
	while(x.read((char*)&obj,sizeof(obj)))
	{
		if(obj.ret_no()!=no)
		y.write((char*)&obj,sizeof(obj));  //Writing to a temporary file
	}
	x.close();
	y.close();
	remove("Moviecn.dat");
	rename("temp.dat","Moviecn.dat"); //Coverting temp to Moviecn
	gotoxy(29,11);
	cout<<"Cancellation Successful";
	gotoxy(29,12);
	cout<<"Previous Menu(1) : ";
	cin>>back;
}
//For Adding Coupons
void add()
{
	int eno;
	char code[50];
	cout<<"\n\n\n\n";
	char k=char(205);
	char l=char(186);
	cout<<"                  ";
	cout<<char(201);
	for(int i=0;i<42;i++)
	cout<<k;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                  COUPONS                 "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Ticket No  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"       Coupon Code  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<char(200);
	for(i=0;i<42;i++)
	cout<<k;
	cout<<char(188);
	gotoxy(42,9);
	cin>>eno;
	gotoxy(42,11);
	gets(code);
	if(strcmpi(code,"CN150")==0)
	{
		x.open("Moviecn.dat",ios::in|ios::out|ios::binary);
		while(x.read((char*)&obj,sizeof(obj)))
		{
			if(obj.ret_no()==eno)
			{
				obj.dis();
				x.seekp(-350,ios::cur);
				x.write((char*)&obj,sizeof(obj));
				break;
			}
		}
	}
	x.close();
	gotoxy(34,13);
	cout<<"Previous Menu(1)\n";
	cin>>back;
}
//For Displaying Tickets
void display()
{
	char all[50];
	strcpy(all,obj.ret_user());
	char k=char(205);
	char l=char(186);
	cout<<"\n\n                  ";
	cout<<char(201);
	for(int i=0;i<43;i++)
	cout<<k;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                           "<<l<<"\n";
	cout<<"                  "<<l<<"                 ALL TICKETS               "<<l<<"\n";
	x.open("Moviecn.dat",ios::in|ios::binary);
	while(x.read((char*)&obj,sizeof(obj)))
	{
		if(strcmp(obj.ret_user(),all)==0)
		obj.disp();
	}
	x.close();
	x.open("Moviecn.dat",ios::in|ios::binary);
	while(x.read((char*)&obj,sizeof(obj)))
	{
		if(strcmp(obj.ret_user(),all)==0)
		break;
	}
	x.close();
	cout<<"                  "<<char(200);
	for(i=0;i<43;i++)
	cout<<k;
	cout<<char(188)<<endl;
	cout<<"Previous Menu(1)\n";
	cin>>back;
}
//Login Option
void login()
{
	char us[50],pas[50],pass[50];
	clrscr();
	cout<<"                                                                               \n";
	cout<<"                                                                               \n";
	cout<<"                                                                               \n";
	cout<<"                                                                               \n";
	char k=char(205);
	char l=char(186);
	cout<<"                  ";
	cout<<char(201);
	for(int i=0;i<42;i++)
	cout<<k;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                 LOGIN                    "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Username   :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Password   :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<char(200);
	for(i=0;i<42;i++)
	cout<<k;
	cout<<char(188);
	gotoxy(42,9);
	gets(us);
	gotoxy(42,11);
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
	for(i=0;i<50;i++)
	{
		pas[i]=getch();
		cout<<"*";
		if(int(pas[i])==13)
		break;
	}
	pas[i]='\0';
	if(strcmp(pas,pass)==0)
	cout<<"Welcome\n";
	else
	startup();
}
//Main menu
void startup()
{
	int choice;
	clrscr();
	cout<<"\n\n\n           ";
	char k=char(205);
	char l=char(186);
	cout<<char(201);
	for(int i=0;i<56;i++)
	cout<<k;
	cout<<char(187)<<endl;
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                    NOW SHOWING.INC                     "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                         MENU                           "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                     (1) SIGN UP                        "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                     (2) LOGIN                          "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                     (3) ADMIN                          "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                     (4) EXIT                           "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                 CHOICE :                               "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<l<<"                                                        "<<l<<"\n";
	cout<<"           "<<char(200);
	for(i=0;i<56;i++)
	cout<<k;
	cout<<char(188);
	gotoxy(40,18);
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
		default:exit(0);
	}
}
//For adding more Movies
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
//Member function of class user for Signup i.e as a new member
void user::signup()
{
	clrscr();
	cout<<"\n\n\n\n";
	char k=char(205);
	char l=char(186);
	cout<<"                  ";
	cout<<char(201);
	for(int i=0;i<42;i++)
	cout<<k;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                 SIGN UP                  "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Full Name  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Username   :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"         Password   :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<char(200);
	for(i=0;i<42;i++)
	cout<<k;
	cout<<char(188);
	gotoxy(42,9);
	gets(name);
	gotoxy(42,11);
	gets(user);
	gotoxy(42,13);
	for(i=0;i<50;i++)
	{
		passw[i]=getch();
		cout<<"*";
		if(int(passw[i])==13)
		break;
	}
	passw[i]='\0';
}
//ASCII Art
void painting()
{
	int i,a,b;
	char k=char(186);
	char j=char(202);
	char n=char(203);
	char l=char(205);
	cout<<"\n\n\n\n\n";
	cout<<"                        ";
	for(i=0;i<32;i++)
	cout<<l;
	cout<<"\n";
	cout<<"                        ";
	cout<<l<<l;
	for(i=0;i<2;i++)
	{
		for(a=0;a<6;a++)
		cout<<l;
		cout<<n<<n;
		for(b=0;b<6;b++)
		cout<<l;
	}
	cout<<l<<l;
	cout<<"\n";
	for(a=0;a<2;a++)
	{
		cout<<"                        ";
		for(i=0;i<8;i++)
		cout<<" ";
		cout<<k<<k;
		for(i=0;i<12;i++)
		cout<<" ";
		cout<<k<<k;
		for(i=0;i<8;i++)
		cout<<" ";
		cout<<"\n";
	}
	cout<<"                        ";
	cout<<l<<l;
	for(i=0;i<2;i++)
	{
		for(a=0;a<6;a++)
		cout<<l;
		cout<<j<<j;
		for(b=0;b<6;b++)
		cout<<l;
	}
	cout<<l<<l;
	cout<<"\n";
	cout<<"                        ";
	for(i=0;i<32;i++)
	cout<<l;
	gotoxy(42,13);
	cout<<"\n\n\t\t\t\t  NOW SHOWING \n\n" ;
}
//Member function of class moviel for displaying info
void moviel::displ()
{
	int n;
	char l=char(186);
	cout<<"                    "<<l<<"      "<<eno<<"."<<namel;
	if(eno<10)
	n=32-strlen(namel);
	else
	n=31-strlen(namel);
	for(int i=0;i<n;i++)
	cout<<" ";
	cout<<l<<endl;
	cout<<"                    "<<l<<"                                        "<<l<<"\n";
}
//Member function of user which takes info from user
void user::details(char movie[50],int count,char n[50],char u[50],char p[50],int sno)
{
	char b='A';
	clrscr();
	int k;
	strcpy(name,n);
	strcpy(user,u);
	strcpy(passw,p);
	tno=count;
	strcpy(fname,movie);
	screen=sno;
	cout<<"                                                                               \n";
	cout<<"                                                                               \n";
	char k1=char(205);
	char l=char(186);
	cout<<"                  ";
	cout<<char(201);
	for(int i=0;i<42;i++)
	cout<<k1;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"              DATE  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                     (DD/MM/YYYY)         "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"              TIME  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                     (HH:MM(am/pm))       "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<" 12:00pm    03:00pm    06:00pm   9:00pm   "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"       NO OF SEATS  :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<char(200);
	for(i=0;i<42;i++)
	cout<<k1;
	cout<<char(188);
	gotoxy(42,7);
	gets(date);
	gotoxy(42,10);
	gets(time);
	gotoxy(42,15);
	cin>>noseat;
	clrscr();
	cout<<"		                  THEATRE SCREEN                          \n";
	cout<<"(------------------------------------------------------------------------------)\n";
	for(int a=0;a<7;a++)
	{
		for(i=0;i<8;i++)
		cout<<char(201)<<k1<<k1<<char(187)<<"      ";
		for(i=1;i<9;i++)
		cout<<l<<b<<i<<l<<"      ";
		for(i=1;i<9;i++)
		cout<<char(200)<<k1<<k1<<char(188)<<"      ";
		b++;
	}
	cout<<" \t\t\t\tSEATS : ";
	gets(seatno);
	clrscr();
	cout<<"\n\n\n                  ";
	cout<<char(201);
	for(i=0;i<42;i++)
	cout<<k1;
	cout<<char(187)<<endl;
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"              CLASS :                     "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<" Normal     Execuive     Premium     VIP  "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<l<<"                                          "<<l<<"\n";
	cout<<"                  "<<char(200);
	for(i=0;i<42;i++)
	cout<<k1;
	cout<<char(188);
	gotoxy(42,8);
	gets(classi);
	if(strcmpi(classi,"Normal")==0)
	{
		price=100*noseat*1.145;
		k=price;
		price=k;
	}
	if(strcmpi(classi,"Executive")==0)
	{
		price=150*noseat*1.145;
		k=price;
		price=k;
	}
	if(strcmpi(classi,"Premium")==0)
	{
		price=200*noseat*1.145;
		k=price;
		price=k;
	}
	if(strcmpi(classi,"VIP")==0)
	{
		price=299*noseat*1.145;
		k=price;
		price=k;
	}
	gotoxy(1,20);
	cout<<"\t\t\tPress any key to confirm booking\n";
	getch();
}
//Member function of class user used to input info
void user::disp()
{
	int n;
	char l=char(186);
	cout<<"                  "<<l<<"                                           "<<l<<"\n";
	cout<<"                  "<<l<<"           Ticket No  : "<<tno<<"              "<<l<<"\n";
	cout<<"                  "<<l<<"           Date       : "<<date<<"         "<<l<<"\n";
	cout<<"                  "<<l<<"           Timing     : "<<time<<"            "<<l<<"\n";
	cout<<"                  "<<l<<"           Screen     : "<<screen<<"                  "<<l<<"\n";
	cout<<"                  "<<l<<"           Seats      : "<<noseat<<"("<<seatno<<")";
	n=16-strlen(seatno);
	for(int i=0;i<n;i++)
	cout<<" ";
	cout<<l<<"\n";
	cout<<"                  "<<l<<"           Class      : "<<classi;
	n=19-strlen(classi);
	for(i=0;i<n;i++)
	cout<<" ";
	cout<<l<<"\n";
	if(price<1000)
	cout<<"                  "<<l<<"           Price      : Rs"<<price<<"              "<<l<<"\n";
	else
	cout<<"                  "<<l<<"           Price      : Rs"<<price<<"             "<<l<<"\n";
	cout<<"                  "<<l<<"                                           "<<l<<"\n";
	cout<<"                  "<<l<<"                                           "<<l<<"\n";
}
