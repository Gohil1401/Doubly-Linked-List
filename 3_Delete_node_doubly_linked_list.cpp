#include<iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
}*first=NULL;

class List
{
    public:

    void create(int a[],int n);
    void Delete(int index);
    void display();
};

void List::create(int a[],int n)
{
    node *last,*t;

    first=new node;
    first->data=a[0];
    first->next=first->prev=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void List::Delete(int index)
{
    node *p;
    int x;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
        if(first)
        {
            first->prev=NULL;
        }

    }
    else
    {
        p=first;

        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        delete p;
    }
}

void List::display()
{
    node *p=first;
    cout<<"your list is : ";

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    int a[]={10,20,30,40,50};
    List l;
    l.create(a,5);
    l.display();
    cout<<endl;
    l.Delete(5);
    l.display();
}

