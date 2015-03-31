//
//  main.cpp
//  test
//
//  Created by Fiona on 14-10-27.
//  Copyright (c) 2014年 Fiona. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

/*
 [question]
 
 2.7  Implement a function to check if a linked list is a palindrome.
 
 [solution]
 using a stack to store the later half of the elements in the list
 then iteratively pop out elements in the stack to compare with the 
 list elements starting from the head.
 
 [time complexity]
 O(n)
 
 [space complexity]
 O(n)
 for the stack
 
 [gist link]
 
 
 [test case]
 
 */

struct ListNode {
    char val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool is_palindrome(ListNode *head){
	ListNode *slow = head, *fast = head;
	stack<char> s;
	
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	//when slow is not the head of later half
	if(fast == NULL)
		slow = slow->next;
		
	while(slow != NULL){
		s.push(slow->val);
		slow = slow->next;
	}
	
	slow = head;
	
	while(s.size()){
		if(s.top() != slow->val)
			return false;
		
		s.pop();
		slow = slow->next;
	}
	
	return true;
}



int main(int argc, const char * argv[]){
    
	char arr[7] = {'a', 'b', 'c', 'd', 'c', 'b', 'a'};
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	
	for(int i = 0; i < 7; i++){
		p->next = new ListNode(arr[i]);
		p = p->next;
	}
	
	bool result = is_palindrome(head->next);
	
	cout<<result<<endl;
    
    return 0;
}



