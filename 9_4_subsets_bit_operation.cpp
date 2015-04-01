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

vector<int> convert(int x, vector<int> input){
	vector<int> temp;
	int index = 0;
	
	//cout<<"x "<<bitset<4>(x)<<endl;
	
	for(int i = x; i > 0; i >>= 1){
		
		//cout<<"i "<<bitset<4>(i)<<endl;
		
		if((i & 1) == 1){
			temp.push_back(input[index]);
		}
		
		index++;
	}
	
	return temp;
}

vector<vector<int>> subsets(vector<int> input){
	vector<vector<int>> res;
	
	int max = 1 << input.size();
	
	for(int i = 0; i < max; i++){
		vector<int> temp = convert(i, input);
		res.push_back(temp);
	}
	
	return res;
}


int main(int argc, const char * argv[]){
	int arr[3] = {1, 2, 3};
	vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
	vector<vector<int>> res = subsets(input);
	
	for(int i = 0; i < res.size(); i++){
		for(int j = 0; j < res[i].size(); j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	
    return 0;
}



