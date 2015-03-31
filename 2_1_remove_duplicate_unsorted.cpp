#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 [question]
 
 2.1 
 Write code to remove duplicates from an unsorted linked list
 FOLLOW UP
 How would you solve this problem if a temporary buffer is not allowed?
 
 [solution]
 1. use a hash table to check whether the cur node exists before
 2. use two pointer, cur and after, we will use 'cur' to scan the linkedlist
    and use 'after' to check for each 'cur' that whether there exist duplicated
    nodes after 'cur'.
 
 [time complexity]
 1.O(n)
 2.O(n^2)
 
 [space complexity]
 1.O(n) for the hashtable
 2.O(1) no extra space, just need the space for pointers
 
 [gist link]

 
 [test case]
 
 */
struct Node{
	int val;
	Node *next;
	
	Node(int v){
		next = NULL;
		val = v;
	}
};

//using hashtable to remove duplicated from unsorted linkedlist
//with buffer
void remove_duplicated(Node *head){
	unordered_set<int> m;
	Node* cur = head;
	Node* last = NULL;
	
	
	while(cur != NULL){
		
		//this node is duplicated
		if(m.find(cur->val) != m.end()){
			
			last->next = cur->next;
			
		}else{ //this node is not duplicated
			
			m.insert(cur->val);
			last = cur;
		}

		cur = cur->next;
	}

	//return head;
}

//using two pointers to remove duplicated from unsorted linkedlist
//without buffer
void remove_duplicated_no_buffer(Node *head){
	if(head == NULL)
		return;
	
	Node* cur = head;
	
	while(cur != NULL){
		Node* after = cur;
		
		while(after->next != NULL){
			if(after->next->val == cur->val)
				after->next = after->next->next;
			else
				after = after->next;
		}
		
		cur = cur->next;
	}
	
}

int main()
{
	int arr[6] = {3, 2, 3, 9, 1, 1};
	
	Node* head = new Node(0);
	Node* cur = head;
	
	for(int i = 0; i < 6; i++){
		Node* node = new Node(arr[i]);
		cur->next = node;
		cur = node;
	}
	
	cur = head;
	
	while(cur != NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	
	cout<<endl;
	
	//remove_duplicated(head);
	remove_duplicated_no_buffer(head);
	
	cur = head;
	
	while(cur != NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	
	return 0;
}

