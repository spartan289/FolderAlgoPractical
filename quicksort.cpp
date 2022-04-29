
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template <class T>
class quicksort
{
    private:
    int size;
	int count=0;
    T* arr;

    public:
    quicksort(){
	    int size=0;
	    int count=0;
        T* arr=0;
	}

    ~quicksort(){
	    delete[] arr;
	}

    
    void input(){
        cout << "\nEnter the number of elements in Array : ";
        cin >> size;
        arr=new T[size];

        cout << "\nEnter the elments of the array : ";
        for (int i=0; i<size; i++){
            cin>>arr[i];
        }
        
    }

    int partition( int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);
    
        for (int j = low; j <= high - 1; j++)
        {
            if (++count && arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
 
    int partition_r( int low, int high)
    {
        srand(time(NULL));
        int random = low + rand() % (high - low);
        swap(arr[random], arr[high]);
        return partition(low, high);
    }


    void quickSort(int low, int high)
    {
        if (low < high) {
            int pi = partition_r(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    int getsize(){
        return size;
    }

    int no_of_comparisons(){
        return count;
    }

    void display()
    {
        for (int i=0; i< size; i++){
            cout<<arr[i]<<" ";
        }
        cout << endl;
    }

};



int main(){

    char choice;
    quicksort<int> prac;

    do{
        prac.input();

        cout << "\n\nElement before sorting : ";
        prac.display();

        prac.quickSort(0,prac.getsize()-1);

        cout << "\n\nElement after sorting : ";
        prac.display();

        cout << "\n\nNo of Comparisons are : " << prac.no_of_comparisons();

        cout << "\nwant to continue again (y/n) : ";
        cin >> choice;

        if ( choice == 'n' || choice == 'N'){
            cout << "\nProgram ended succesfully.\n";
        }
    }while (choice ==  'y' || choice == 'Y');
}