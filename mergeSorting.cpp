#include<iostream>
using namespace std; 
void merge(int arr[], int left, int mid, int right)    
{
	int i, j, k;
   //i for looping over the first array and j for the second 
	//k for looping over the new array and inserting new data 
	const int leftSubArr_size = mid - left + 1;                 
	const int rightSubArr_size = right - mid;         
	int leftSubArr[leftSubArr_size], rightSubArr[rightSubArr_size];
	for (i = 0; i < leftSubArr_size; i++)
		leftSubArr[i] = arr[left + i];
	for (j = 0; j < rightSubArr_size; j++)
		rightSubArr[j] = arr[mid + 1 + j];

	i = j = 0; 
	k = left;
   //comparing and storing the smaller value first in the new array
	while (i < leftSubArr_size && j < rightSubArr_size)
	{
		if (leftSubArr[i] <= rightSubArr[j])
		{
			arr[k] = leftSubArr[i];
			i++;
		}
		else
		{
			arr[k] = rightSubArr[j];
			j++;
		}
		k++;
	}
   //storing the rest of elements from any of the two arrays if they aren't equal in size 
	while (i < leftSubArr_size)
	{
		arr[k] = leftSubArr[i];
		i++;
		k++;
	}

	while (j < rightSubArr_size)
	{
		arr[k] = rightSubArr[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
        
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}



void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}
int main()
{

		int arr[] = { 51,0,165,-51,30,1,15,0,-15 };
		int size = sizeof(arr) / sizeof(arr[0]);//24/4=6

		mergeSort(arr, 0, size-1);
		print(arr,size);
	return 0;

	}
