#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 [question]
 
 2.5
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
  O(n) scan the two linked lists
  n depend on the size of the longer linked list
 
 [space complexity]
  O(n) space for the new result linked list
  n depend on the size of the longer linked list
 
 [gist link]

 
 [test case]
 
 */

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
	ListNode *res =  new ListNode(0);
	ListNode *cur = res;
	int sum, carry = 0;
	
	if(l1 == NULL)
		return l2;
	else if(l2 == NULL)
		return l1;
	
	while(l1 != NULL && l2 != NULL){
		sum = l1->val + l2->val + carry;
	
		if(sum >= 10){
			sum = sum % 10;
			carry = 1;
		}else
			carry = 0;
		
		cur->next = new ListNode(sum);
		cur = cur->next;
		
		l1 = l1->next;
		l2 = l2->next;
	}
	
	// if we have not reache the end of l1
	while(l1 != NULL){
		sum = l1->val + carry;
		
		if(sum >= 10){
			sum = sum % 10;
			carry = 1;
		}else
			carry = 0;
		
		cur->next = new ListNode(sum);
		cur = cur->next;
		
		l1 = l1->next;
	}
	
	// if we have not reach the end of l2
	while(l2 != NULL){
		sum = l2->val + carry;
		
		if(sum >= 10){
			sum = sum % 10;
			carry = 1;
		}else
			carry = 0;
		
		cur->next = new ListNode(sum);
		cur = cur->next;
		
		l2 = l2->next;
	}
	
	//if there is still a carry
	if(carry){
		cur->next = new ListNode(carry);
	}
	
	return res->next;
}

int main(){
	ListNode *l1 = new ListNode(7);
	ListNode *l2 = new ListNode(2);
	
	ListNode *p1 = l1, *p2 = l2;
	
	int arr1[2] = {2, 9};
	int arr2[3] = {9, 3, 9};
	
	for(int i = 0; i < 2; i++){
		p1->next = new ListNode(arr1[i]);
		p1 = p1->next;
	}
	
	for(int i = 0; i < 3; i++){
		p2->next = new ListNode(arr2[i]);
		p2 = p2->next;
	}
	
	p1 = l1;
	p2 = l2;
	
	while(p1 != NULL){
		cout<<p1->val<<" ";
		p1 = p1->next;
	}
	
	cout<<endl;
	
	while(p2 != NULL){
		cout<<p2->val<<" ";
		p2 = p2->next;
	}
	
	cout<<endl;
	
	ListNode *res = addTwoNumbers(l1, l2);
	
	while(res != NULL){
		cout<<res->val<<" ";
		res = res->next;
	}
	
    
	return 0;
}



