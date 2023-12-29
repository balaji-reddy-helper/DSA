/*Add two numbers
Given two decimal numbers represented by two linked lists of size N and M respectively. 
The task is to return a linked list that represents the sum of these two numbers.
*/

/*
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
*/


#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}



class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node *temp,*temp1,*prev,*head1,*head2,*head;
        prev=NULL;temp=temp1=first;
        while(temp!=NULL)
        {
            temp1=temp1->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        head1=prev;
        prev=NULL;temp=temp1=second;
        while(temp!=NULL)
        {
            temp1=temp1->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        head2=prev;int c=0;
        head = new Node(0);
        temp1=head;
        while(head1!=NULL && head2!=NULL)
        {
            int s=head1->data+head2->data+c;
            temp=new Node(s%10);
            c=s/10;
            temp1->next=temp;
            head1=head1->next;
            head2=head2->next;
            temp1=temp1->next;
        }

        if(head1!=NULL)
        {
            while(head1!=NULL)
            {
                int s=head1->data+c;
                temp=new Node(s%10);
                c=s/10;
                temp1->next=temp;
                head1=head1->next;
                temp1=temp1->next;
            }
        }
        if(head2!=NULL)
        {
            while(head2!=NULL)
            {
                int s=head2->data+c;
                temp=new Node(s%10);
                c=s/10;
                temp1->next=temp;
                head2=head2->next;
                temp1=temp1->next;
            }
        }
        if(head1==NULL && head2==NULL && c>0)
        {
            temp1->next=new Node(c);
        }
        prev=NULL;temp=temp1=head->next;
        while(temp!=NULL)
        {
            temp1=temp1->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
        }
        return prev;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

