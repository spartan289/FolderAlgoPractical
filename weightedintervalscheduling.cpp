#include <iostream>
using namespace std;

class weightedintervalschedule
{
	int **arr;
	int *m;
	int size;

public:
	weightedintervalschedule(int n)
	{
		size = n + 1;
		m = new int[size];
		arr = new int *[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new int[4];
		}
	}

	void sort()
	{
		for (int i = 1; i < size - 2; i++)
		{
			for (int j = i + 1; j < size - 1; j++)
			{

				if (arr[i][1] > arr[j][1])
				{
					swap(arr[i][0], arr[j][0]);
					swap(arr[i][1], arr[j][1]);
					swap(arr[i][2], arr[j][2]);
				}
			}
		}
	}

	int maximum(int v1, int v2)
	{
		if (v1 > v2)
			return v1;
		else
			return v2;
	}

	void input()
	{
		int s, f, w;
		arr[0][0] = 0;
		arr[0][1] = 0;
		arr[0][2] = 0;
		for (int i = 1; i < size; i++)
		{
			cout << "\nEnter the start,finish and weight of schedule number " << i << endl;
			cin >> s >> f >> w;
			arr[i][0] = s;
			arr[i][1] = f;
			arr[i][2] = w;
		}
	}

	void OPT()
	{
		sort();
		arr[0][3] = 0;
		for (int i = 1; i < size; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (arr[j][1] <= arr[i][0])
				{
					arr[i][3] = j;
					break;
				}
			}
		}

		cout << "\nValue of p(i) of each schedule: \n";
		for (int i = 1; i < size; i++)
		{
			cout << "p(" << i << ") : " << arr[i][3] << endl;
		}

		m[0] = 0;
		for (int i = 1; i < size; i++)
		{
			m[i] = maximum((arr[i][2] + m[arr[i][3]]), m[i - 1]);
		}

		cout << "\nOptimal value at each schedule: \n";
		for (int i = 1; i < size; i++)
		{
			cout << "m(" << i << ") : " << m[i] << endl;
		}

		cout << "\nSolution for weighted scheduling algorithm: \n";
		cout << "\t\t Start Time\tEnd Time\tWeight\n";
		find_solution(size - 1);
		cout << "\nOptimal Solution of the problem is: " << m[size - 1];
	}

	void find_solution(int x)
	{
		if (x != 0)
		{
			if ((arr[x][2] + m[arr[x][3]]) > m[x - 1])
			{
				find_solution(arr[x][3]);
				cout << "Schedule " << x << " :\t\t" << arr[x][0] << "\t " << arr[x][1] << "\t\t" << arr[x][2] << endl;
			}
			else
			{
				find_solution(x - 1);
			}
		}
	}

	void display()
	{
		cout << endl;
		cout << "\t\t Start Time\tEnd Time\tWeight\n";
		for (int i = 1; i < size; i++)
		{
			cout << "Schedule " << i << " :\t\t" << arr[i][0] << "\t " << arr[i][1] << "\t\t" << arr[i][2] << endl;
		}
	}
};

int main()
{
	cout << "\t\t WEIGHTED INTERVAL SCHEDULING\t\t";
	cout << endl
		 << "Enter the number of schedules: ";
	int n;
	cin >> n;
	weightedintervalschedule *w = new weightedintervalschedule(n);
	w->input();
	w->display();
	w->OPT();
}