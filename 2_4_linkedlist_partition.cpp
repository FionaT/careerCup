#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 [question]
 
 2.4
 You have two numbers represented by a linked list, where each node contains a sin-
 gle digit   The digits are stored in reverse order, such that the 1’s digit is at the head of
 the list   Write a function that adds the two numbers and returns the sum as a linked
 list
 EXAMPLE
 Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
 Output: 8 -> 0 -> 8
 
 [solution]
 Create two linked lists
 then combine them
 
 [time complexity]
 O(n) scan the linked list
 
 [space complexity]
 O(n) space for the two new linked list
 
 [gist link]

 
 [test case]
 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);
    ListNode *temp1 = l1, *temp2 = l2;
    
    while(head){
        if(head->val < x){
            
            ListNode *node = new ListNode(head->val);
            
            temp1->next = node;
            temp1 = node;
            
        }else{
            ListNode *node = new ListNode(head->val);
            
            temp2->next = node;
            temp2 = node;
        }
        
        head = head->next;
    }
    
    temp1->next = NULL;
    temp2->next = NULL;
    
    temp1->next = l2->next;
    
    return l1->next;
}


int main(int argc, const char * argv[]){
    vector<int> num;
    int arr[6] = {1, 4, 3, 2, 5, 2};
    
    ListNode *head = new ListNode(arr[0]);
    ListNode *last = head;
    
    for(int i = 1; i < 6; i++){
        ListNode *temp = new ListNode(arr[i]);
        last->next = temp;
        
        last = temp;
    }
    
    last = head;
    
    while(last != NULL){
        cout<<last->val<<" ";
        last = last->next;
    }
    
    cout<<endl;
    
    ListNode *ans = partition(head, 4);
	
	
    while(ans != NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    
    cout<<endl;
	
    return 0;
}





