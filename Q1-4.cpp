#include<iostream>
#include<ctype.h>

using namespace std;

char * replaceSpace (char *str, int length) {

	int charFound = 0;
	int beg = length - 1;

	int i;
	for (i = length-1; i>=0 ; --i)
	{		
		if(str[i] != ' '){

			charFound = 1;
			beg = i;
			cout << "\ni =  " << i << "ch = " << str[i];
			break;
		}

	}

	for (; i >=0  ; --i)
	{

		if(charFound && str[i] == ' '){
			
			int j;
			for(j = beg; j > i; --j){
				str[j + 2] = str[j];
			}
			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
			beg +=2;
			cout << "\n i = " << i << "  copying";

		}
	}
	return str;
}


int main() {

    char str1[100];
    cin.getline(str1, 100);
    cout << "str is " << str1;
    char *str = replaceSpace(str1, 17);

	cout << "\nFinal result,," << endl;

	for (int i = 0; str[i] != '\0'; ++i)
	{
		cout << str[i];
	}
	cout << endl;



}
