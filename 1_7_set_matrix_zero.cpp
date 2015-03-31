#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/*
 [question]
 
 1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row
 and column are set to 0.
 
 [solution]
 We should use two vectors to record which columns and which rows include zero. If a row
 or a column includes a zero, then the entire column or row will be set to zero later.
 Actually, we can use the first column and the first row in the maxtrix to record.
 But before that, we should check whether they include zero, if they include zero, they
 should be all set to zero later.
 
 [time complexity]
 O(n^2)
 
 [space complexity]
 if use extra 2 vectors, then O(n)
 if use the first column and the first row in the maxtrix to record,
 then O(1) to record whether the first column and the first row in the 
 maxtrix includes any zero.
 
 [gist link]

 
 [test case]
 
 */

void set_zero_1(vector<vector<int>> &v){
	vector<int> zero_col;
	vector<int> zero_row;
	
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[i].size(); j++){
			if(v[i][j] == 0){
				zero_col.push_back(j);
				zero_row.push_back(i);
			}
		}
	}
	
	for(int i = 0; i < zero_row.size(); i++){
		for(int j = 0; j < v[zero_row[i]].size(); j++){
			v[zero_row[i]][j] = 0;
		}
	}

	for(int i = 0; i < zero_col.size(); i++){
		for(int j = 0; j < v.size(); j++){
			v[j][zero_col[i]] = 0;
		}
	}
	
}

int main()
{
	int arr[4][4] = {{1, 9, 1, 1}, {1, 9, 8, 0}, {3, 2, 1, 4}, {0, 4, 4, 2}};
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
    
    set_zero_1(v);
	
	cout<<endl;
	
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
	
	return 0;
}

