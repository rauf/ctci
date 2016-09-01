#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
	int	data;
	vector<int> v;
	
	Node(int d) {
		data = d;
	}
};

class Graph {
public:

	int no;
	vector<Node> nodes;

	Graph(int n) {
		no = n;

		for (int i = 0; i < n; ++i) {
			nodes.push_back(Node(n));
		}
	}

	void addEdge(int from, int to) {
		nodes[from].v.push_back(to);
	}

	bool search(int v1, int v2) {
		int start = v1;
		queue<int> q;
		int *visited = new int [no];

		for (int i = 0; i < no; ++i)
			visited[i] = 0;
		
		q.push(start);

		while(!q.empty()) {
		
			int elem = q.front();
			q.pop();

			if(!visited[elem]) {

				for (int i = 0; i < nodes[elem].v.size(); ++i){
					q.push(nodes[elem].v[i]);
				}
				visited[elem] = 1;

				if(elem == v2) {
					return true;
				}
			}
		}
		return false;
	}

};



int main() {
  	
  	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    //g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "\nSearch Result:  " << g.search(1, 3) << endl;
}