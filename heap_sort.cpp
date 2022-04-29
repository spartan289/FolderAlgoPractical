#include<iostream>
#include <cmath>
using namespace std;

template <class T>
class HeapSort
{
    private:
    int heapsize; //heap Size
	int length;
	int count;
    T* heaparr;

	public:
		HeapSort(){
	      heapsize=0; 
	      length=0;
	      count=0;
          heaparr=0;
		}

        ~HeapSort(){
	      delete[] heaparr;
		}


        void input(){
            cout << "\nEnter the number of elements in heap : ";
            cin >> length;
            heapsize=length;
            heaparr=new T[length+1];

            cout << "\nEnter the elments of the heap : ";
            for (int i=1; i<length+1; i++){
                cin>>heaparr[i];
            }

            // for (int i=1; i<length+1; i++){
            //     heaparr[i] = rand()%200;
            // }
        }


        int  max_heapify(int i)
        {

            int left = 2*i;
            int right = 2*i+1;
            int largest=i;
            if(left<=heapsize && ++count && heaparr[left]>heaparr[i] )
            largest = left;
            else
                largest = i;
            if(right<=heapsize && ++count && heaparr[right]>heaparr[ largest] )
                largest = right;
            if(largest != i){
                swap(heaparr[i],heaparr[largest]);
                max_heapify(largest);
            }
        }

        void BuildMaxHeap()
        {
            for(int i=heapsize/2; i>=1;i--)
                max_heapify(i);

        }

        void heapSort(){

            BuildMaxHeap();
            for(int i=length; i>=2;i--){
                swap(heaparr[1],heaparr[i]);
                heapsize=heapsize-1;
                max_heapify(1);
            }

            cout << "\nNumber of comparisons are : " << count;
        }

        void display()
        {
            for (int i=1; i<=length; i++){
                cout<<heaparr[i]<<" ";
            }
            cout << endl;
        }


};


int main(){

    char choice;
    HeapSort<int> prac;

    do{
        prac.input();

        cout << "\n\nElement before sorting : ";
        prac.display();

        prac.heapSort();

        cout << "\n\nElement after sorting : ";
        prac.display();

        cout << "\nwant to continue again (y/n) : ";
        cin >> choice;

        if ( choice == 'n' || choice == 'N'){
            cout << "\nProgram ended succesfully.\n";
        }
    }while (choice ==  'y' || choice == 'Y');
}