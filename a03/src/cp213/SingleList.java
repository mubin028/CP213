package cp213;

import java.util.Iterator;

/**
 * A single linked list structure of <code>Node T</code> objects. These data
 * objects must be Comparable - i.e. they must provide the compareTo method.
 * Only the <code>T</code> value contained in the priority queue is visible
 * through the standard priority queue methods. Extends the
 * <code>SingleLink</code> class.
 *
/**
 * @author Mubin Qureshi 180181900
 * @version 2021-10-30
 */
public class SingleList<T extends Comparable<T>> extends SingleLink<T> {

    /**
	 * Searches for the first occurrence of key in this SingleList. Private helper
	 * methods - used only by other ADT methods.
	 *
	 * @param key The value to look for.
	 * @return A pointer to the node previous to the node containing key.
	 */
	private SingleNode<T> linearSearch(final T key) {
	
		SingleNode<T> prev = null;
		SingleNode<T> curr = this.front;
		while (curr != null && curr.getData() != key) {
			prev = curr;
			curr = curr.getNext();
		}
		return prev;
	
	}


    /**
     * Appends data to the end of this SingleList.
     *
     * @param data The value to append.
     */
	public void append(final T data) {

		SingleNode<T> node = new SingleNode(data, null);
		if (this.front == null) {
			this.front = node;
			this.length += 1;
		} else {

			SingleNode<T> curr = this.front;
			while (curr.getNext() != null) {
				curr = curr.getNext();
			}
			curr.setNext(node);
			this.length += 1;
			
		}
		return;
	}

    /**
     * Removes duplicates from this SingleList. The list contains one and only one
     * of each value formerly present in this SingleList. The first occurrence of
     * each value is preserved.
     */
    public void clean() {
    	
    	SingleNode<T> node1 = this.front;
    	SingleNode<T> node2 = this.front;
    	SingleNode<T> prev = this.front;
    	int counter = 0;

    	while (node1 != null) {
    		
    		prev = node1;
    		counter = 0;
    		while (node2 != null) {
    			
    			if (node1.getData() == node2.getData()){
    				counter++;
    				if (counter >= 1) {
    				prev.setNext(node2.getNext()); 	
    				this.length -= 1;
    				}else {
    					prev = prev.getNext();
    				}
    			}else {
    				prev = prev.getNext();
    				 
    			}
    			node2 = node2.getNext();
    			
    			
    		}
    		node1 = node1.getNext();
    	}

	return;
    }

    /**
     * Combines contents of two lists into a third. Values are alternated from the
     * origin lists into this SingleList. The origin lists are empty when finished.
     * NOTE: data must not be moved, only nodes.
     *
     * @param left  The first list to combine with this SingleList.
     * @param right The second list to combine with this SingleList.
     */
    public void combine(final SingleList<T> left, final SingleList<T> right) {

		this.moveFrontToFront(left);
		this.moveFrontToFront(right);
		return;
		
	}

    /**
     * Determines if this SingleList contains key.
     *
     * @param key The key value to look for.
     * @return true if key is in this SingleList, false otherwise.
     */
    public boolean contains(final T key) {

		SingleNode<T> node1 = this.front;
		while (node1 != null) {
			if (node1.getData() == key) {
				return true;
			}
			node1 = node1.getNext();
		}

		return false;
	}

    /**
     * Finds the number of times key appears in list.
     *
     * @param key The value to look for.
     * @return The number of times key appears in this SingleList.
     */
    public int count(final T key) {

    	int counter = 0;
    	SingleNode<T> node1 = this.front;
		while (node1 != null) {
			if (node1.getData() == key) {
				counter++;
			}
			node1 = node1.getNext();
		}

	return counter;
    }

    /**
     * Finds and returns the value in list that matches key.
     *
     * @param key The value to search for.
     * @return The value that matches key, null otherwise.
     */
	public T find(final T key) {
		SingleNode<T> find = this.front;

		if (this.length >= 0) {
			while (find != null) {
				if (find.getData() == key) {
					return find.getData();
				}
				find = find.getNext();
			}

		}
		return null;
	}

