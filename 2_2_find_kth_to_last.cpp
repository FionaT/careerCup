#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 [question]
 
 2.2
 Implement an algorithm to find the kth to last element of a singly linked list
 
 [solution]
 1.two pointers, one goes ahead k steps, and another starts from the head.
   The two pointers then start at the same time, one node per step. When the first
   one reaches NULL, the second one reaches the kth to last element.
 
 2.Do this in a recursive way
 
 [time complexity]
 1. O(n) walk through the linked list
 
 2. O(n)
 
 
 [space complexity]
 1. O(1) the two pointers
 
 2. O(1)
 
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

Node* find_kth_to_last(Node* head, int k){
	Node *p1 = head, *p2 = head;
	
	while(k-- && p1 != NULL)
		p1 = p1->next;
	
	while(p1 != NULL){
		p1 = p1->next;
		p2 = p2->next;
	}
	
	return p2;
}

Node* find_kth_recursive(Node* head, int k, int& i){
	if(head == NULL)
		return NULL;
	
	Node *res = find_kth_recursive(head->next, k, i);
	
	//i will start to increase when head reaches NULL tail
	i = i + 1;
	
	if(i == k){
		return head;
	}
	
	return res;
}


int main()
{
	int arr[6] = {2, 3, 4, 5, 6, 7};
	
	Node* head = new Node(1);
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
	
	int i = 0;
	int k = 2;
	
	Node *res = find_kth_recursive(head, k, i);
	
	cout<<res->val<<endl;
	
	
	return 0;
}

