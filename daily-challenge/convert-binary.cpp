// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.

#include<bits/stdc++.h>
using namespace std;


  //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int size=0;
        while(temp){
            temp=temp->next;
            size++;
        }
        size--;
        int num=0;
        while(head){
            num += head->val*pow(2,size);
            size--;
            head=head->next;
        }
        return num;
    }
};