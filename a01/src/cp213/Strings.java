package cp213;

/**
 * @author Mubin Qureshi 180181900
 * @version 2021-09-11
 */
public class Strings {
	// Constants
	public static final String VOWELS = "aeiouAEIOU";

	/**
	 * Determines if string is a "palindrome": a word, verse, or sentence (such as
	 * "Able was I ere I saw Elba") that reads the same backward or forward. Ignores
	 * case, spaces, digits, and punctuation in the string parameter s.
	 *
	 * @param string a string
	 * @return true if string is a palindrome, false otherwise
	 */
	public static boolean isPalindrome(final String string) {

		String string1;
		string1 = string.replaceAll("[^A-Za-z]+", "").toLowerCase();
		int x = 0, y = (string1.length() - 1);

		while (x < y) {

			if (string1.charAt(x) != string1.charAt(y)) {
				return false;
			}
			x += 1;
			y -= 1;
		}
		return true;
	}

	/**
	 * Determines if name is a valid Java variable name. Variables names must start
	 * with a letter or an underscore, but cannot be an underscore alone. The rest
	 * of the variable name may consist of letters, numbers and underscores.
	 *
	 * @param name a string to test as a Java variable name
	 * @return true if name is a valid Java variable name, false otherwise
	 */
	public static boolean isValid(final String name) {
		boolean valid = true;

		String specialChars = "~`!@#$%^&*()-=+";

		if (name.isEmpty()) {
			return false;
		}

		if (name.startsWith("_") && name.length() == 1) {
			return false;
		}

		if (Character.isDigit(name.charAt(0))) {
			return false;
		} else {
			for (int i = 0; i < name.length(); i++) {
				if (specialChars.contains(String.valueOf(name.charAt(i)))) {
					return false;
				}
			}
		}

		return valid;
	}

	/**
	 * Converts a word to Pig Latin. The conversion is:
	 * <ul>
	 * <li>if a word begins with a vowel, add "way" to the end of the word.</li>
	 * <li>if the word begins with consonants, move the leading consonants to the
	 * end of the word and add "ay" to the end of that. "y" is treated as a
	 * consonant if it is the first character in the word, and as a vowel for
	 * anywhere else in the word.</li>
	 * </ul>
	 * Preserve the case of the word - i.e. if the first character of word is
	 * upper-case, then the new first character should also be upper case.
	 *
	 * @param word The string to convert to Pig Latin
	 * @return the Pig Latin version of word
	 */
	public static String pigLatin(String word) {
		int num = 0;
		String newWord = "";

		if (VOWELS.contains(String.valueOf(word.charAt(0)))) {
			newWord = word + "way";
		}

		else {

			for (int i = 0; i < word.length(); i++) {
				if (VOWELS.contains(String.valueOf(word.charAt(i)))) {
					num = i;
					break;
				}
			}

			String str = "";
			for (int i = 0; i < num; i++) {
				str += word.charAt(i);
			}

			if (Character.isUpperCase(word.charAt(0))) {

				newWord = word.substring(num, num + 1).toUpperCase() + word.substring(num + 1) + str.toLowerCase()
						+ "ay";
			} else {
				newWord = word.substring(num, num + 1).toLowerCase() + word.substring(num + 1) + str.toLowerCase()
						+ "ay";
			}
		}

		return newWord;

	}
}
