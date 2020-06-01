#include <iostream> 
using namespace std;
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void bubbleSort(int arr[], int length) 
{
	int counter=0;
	for (int i = 0; i < length-1; i++) 
	{ 
		for (int j = 0; j < length-i-1; j++) 
		{ 
			if (arr[j] > arr[j+1]) 
			{ 
				swap(&arr[j], &arr[j+1]); 
				counter++;
			} 
		} 
		if (counter == 0) //when no swaps occurs (the list is sorted)
			break; 
		counter=0;//reIntialize for the new turn
	} 
	//looping and printing the result 
	for (int i=0; i < length; i++) 
		cout<<arr[i]<<" ";
	cout<<endl;
} 

int main() 
{ 
	int arr[] = {-20,15,35,10,0,-51,51}; 
	int length = sizeof(arr)/sizeof(arr[0]); 
	bubbleSort(arr, length); 
	return 0; 
} 
