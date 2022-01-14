#include<iostream>
using namespace std;
#include<string>
#include<map>
struct guest
{
	int room_No;
	string name;
	int friend_Room_No;
	public:
	void get();	
};
class hotel
{
	int num_Of_Guest;
	map<int,guest> stay_Det;
	
	int first_Room_No;
	public:
	void get();
	void serve_Coffee();
};



void hotel::get()
{
	cin>>num_Of_Guest;
	struct guest Guest[num_Of_Guest];
	for(int i=0;i<num_Of_Guest;i++)
	{
		cin>>Guest[i].room_No;
		cin>>Guest[i].name;
		cin>>Guest[i].friend_Room_No;
	}
	
	cin>>first_Room_No;
	
	for(int i=0;i<num_Of_Guest;i++)
	{
		stay_Det.insert(pair<int,guest>(Guest[i].room_No,Guest[i]));
	}
	
	
/*	int itr=stay_Det.at(first_Room_No);
	
	
	for(int i=0;i<num_Of_Guest;i++)
	{ 
		if(i!=itr)
		{
		//	itr1 stay_Det.find()
		}
	}*/
	
	
}


void hotel::serve_Coffee()
{
	cout<<"done";
}

main()
{
	hotel h;
	h.get();
	h.serve_Coffee();
}
