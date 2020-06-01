#include <iostream> 
using namespace std; 

void swap(int *x, int *y);
void selectionSort(int arr[], int length) 
{ 
	int temp; 
	for (int i = 0; i < length-1; i++) 
	{ 
		temp = i; 
		for (int j = i+1; j < length; j++) 
		if (arr[j] < arr[temp]) 
			temp = j; 
		swap(&arr[temp], &arr[i]); 
	} 
	for (int i=0; i <length; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 
int main() 
{ 
	int arr[] = {5,32,1,0,-41,15,20,0,-5,13}; 
	int length = sizeof(arr)/sizeof(arr[0]); //for getting length of the array
	selectionSort(arr, length); 
	return 0; 
} 


void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 