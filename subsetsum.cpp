#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{

    bool subset[n + 1][sum + 1];
    int i;
    for (i = 0; i <= n; i++)
        subset[i][0] = true;

    for (i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

int main()
{
    char ch;
    do
    {
        system("cls");
        int i;
        cout << "Enter the Size of the Set : ";
        int size;
        cin >> size;
        int set[size] = {0};
        cout << "Enter elements for the set : \n";
        for (i = 0; i < size; i++)
        {
            cin >> set[i];
        }
        cout << "\n\n";
        int sum = 0;
        cout << "Enter now enter the sum : ";
        cin >> sum;

        if (isSubsetSum(set, size, sum) == true)
            cout << "Subset Sum found\n\n";
        else
            cout << "No subset found\n\n";

        cout << "Do you want to continue ( y/n ) : ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}