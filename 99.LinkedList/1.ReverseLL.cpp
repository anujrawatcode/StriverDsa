#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    //contructor
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct LinkedList
{
    node *head;
    LinkedList() { head == NULL; }

    void push(int data)
    {
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }

    void print()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void reverse(node *head)
    {
        node *pre = NULL;
        node *curr = head;
        node *nxt = NULL;

        while (curr)
        {
            nxt = curr->next;

            curr->next = pre;

            pre = curr;
            curr = nxt;
        }
        head = pre;
    }
};

int main()
{
}