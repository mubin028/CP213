package cp213;

/**
 * A single linked stack structure of <code>Node T</code> objects. Only the
 * <code>T</code> value contained in the stack is visible through the standard
 * stack methods. Extends the <code>SingleLink</code> class. Note that the rear
 * attribute should be ignored as the rear is not used in a stack.
 *
/**
 * @author Mubin Qureshi 180181900
 * @version 2021-10-30
 */
public class SingleStack<T> extends SingleLink<T> {

    /**
     * Combines the contents of the left and right SingleStacks into the current
     * SingleStack. Moves nodes only - does not refer to values in any way, or call
     * the high-level methods pop or push. left and right SingleStacks are empty
     * when done. Nodes are moved alternately from left and right to this
     * SingleStack.
     *
     * You have two source stacks named left and right. Move all nodes from these
     * two stacks to the current stack. It does not make a difference if the current
     * stack is empty or not, just get nodes from the right and left stacks and add
     * them to the current stack. You may use any appropriate SingleLink helper
     * methods available.
     *
     * Do not assume that both right and left stacks are of the same length.
     *
     * @param left  The first SingleStack to extract nodes from.
     * @param right The second SingleStack to extract nodes from.
     */
    public void combine(final SingleStack<T> left, final SingleStack<T> right) {

    	SingleNode<T> temp1 = left.front;
    	SingleNode<T> temp2 = left.front;
    	
	if (left.getLength()>0) {
		this.moveFrontToRear(left);
	}
	if (right.getLength() > 0) {
		this.moveFrontToFront(right);
	}

	return;
    }

    /**
     * Returns the top value of the stack and removes that value from the stack. The
     * next node in the stack becomes the new top node. Decrements the stack length.
     *
     * @return The value at the top of the stack.
     */
    public T pop() {
    	if(this.length > 0) {
	    	T value = this.front.getData();
	    	this.front = this.front.getNext();
	    	this.length --;
	    	return value;
    	}
    	return null;
    }

    /**
     * Adds data to the top of the stack. Increments the stack length.
     *
     * @param data The value to add to the top of the stack.
     */
    public void push(final T data) {

    	SingleNode<T> temp = new SingleNode(data,this.front);
    	this.front = temp;
    	this.length ++;

	return;
    }

    /**
     * Splits the contents of the current SingleStack into the left and right
     * SingleStacks. Moves nodes only - does not move value or call the high-level
     * methods insert or remove. this SingleStack is empty when done. Nodes are
     * moved alternately from this SingleStack to left and right. left and right may
     * already contain values.
     *
     * This is the opposite of the combine method.
     *
     * @param left  The first SingleStack to move nodes to.
     * @param right The second SingleStack to move nodes to.
     */
    public void splitAlternate(final SingleStack<T> left, final SingleStack<T> right) {

		int z = this.length / 2;
		int i = 0;

		for (i = 0; i < z; i++) {
			left.push(this.pop());
		}
		for (i = 0; i < z; i++) {
			right.push(this.pop());
		}

		return;
	}
}