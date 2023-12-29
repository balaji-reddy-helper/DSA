/*
Given a linked list consisting of L nodes and given a number N. The task is to remove the Nth node from the end of the linked list.

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 1->2->3->4->5->6->7->9
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end is 8.
*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


int getNthFromLast(struct Node* head, int n);

class Solution{
public:
    Node* removeNthFromLast(Node *head, int n)
    {
        int cn=0;
        struct Node *temp=head,*temp1;
        while(temp!=NULL)
        {
            cn++;
            temp=temp->next;
        }
        n=cn-n+1;
        temp=head;
        if(n==1)
        {
            head=head->next;
            temp->next=NULL;
            return head;
        }
        while(--n && temp!=NULL)
          {
            temp1=temp;
            temp=temp->next;
          }
        temp1-next=temp->next;
        temp->next=NULL;
        free(temp);
        return head;
    }
};


int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    Node *res=obj.removeNthFromLast(head, k)<<endl;
    Node *temp=res;
    while(temp!=NULL)
      cout<<temp->data<<" ";
    }
    return 0;
}
