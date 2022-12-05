#include <iostream>
#include <algorithm>

using namespace std;

struct Pair{
	int min;
	int max;
};

Pair getMinMax(int arr[], int n){
	struct Pair minmax;	
	int i;
	
	
	if (n == 1){
		minmax.max = arr[0];
		minmax.min = arr[0];	
		return minmax;
	}
	
	if (arr[0] > arr[1]){
		minmax.max = arr[0];
		minmax.min = arr[1];
	} 

	else{
		minmax.max = arr[1];
		minmax.min = arr[0];
	}
	
	for(i = 2; i < n; i++){
		if (arr[i] > minmax.max)	
			minmax.max = arr[i];
			
		else if (arr[i] < minmax.min)	
			minmax.min = arr[i];
	}
	return minmax;
}


int main(){
    int n = 7;
	int arr[] = { 12, 10, 67,12, 33, 4000,8};
	
	struct Pair minmax = getMinMax(arr, n);
	
	cout << "min "<< minmax.min << endl;
	cout << "max "<< minmax.max;
	return 0;
}


