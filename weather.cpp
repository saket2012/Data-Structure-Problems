#include<iostream>
#include<cstdlib>
using namespace std;

class weather
{
private:
int day;
float ltemp,htemp,arain,asnow;

public:
void input(int);
void display();
int lowtemp();
weather()
{
day=99;
ltemp=-999;
htemp=999;
arain=0;
asnow=0;
}
};
int weather::lowtemp()
{
return ltemp;
}
void weather::input(int a)
{
day=a;
cout<<"\nenter the high temp";
cin>>htemp;
cout<<"\nenter the low temp";
cin>>ltemp;
cout<<"\nenter the amount of rain";
cin>>arain;
cout<<"\nenter the amount of snow";
cin>>asnow;
}


void weather::display()
{
cout<<"\t"<<day;
cout<<"\t"<<htemp;
cout<<"\t"<<ltemp;
cout<<"\t"<<arain;
cout<<"\t"<<asnow;
}

const int d=31;
int main()
{
int i,a,ch,sum=0,n;
float avg;
weather w[d];
do
{
	cout<<"\nMENU: ";
	cout<<"\n1. INSERT ";
	cout<<"\n2. DISPLAY ";
	cout<<"\n3. AVERAGE ";
	cout<<"\n4. EXIT ";
	cout<<"\nenter your choice";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"\nenter the number of days";
		cin>>n;
		for(i=0;i<n;i++)
		{
		cout<<"\nenter the day";
		cin>>a;
		w[a-1].input(a);
		}

	break;
	case 2:
		cout<<"\n\tday\thtemp\tltemp\tarain\tasnow\n";
		for(i=0;i<d;i++)
		{
		cout<<"\n"<<i+1;
		w[i].display();
		}
    break;
	case 3:
		for(i=0;i<n;i++)
		{
			sum=sum+w[i].lowtemp();
		}
		avg=sum/n;
		cout<<"\naverage low temp is "<<avg;
		break;
	case 4:
		exit(0);
		break;
	}
}while(ch!=4);
return 0;
}



