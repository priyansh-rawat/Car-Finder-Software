#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<iomanip>
#define CLRSCR system("cls");
using namespace std;

class cars
{
	int abs, airbags,seats,code;
  	float hp,btspc,price,mileage,rating;
  	char eng[30],fuel[20],transmission[30],drvtrain[5];
  	char company[15], name[20],type[20];
 	public:
  		void input();
  		void output();
		void compare();
		int getcode(){return code;};
		int getabs(){return abs;};
		int getabags(){return airbags;};  
		int getseats(){return seats;};
		float gethp(){return hp;};
		float getbtspc(){return btspc;};
		float getprice(){return price;};
		float getmil(){return mileage;};
		float getrating(){return rating;};
		char * geteng(){return eng;};
		char * getfuel(){return fuel;};
		char * gettrans(){return transmission;};
		char * getdt(){return drvtrain;};
		char * gettype(){return type;};
		char * getcomp(){return company;}
		char * getname(){return name;}
};

void edit();
cars showcomp(char []);
cars showcar();
cars carsel()
{ 
	char comp[15],ans,ans1,buf;
 	cars ret;
 	retry:	cout<<"\nDo you prefer any company(y/n):";
	cin>>ans;
 	if(ans=='y'||ans=='Y')
 	{ 
	 	cin.get(buf);
  		CLRSCR;
  		cout<<"\nEnter name of the company you want:";
		cin.getline(comp,15);
  		ret=showcomp(comp);
	}
 	else if(ans=='n'||ans=='N')
 		ret=showcar();
 	else
 	{ 
	 	cout<<"\nInvalid choice. Do you want to retry(y/n):";
  		cin>>ans1;
  		if(ans1=='y'||ans1=='Y')
   			goto retry;
   		cout<<"\nExiting---";
   		getch();
   		CLRSCR;
   		for(int i=0;i<12;i++)
		   	cout<<"\n";
   		cout<<"---------------------------Thank You!! Please Visit Again----------------------";
   		getch();
   		exit(1);
 	}
 	return ret;
}
void main()
{
	CLRSCR;
   	char pass[10],buf,ans;
 	cout<<"Type password to edit or press ENTER";
	for(int s=0;s<11;s++)
		cout<<"\n";
 	cout<<setw(40)<<"Password:";
	cin.getline(pass,10);
 	if(!strcmp(pass,"password"))
  	{
	  	edit();
		exit(0);
	}
 	char cont='y';
 	while(cont=='y'||cont=='Y')
 	{
	 	CLRSCR;
   		cars compare;
  		CLRSCR;
  		cout<<"\n-----------------------Welcome to RAWAT MOTORS ----------------------- ";
  		compare=carsel();
  		cout<<"\nDo you want to compare or see another car(c/a)";
  		cout<<"\nPress any other key to exit:";
  		cin>>ans;
  		if(ans=='c'||ans=='C')
  		{
		  	compare.compare();
   			cout<<"\nDo you want to see another car(y/n):";
   			cin>>cont;
  		}	
  		else if(ans=='a'||ans=='A')
   		{
		   cont='y';
		   continue;
		}
  		else
  			cont='n';
 	}
 	CLRSCR;
 	for(int i=0;i<12;i++)
	 	cout<<"\n";
 	cout<<"---------------------------Thank You!! Please Vist Again----------------------";
 	getch();
}

