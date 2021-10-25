#include <iostream>

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main()
{
	int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
	int res1, res2, res3, res4;

	res1 = minInArray1(arr, 10);
	res2 = minInArray2(arr, 0, 9);
	std::cout << res1 << ' ' << res2 << std::endl; //should both be -9

	res3 = minInArray2(arr, 2, 5);
	res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
	std::cout << res3 << ' ' << res4 << std::endl; //should both be 3

	return 0;
}

/*
finds the minimum element in the array by setting temp to the first element when the base case is reached recursively,
when the stack call pops off temp from the base case is compared to the next element in the array and if the next element is smaller
then it becomes temp and is returned for the next function call on the stack to compare against
*/
int minInArray1(int arr[], int arrSize) {
	int temp = 0;
	if (arrSize == 1) {
		temp = arr[0];
	}
	else {
		temp = minInArray1(arr, arrSize - 1);
		if (temp > arr[arrSize - 1]) {
			temp = arr[arrSize - 1];
		}
	}
	return temp;
}

/*
finds the minimum element in the array by setting temp to the first element when the base case is reached recursively,
instead of using arrSize we see if high is equal to low. we basically use high as the recusive iterator and compare it to low
after the base case pops of the stack we compare temp to the next arr element and if smaller, set that to temp.
*/
int minInArray2(int arr[], int low, int high) {
	int temp = 0;
	if (high == low) {
		temp = arr[low];
	}
	else {
		temp = minInArray2(arr, low, (high-1));
		if (temp > arr[high - 1]) {
			temp = arr[high - 1];
		}
	}
	return temp;
}