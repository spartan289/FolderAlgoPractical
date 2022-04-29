#include <iostream>
using namespace std;

class node // class for creating a node
{
	float data;
	node *prev;
	node *next;

public:
	node(float val = 0.0, node *ptr = 0, node *temp = 0)
	{
		data = val;
		prev = ptr;
		next = temp;
	}
	friend class DLL;
	friend class b_sort;
};

class DLL
{
	node *head, *tail;

public:
	DLL() // creates sentinal nodes: head and tail
	{
		head = new node();
		tail = new node();
		tail->prev = head;
		head->next = tail;
	}
	~DLL()
	{
		node *ptr;
		// cout<<"\n\tDestructor called.";
		for (ptr = head; head; ptr = head)
		{
			head = head->next;
			delete ptr;
		}
	}
	void insert(node *, float);
	void insert_tail(float);
	bool isempty();
	friend class b_sort;
};

void DLL::insert(node *v, float x) // function to add node to the left of existing node
{
	node *u = new node(x);
	u->next = v;
	u->prev = v->prev;
	v->prev->next = v->prev = u;
	return;
}

void DLL::insert_tail(float x)
{
	insert(tail, x);
	return;
}

bool DLL::isempty()
{
	return (head->next == tail);
}

class b_sort
{
	int n;	  // size
	float *A; // array
	DLL *bucket;
	float max;

public:
	b_sort(int x)
	{
		n = x;
		A = new float[n];
		bucket = new DLL[n];
	}
	void input()
	{
		cout << "\nEnter the array: ";
		for (int i = 0; i < n; i++)
			cin >> A[i];
	}
	void Max() // finds maximum element
	{
		max = A[0];
		for (int i = 0; i < n; i++)
		{
			if (max < A[i])
				max = A[i];
		}
	}
	void fill() // insert elements in bucket
	{
		Max();
		int r = (max + 1) / n;
		int z;
		for (int i = 0; i < n; i++)
		{
			z = A[i] / r;
			bucket[z].insert_tail(A[i]);
		}
		Insertion_sort();
		combine();
	}
	void Insertion_sort()
	{
		float temp;
		for (int i = 0; i < n; i++)
		{
			if (!bucket[i].isempty())
			{
				if (bucket[i].head->next->next != bucket[i].tail)
				{
					node *curr = bucket[i].head->next->next;
					do
					{
						temp = curr->data;
						node *ptr = curr->prev;
						while (ptr != bucket[i].head && ptr->data > temp)
						{
							ptr->next->data = ptr->data;
							ptr = ptr->prev;
						}
						ptr->next->data = temp;
						curr = curr->next;
					} while (curr != bucket[i].tail);
				}
			}
		}
	}
	void combine()
	{
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (!bucket[i].isempty())
			{
				node *curr = bucket[i].head->next;
				while (curr != bucket[i].tail)
				{
					A[j] = curr->data;
					curr = curr->next;
					j++;
				}
			}
		}
	}
	void Print()
	{
		cout << "\nSorted array is: ";
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
	}
};

int main()
{
	int n;
	cout << "\nEnter the size of array: ";
	cin >> n;
	b_sort B(n);
	B.input();
	B.fill();
	B.Print();

	return 1;
}
