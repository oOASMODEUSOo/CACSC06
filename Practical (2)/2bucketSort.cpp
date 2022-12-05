#include <iostream>
using namespace std;

int Max(int list[], int length){  //function returning the max from array
    int maximum = list[0];
    for (int i = 1; i < length; i++)
        if (list[i] > maximum){
            maximum = list[i];
        }
    return maximum;
}

void bucketSort(int list[], int length){
    int bucket[10];
    int maximum = Max(list, length);
    for (int i = 0; i <= maximum; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        bucket[list[i]]++;
    }
    for (int i = 0; i <= maximum; i++)
    {
        static int j = 0;
        while (bucket[i] > 0)
        {
            list[j++] = i;
            bucket[i]--;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of counts for taking BP details: "<<endl;
    cin>>n;
    int * BP = new int[n];
    cout<<"Enter BP data: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>BP[i];
    }
    bucketSort(BP,n);
    cout<<"Max BP recorded: "<<BP[n-1]<<endl;
    cout<<"Min BP recorded: "<<BP[0]<<endl;
    return 0;
}

