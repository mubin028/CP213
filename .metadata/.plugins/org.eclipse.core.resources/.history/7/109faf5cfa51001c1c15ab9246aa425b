package cp213;

import java.math.BigDecimal;
import java.math.RoundingMode;

/**
 * Defines the name and price of a menu item. Price is stored as a BigDecimal to
 * avoid rounding errors.
 *
 * @author your name here
 * @author Abdul-Rahman Mawlood-Yunis
 * @author David Brown
 * @version 2021-11-01
 */
public class MenuItem {

    private String name = null;
    private BigDecimal price = null;

    /**
     * Constructor.
     *
     * @param name  Name of the menu item.
     * @param price Price of the menu item.
     */
    public MenuItem(final String name, final BigDecimal price) {
	this.name = name;
	this.price = price;
	// Set to use 2 decimal points in calculations
	this.price.setScale(2, RoundingMode.HALF_EVEN);
    }

    /**
     * Alternate constructor. Converts a double price to BigDecimal.
     *
     * @param name  Name of the menu item.
     * @param price Price of the menu item.
     */
    public MenuItem(final String name, final double price) {
	// Call super constructor
	this(name, new BigDecimal(price));
    }

    /**
     * name getter
     *
     * @return Name of the menu item.
     */
    public String getName() {

	// your code here

	return null;
    }

    /**
     * price getter
     *
     * @return Price of the menu item.
     */
    public BigDecimal getPrice() {

	// your code here

	return null;
    }

    /**
     * Returns a MenuItem as a String in the format:
     *
     * <pre>
hot dog      $ 1.25
pizza        $10.00
</pre>
     */
    @Override
    public String toString() {

	// your code here

	return null;
    }
}