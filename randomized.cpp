
#include <iostream>
using namespace std;

int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	int temp = 0;
	int s = 0;
	// cout<<"\ndef";
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	s = A[i + 1];
	A[i + 1] = A[r];
	A[r] = s;
	return i + 1;
}

int random_part(int A[], int p, int r)
{
	int i = rand() % (r - p) + p;
	// cout<<"\nRandom no: "<<i<<" ";
	int temp = A[r];
	A[r] = A[i];
	A[i] = temp;
	return Partition(A, p, r);
}

int Randomised_Select(int A[], int p, int r, int i)
{
	if (p == r)
	{
		return A[p];
	}
	int q = random_part(A, p, r);
	int k = q - p + 1;
	if (i == k)
	{
		return A[q];
	}
	else if (i < k)
	{
		return Randomised_Select(A, p, q - 1, i);
	}
	else
	{
		return Randomised_Select(A, q + 1, r, i - k);
	}
}

int main()
{
	int n, i, x;
	cout << "\nEnter the size of the array: ";
	cin >> n;
	int A[n];
	cout << "\nEnter the elements of array: ";
	for (int j = 0; j < n; j++)
	{
		cin >> A[j];
	}

	cout << "\nSpecify position of smallest element that you want: ";
	cin >> i;

	x = Randomised_Select(A, 0, n - 1, i);
	cout << "\n"
		 << i << "th smallest number is: " << x;

	return 1;
}
