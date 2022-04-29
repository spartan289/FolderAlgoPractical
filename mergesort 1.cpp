#include<iostream>
#include <cmath>
using namespace std;

template <class T>
class Mergsort
{
    private:
    int size; //heap Size
	int length;
	int count;
    T* mergarr;

	public:
		Mergsort(){
	      size=0; 
	      length=0;
	      count=0;
          mergarr=0;
		}

        ~Mergsort(){
	      delete[] mergarr;
		}

        void merge(int l, int m, int r) {
  
        int nl = m - l + 1;
        int nr = r - m;

        int larr[nl], rarr[nr];

        for (int i = 0; i < nl; i++)
            larr[i] = mergarr[l + i];
        for (int j = 0; j < nr; j++)
            rarr[j] = mergarr[m + 1 + j];

        int i, j, k;
        i = 0;   j = 0,   k = l;

        while (i < nl && j < nr) {
            if (larr[i] <= rarr[j]) {
            mergarr[k] = larr[i];
            i++;
            } else {
            mergarr[k] = rarr[j];
            j++;
            }
            k++;
            count++;
        }

        while (i < nl) {
            mergarr[k] = larr[i];
            i++;
            k++;
        }

        while (j < nr) {
            mergarr[k] = rarr[j];
            j++;
            k++;
        }
    }


    void input(){
        cout << "\nEnter the number of elements in Merge array : ";
        cin >> length;
        count = 0;
        // length =  (rand() % (1000 - 30 + 1)) + 30;
        cout << length << "\n";
        size=length;
        mergarr=new T[length];


        cout << "\nEnter the elments of the merge array : ";
        for (int i=0; i<length; i++){
            cin>>mergarr[i];
        }

        
        // for (int i=0; i<length; i++){
        //     mergarr[i] = rand()%1500;
        // }

    }

    void mergeSort( int l, int r) {

        if (l < r) {    
        
            int m = l + (r - l) / 2;
            mergeSort( l, m);
            mergeSort( m + 1, r);
            merge( l, m, r);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << mergarr[i] << " ";
        cout << endl;
    }

    int getsize(){
        return size;
    }

    int displaycount(){
        return count;
    }


};


int main(){

    char choice;
    Mergsort<int> prac;

    do{
        prac.input();

        cout << "\n\nElement before sorting : ";
        prac.display();

        prac.mergeSort(0, prac.getsize() - 1);

        cout << "\n\nElement after sorting : ";
        prac.display();

        cout << "\nNumber of Comparisons : " << prac.displaycount() << "\n\n";

        cout << "\nwant to continue again (y/n) : ";
        cin >> choice;

        if ( choice == 'n' || choice == 'N'){
            cout << "\nProgram ended succesfully.\n";
        }
    }while (choice ==  'y' || choice == 'Y');
}