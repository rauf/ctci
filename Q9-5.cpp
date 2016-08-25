#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string insertCharAt(string str, char ch, int n) {

	int strLength = str.length();
	char s[100];

	for (int i = strLength; i >= 0; --i) {
		if(i > n) s[i] = str[i - 1];
		else s[i] = str[i];
	}
	s[n] = ch;
	s[strLength + 1] = '\0';
	return string(s);
}

vector<string> permutation(string str, int n) {

	if(n == 0)	{
		vector<string> vec;
		string s;
		s.push_back(str[n]);
		vec.push_back(s);
		return vec;
	}

	vector<string> vec = permutation(str, n - 1);
	int vecLength = vec.size();

	for (int i = 0; i < vecLength; ++i) {
		
		for (int j = 0; j <= vec[i].length(); ++j){
			vec.push_back(insertCharAt(vec[i], str[n], j));
		}
	}

	for (int i = 0; i < vecLength; ++i) {
		vec.erase(vec.begin());
	}

	return vec;
}


void print(vector<string> vec){

	std::cout << "\n\nAll permutations: " << std::endl;
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << "No. " << i + 1 << "  " << vec[i] << std::endl;
	}
}


int main() {

	string str = "abcd";

	vector<string> v = permutation(str, str.length() - 1);
	print(v);
}