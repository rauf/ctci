class Q9_9 {

	private static boolean isSafe(int arr[][], int x, int y) {

		for (int i = y; i >= 0; --i) {
			if(arr[i][x] == 1) return false; 	//check left side
		}

		for (int i = x; i >= 0; --i) {
			if(arr[y][i] == 1) return false; 	//check upwards
		}

		int i = x;
		int j = y;

		while(i >= 0 && j >= 0) {
			if(arr[j--][i--] == 1) return false;	//check upper diagonal on left side
		}

		i = x;
		j = y;

		while(i >= 0 && j < arr.length) {
			if(arr[j++][i--] == 1) return false;	//check lower diagonal on left side
		}
		return true;
	}

	private static void printBoard(int arr[][]) {

		for (int i = 0; i < arr.length ; i++ ) {
				
			System.out.println();
			for (int j = 0; j < arr[0].length ; j++ ) {
				System.out.print("\t" + arr[i][j]);
			}			
		}
			System.out.println("\n\n");
	}

	private static int nqueens(int arr[][], int col, int n) {	//n = no. of queens

		if(n == 0) {
			printBoard(arr);
			return 1;
		}

		int ways = 0;
		for (int i = 0; i < arr.length; ++i) {
			if(isSafe(arr, col, i)) {
				arr[i][col] = 1;		//queen placed
				ways += nqueens(arr, col + 1, n - 1);
				arr[i][col] = 0;
			}
		}
		return ways;
	}

	public static void main(String[] args) {
		int n = 8;
		int arr[][] = new int [n][n];
		System.out.println("Solution of nqueens for n = " + n + " : " + nqueens(arr, 0, n));
	}
}