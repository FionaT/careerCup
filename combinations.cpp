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
#include <bitset>
#include <math.h>

using namespace std;

/*
 [question]
 9.4 subsets ii
 
 [solution]

 
 [time complexity]
 O(2^n)
 2 to the power n
 base power
 depend on the size of the result subset
 
 [space complexity]
 O(2^n)
 as the result vector
 
 [gist link]
 
 
 [test case]
 
 */

void combine_sub(int n, int k, int level, vector<vector<int>> &res, vector<int> &temp){
	
	for(int i = level; i <= n; i++){
		temp.push_back(i);
		
		if(temp.size() == k)
			res.push_back(temp);
		else if(temp.size() < k){
			combine_sub(n, k, i + 1, res, temp);
		}
		
		temp.pop_back();
	}
	
}

vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> res;
	vector<int> temp;
	
	combine_sub(n, k, 1, res, temp);
	
	return res;
}


int main(int argc, const char * argv[]){
	vector<vector<int>> res = combine(4, 2);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++)
			cout<<res[i][j]<<" ";
		
		cout<<endl;
	}
	
	
    return 0;
}