    /**
     * Get the nth item in this SingleList.
     *
     * @param n The index of the item to return.
     * @return The nth item in this SingleList.
     * @throws ArrayIndexOutOfBoundsException if n is not a valid index.
     */
    public T get(final int n) throws ArrayIndexOutOfBoundsException {

    	 SingleNode<T> find = this.front;
    	 
    	 for (int i = 0; i < n;i++) {
    		 find = find.getNext();
    	 }

	return find.getData();
    }

    /**
     * Determines whether two lists are identical.
     *
     * @param source The list to compare against this SingleList.
     * @return true if this SingleList contains the same values in the same order as
     *         source, false otherwise.
     */
    public boolean identical(final SingleList<T> source) {

		SingleNode<T> list1 = this.front;
		SingleNode<T> list2 = source.front;

		while (list1 != null && list2 != null) {
			if (list1.getData() != list2.getData()) {
				return false;
			}
			list1 = list1.getNext();
			list2 = list2.getNext();
		}

		return true;
	}

    /**
     * Finds the first location of a value by key in this SingleList.
     *
     * @param key The value to search for.
     * @return The index of key in this SingleList, -1 otherwise.
     */
    public int index(final T key) {

		int index = 0;
		Iterator<T> iter = this.iterator();

		while (iter.hasNext()) {

			if (iter.next() == key) {
				return index;
			}
			index++;
		}

		return -1;
	}

 


	/**
     * Inserts value into this SingleList at index i. If i greater than the length
     * of this SingleList, append data to the end of this SingleList.
     *
     * @param i     The index to insert the new data at.
     * @param data The new value to insert into this SingleList.
     */
    public void insert(int i, final T data) {

		if (i > this.length && this.length != 0) {
			this.append(data);

		} else {
			if (this.length == 0) {
				this.prepend(data);
				
				//SingleNode<T> newData = new SingleNode(data, null);
				//this.front = newData;
				//this.length += 1;
			} else {

				int x;
				SingleNode<T> temp = this.front;
				SingleNode<T> prev = this.front;

				for (x = 0; x < i; x++) {
					prev = temp;
					temp = temp.getNext();

				}
				prev.setNext(new SingleNode(data, temp));
				this.length += 1;
			}
		}
		
		return;
	}


	/**
     * Creates an intersection of two other SingleLists into this SingleList. Copies
     * data to this SingleList. left and right SingleLists are unchanged. Values
     * from left are copied in order first, then values from right are copied in
     * order.
     *
     * @param left  The first SingleList to create an intersection from.
     * @param right The second SingleList to create an intersection from.
     */
    public void intersection(final SingleList<T> left, final SingleList<T> right) {

		SingleNode<T> node1 = left.front;

		while (node1 != null) {
			if (this.index(node1.getData()) == -1) {
				this.append(node1.getData());
			}
			node1 = node1.getNext();
		}

		SingleNode<T> node2 = right.front;

		while (node2 != null) {
			
			T value = node2.getData();
			int in2 = this.index(value);

			if (this.index(node2.getData()) == -1) {
				this.append(node2.getData());
			}
			node2 = node2.getNext();
		}

	}

    /**
     * Finds the maximum value in this SingleList.
     *
     * @return The maximum value.
     */
    public T max() {

		T max = this.front.getData();
		SingleNode<T> curr = this.front;

		while (curr != null) {
			if (curr.getData().compareTo(max) > 0) {
				max = curr.getData();
			}
			curr = curr.getNext();
		}
		return max;
    }

    /**
     * Finds the minimum value in this SingleList.
     *
     * @return The minimum value.
     */
    public T min() {

    	T min = this.front.getData();
    	SingleNode<T> curr = this.front;
    	
    	while (curr!= null) {
    		if (curr.getData().compareTo(min)<0) {
    			min = curr.getData();
    		}
    		curr = curr.getNext();
    	}
    	return min;

    }



	/**
     * Inserts value into the front of this SingleList.
     *
     * @param data The value to insert into the front of this SingleList.
     */
    public void prepend(final T data) {

    	this.front = new SingleNode(data,this.front);
    	this.length+=1;

	return;
    }

