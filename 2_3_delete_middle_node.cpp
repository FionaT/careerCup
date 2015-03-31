#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 [question]
 
 2.3
 Implement an algorithm to delete a node in the middle of a single linked list, given
 only access to that node
 
 [solution]
 1. copy middle node's next node's val to the middle node.
 2. delete middle node's next node. let middle node points to middle node's next's next node.

 
 [time complexity]
 1. O(1)
 
 [space complexity]
 1. O(1)
 
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

bool delete_middle_node(Node *p){
	
	//if p->next == NULL, then p is not a middle node
	if(p == NULL || p->next == NULL)
		return false;
	
	Node *next = p->next;
	
	p->val = next->val;
	p->next = next->next;
	
	return true;
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
	
	Node *n = head + 2;
	
	delete_middle_node(n);
	
	cur = head;
	
	while(cur != NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	
	cout<<endl;
	
	
	return 0;
}

