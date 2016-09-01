#include<iostream>
#include<string.h>
#include<stdio.h>

int checkPermutation(char *str1, char *str2) {

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	if(len1 != len2) return 0;

	int letters1[256];
	int letters2[256];
	
	for (int i = 0; i < 256; ++i){
		letters1[i] = 0;
		letters2[i] = 0;
	}

	for (int i = 0; i < len1; ++i)
	{
		char ch1 = str1[i];
		char ch2 = str2[i];
 		
		letters1[ch1]+=1;
		letters2[ch2]+=1;
	}


	for (int i = 0; i < 256; ++i)
	{
		if(letters1[i] != letters2[i]){
			return 0;
		}
	}
	return 1;

}

int main() {

	char str1[] = "Hello";
	char str2[] = "Heoll";
	char *p1 = str1;
	char *p2 = str2;

	std::cout << "\nFirst string " << p1;
	std::cout << "\nSecond string " << p2;

	std::cout << "\nanswer is " << checkPermutation(p1, p2) << std::endl;

}