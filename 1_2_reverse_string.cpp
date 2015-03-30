#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
 [question]
 
 1.2 Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated string.
 
 [solution]
 use two pointers, one in the head another in the tail,
 exchange the head and the tail element, head++ tail--
 until when tail is smaller or euqal to head, then the loop can stop
 
 [time complexity]
 O(n)
 scan every char in the string
 
 [space complexity]
 O(1)
 we do this in place, so no extra space
 
 [gist link]

 
 [test case]
 
 */

void reverse_str(char *str)
{
	int len = 0;
	char *p = str, temp;
	
	while(*p != NULL){
		p++;
		len++;
	}
	
	for(int i = 0, j = len - 1; i < j; i++, j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	
}



int main()
{
	char str[] = "";
	
	reverse_str(str);
	
	cout<<str<<endl;
	
	return 0;
}

