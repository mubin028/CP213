package cp213;

/**
 * Implements an AVL (Adelson-Velsky Landis) tree. Extends BST.
 *
 * @author Mubin Qureshi
 * @author David Brown
 * @version 2021-11-01
 */
public class AVL<T extends Comparable<T>> extends BST<T> {

    /**
     * Returns the balance item of node. If greater than 1, then left heavy, if
     * less than -1, then right heavy. If in the range -1 to 1 inclusive, the node
     * is balanced. Used to determine whether to rotate a node upon insertion.
     *
     * @param node The TreeNode to analyze for balance.
     * @return A balance number.
     */
    private int balance(final TreeNode<T> node) {
    	int balance;
    	if (node == null) {
    		balance = 0;
    	}else {
        	balance = this.nodeHeight(node.getLeft()) - this.nodeHeight(node.getRight());
    	}

    	
	return balance;
    }

    /**
     * Performs a left rotation around node.
     *
     * @param node The subtree to rotate.
     * @return The new root of the subtree.
     */
    private TreeNode<T> rotateLeft(final TreeNode<T> node) {

		TreeNode<T> x = node.getRight();
		node.setRight(x.getLeft());
		x.setLeft(node);

		node.updateHeight();
		x.updateHeight();

		return x;
	}

    /**
     * Performs a right rotation around {@code node}.
     *
     * @param node The subtree to rotate.
     * @return The new root of the subtree.
     */
    private TreeNode<T> rotateRight(final TreeNode<T> node) {

    	TreeNode<T> x = node.getLeft();
		node.setLeft(x.getRight());
		x.setRight(node);

		node.updateHeight();
		x.updateHeight();

		return x;
		
		
		
		
	}

    /**
     * Auxiliary method for {@code insert}. Inserts data into this AVL.
     *
     * @param node the current node (TreeNode)
     * @param data Data to be inserted into the node
     * @return The inserted node.
     */
    @Override
    protected TreeNode<T> insertAux(TreeNode<T> node, final CountedItem<T> data) {

		if (node == null) {
			
			this.size++;
			node = new TreeNode<T>(data);
			node.getItem().incrementCount();
			node.updateHeight();
			return node;
			
			
			
		}

		int x = node.getItem().compareTo(data), y;

		if (x == 0) {
			this.size++;
			node.getItem().incrementCount();
			return node;
		} else if (x > 0) {
			node.setLeft(this.insertAux(node.getLeft(), data));
			node.updateHeight();
			y = this.balance(node);

			if (y >= 2 && this.balance(node.getLeft()) >= 0) {
				node = this.rotateRight(node);
			} else if (y >= 2 && this.balance(node.getLeft()) <= -1) {
				node.setLeft(this.rotateLeft(node.getLeft()));
				node = this.rotateRight(node);
			}
			this.size++;
			return node;
			
		} else if (x < 0) {
			node.setRight(this.insertAux(node.getLeft(), data));
			node.updateHeight();
			y = this.balance(node);

			if (y <= -2 && this.balance(node.getRight()) <= 0) {
				node = this.rotateLeft(node);
			} else if (y <= -2 && this.balance(node.getRight()) >= 1) {
				node.setRight(this.rotateRight(node.getRight()));
				node = this.rotateLeft(node);
			}
			this.size++;

			return node;
		} 
		else {
			node = new TreeNode<T>(data);
			node.getItem().incrementCount();
			this.size++;
			return node;
			
		}
	}

    /**
     * Auxiliary method for {@code valid}. Determines if a subtree based on node is
     * a valid subtree. An AVL must meet the BST validation conditions, and
     * additionally be balanced in all its subtrees - i.e. the difference in height
     * between any two children must be no greater than 1.
     *
     * @param node The root of the subtree to test for validity.
     * @return true if the subtree base on node is valid, false otherwise.
     */
    @Override
    protected boolean isValidAux(final TreeNode<T> node, TreeNode<T> minNode, TreeNode<T> maxNode) {
    	boolean valid = false;

		if (node == null) {
			valid = true;
			return valid;
		} 
		
		
		if (Math.max(this.nodeHeight(node.getLeft()), this.nodeHeight(node.getRight())) != node.getHeight() - 1) {
			valid = false;
		} else if(Math.abs(this.nodeHeight(node.getLeft()) - this.nodeHeight(node.getRight())) > 1)  {
			valid = false;
		} else if (node.getLeft() != null && node.getLeft().getItem().compareTo(node.getItem()) >= 0
				|| node.getRight() != null && node.getRight().getItem().compareTo(node.getItem()) <= 0){
			valid = false;
		} else {
			valid = this.isValidAux(node.getLeft(), minNode, maxNode)
					&& this.isValidAux(node.getRight(), minNode, maxNode);
		}
		return valid;
	}

    /**
     * Determines whether two AVLs are identical.
     *
     * @param target The AVL to compare this AVL against.
     * @return true if this AVL and target contain nodes that match in position,
     *         item, count, and height, false otherwise.
     */
    public boolean equals(final AVL<T> target) {
	return super.equals(target);
    }

}
