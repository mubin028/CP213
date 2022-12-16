package cp213;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.print.PrinterJob;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * The GUI for the Order class.
 *
 * @author Mubin Qureshi
 * @author Abdul-Rahman Mawlood-Yunis
 * @author David Brown
 * @version 2021-11-01
 */
@SuppressWarnings("serial")
public class OrderPanel extends JPanel {

    /**
     * Implements an ActionListener for the 'Print' button. Prints the current
     * contents of the Order to a system printer or PDF.
     */
    private class PrintListener implements ActionListener {

	@Override
	public void actionPerformed(final ActionEvent e) {
	    final PrinterJob printJob = PrinterJob.getPrinterJob();
	    printJob.setPrintable(order);

	    if (printJob.printDialog()) {
		try {
		    printJob.print();
		} catch (final Exception printException) {
		    System.err.println(printException);
		}
	    }
	}
    }

    /**
     * Implements a FocusListener on a JTextField. Accepts only positive integers,
     * all other values are reset to 0. Adds a new MenuItem to the Order with the
     * new quantity, updates an existing MenuItem in the Order with the new
     * quantity, or removes the MenuItem from the Order if the resulting quantity is
     * 0.
     */
    private class QuantityListener implements FocusListener {

	

	@Override
	public void focusGained(final FocusEvent evt) {

	    // your code here

	}

	@Override
	public void focusLost(final FocusEvent evt) {

	    // your code here

	}
    }

    // Attributes
    private Menu menu = null;
    private final Order order = new Order();
    private final JButton printButton = new JButton("Print");
    private final JLabel subtotalLabel = new JLabel("0");
    private final JLabel taxLabel = new JLabel("0");
    private final JLabel totalLabel = new JLabel("0");
    

    /**
     * Displays the menu in a GUI.
     *
     * @param menu The menu to display.
     */
    public OrderPanel(final Menu menu) {
	this.menu = menu;
	this.layoutView();
    }

    /**
     * Uses the GridLayout to place the labels and buttons.
     */
    	
	private void layoutView() {
		this.setBorder(BorderFactory.createEmptyBorder(6, 6, 6, 6));
		// Number of rows of GridLayout must be updated to accommodate all MenuItems,
		// totals, and Print button
		this.setLayout(new GridLayout(0, 3));
		this.add(new JLabel("Item"));
		this.add(new JLabel("Price"));
		this.add(new JLabel("Quantity"));
		QuantityListener q = new QuantityListener();

		for (int i = 0; i < menu.size(); i++) {
			this.add(new JLabel(menu.getItem(i).getName()));
			this.add(new JLabel(String.format("$%.2f", menu.getItem(i).getPrice())));

			JTextField quantityBox = new JTextField("0");
			this.add(quantityBox);
			quantityBox.addFocusListener(q);
			quantities.add(quantityBox);

		}
		this.add(new JLabel("Subtotal:"));
		this.add(new JLabel());
		this.add(subtotalLabel);

		this.add(new JLabel("Tax:"));
		this.add(new JLabel());
		this.add(taxLabel);

		this.add(new JLabel("Total:"));
		this.add(new JLabel());
		this.add(totalLabel);

		this.printButton.addActionListener(new PrintListener());
		this.add(this.printButton);
		return;
	}
}
