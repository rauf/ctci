#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//recursive
vector<vector<int> >  getSubsets(int arr[], int n) {

	if(n < 0) {
		vector<vector<int> > v;
		v.push_back(vector<int>());
		return v;
	}


	vector<vector<int> > sets = getSubsets(arr, n - 1);

	vector<int> vec;
	int length = sets.size();	//!!! careful. as sets is growing, do not use sets.size() as condition in the loop
	for (int i = 0; i < length; ++i) {
		vec = sets[i];
		vec.push_back(arr[n]);
		sort(vec.begin(), vec.end());
		sets.push_back(vec);
	}

	return sets;
}

//iterative
vector<vector<int> > getSubsetsItr(vector<int> vec, int n) {

	vector<vector<int> > sets;

	sets.push_back(vec);

	for (int i = 0; i < vec.size(); ++i) {
		
		int setLenth = sets.size();

		for (int j = 0; j < setLenth; ++j) {
			for (int k = 0; k < sets[j].size(); ++k) {
		
				if(vec[i] == sets[j][k]) {

					vector<int> v = sets[j];
					v.erase(v.begin() + k);
					sets.push_back(v);
				}
			}
		}
	}

	return sets;
}


void print(vector<vector<int> > sets) {
	
	for (int i = 0; i < sets.size(); ++i) {
		cout << "\n\nSet no.: "<< i << endl;
		cout << "{ ";
		for (int j = 0; j < sets[i].size(); ++j) {
			cout << " " << sets[i][j] << " ";
		}
		cout<< " }";
	}
}


int main() {

	int arr[] = {1, 2, 3, 4};
	vector<vector<int> > sets =  getSubsets(arr, 3);

	vector<int> v;
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	vector<vector<int> > sets2 =  getSubsetsItr(v, 3);	

	cout << "Recursive:\n";
	print(sets);

	cout << "\n\n\n\n\nIterative:\n";
	print(sets2);
	
	cout << endl;
}