cars showcomp(char comp1[])
{	
	cars sc,ret,scars[10];
 	int valcode[4],i=0,scode,res,flag=-1,j=0;
 	char ans,*temp,comp2[15];
 	for(i=0;i<15;i++)
  		comp1[i]=toupper(comp1[i]);
 	ifstream fin("Cars.dat",ios::binary);
 	cout<<endl;
 	while(fin.read((char*)&sc,sizeof(sc)))
	{
	 	temp=sc.getcomp();
  		for(i=0;i<15;i++)
   		comp2[i]=toupper(*(temp+i));
  		if(!strcmp(comp1,comp2))
  		{
		  	valcode[j]=sc.getcode();
   			scars[j]=sc;
   			j++;
   			flag=0;
  		}
 	}
 	if (flag==-1)
 	{
	 	cout<<"\nWe do not have records of the company:"<<comp1;
  		cout<<"\nExiting...";
  		getch();
  		CLRSCR;
  		for(int i=0;i<12;i++)
	  		cout<<"\n";
  		cout<<"---------------------------Thank You!! Please Vist Again----------------------";
 		getch();
  		exit(1);
 	}
 	cout<<"\nThe cars from "<<comp1<<" are:"<<endl;
 	for(i=0;i<56;i++)
	 	cout<<"=";
 		cout<<endl<<"|"<<setw(13)<<"Code	|"<<setw(18)<<"Name  	|"<<setw(24)<<"Price    	|"<<endl;
 	for(i=0;i<56;i++)
	 	cout<<"=";
 	for(i=0;i<j;i++)
  		cout<<endl<<"|"<<setw(10)<<scars[i].getcode()<<"  |"<<setw(15)<<scars[i].getname()<<"  |"<<setw(15)<<setprecision(2)<<scars[i].getprice()<<" Lakhs  |";
 	cout<<endl;
 	for(i=0;i<56;i++)
	 	cout<<"=";
 	retryc:		cout<<"\nEnter code of the car you want to see:";cin>>scode;
 	for(i=0;i<4;i++)
 	{
	 	if(scode==valcode[i])
  		{
		  	res=0;
			break ;
		}
  	else
   		res=-1;
 	}
 	if(res==-1)
 	{
 		cout<<"\nCar not in this company. Do you want to retry(y/n):" ;
  		cin>>ans;
  		if(ans=='y'||ans=='Y')
	   		goto retryc;
	  	else
	  	{
		  	cout<<"\nExitting---";
	   		getch();
	   		CLRSCR;
	   		for(int i=0;i<12;i++)
			   cout<<"\n";
	   		cout<<"---------------------------Thank You!! Please Vist Again----------------------";
	   		getch();
	   		exit(1);
	 	}
	}
 	CLRSCR;
  	fin.close();
 	ifstream fin1("Cars.dat",ios::binary);
 	while(fin1.read((char*)&sc,sizeof(sc)))
	{
  		if(sc.getcode()==scode)
   		{
			sc.output();
			getch();
			ret=sc;
   		}
 	}
 	return ret;
}

