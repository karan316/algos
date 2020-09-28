import java.util.Stack;

// Given alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

// You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

// Return the reformatted string or return an empty string if it is impossible to reformat the string.

// Example 1:

// Input: s = "a0b1c2"
// Output: "0a1b2c"
// Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a

class ValidPermutations {
    public static void main(String[] args) {
        String s = "ab123";
        String perm_string = new String();
        int num_of_char = 0;
        int num_of_digits = 0;

        Stack<Character> char_stack = new Stack<Character>();
        Stack<Character> num_stack = new Stack<Character>();

        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetter(s.charAt(i))) {
                num_of_char++;
            } else {
                num_of_digits++;
            }
        }

        if (Math.abs(num_of_char - num_of_digits) != 1) {
            System.out.println("no perm");
            return;
        }
        {
            int i = 0, j = 0;
            for (char ch : s.toCharArray()) {
                if (Character.isLetter(ch)) {
                    char_stack.push(ch);
                } else {
                    num_stack.push(ch);
                }
            }
        }

        // num_of_char = num_of_digits-1
        if (num_of_char == num_of_digits - 1) {
            for (int i = 0; i < s.length(); i++) {
                if (!num_stack.isEmpty())
                    perm_string += num_stack.pop().toString();
                if (!char_stack.isEmpty())
                    perm_string += char_stack.pop().toString();
            }
        } else {
            for (int i = 0; i < s.length(); i++) {
                if (!char_stack.isEmpty())
                    perm_string += char_stack.pop().toString();
                if (!num_stack.isEmpty())
                    perm_string += num_stack.pop().toString();
            }
        }
        System.out.println(perm_string);

    }
}