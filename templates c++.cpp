// CPP code for bubble sort 
// using template function 
#include <iostream> 
using namespace std; 

// A template function to implement bubble sort. 
// We can use this for any data type that supports 
// comparison operator < and swap works for it. 
template <class T> 
void bubbleSort(T a[], int n) { 
	for (int i = 0; i < n - 1; i++) 
		for (int j = n - 1; i < j; j--) 
			if (a[j] < a[j - 1]) 
			swap(a[j], a[j - 1]); 
} 

// Driver Code 
int main() { 
	char a[5] = {'d','g','e','z','o'}; 
	int n1 = sizeof(a) / sizeof(a[0]); 

int b[5] = {10, 50, 30, 40, 20}; 
    int n2 = sizeof(b) / sizeof(b[0]);
	// calls template function 
	bubbleSort(a, 5);
	bubbleSort(b, 5);  

	cout << " Sorted array 'a' : "; 
	for (int i = 0; i < n1; i++) 
		cout << a[i] << " "; 
	cout << endl;
	
		cout << " Sorted array 'b' : "; 
	for (int i = 0; i < n2; i++) 
		cout << b[i] << " "; 
	cout << endl; 

return 0; 
} 

