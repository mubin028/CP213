package cp213;

/**
 * A single linked queue structure of <code>Node T</code> objects. Only the
 * <code>T</code> value contained in the queue is visible through the standard
 * queue methods. Extends the <code>SingleLink</code> class.
 *
/**
 * @author Mubin Qureshi 180181900
 * @version 2021-10-30
 */
public class SingleQueue<T> extends SingleLink<T> {

    /**
     * Combines the contents of the left and right SingleQueues into the current
     * SingleQueue. Moves nodes only - does not refer to values in any way, or call
     * the high-level methods insert or remove. left and right SingleQueues are
     * empty when done. Nodes are moved alternately from left and right to this
     * SingleQueue.
     *
     * You have two source queues named left and right. Move all nodes from these
     * two queues to the current queue. It does not make a difference if the current
     * queue is empty or not, just get nodes from the right and left queues and add
     * them to the current queue. You may use any appropriate SingleLink helper
     * methods available.
     *
     * Do not assume that both right and left queues are of the same length.
     *
     * @param left  The first SingleQueue to extract nodes from.
     * @param right The second SingleQueue to extract nodes from.
     */
    public void combine(final SingleQueue<T> left, final SingleQueue<T> right) {
    	
    	if (left.length != 0 && right.length != 0) {
    		this.moveFrontToRear(left);
    		this.moveFrontToRear(right);
    	}
    	
    	else if (left.length ==0) {
    			this.moveFrontToRear(right);
        	}
    	
        	else if (right.length == 0) {
        		this.moveFrontToRear(right);        	
    	}

        return;	
	}

    /**
     * Adds value to the rear of the queue. Increments the queue length.
     *
     * @param data The value to added to the rear of the queue.
     */
    public void insert(final T data) {
    	SingleNode<T> new1 = new SingleNode(data,null);
    	if (this.front == null) {
    		this.front = new1;
    		this.rear = new1;
    	}
    	else{
    		this.rear.setNext(new1);
    		this.rear = new1;
    	}
    	
    	this.length++;

	return;
    }

    /**
     * Returns the front value of the queue and removes that value from the queue.
     * The next node in the queue becomes the new first node. Decrements the queue
     * length.
     *
     * @return The value at the front of the queue.
     */
    public T remove() {
		SingleNode<T> node = this.front;
		if (this.length > 0) {

			if (this.length == 1) {
				this.front = null;
				this.rear = null;
			}

			else {
				this.front = node.getNext();
			}
			T val = node.getData();
			this.length--;
			return val;
		}
		return null;
	}

    /**
     * Splits the contents of the current SingleQueue into the left and right
     * SingleQueues. Moves nodes only - does not move value or call the high-level
     * methods insert or remove. this SingleQueue is empty when done. Nodes are
     * moved alternately from this SingleQueue to left and right. left and right may
     * already contain values.
     *
     * This is the opposite of the combine method.
     *
     * @param left  The first SingleQueue to move nodes to.
     * @param right The second SingleQueue to move nodes to.
     */
    public void splitAlternate(final SingleQueue<T> left, final SingleQueue<T> right) {

    	boolean x = true;
    	
    	left.moveFrontToRear(this);
	    while (this.front!=null) {
	    		right.moveFrontToRear(this);
	    }

	return;
    }
}
