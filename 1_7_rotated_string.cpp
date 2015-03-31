#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/*
 [question]
 
 1.8 Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g.,"waterbottle"is a rotation of"erbottlewat").
 
 [solution]
 we should first concatenate the string s1 with itself, so that we have a 
 new string like s1s1. Then we check whether s2 is a substring in s1. If it
 is, then it is a rotated form of s1.
 
 [time complexity]

 
 [space complexity]

 
 [gist link]

 
 [test case]
 
 */
bool is_rotated(string s1, string s2){
	string s1s1 = s1 + s1;
	
	//if they have different size, or s1 is an empty string
	// then it is impossible for s2 to be the rotated form of s1
	if(s1.size() != s2.size() || s1.size() == 0)
		return false;
	
	if (s1s1.find(s2) != std::string::npos) {
		cout<<"found!"<<endl;
		return true;
	}
	
	return false;
}

int main()
{
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	
	cout<<is_rotated(s1, s2)<<endl;
	
	return 0;
}

