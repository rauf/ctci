
class Q21 {

	static class Node{
		int data;
		Node link = null;

		Node(int n){
			data = n;
		}

		void appendToEnd(int n){

			Node end = new Node(n);
			Node root = this;
			while(root.link != null){
				root = root.link;
			}
			root.link = end;
		}



		void print() {
			Node root = this;

			while(root != null){
				System.out.print(root.data + "  ");
				root = root.link;
			}
			System.out.println();
		}

		void deleteNode(int n){
			Node root = this;

			while(root.link != null){
				
				if(root.link.data == n){
					root.link = root.link.link;
				}
				else root = root.link;
			}
		}

		boolean isPalindrome(){
			Node root = this;
			Result result = new Result();
			result.node = this;
			return isPalindromeImpl(root, result);
		}

		private class Result{
			Node node;
		}

		private boolean isPalindromeImpl(Node root, Result result){
			if(root == null) return true;

			boolean ret = isPalindromeImpl(root.link, result);

			if(root.data != result.node.data) return false;
			result.node = result.node.link;
			return ret;
		}

	}

	public static void main(String[] args) {
		
		Node node = new Node(1);

		node.appendToEnd(2);
		node.appendToEnd(3);
		node.appendToEnd(4);
		node.appendToEnd(3);
		node.appendToEnd(2);
		node.appendToEnd(1);

		node.print();

		System.out.println("isPalindrome:  " + node.isPalindrome());

	}
}