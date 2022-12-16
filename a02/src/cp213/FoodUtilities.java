package cp213;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Utilities for working with Food objects.
 *
* @author Mubin Qureshi, 180181900, qure1900@mylaurier.ca
 * @version 2021-10-10
 */
public class FoodUtilities {

    /**
     * Determines the average calories in a list of foods. No rounding necessary.
     * Foods list parameter may be empty.
     *
     * @param foods a list of Food
     * @return average calories in all Food objects
     */
    public static int averageCalories(final ArrayList<Food> foods) {

	int i = 0;
	int avg = 0;
	
	for (i = 0; i < foods.size();i++) {
		avg += foods.get(i).getCalories();
		
	}
	avg = avg/i;
		

	return avg;
    }

    /**
     * Determines the average calories in a list of foods for a particular origin.
     * No rounding necessary. Foods list parameter may be empty.
     *
     * @param foods  a list of Food
     * @param origin the origin of the Food
     * @return average calories for all Foods of the specified origin
     */
    public static int averageCaloriesByOrigin(final ArrayList<Food> foods, final int origin) {

    	int i = 0;
    	int j = 0;
    	int avg = 0;
    	
    	for (i = 0; i < foods.size();i++) {
    		if (foods.get(i).getOrigin() == origin){
    		avg += foods.get(i).getCalories();
    		j++;
    		}
    	}
    	avg = avg/j;
    	return avg;
        }

    /**
     * Creates a list of foods by origin.
     *
     * @param foods  a list of Food
     * @param origin a food origin
     * @return a list of Food from origin
     */
    public static ArrayList<Food> getByOrigin(final ArrayList<Food> foods, final int origin) {

    	ArrayList<Food> foodorigin = new ArrayList<>();
		for (int i = 0; i < foods.size(); i++) {

			if (foods.get(i).getOrigin() == origin) {
				foodorigin.add(foods.get(i));
			}
		}
		return foodorigin;
	}
    /**
     * Creates a Food object by requesting data from a user. Uses the format:
     *
     * <pre>
    Name: name
    Origins
     0 Canadian
     1 Chinese
    ...
    11 English
    Origin: origin number
    Vegetarian (Y/N): Y/N
    Calories: calories
     * </pre>
     *
     * @param keyboard a keyboard Scanner
     * @return a Food object
     */
    public static Food getFood(final Scanner keyboard) {

    	System.out.print("Name: ");
		String name = keyboard.next();
		System.out.println(Food.originsMenu());
		System.out.print("Origin: ");
		int orig = keyboard.nextInt();
		
		System.out.print("Vegetarian (Y/N): ");
		boolean isVegetarian = true;
		String veg = keyboard.next();
		
		if( veg.equalsIgnoreCase("y")){
			isVegetarian = true;
		}else {
			isVegetarian = false;
		}
		
		System.out.print("Calories: ");
		int calories = keyboard.nextInt();

    	
    	Food newFood = new Food(name, orig, isVegetarian, calories);
    	
    	return newFood;
    }

    /**
     * Creates a list of vegetarian foods.
     *
     * @param foods a list of Food
     * @return a list of vegetarian Food
     */
    public static ArrayList<Food> getVegetarian(final ArrayList<Food> foods) {

    	ArrayList<Food> foodVeg = new ArrayList<>();
		for (int i = 0; i < foods.size(); i++) {

			if (foods.get(i).isVegetarian() == true) {
				foodVeg.add(foods.get(i));
			}
		}
		return foodVeg;
	}

    /**
     * Creates and returns a Food object from a line of string data.
     *
     * @param line a vertical bar-delimited line of food data in the format
     *             name|origin|isVegetarian|calories
     * @return the data from line as a Food object
     */
    public static Food readFood(final String line) {

Scanner lineScanner = new Scanner(line);
    	int y,cal;
    	boolean isVeg;
    	String x;
    	
		lineScanner.useDelimiter("\\|");
		x = lineScanner.next();
		y = Integer.parseInt(lineScanner.next());
		isVeg = Boolean.parseBoolean(lineScanner.next());
		cal = Integer.parseInt(lineScanner.next());
		Food newFood = new Food(x, y, isVeg, cal);
		lineScanner.close();
		
		return newFood;
    }

    /**
     * Reads a file of food strings into a list of Food objects.
     *
     * @param fileIn a Scanner of a Food data file in the format
     *               name|origin|isVegetarian|calories
     * @return a list of Food
     */
    public static ArrayList<Food> readFoods(final Scanner fileIn) {

	ArrayList<Food> foods = new ArrayList<>();
    	
		while (fileIn.hasNext()) {
			foods.add(readFood(fileIn.nextLine()));
		}

	return foods;
	}

    /**
     * Searches for foods that fit certain conditions.
     *
     * @param foods        a list of Food
     * @param origin       the origin of the food; if -1, accept any origin
     * @param maxCalories  the maximum calories for the food; if 0, accept any
     * @param isVegetarian whether the food is vegetarian or not; if false accept
     *                     any
     * @return a list of foods that fit the conditions specified
     */
    public static ArrayList<Food> foodSearch(final ArrayList<Food> foods, final int origin, final int maxCalories,
	    final boolean isVegetarian) {
    	
    	
		ArrayList<Food> search = new ArrayList<>();

		for (int i = 0; i < foods.size(); i++) {
			if (maxCalories == 0 && origin == -1 && isVegetarian == false) {
				search.add(foods.get(i));
			}
			if (maxCalories > 0) {
				if (origin == -1) {
					if (isVegetarian == false) {
						if (foods.get(i).getCalories() <= maxCalories) {
							search.add(foods.get(i));
						}
					} else {
						if (foods.get(i).isVegetarian() == true)
							if (foods.get(i).getCalories() <= maxCalories) {
							search.add(foods.get(i));
							}
					}

				} else {
					if (isVegetarian == false) {
						if (foods.get(i).getOrigin() == origin) {
							if (foods.get(i).getCalories() <= maxCalories) {
								search.add(foods.get(i));
							}
						}
					} else {
						if (foods.get(i).getOrigin() == origin) {
							if (foods.get(i).isVegetarian() == true)
								if (foods.get(i).getCalories() <= maxCalories) {
								search.add(foods.get(i));
								}
						}
					}
				}
			} else {
				
				if (origin == -1) {
					if (isVegetarian == false) {
							search.add(foods.get(i));
						
					} else {
						if (foods.get(i).isVegetarian() == true)
							search.add(foods.get(i));
					}

				} else {
					if (isVegetarian == false) {
						if (foods.get(i).getOrigin() == origin) {
								search.add(foods.get(i));
							
						}
					} else {
						if (foods.get(i).getOrigin() == origin) {
							if (foods.get(i).isVegetarian() == true)
								search.add(foods.get(i));
						}
					}
				}
				
			}
		}

		
		return search;
	}

    /**
     * Writes the contents of a list of Food to a PrintStream.
     *
     * @param foods a list of Food
     * @param ps    the PrintStream to write to
     */
    public static void writeFoods(final ArrayList<Food> foods, PrintStream ps) {

    	for (int i = 0; i < foods.size(); i++) {
			ps.println(foods.get(i).toString());
		}
		ps.close();
    }
}

