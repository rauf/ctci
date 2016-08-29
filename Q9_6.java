import java.util.*;

class Q9_6 {

	public static HashSet<String> permutation(int n) {

		HashSet<String> set = new HashSet<>();

		if(n == 1) {
			set.add("()");
			return set;
		}
	
		HashSet<String> prev = permutation(n - 1);

		for (String str: prev) {

			for (int j = 0; j < str.length() ; ++j) {
				if(str.charAt(j) == '(')
					set.add(insert(str, j));
			}
			
			if(!set.contains("()" + str))
				set.add("()" + str);
		}

		return set;
	}

	public static String insert(String str, int idx) {
		String s1 = str.substring(0, idx + 1);
		String s2 = str.substring(idx + 1, str.length());
		return s1 + "()" + s2;
	}


	private static HashSet<String> permImpl(int lCount, int rCount, int n) {

		if(lCount == n && rCount == n) return;

	}

	public static HashSet<String> perm(int n) {

	}

	public static void main(String[] args) {
		HashSet<String> set = permutation(3);

		for (String str: set ) {
			System.out.println(str);
		}
	}
}