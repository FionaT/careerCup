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
 9.4 subsets
 
 [solution]
 the main idea is that we can build the larger subset from the smaller subset
 so I will initialize from an empty subset, and them start to add elements into it
 continue using the previous generated subsets to build new subsets
 
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

//iterative
vector<vector<int>> subsets(vector<int> input){
	vector<vector<int>> res;
	vector<int> temp;
	
	res.push_back(temp);
	
	for(int i = 0; i < input.size(); i++){
		
		vector<vector<int>> cur = res;
		
		for(int j = 0; j < cur.size(); j++){
			temp = cur[j];
			temp.push_back(input[i]);
			res.push_back(temp);
		}
	}
	
	return res;
}

//revursive way
vector<vector<int>> subsets_rec(vector<int> input){
	vector<vector<int>> res;
	vector<int> temp;
	
	if(input.size() == 0){
		res.push_back(temp);
		return res;
	}else{
		
		vector<int> smaller_input;
		
		for(int i = 0; i < input.size() - 1; i++)
			smaller_input.push_back(input[i]);
		
		vector<vector<int>> smaller_res = subsets_rec(smaller_input);
		res = smaller_res;
		
		for(int i = 0; i < smaller_res.size(); i++){
			temp = smaller_res[i];
			
			temp.push_back(input[input.size() - 1]);
			res.push_back(temp);
		}
	}
		
	return res;
}

/*
 void subsets_sub(vector<vector<int>> &res, vector<int> &temp, vector<int> input, int index){
 
	 for(int i = index; i < input.size(); i++){
	 temp.push_back(input[i]);
	 res.push_back(temp);
	 
	 subsets_sub(res, temp, input, i + 1);
	 
	 temp.pop_back();
	 }
 }
 
 vector<vector<int>> subsetsWithDup(vector<int> &S) {
	 vector<vector<int>> res;
	 vector<int> temp;
	 
	 res.push_back(temp);
	 
	 sort(S.begin(), S.end());
	 
	 subsets_sub(res, temp, S, 0);
	 
	 return res;
 }
 */

int main(int argc, const char * argv[]){
    int arr[3] = {1, 2, 3};
	vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	vector<vector<int>> res = subsets_rec(input);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout<<res[i][j]<<" ";
		}
		
		cout<<endl;
	}
	
    return 0;
}



