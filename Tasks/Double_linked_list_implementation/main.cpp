/*Implementing Double Linked List*/

#include<bits/stdc++.h>
using namespace std;

// creating a node

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

struct Node *head=NULL,*tail=NULL;

struct Node* insertNode(struct Node *head,int pos,int key)
{
    struct Node *temp=NULL;
    temp=new Node(key);
    if(head==NULL)
    {
        if(pos==1)
        {
            head=tail=temp;
            return head;
        }
        else
        {
            cout<<"list is empty!invalid position"<<endl;
            return head;
        }
    }
    struct Node *t,*t1;
    t=head;
    while(--pos && t!=NULL)
    {
        t1=t;
        t=t->next;
    }
    if(pos!=0 && t==NULL)
    {
        cout<<"Invalid pos:"<<endl;
        return head;
    }
    else if(pos==0 && t==NULL)
    {
        t1->next=temp;
        temp->prev=t1;
        tail=temp;
    }
    else
    {
        temp->next=t;
        temp->prev=t->prev;
        if(t->prev!=NULL)
            t->prev->next=temp;
        else
        {
            head=temp;
        }
        t->prev=temp;
    }
    return head;    
}

struct Node* deleteNode(struct Node *head,int key)
{
    if(head==NULL)
    {
        cout<<"List is Empty!"<<endl;
        return head;
    }
    struct Node *t,*t1;
    t=head;

    while(t)
    {
        if(t->data==key)
        {   
            if(t==head)
            {
                if(t->next==NULL)
                    head=tail=NULL;
                else
                {
                    head=t->next;
                    t->next->prev=NULL;
                    t->next=NULL;
                }
            }
            else if(t==tail)
            {
                tail=t->prev;
                t->prev->next=NULL;
                t->prev=NULL;
            }
            else
            {
                t->next->prev=t->prev;
                t->prev->next=t->next;
                t->next=t->prev=NULL;
            }
            return head;
        }
        t=t->next;
    }
    
    cout<<"key is not present"<<endl;
    return head;
}

bool searchNode(struct Node *head,int key)
{
    if(head==NULL)
        return false;
    struct Node *t;
    t=head;
    while(t!=NULL)
    {
        if(t->data==key)
            return true;
        t=t->next;
    }
    return false;
}

struct Node* reverseList(struct Node *head)
{
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return head;
    }
    struct Node *temp,*temp1,*pre;
    pre=NULL;temp=temp1=head;
    while(temp!=NULL)
    {
        temp1=temp1->next;
        temp->next=pre;
        if(pre!=NULL)
            pre->prev=temp;
        pre=temp;
        temp=temp1;
    }
    tail=head;
    pre->prev=NULL;
    return pre;
    
}

void displayNodes(struct Node *head)
{
    if(head==NULL)
        cout<<"list is empty!"<<endl;
    else
    {
        struct Node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

int main()
{
    int o=1,key,pos;
    while(o)
    {
        cout<<"\nEnter the operation:"<<endl;
        cout<<"************************"<<endl;
        cout<<"Enter 1 for insertion operation"<<endl;
        cout<<"Enter 2 for deletion operation"<<endl;
        cout<<"Enter 3 for search operation"<<endl;
        cout<<"Enter 4 for reverse operation"<<endl;
        cout<<"Enter 5 for display nodes"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        int ope;
        cin>>ope;
        switch(ope)
        {
            case 1:
                cout<<"Enter pos and key:"<<endl;
                cin>>pos>>key;
                head=insertNode(head,pos,key);
                break;
            case 2:
                cout<<"Enter key to delete:"<<endl;
                cin>>key;
                head=deleteNode(head,key);
                break;
            case 3:
                cout<<"Enter key to search:"<<endl;
                cin>>key;
                (searchNode(head,key))?(cout<<"key exist"<<endl):(cout<<"key doesn't exist"<<endl);
                break;
            case 4:
                head=reverseList(head);
                break;
            case 5:
                displayNodes(head);
                break;
            default:
                o=0;
        }
    }
    return 0;
}