    /**
     * Finds, removes, and returns the value in this SingleList that matches key.
     *
     * @param key The value to search for.
     * @return The value matching key, null otherwise.
     */
    public T remove(final T key) {

		SingleNode<T> prev = this.linearSearch(key);

		T value;

		if (prev == null) {
			value = this.front.getData();
			this.front = this.front.getNext();
		} else {
			if (prev.getNext() == null) {
				value = null;
			} else {
				value = prev.getNext().getData();
				prev.setNext(prev.getNext().getNext());
			}
			this.length--;
		}

		return value;
    }

    /**
     * Removes the value at the front of this SingleList.
     *
     * @return The value at the front of this SingleList.
     */
    public T removeFront() {

		if (!this.isEmpty()) {
			SingleNode<T> node = this.front;
			if (this.length == 1) {
				this.front = null;
			}

			else {
				this.front = node.getNext();
			}
			T value = node.getData();
			this.length--;
			return value;
		}
		return null;

	}

    /**
	 * Finds and removes all values in this SingleList that match key.
	 *
	 * @param key The value to search for.
	 */
	public void removeMany(final T key) {
		while (this.find(key)!=null) {
			SingleNode<T> prev = this.linearSearch(key);
			if (prev == null) {
				this.front = this.front.getNext();
			} else {
				prev.setNext(prev.getNext().getNext());
			}
			this.length--;
		}
		return;
	}



    /**
     * Reverses the order of the values in this SingleList.
     */
    public void reverse() {

		SingleNode<T> newHead = null;
		SingleNode<T> temp = null;

		while (this.front != null) {
			temp = this.front.getNext();
			this.front.setNext(newHead);
			newHead = this.front;
			this.front = temp;
		}
		this.front = newHead;
		return;
    }

    /**
     * Splits the contents of this SingleList into the left and right SingleLists.
     * Moves nodes only - does not move value or call the high-level methods insert
     * or remove. this SingleList is empty when done. The first half of this
     * SingleList is moved to left, and the last half of this SingleList is moved to
     * right. If the resulting lengths are not the same, left should have one more
     * item than right. Order is preserved.
     *
     * @param left  The first SingleList to move nodes to.
     * @param right The second SingleList to move nodes to.
     */
    public void split(final SingleList<T> left, final SingleList<T> right) {

int mid = this.length/2;
    	
    	if (this.length%2==0) {
    		
    		while (left.length<mid) {
    			left.moveFrontToRear(this);
    		}
    		
    		while (right.length<mid) {
    			right.moveFrontToRear(this);
    		}
    	}
    	else {
    		while (left.length<=mid) {
    			left.moveFrontToRear(this);
    		}
    		while (right.length<mid) {
    			right.moveFrontToRear(this);
    		}
    	}

    }

    /**
     * Splits the contents of this SingleList into the left and right SingleLists.
     * Moves nodes only - does not move value or call the high-level methods insert
     * or remove. this SingleList is empty when done. Nodes are moved alternately
     * from this SingleList to left and right. Order is preserved.
     *
     * @param left  The first SingleList to move nodes to.
     * @param right The second SingleList to move nodes to.
     */
    public void splitAlternate(final SingleList<T> left, final SingleList<T> right) {

		boolean b = true;

		while (this.front != null) {
			if (b == true) {
				left.moveFrontToRear(this);
			} else {
				right.moveFrontToRear(this);
			}
			b = !b;
		}

	}

    /**
     * Creates a union of two other SingleLists into this SingleList. Copies value
     * to this list. left and right SingleLists are unchanged. Values from left are
     * copied in order first, then values from right are copied in order.
     *
     * @param left  The first SingleList to create a union from.
     * @param right The second SingleList to create a union from.
     */
    public void union(final SingleList<T> left, final SingleList<T> right) {
		SingleNode<T> node1 = left.front;
		SingleNode<T> node2 = right.front;

		while (node1 != null) {

			T value = node1.getData();
			int y = this.index(value);
			if (y == -1) {
				this.append(value);
			}
			node1 = node1.getNext();
		}

		

		while (node2 != null) {
			T value = node2.getData();
			int x = this.index(value);

			if (x == -1) {
				this.append(value);
			}
			node2 = node2.getNext();
		}

	}
}
