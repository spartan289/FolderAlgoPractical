#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int i)
{
    int output[n];
    int j, count[10] = { 0 };
 
    
    for (j = 0; j < n; j++)
        count[(arr[j] / i) % 10]++;
 
    //setting position of each element
    for (j = 1; j < 10; j++)
        count[j] += count[j - 1];
 
    //output array
    for (j = n - 1; j >= 0; j--) {
        output[count[(arr[j] / i) % 10] - 1] = arr[j];
        count[(arr[j] / i) % 10]--;
    }
 
    // original array is arranged in the same way as the output array
    for (j = 0; j < n; j++)
        arr[j] = output[j];
}
 

void radixsort(int arr[], int n) {
    int maxEle = getMax(arr, n);
 
    /*
    first we need to check numbers from 0 to 9
    then from 0 to 99
    then from 0 to 999 and so on
    we need to check numbers from 0 till (and excluding) 10^i
    */
    for (int i = 1; maxEle / i > 0; i *= 10)
        countSort(arr, n, i);
}


int main()
{   
    int n;
    cout<<"How many numbers do you want to enter?\n";
    cin>>n;

    cout<<"Enter "<<n<<" number(s):\n";
    int input, arr[n];
    for(int i=0;i<n;i++){
        cin>>input;  
        arr[i] = input;  
    }
     

    radixsort(arr, n);
    
    cout<<"The sorted array is:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}