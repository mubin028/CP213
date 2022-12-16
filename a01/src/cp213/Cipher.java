package cp213;

/**
 * @author Mubin Qureshi 180181900
 * @version 2021-09-11
 */
public class Cipher {
	// Constants
	public static final String ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	public static final int ALPHA_LENGTH = ALPHA.length();

	/**
	 * Encipher a string using a shift cipher. Each letter is replaced by a letter
	 * 'n' letters to the right of the original. Thus for example, all shift values
	 * evenly divisible by 26 (the length of the English alphabet) replace a letter
	 * with itself. Non-letters are left unchanged.
	 *
	 * @param s string to encipher
	 * @param n the number of letters to shift
	 * @return the enciphered string
	 */
	public static String shift(final String s, final int n) {

		int replace;
		String switched = "";
		for (int i = 0; i < s.length(); i++) {
			if ( (s.charAt(i) <= 90)&& (s.charAt(i) >= 65)) {
					replace = s.charAt(i) + n;
				switched = switched + Character.toString(replace);	
				}
		
			}
		return switched;
		}
	


	/**
	 * Encipher a string using the letter positions in ciphertext. Each letter is
	 * replaced by the letter in the same ordinal position in the ciphertext.
	 * Non-letters are left unchanged. Ex:
	 *
	 * <pre>
	Alphabet:   ABCDEFGHIJKLMNOPQRSTUVWXYZ
	Ciphertext: AVIBROWNZCEFGHJKLMPQSTUXYD
	 * </pre>
	 *
	 * A is replaced by A, B by V, C by I, D by B, E by R, and so on. Non-letters
	 * are ignored.
	 *
	 * @param s          string to encipher
	 * @param ciphertext ciphertext alphabet
	 * @return the enciphered string
	 */
	public static String substitute(final String s, final String ciphertext) {

		String str = "";

		for (int i = 0; i < s.length(); i++) {
			if ((s.charAt(i) <= 90) && (s.charAt(i) >= 65)) {
				str = str + ciphertext.charAt((s.charAt(i)) - 65);
			} else {
				str = str + s.charAt(i);
			}
		}
		return str;
	}
}