#include<iostream>

int robot(int **arr, int x, int y){

   if(x == 0 || y == 0) return 1;

   if(arr[x][y] != 0) return arr[x][y];
    
   arr[x][y] = robot(arr, x - 1, y) + robot(arr, x, y - 1);
   return arr[x][y];
}
/*

int path(int **arr, int *ignore, int max, int x, int y, int *prevX, int *prevY){

    if(x == 0 || y == 0) return 1;

    for(int i = 0; i < max; ++i) {

        if(x == i && y == ignore[i]) {
            std::cout << "Match found:: " << x << "   " << y;
            int ignoreX = i;
            int ignoreY = ignore[i];

            if(ignoreX == *prevX)   {
                *prevY = ignoreY;
                arr[x][y] = robot(arr, ignore, max, x, y - 1, prevX, prevY);
                return arr[x][y];
            } else if(ignoreY == *prevY) {
                *prevX = ignoreX;
                arr[x][y] = robot(arr, ignore, max, x - 1, y, prevX, prevY);
                return arr[x][y];
            }
            else std::cout << "No match";
        }
    }

    *prevX = x;
    *prevY = y;

    if(arr[x][y] != 0) return arr[x][y];
    
    arr[x][y] = robot(arr, ignore, max, x - 1, y, prevX, prevY) 
                + robot(arr, ignore, max, x, y - 1, prevX, prevY);
    return arr[x][y];
}


int path(int **arr, int *ignore, int max, int x, int y) {
    int *prevX = new int;
    int *prevY = new int;
    return robot(arr, ignore, max, x, y, prevX, prevY);
}
*/

int main() {

    int max = 100;
    int **arr = new int*[max];
    int *ignore = new int[max];

    for (int i = 0; i < max; ++i){
        arr[i] = new int[max];
    }

    int x, y;
    x = y = 20;

    ignore[3] = 2;  //x = index, y = value at that index

   std::cout << "\nSolution for X by Y " << x << "x" << y << " = "<< robot(arr, x, y) << std::endl;
/*
   std::cout << "\nSolution(Ignoring points) for X by Y " 
   << x << "x" << y << " = "<< robot(arr, ignore, max, x, y) << std::endl;
*/
}