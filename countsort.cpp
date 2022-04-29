#include<iostream>
using namespace std;

class countsort
{
    private:
    int size;
    int* array;
    int max;
    int min;

	public:
		countsort(){
	      size = 0;
          max = 0;
          min = 0; 
          array = 0;
		}

        ~countsort(){
	      delete[] array;
		}

        
        int MaxCal() {
            max = array[0];
            
            for (int i = 0; i < size; i++){
                if( array[i] > max){
                    max = array[i];
                }
            }

            return max;
        }

        int MinCal() {
            min = array[0];

            for (int i = 0; i < size; i++){
                if ( array[i] < min ){
                    min = array[i];
                }
            }

            return min;
        }

        void Cosort() 
        {
            int min = MinCal();
            int max = MaxCal();
            int s = (max-min)+1;

            int* counts = new int[s];
            int i = 0;
            for (i = 0; i < s; i++){
                counts[i] = 0;
            }
            
            for (i = 0; i < size; i++){
                counts[array[i] - min ]++;
            }

            for (i = 1; i < s ; i++){
                counts[i] = counts[i] + counts[i - 1];
            }

            int* store = new int[size];
            for ( i = size - 1;  i >= 0 ; i--){
                store[counts[array[i] - min ] - 1] = array[i];
                counts[array[i] - min]--;
            }

            for ( i = 0; i < size; i++){
                array[i] = store[i];
            }

            delete[] counts;
            delete[] store;
            return;
        }


        void input(){
            cout << "\nEnter the number of elements in Array : ";
            cin >> size;
            array=new int[size];

            cout << "\nEnter the elments of array : ";
            for (int i=0; i<size; i++){
                cin>>array[i];
            }
        }

        void display()
        {
            for (int i = 0; i < size; i++)
                cout << array[i] << " ";
            cout << endl;
        }
};

int main(){
    char choice;
    countsort prac;
    do{
        prac.input();
        cout << "\n\nElement before sorting : ";
        prac.display();
        prac.Cosort();
        cout << "\n\nElement after sorting : ";
        prac.display();
        cout << "\nwant to continue again (y/n) : ";
        cin >> choice;
        if ( choice == 'n' || choice == 'N'){
            cout << "\nProgram ended succesfully.\n";
        }
    }while (choice ==  'y' || choice == 'Y');
}