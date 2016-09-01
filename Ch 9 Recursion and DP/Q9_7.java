import java.util.*;

class Q9_7 {

	public static void color(int arr[][], int x, int y, int oldColor, int newColor) {

		if(oldColor != arr[x][y]) return;

		int color = arr[x][y];
		arr[x][y] = newColor;

		if(x > 0 )  				 color(arr, x - 1, y, color, newColor);
		if(x < arr.length - 1 )      color(arr, x + 1, y, color, newColor);
		if(y > 0 )  				 color(arr, x, y - 1, color, newColor);
		if(y < arr[0].length - 1 )   color(arr, x, y + 1, color, newColor);
	}

	public static void printArr(int arr[][]) {
		for (int i = 0; i < arr.length; ++i) {
			System.out.println();
			for (int j = 0; j < arr[0].length; ++j) {
				System.out.print("\t" + arr[i][j]);
			}
		}
	}

	public static void main(String[] args) {
		
		int arr[][] = {{5, 2, 2, 13, 18},
						{15, 3, 2, 11, 17},
						{16, 3, 2, 2, 2}, 
						{2, 2, 2, 3, 2},
						{9, 8, 5, 2, 2} };

		printArr(arr);

		color(arr, 2, 2, arr[2][2], -1);

		System.out.println("\n\n\nNew color filled");
		printArr(arr);

		System.out.println();
	}
}