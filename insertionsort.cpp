#include <bits/stdc++.h>
using namespace std;

template <class T>
class InsertionSort
{
private:
    int size;
    int count = 0;
    T *array;

public:
    InsertionSort()
    {
        int size = 0;
        int count = 0;
        T *array = 0;
    }

    ~InsertionSort()
    {
        delete[] array;
    }

    void input()
    {

        // size= (rand() % (1000 - 30 + 1)) + 30;
        cout << "\nEnter the number of elements : ";
        cin >> size;
        array = new T[size];

        cout << "\nEnter the elements : ";

        for (int i = 0; i < size; i++)
        {
            cin >> array[i];
        }

        // for (int i=0; i < size; i++)
        //     array[i]= rand()%1500;
    }

    int no_of_comparisons()
    {
        return count;
    }

    int Size()
    {
        return size;
    }

    void insertion_sort()
    {
        for (int i = 1; i < size; i++)
        {
            int current = array[i];
            int j = i - 1;
            while (array[j] > current && ++count && j >= 0)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = current;
        }
    }

    void display()
    {

        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl;
    }
};

int main()
{

    InsertionSort<int> prac;

    char choice;
    vector<int> adjList;
    adjList.

        do
    {
        prac.input();

        cout << "\n\nElement before sorting : ";
        prac.display();

        prac.insertion_sort();

        cout << "\n\nElement after sorting : ";
        prac.display();

        cout << "\nNumber of Comparisons : " << prac.no_of_comparisons() << "\n\n";

        cout << "\nwant to continue again (y/n) : ";
        cin >> choice;

        if (choice == 'n' || choice == 'N')
        {
            cout << "\nProgram ended succesfully.\n";
        }
    }
    while (choice == 'y' || choice == 'Y')
        ;

    return 0;
}