cars showcar()
{
 	int choice,count=0,res=-1,scode,j=0;
 	float budget,min;
 	char again,stype[20],buf,out[5];
 	cars c3,ret,scars[15];
 	int valcode[30];
 	for(j=0;j<30;j++)
  		valcode[j]=0;
 	CLRSCR;
 	notfnd:		CLRSCR;
 	cout<<"Enter which type of car you want from the following list:";
 	cout<<"\n1)Hatchback\n2)Sedan\n3)Luxury Sedan\n4)SUV\n5)MPV\n6)Sports\n";
 	cout<<"Enter choice:";
 	cin>>choice;
 	switch (choice)
 	{
  	case 1:	strcpy(stype,"Hatchback");
   		   	strcpy(out,"s”);
   	   		min=2.86;
   	   		break;
  	case 2: strcpy(stype,"Sedan");
   	   		strcpy(out,"s");
   	   		min=7.37;
   	   		break;
  	case 3:	strcpy(stype,"Luxury Sedan");
   	   		strcpy(out,"s");
   	   		min=52.81;
   	   		break;
  	case 4: strcpy(stype,"SUV");
   	   		strcpy(out,"s");
   	   		min=8.54;
   	   		break;
  	case 5:	strcpy(stype,"MPV");
		   	strcpy(out,"s");
		   	min=5.82;
		   	break;
	case 6: strcpy(stype,"Sports");
   	   		strcpy(out," cars");
   	   		min=85.45;
   	   		break;
  	default:cout<<"\nInvalid choice!! Do you want to try again(y/n):";
   	   		cin>>again;
   	   		if (again=='y'||again=='Y')
   			goto notfnd;
   	   		else
   	   		{	
   				cout<<"\nExiting---";
   				getch();
   				CLRSCR;
   				for(int i=0;i<12;i++)
				   	cout<<"\n";
   				cout<<"---------------------------Thank You!! Please Vist Again----------------------";
		   		getch();
		   		exit(1);
		   	}
 	}
 	cout<<"\nEnter budget in lakhs (min."<<setprecision(2)<<min<<" Lakhs):";
	cin>>budget;
 	ifstream fin("Cars.dat",ios::binary);
 	while(fin.read((char*)&c3,sizeof(c3)))
 	{
  		if(!strcmp(stype,c3.gettype())&&c3.getprice()<=budget)
  		{
   			res=0;
   			valcode[count]=c3.getcode();
   			scars[count]=c3;
   			count++;
  		}
 	}
 	cout<<endl;
 	if (res==-1)
 	{	
  		cout<<"\nCar with given specifics not found. Try again?(y/n):";
  		cin>>again;
  		if (again=='y'||again=='Y')
   		goto notfnd;
  		cout<<"\nExiting---";
  		getch();
  		CLRSCR;
  		for(int i=0;i<12;i++)
		  	cout<<"\n";
  		cout<<"---------------------------Thank You!! Please Vist Again----------------------";
  		getch();
  		exit(0);
 	}
 	CLRSCR;
 	cout<<stype<<out<<" under "<<budget<<" Lakhs are:"<<endl;
 	for(j=0;j<74;j++)	
	 	cout<<"=";
 	cout<<endl<<"|"<<setw(13)<<"Code	|"<<setw(18)<<"Company 	|"<<setw(18)<<"Name  	|"<<setw(24)<<"Price   	|"<<endl;
 	for(j=0;j<74;j++)
	 	cout<<"=";
 	for(j=0;j<count;j++)
  		cout<<endl<<"|"<<setw(10)<<scars[j].getcode()<<"  |"<<setw(15)<<scars[j].getcomp()<<"  |"<<setw(15)<<scars[j].getname()<<"  |"<<setw(15)<<setprecision(2)<<scars[j].getprice()<<" Lakhs  |";
 	cout<<endl;
 	for(j=0;j<74;j++)
	 	cout<<"=";
 	wrncd:	cout<<"\nEnter code of the car you want to see:";
	 		cin>>scode;
 	for(j=0;j<30;j++)
  	{
   		if(scode==valcode[j])
		{
 			res=0 ;
 			break ; 
       	}
   		else
			res=-1;
  	}
  	if (res==-1)
  	{
   		cout<<"\nCar not within given specifics. Try again(y/n):";
   		cin>>again;
   		if (again=='y'||again=='Y')
   		goto wrncd;
   		exit(0);
  	}
  	CLRSCR;
  	fin.close();
  	ifstream fin1("Cars.dat",ios::binary);
  	while(fin1.read((char*)&c3,sizeof(c3)))
  	{
   		if(c3.getcode()==scode)
		{
 			c3.output();
 			ret=c3;
		}
  	}
  	getch();
  	return ret;
}

void cars :: compare()
{
 	char ans;
 	int i;
 	re:		cars sc;
 	CLRSCR;
 	sc=carsel();
 	cout<<"\nIs this the car you want to compare with "<<company<<" "<<name<<" (y/n):";
 	cin>>ans;
 	if (ans=='n'||ans=='N')
 	{
  		cout<<"\nDo you want to select again:";
		cin>>ans;
  		if (ans=='y'||ans=='Y')
   		goto re;
 	}
 	char abs1[3],abs2[3];
 	if(abs==0)
  		strcpy(abs1,"NO");
 	else
  		strcpy(abs1,"YES");
 	if(sc.abs==0)
  		strcpy(abs2,"NO");
 	else
  		strcpy(abs2,"YES");
 	CLRSCR;
 	if (code==sc.getcode())
  	{
   		cout<<"\nCar already chosen. Choose another car\nPress any key to continue";
   		getch();
   		goto re;
  	}		
 	cout<<company<<" "<<name<<" Vs "<<sc.getcomp()<<" "<<sc.getname()<<endl;
 	for(i=0;i<70;i++) 
	 	cout<<"=";
 	cout<<endl<<"|"<<setw(16)<<"Code  |"<<setw(25)<<code<<setw(25)<<sc.getcode()<<"  |";
	cout<<endl<<"|"<<setw(16)<<"Company  |"<<setw(25)<<company<<setw(25)<<sc.getcomp()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Name  |"<<setw(25)<<name<<setw(25)<<sc.getname()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Type  |"<<setw(25)<<type<<setw(25)<<sc.gettype()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Price  |"<<setw(19)<<setprecision(2)<<price<<" Lakhs"<<setw(19)<<setprecision(2)<<sc.getprice()<<" Lakhs  |"<<endl;
 	for(i=0;i<70;i++) 
	 	cout<<"-";
 	cout<<endl<<"|"<<setw(16)<<"Engine  |"<<setw(25)<<eng<<setw(25)<<sc.geteng()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Transmission  |"<<setw(25)<<transmission<<setw(25)<<sc.gettrans()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Drivetrain  |"<<setw(25)<<drvtrain<<setw(25)<<sc.getdt()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Fuel  |"<<setw(25)<<fuel<<setw(25)<<sc.getfuel()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Power  |"<<setw(21)<<hp<<" BHP"<<setw(21)<<sc.gethp()<<" BHP"<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Mileage  |"<<setw(20)<<setprecision(2)<<mileage<<" KMPL"<<setw(20)<<setprecision(2)<<sc.getmil()<<" KMPL"<<"  |"<<endl;
 	for(i=0;i<70;i++)
	  	cout<<"-";
 	cout<<endl<<"|"<<setw(16)<<"No of Seats  |"<<setw(25)<<seats<<setw(25)<<sc.getseats()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Boot Space  |"<<setw(23)<<btspc<<" L"<<setw(23)<<sc.getbtspc()<<" L"<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"ABS  |"<<setw(25)<<abs1<<setw(25)<<abs2<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Airbags  |"<<setw(25)<<airbags<<setw(25)<<sc.getabags()<<"  |";
 	cout<<endl<<"|"<<setw(16)<<"Rating  |"<<setw(25)<<rating<<setw(25)<<sc.getrating()<<"  |"<<endl;
 	for(i=0;i<70;i++)
	 	cout<<"=";
 	getch();
}

void cars :: input()
{
 	char ch;
 	cout<<"\nCode:";
	cin>>code;
	cin.get(ch);
 	cout<<"\nCompany:";
	cin.getline(company,15);
 	cout<<"\nName:";
	cin.getline(name,20);
 	cout<<"\nType:";
	cin.getline(type,20);
 	cout<<"\nPrice in lakhs:";
	cin>>price;
	cin.get(ch);
	cout<<"\nEngine:";
	cin.getline(eng,30);
	cout<<"\nFuel:";
	cin.getline(fuel,20);
	cout<<"\nMileage:";
	cin>>mileage;
	cin.get(ch);
	cout<<"\nTransmission:";
	cin.getline(transmission,30);
	cout<<"\nDrivetrain:";
	cin.getline(drvtrain,5);
	cout<<"\nPower:";
	cin>>hp;
	cout<<"\nBoot Space:";
	cin>>btspc;
	cout<<"\nABS(1/0):";
	cin>>abs;
	cout<<"\nAirbags:";
	cin>>airbags;
	cout<<"\nNo. of seats:";
	cin>>seats;
	cout<<"\nRating:";
	cin>>rating;
}

void cars :: output()
{
 	char abs1[3];
 	(abs==1)?strcpy(abs1,"YES"):strcpy(abs1,"NO");
 	cout<<"\nThese are your car specifications:\n\n";
 	for(int i=0;i<54;i++)
	 	cout<<"=";
 	cout<<endl<<"|"<<setw(20)<<"Code  |"<<setw(30)<<code<<"  |";
 	cout<<endl<<"|"<<setw(20)<<"Company  |"<<setw(30)<<company<<"  |";
 	cout<<endl<<"|"<<setw(20)<<"Name  |"<<setw(30)<<name<<"  |";
 	cout<<endl<<"|"<<setw(20)<<"Type  |" <<setw(30)<<type<<"  |";
 	cout<<endl<<"|"<<setw(20)<<"Price  |"<<setw(24)<<setprecision(2)<<price<<" Lakhs"<<"  |"<<endl;
 	for(i=0;i<54;i++)
	 	cout<<"-";
 	cout<<endl<<"|"<<setw(20)<<"Engine  |"<<setw(30)<<eng<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Transmission  |"<<setw(30)<<transmission<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Drivetrain  |"<<setw(30)<<drvtrain<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Fuel  |"<<setw(30)<<fuel<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Power  |"<<setw(26)<<hp<<" BHP"<<"  |";
	cout<<endl<<"|"<<setw(20)<<setprecision(2)<<"Mileage  |"<<setw(25)<<setprecision(2)<<mileage<<" KMPL"<<"  |"<<endl;
	for(i=0;i<54;i++) 
		cout<<"-";
	cout<<endl<<"|"<<setw(20)<<"No of Seats  |"<<setw(30)<<seats<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Boot Space  |"<<setw(28)<<btspc<<" L"<<"  |";
	cout<<endl<<"|"<<setw(20)<<"ABS  |"<<setw(30)<<abs1<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Airbags  |"<<setw(30)<<airbags<<"  |";
	cout<<endl<<"|"<<setw(20)<<"Rating  |"<<setw(30)<<rating<<"  |"<<endl;
	for(i=0;i<54;i++)
		cout<<"=";
}

void edit()
{
 	CLRSCR;
 	char cd,cont='y';
	cars c1;
 	while(cont=='y'||cont=='Y')
 	{
  		cout<<"Do you want to enter or delete (e/d)?:";
  		cin>>cd;
  		if(cd=='e'||cd=='E')
  		{
   			char ans='y';
   			ofstream fout("Cars.dat",ios::app|ios::binary);
   			while(ans=='y'||ans=='Y')
			{
				CLRSCR;
				c1.input();
				fout.write((char*)&c1,sizeof(c1));
				CLRSCR;
				c1.output();
				cout<<"\nDo you want to enter more cars(y/n)?:";
				cin>>ans;
			}
  		}
  		else if(cd=='d'||cd=='D')
  		{
   			int del;
   			char ans='y';
   			while(ans=='Y'||ans=='y')
   			{
				cout<<"Enter the code of car you want to delete:";
				cin>>del;
				ifstream fin("Cars.dat",ios::binary);
				ofstream fout("Temp.dat",ios::app|ios::binary);
				while(fin.read((char*)&c1,sizeof(c1)))
				{
			 		if(del==c1.getcode())
			 		{
			  			c1.output();
			  			cout<<"\nDelete(y/n)?:";
			  			char confirm;
					  	cin>>confirm;
					  	if(confirm=='n')
					   	fout.write((char*)&c1,sizeof(c1));
					}
 					else
  						fout.write((char*)&c1,sizeof(c1));
				}
				fout.close();
				fin.close();
				remove("Cars.dat");
				rename("temp.dat","Cars.dat");
				cout<<"\nDo you want to delete more(y/n):";
				cin>>ans;
   			}
  		}
  		else
   			exit(0);
  		cout<<"\nDo you want to continue editing(y/n)?:";cin>>cont;
 	}
}

