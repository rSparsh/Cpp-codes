/*
A leather manufacturing company maintains a DB with the details of their employees. The details maintained are name, employeeid, age. Age of the employees in the company can only be 18 to 50. Write a C++ function to read the details of employees from user, the function should print the details if it is valid.

When age < 18, raise an integer exception and print ‘Age cannot be less than 18’

When age > 50, raise a character exception and print ‘Age cannot be greater than 50’

Example 1

If the details entered are Ramu, E123 and 25 then print the details ramu, 123 and 25, one in each line.

Example 2

If the details entered are Ramu, E123 and 15 then raise an exception and print ‘Age cannot be less than 18’.

Example 3

If the details entered are Ramu, E123 and 55 then raise an exception and print ‘Age cannot be greater than 50’.

 

Input Format

First line contains name of the employee

Second line contains employee ID of the employee

Third line contains age of the employee

 

Output Format

Print either the details of the employee entered. One detail in each line or print ‘Age cannot be less than 18’ or ‘Age cannot be greater than 50’ when invalid age is entered
*/

#include<iostream>
using namespace std;

struct emp_details{
	char name[50];
	char emp_id[10];
	int age;
};

int main()
{
	struct emp_details emp;
	cin>>emp.name;
	cin>>emp.emp_id;
	cin>>emp.age;
	
	try{
		if(emp.age<18)
			throw 0;
		if(emp.age>50)
			throw 'a';
		}
		
	catch(int a)
	{
		cout<<"Age cannot be less than 18";
	}
	
	catch(char a)
	{
		cout<<"Age cannot be greater than 50";
	}
	
	if(emp.age>=18 && emp.age<=50)
		{
			cout<<emp.name<<endl;
			cout<<emp.emp_id<<endl;
			cout<<emp.age<<endl;
		}
		
	
	
	
}
