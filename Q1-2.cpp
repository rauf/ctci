#include<iostream>
#include<string.h>

using namespace std;

char * rev ( char *str) {

    char *cop = str;            //strorint initial value as str value is changed later
    int len = strlen(str);
    //char *newStr = new char[len];     //not using as it is using extra space
    char *endd = str + len -1;
    char ch;
    int i=0,j;

    while( str < endd) {

        ch = *str;
        *str++ = *endd;
        *endd-- = ch;
    }

    return cop;
}

int main() {


    char s[] = "Abdul rauf";
    char *p = (char *) &s;

    char *abc = rev(p);

    for(int i = 0; i  < strlen(abc); ++i)
        cout << abc[i];


}
