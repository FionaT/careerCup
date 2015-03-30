#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 [solution]
 1.we can create a boolean arrary with size of 256 since there are
 256 ascii character in total. 
 2.Then for each char in the string, we use the array to test whether
 the current char existed before, if yes, return false.
 3.After scanning the whole string, if no false returned, the function
 will return true.
 
 [time complexity]
 O(n), n is the size of the string
 
 [space complexity]
 O(1), for the array with size of 256
 
 [gist link]
 
 
 [test case]
 ""
 "abca"
 "abcde"
 "bbb"
 
*/

bool unique_char(string str){
	bool check[256];
	
	for(int i = 0; i < 256; i++)
		check[i] = false;
	
	
	for(int i = 0; i < str.size(); i++){
		if(check[str[i]] == true)
			return false;
		
		check[str[i]] = true;
	}
	
	return true;
}



int main(){
	string s1 = "aaa";
	
	cout<<unique_char(s1)<<endl;
	
	
	return 0;
}