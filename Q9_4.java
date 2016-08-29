import java.util.*;

class Q9_4 {

	public static ArrayList<ArrayList<Integer>> getSubsets(ArrayList<Integer> list, int n) {

	if(n < 0) {
		ArrayList<ArrayList<Integer>> sets = new ArrayList<>();
		sets.add(new ArrayList<Integer>());
		return sets;
	}

	ArrayList<ArrayList<Integer>> sets = getSubsets(list, n - 1);

	int length = sets.size();
	for (int i = 0; i < length; ++i) {
		ArrayList<Integer> li = new ArrayList<>(sets.get(i));

		li.add(list.get(n));
		Collections.sort(li);
		sets.add(li);
	}

	return sets;
	}


	public static void main(String[] args) {
		
		ArrayList<Integer> list = new ArrayList<>();
		list.add(1);
		list.add(2);
		list.add(3);

		ArrayList<ArrayList<Integer>> sets =  getSubsets(list, 2);

		for (int i = 0; i < sets.size(); ++i) {
			System.out.print("\n\nSet no.: " + i);
			
			System.out.print("{");
			for (int j = 0; j < sets.get(i).size(); ++j) {
				System.out.print("  " + sets.get(i).get(j));
			}
			System.out.print(" }");

		}
	}
}