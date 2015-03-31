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
#include <queue>
#include <math.h>

using namespace std;

/*
 [question]
 
 2.6
Linkedlist cycle 
 starting point
 
 [solution]

 
 [time complexity]
O(n)
 scan the linked list
 
 [space complexity]
O(1)
 
 [gist link]
 
 
 [test case]
 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *slow, *fast;
    int flag = 0;
    
    slow = head;
    fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            flag = 1;
            //cout<<"has cycle"<<endl;
            break;
        }
    }
    
    if(flag){
        slow = head;
        
        while(slow != NULL){
            if(slow == fast){
                //cout<<"* "<<slow->val<<endl;
                break;
            }
            
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }else
        return NULL;
}

int main(int argc, const char * argv[]){
    vector<int> num;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    
    ListNode *head = new ListNode(arr[0]);
    ListNode *last = head;
    
    for(int i = 1; i < 6; i++){
        ListNode *temp = new ListNode(arr[i]);
        last->next = temp;
        
        last = temp;
    }
    
    
    last = head;
    int n = 3;
    
    while(n--){
        last = last->next;
    }
    
    ListNode *point = last;
    
    //cout<<point->val<<endl;
    
    last = head;
    
    while(last != NULL){
        last = last->next;
        
        if(last->next == NULL)
            break;
    }
    
    //cout<<last->val<<endl;
    
    last->next = point;
    
    ListNode *ans = detectCycle(head);
  
    n = 15;
    
    last = head;
    
    while(n--){
        cout<<last->val<<" ";
        last = last->next;
    }
    
    cout<<endl;

    
    if(ans != NULL)
        cout<<ans->val<<endl;
    else
        cout<<"NULL"<<endl;
    
    
    return 0;
}



