/* Pizza is a delicious circular food item that is a favorite for many people. Given the radius of the pizza, ingredients required for the preparation of the pizza, per square cm (cm2) area of the pizza and cost of its ingredients per 100 grams, design an OOP model and write a C++ program to calculate the cost of the pizza. Add Rs 50 for veg pizza and Rs 100 for chicken pizza. Use 3.14 for pi. Your program should  get all the ingredients available in the kitchen with their cost per 100 grams, as an input.  Assume that all the ingredients required for the preparation of the pizza is available in the kitchen.

Note: Syntax to print 'x' decimal places of variable 'a'

include <iomanip>

use

cout<<fixed<<setprecision(x)<<a;

Input Format

Give 0 for veg pizza and 1 for chicken pizza

Radius of pizza

Number of ingredients required for the preparation of the pizza

Name of ingredient1

Quantity of ingredient1 required (in grams)

Name of ingredient2

Quantity of ingredient2 required

....

Name of ingredient-n

Quantity of ingredient-n required

 

Number of ingredients available in the kitchen.

 

Name of ingredient-1 available in the kitchen

Cost of 100 gm of ingredient1 available in kitchen

Name of ingredient-2 in kitchen

Cost of 100 gm of ingredient2 in kitchen

....

Name of ingredient-n in kitchen

Cost of 100 gm of ingredient-n in kitchen

 

Output Format

Cost of pizza
*/

#include<iostream>
using namespace std;
#include<string.h>
#include<iomanip>
class circle
{
	protected:
	float radius;
	public:
	void get_C();
	void print_C();
	float area();
};

struct ingre_Cost
{
	char name[30];
	float price;
};

class kitchen
{
	protected:
	int num1;
	//ingredients in the kitchen and their cost
	ingre_Cost ing_Cost[20];
	public:
	void get_K();
	void print_K();
	//Given name of ingredients
	//return cost of 100gm of it
	float get_Cost(char*);
};


struct ingre_Qty
{
	char name[30];
	float qty;
};

class cookeditem
{
	protected:
	//number of ingredients
	int num;
	// names of ingredients and their quantity in
	// Pizza
	ingre_Qty ing_Qty[20];
	public:
	void get_CI();
	void print_CI();
};


//Create a class pizza that inherits circle and cookeditem
//Create another class veg_Pizza inherited that inherits pizza
//Create another class chik_Pizza inherited that inherits pizza

class pizza:public circle,public cookeditem
{
	
};

class veg_Pizza:public pizza
{
	
};

class chik_pizza:public pizza
{
	
};

int main()
{
	int ch;
	cin>>ch;
	if (ch==0)
	{
	//Create an oject for veg pizza
	veg_Pizza p;
	//get radius of circle(pizza)
	// get ingredients and quantity required for 1 square centimeter
	p.get_P();
	//get items in kitchen and their cost
	kitchen k;
	k.get_K();
	//compute cost
	p.compute_Cost(k);
	p.print_P();
	}
	else
	{
	if (ch==1)
	{
	chik_Pizza c;
	c.get_P();
	kitchen k1;
	k1.get_K();
	c.compute_Cost(k1);
	c.print_P();
	}
	}
}
