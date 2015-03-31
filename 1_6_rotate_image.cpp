#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/*
 [question]
 
 
 1.6 Given an image represented by an NxN matrix, where each pixel in the image is
 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
 place?
 
 [solution]
 The key idea is to do this in place, so we have to do this layer by layer using
 a cycle swap between top, left, bottom, and right.
 
 [time complexity]
 O(n^2)
 visit each node once
 
 [space complexity]
 no more extra space

 
 [gist link]

 
 [test case]
 
 */

void rotate_simple(vector<vector<int>> &matrix){
	int n = matrix.size();
	int start = 0, end = n - 1;
	int temp = 0;
	
	//save left vertical line to temp and rotate 90 degree line by line
	while( start < end ){
		for( int i = 0; i < end - start; i++ )
		{
			temp = matrix[ start ][ start + i ];
			matrix[ start ][ start + i ] = matrix[ end - i ][ start ];
			matrix[ end - i ][ start ] = matrix[ end ][ end - i ];
			matrix[ end ][ end - i ] = matrix[ start + i ][ end ];
			matrix[ start + i ][ end ] = temp;
		}
		start++;
		end--;
	}
}

void rotate(vector<vector<int>> &v){
	int n = v.size();
	int top, left, bottom, right, offset;
	
	for(int layer = 0; layer < n / 2; layer++){
		int first = layer;
		int last = n - 1 - layer;
		
		for(int i = first; i < last; i++){
			offset = i - first;
			
			/*
			top = v[layer][i];
			left = v[last - offset][layer];
			bottom = v[last][last - offset];
			right = v[i][last];
			*/
			
			top = v[layer][i];
			
			v[layer][i] = v[last - offset][layer];
			v[last - offset][layer] = v[last][last - offset];
			v[last][last - offset] = v[i][last];
			v[i][last] = top;
		}
	}
}


int main()
{
	int arr[4][4] = {{11, 12, 13, 14}, {21, 22, 23, 24}, {31, 32, 33, 34}, {41, 42, 43, 44}};
    vector<vector<int>> v;
    
    
    for(int i = 0; i < 4; i++){
        vector<int> temp;
        
        for(int j = 0; j < 4; j++){
            temp.push_back(arr[i][j]);
            //cout<<arr[i][j]<<" ";
        }
        
        v.push_back(temp);
    }
    
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    rotate(v);
	
	cout<<endl;
	
	for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
	
	rotate_simple(v);
	
	cout<<endl;
	
	for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
	
	return 0;
}

