#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 [question]
 
 
 1.4 Write a method to replace all spaces in a string with'%20'. You may assume that
 the string has sufficient space at the end of the string to hold the additional
 characters, and that you are given the "true" length of the string. (Note: if implementing
 in Java, please use a character array so that you can perform this operation
 in place.)
 
 [solution]
 1. caculate the string len after inserting these 20% as newLen
 2. add a end symbol '/0' in the tail
 3. start from the tail of the string, there will be two pointer, one 
	points to the newTail another points to the original_tail, if the 
	original tail points to a space, we will add 20% in the newTail position
    else just copy the char
 4. until we reach the 0 index
 
 [time complexity]
 O(n)
 scan all chars in the string
 
 [space complexity]
 O(1)
 do this in place
 
 [gist link]

 
 [test case]
 
 */


void replace_with20(char str[], int len){
	int space_counter = 0;
	int newLen;
	
	for(int i = 0; i < len; i++){
		if(str[i] == ' ')
			space_counter++;
	}
	
	newLen = len + space_counter * 2;

	str[newLen] = '\0';
	
	for(int i = newLen - 1, j = len - 1; i >= 0; i--, j--){
		
		if(str[j] != ' '){
			str[i] = str[j];
		}else{
			str[i] = '0';
			i--;
			str[i] = '2';
			i--;
			str[i] = '%';
		}
	}
}



int main()
{
	char str[100] = "Mr John Smith and you like";
	char s[100] = "";
	int len = 26;
	
	replace_with20(s, len);
	
	cout<<s<<endl;
	
	return 0;
}

