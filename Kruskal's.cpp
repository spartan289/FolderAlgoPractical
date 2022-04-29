#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Kruskal
{
private:
	vector<pair<int, pair<int, int>>> vert_list;
	vector<pair<int, pair<int, int>>> mstTree;
	int vertSize;
	int edgeSize;
	int *setName;

public:
	Kruskal()
	{
		vertSize = 0;
		edgeSize = 0;
		setName = 0;
	}
	~Kruskal() { delete[] setName; }

	void input();
	int findSetName(int i);
	void Union(int u, int v);
	void kruskal();
	void printMst();
	int mstLength();
};

void Kruskal ::input()
{
	cout << "\n\nEnter the details of vertices of graph\n\n";
	cout << "\nEnter the number of vertex :   ";
	cin >> vertSize;

	setName = new int[vertSize];
	for (int i = 0; i < vertSize; i++)
	{
		setName[i] = i;
	}

	cout << "\n\nEnter the details of edges of graph\n\n";
	cout << "\nHow many edges in your graph?  :   ";
	cin >> edgeSize;

	for (int i = 0; i < edgeSize; i++)
	{
		int vert1, vert2, wt;

		cout << "\n\nEnter the vertices that joined by edge e" << i + 1 << endl
			 << endl;
		cout << "Enter first vertex  :  ";
		cin >> vert1;
		cout << "Enter second vertex :  ";
		cin >> vert2;
		cout << "\nEnter the weight of edge e" << i + 1 << " :   ";
		cin >> wt;

		if ((vert1 > 0 && vert1 <= vertSize) && (vert2 > 0 && vert2 <= vertSize))
		{
			vert_list.push_back(make_pair(wt, make_pair(vert1 - 1, vert2 - 1)));
		}
		else
		{
			i--;
			cout << "\n\nVertex does'nt exist\n";
		}
	}

	cout << endl
		 << endl;

	return;
}

int Kruskal ::findSetName(int i)
{
	if (i == setName[i])
		return i;
	else
		return findSetName(setName[i]);
}

void Kruskal ::Union(int u, int v)
{
	setName[u] = setName[v];
}

void Kruskal ::kruskal()
{
	int uSetname, vSetname, k = 0;
	sort(vert_list.begin(), vert_list.end());

	for (int i = 0; i < vert_list.size(); i++)
	{
		uSetname = findSetName(vert_list[i].second.first);
		vSetname = findSetName(vert_list[i].second.second);

		if (uSetname != vSetname)
		{
			mstTree.push_back(vert_list[i]);
			Union(uSetname, vSetname);
		}
	}

	return;
}

void Kruskal ::printMst()
{
	cout << "\nVertex explored in order:   {\n";

	for (int i = 0; i < mstTree.size(); i++)
	{
		cout << endl
			 << "" << mstTree[i].second.first + 1 << "  -->  " << mstTree[i].second.second + 1 << " :  " << mstTree[i].first;
	}

	cout << "\n\n   }";
}

int Kruskal ::mstLength()
{
	int sum = 0;

	for (int i = 0; i < mstTree.size(); i++)
		sum = sum + mstTree[i].first;

	return sum;
}

int main()
{
	char option;
	int source;

	do
	{
		system("cls");
		Kruskal ob;
		ob.input();

		ob.kruskal();
		cout << "\n\nMinimum Spanning Tree\n";
		ob.printMst();

		cout << "\n\nLength of Minimum spanning tree is :   ";
		cout << ob.mstLength() << endl;
		cout << "\n\nDo you want to continue(y/n) :       ";
		cin >> option;

	} while (option == 'y' || option == 'Y');

	return 0;
}