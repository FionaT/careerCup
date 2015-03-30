#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 [question]
 
 1.3 Given two strings, write a method to decide if one is a permutation of the other.
 
 [solution]
 use two array of size 256 to count the appear time of each ascii char in
 both string. Then compare the count array of the two string, if any char
 has different appear time in the two array, then return false. If no false
 returned after the loop, the function will return true.
 
 [time complexity]
 O(n)
 
 [space complexity]
 O(1)
 
 [gist link]
 https://gist.github.com/FionaT/bf63252875f31dd1bacb
 
 [test case]
 
 */


bool isPermu(string s1, string s2){
    int bucket1[256];
    int bucket2[256];
    
	//if different length, can not be permutation
    if(s1.length() != s2.length())
        return false;
    
	//initialize the count arrary
    for(int i = 0; i < 256; i++){
        bucket1[i] = 0;
        bucket2[i] = 0;
    }
    
	//count the appear time of each char in both string
    for(int i = 0; i < s1.length(); i++){
        bucket1[int(s1[i])] ++;
        bucket2[int(s2[i])] ++;
    }
    
	//compare the count array of the two string
    for(int i = 0; i < 256; i++){
        if(bucket1[i] != bucket2[i])
            return false;
    }
    
    return true;
}


int main()
{
    string s1 = "abcdef";
    string s2 = "bcdaef";
	string s3 = "aaabsd";
    
    cout<<isPermu(s1, s2)<<endl;
	cout<<isPermu(s1, s3)<<endl;
	
	return 0;
}

