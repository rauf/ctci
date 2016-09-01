#include<iostream>
#include<vector>

int robot(int **arr, int x, int y){

   if(x == 0 || y == 0) return 1;

   if(arr[x][y] != 0) return arr[x][y];
    
   arr[x][y] = robot(arr, x - 1, y) + robot(arr, x, y - 1);
   return arr[x][y];
}

class Point {
public:
    int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};


int findPathImpl(int **arr, int **ignore, int x, int y, int max, std::vector<Point> &v){

    if(x == 0 && y == 0) {
        v.push_back(Point(0, 0));
        return 1;
    }

    int succ = 0;

    if(x > 0 && !ignore[x - 1][y]) {
        succ = findPathImpl(arr, ignore, x - 1, y,  max, v);
    }

    if(!succ && y > 0 && !ignore[x][y - 1]) {
        succ = findPathImpl(arr, ignore, x, y - 1, max, v);
    }

    if(succ){
        v.push_back(Point(x, y));
    }

    return succ;
}


std::vector<Point> findPath(int **arr, int **ignore, int x, int y, int max){
    std::vector<Point> v;
    findPathImpl(arr, ignore, x, y, max, v);
    return v;
}

int main() {

    int max = 100;
    int **arr = new int*[max];
    int **ignore = new int*[max];

    for (int i = 0; i < max; ++i){
        arr[i] = new int[max];
        ignore[i] = new int[max];
    }

    int x, y;
    x = y = 20;

    ignore[0][3] = 2;
    ignore[5][20] = 2;

    std::cout << "\nSolution for X by Y " << x << "x" << y << " = "<< robot(arr, x, y) << std::endl;

   std::cout << "\nSolution(Ignoring points) for X by Y \n"; 


   std::vector<Point> v = findPath(arr, ignore, x, y , max);

   for (int i = 0; i < v.size() ; ++i){
        std::cout << "\n(" << v[i].x << ", " << v[i].y << ")  ";
   }


}