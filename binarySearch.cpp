#include<iostream>
using namespace std;
int binarySearch(int arr[], int start, int end, int key)
{
	while (start <= end) {
		
		int mid = (start + end) / 2;//both=>m = l + (r - l) / 2 both=>m = (2 l + r -l)/2

		
		if (arr[mid] == key)
			return mid;
        
		if (arr[mid] > key)
			
		end = mid - 1;

		else

		start = mid + 1;

	}

	return -1;
}
int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int num;
	cout << "Enter an Integer :";
	cin >> num;

	int result = binarySearch(arr, 0, size - 1, num);
	if(result == -1)
		cout << "The Number : (" << num << ") Was Not Found." << endl;
	else
		cout << "The Number : (" << arr[result] << ") Was Found At Index : (" << result << ")" << endl;
	
	return 0;
}