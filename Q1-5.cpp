#include<iostream>
#include<ctype.h>
#include<malloc.h>
#include<string.h>

using namespace std;

/*char * compress (char *str) {

	char *newStr = (char *) malloc (100);

	int count = 1;
	char next;
	int z = 0;
	int i;

	for (i = 0; str[i] != '\0'; ++i)
	{
		next = str[i + 1];
		if(str[i] == next){
			count++;
		}
		else
		{
			newStr[z++] = str[i];
			newStr[z++] = count + '0';
			count = 1;
		}
	}

	cout << endl;
	newStr[i] = '\0';

	for (int i = 0; newStr[i] != '\0'; ++i)
	{
		cout << newStr[i];
	}


	if(z >= i) {
		cout << "returned first";
		return str;
	}
	return newStr;
}
*/

char * compress (char *str) {

	char *newStr = (char *) malloc (100);

	int count = 1;
	char prev = str[0];
	int z = 0;
	int i;

	for (i = 1; i <= strlen(str)  /*str[i] != '\0'*/; ++i)
	{
		if(str[i] == prev){
			count++;
		}
		else
		{
			newStr[z++] = prev;
			newStr[z++] = count + '0';
			count = 1;
		}
		prev = str[i];
	}

	cout << endl;
	newStr[z] = '\0';

	for (int i = 0; newStr[i] != '\0'; ++i)
	{
		cout << newStr[i];
	}


	if(z >= i) {
		cout << "returned first";
		return str;
	}
	return newStr;
}


int main() {

    char str1[100];
    cin.getline(str1, 100);
    cout << "str is " << str1;
    char *str = compress(str1);

	cout << "\nFinal result,," << endl;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		cout << str[i];
	}
	cout << endl;

	free(str);
}
