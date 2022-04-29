#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Linkedlist
{
public:
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }
    void insert(int data)
    {
        if (head == NULL)
            head = new Node(data);
        else
        {
            Node *temp = head;
            if (temp->next == NULL)
                temp->next = new Node(data);
            else
            {
                Node *newnode = new Node(data);
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }
};
class Graph
{
public:
    int vertex;
    int c = 0;
    Linkedlist *arr = new Linkedlist[vertex];

public:
    Graph(int v)
    {
        vertex = v;
    }
    void addEdge(int s, int d)
    { // s->kisme daalni hai , d->value jo daalni hai
        cout << s << " " << d << endl;
        bool flag = false;
        for (int i = 0; i < vertex; i++)
        {
            cout << " " << i << " ";
            Linkedlist src = arr[i];
            src.head->data = 5;

            cout << src.head->data << " ";
            if (src.head->data == s)
            {
                cout << 1;
                src.insert(d);
                flag = true;
                cout << d;
            }
        }
        if (!flag)
        {
            Linkedlist src = arr[c];
            src.insert(d);
            cout << d;
            c++;
        }
    }

    void printGraph()
    {
        cout << "Hello World";
        for (int i = 0; i < vertex; i++)
        {
            Node *temp = arr[i].head;
            while (temp->next != NULL)
            {
                cout << temp->data << "-> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << -2147483648 << endl;
    Graph graph(5);
    cout << -2147483648 << endl;

    graph.addEdge(0, 1);
    cout << -2147483648 << endl;

    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(3, 0);
    cout << "hello world;";
    graph.printGraph();
    cout << -1;
    return 0;
}