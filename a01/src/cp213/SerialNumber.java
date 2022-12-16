package cp213;

import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Mubin Qureshi 180181900
 * @version 2021-09-11
 */
public class SerialNumber {

	/**
	 * Determines if a string contains all digits.
	 *
	 * @param str The string to test.
	 * @return true if str is all digits, false otherwise.
	 */
	public static boolean allDigits(final String str) {

		String nums = "0123456789";

		for (int i = 0; i < str.length(); i++) {
			if (!nums.contains(String.valueOf(str.charAt(i)))) {
				return false;
			}
		}

		return true;
	}

	/**
	 * Determines if a string is a good serial number. Good serial numbers are of
	 * the form 'SN/nnnn-nnn', where 'n' is a digit.
	 *
	 * @param sn The serial number to test.
	 * @return true if the serial number is valid in form, false otherwise.
	 */
	public static boolean validSn(final String sn) {

		if (sn.length() == 11) {
			if ((sn.startsWith("SN/"))) {
				for (int i = 3; i <= 10; i++) {
					if (i == 7) {
						if (sn.charAt(i) != '-') {
							return false;
						}
					} else if (!(Character.isDigit(sn.charAt(i)))) {
						return false;
					}
				}
				return true;
			}
		}
		return false;
	}

	/**
	 * Evaluates serial numbers from a file. Writes valid serial numbers to
	 * good_sns, and invalid serial numbers to bad_sns.
	 *
	 * @param fileIn  a file already open for reading
	 * @param goodSns a file already open for writing
	 * @param badSns  a file already open for writing
	 */
	public static void validSnFile(final Scanner fileIn, final PrintStream goodSns, final PrintStream badSns) {

		while (fileIn.hasNext()) {
			String x = fileIn.nextLine();
			if (validSn(x)) {
				goodSns.println(x);
			} else {
				badSns.println(x);
			}
		}
	}
}
