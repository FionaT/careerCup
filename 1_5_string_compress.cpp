#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 [question]
 
 1.5 Implement a method to perform basic string compression using the counts
 of repeated characters. For example, the string aabcccccaaa would become
 a2blc5a3. If the "compressed" string would not become smaller than the original
 string, your method should return the original string.
 
 [solution]
 1. create a new empty string res
 2. scan the string, if it meets an old char, just increase count
    else change the last char varibale and reset count to 1
 3. at last, compare the size of the old one and the new one
    if same size or longer, output the original one
 
 [time complexity]
 O(n)
 scan all chars in the string
 
 [space complexity]
 O(n)
 for the new string
 
 [gist link]

 
 [test case]
 
 */


string compress(string str){
	string res;
	
	if(str.size() == 0)
		return res;
	
	int count = 1;
	char last = str[0];
	
	for(int i = 1; i < str.size(); i++){
		if(str[i] == last){
			count++;
		}else{
			res.push_back(last);
			res.push_back('0' + count);
			
			last = str[i];
			count = 1;
		}
	}
	
	res.push_back(last);
	res.push_back('0' + count);
	
	if(res.size() >= str.size())
		return str;

	return res;
}


int main()
{
	string str = "abbbccc";
	
	string s = compress(str);
	
	cout<<s<<endl;
	
	return 0;
}

