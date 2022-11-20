#include <iostream> 

using namespace std; 

void merge(int array[], int const left, int const mid, int const right){
    auto const subArrayOne = mid - left + 1;  //these are the lenghts for the new subArrays
    auto const subArrayTwo = right - mid;

    //create temp arrays
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    //copy data from main array to the new arrays
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
     for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    //copying the elements while the index of both the subarrays are in limits
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }

        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    //copying the elements while only elements in the left subarrays remains
    while (indexOfSubArrayOne < subArrayOne){
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    //copying the elements while only the elements in the right subarray remains
    while (indexOfSubArrayTwo < subArrayTwo){
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end){
    if (begin >= end) //base case for ending the recusive call
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array , mid + 1 , end);
    merge(array, begin , mid, end);
}

void printArray(int arr[] , int N){
    for (int i = 0 ; i < N ; i++)
        cout << arr[i] << "\n";
}

int main(){ 

    int arr[6] = {12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    for (int i = 0 ; i < N ; i++){
        cout << arr[i] << " ";
    }
    
    mergeSort(arr, 0 , N-1);

    cout << "After: ";
    for (int i = 0 ; i < N ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}