#include <iostream>
using namespace std;

int gcd(int x, int y);

int main()
{
   int x, y;

   cout << "Enter two positive integers: ";
   cin >> x >> y;

   cout << "GCD of " << x << " & " <<  y << " is: " << gcd(x, y);

   return 0;
}

int gcd(int x, int y)
{
    if (y != 0)
       return gcd(y, x % y);
    else 
       return x;
}

