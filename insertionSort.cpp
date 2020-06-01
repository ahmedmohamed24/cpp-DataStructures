#include<iostream>
using namespace std;
void insertionSort(int *arr, int length) {
   int temp, j;
   for(int i = 1; i<length; i++) {
      temp = arr[i];//take value
      j = i;
      while(j > 0 && arr[j-1]>temp) {
	  	//shift the item to it's right place
         arr[j] = arr[j-1];
         j--;
      }
      arr[j] = temp;//No shifting needed 
   }
   //printing the list after sorting 
   for(int i = 0; i<length; i++)
      cout << arr[i] << " ";
   cout << endl;
}
int main() {
   
   int arr[]={5,62,15,31,-15,0,-41,15,655}; 
   int length = sizeof(arr)/sizeof(arr[0]); 
   insertionSort(arr, length);
   
}