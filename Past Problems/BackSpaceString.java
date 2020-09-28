import java.util.*;

class BackSpaceString {

    // public static String removeBackspace(String s) {
    // StringBuffer s1 = new StringBuffer(s);
    // StringBuilder s2 = new StringBuilder(s);
    // for (int i = 0; i != s.length(); i++) {
    // if ((s.charAt(i) == '#') && (i != 0) && (s.charAt(i - 1) !=
    // Character.MIN_VALUE)) {
    // if (i != s.length() - 1)
    // s1.replace(i, i + 1, "");
    // else
    // s1.deleteCharAt(i);
    // s1.replace(i - 1, i, "");
    // }
    // }
    // String new_string = new String(s1);
    // return new_string;
    // }
    // public static String deleteBackspace(String s) {
    // StringBuffer s1 = new StringBuffer(s);
    // for (int i = 0; i != s.length(); i++) {
    // if (s.charAt(i) == '#') {
    // s1.delete(i - 1, i + 1);
    // }
    // }
    // String s2 = new String(s1);
    // return s2;
    // }

    public static boolean backspaceCompare(String s, String t) {
        Stack<Character> sStack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c != '#') {
                sStack.push(c);
            } else if (!sStack.isEmpty()) {
                sStack.pop();
            }
        }

        Stack<Character> tStack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c != '#') {
                tStack.push(c);
            } else if (!tStack.isEmpty()) {
                tStack.pop();
            }
        }

        while (!sStack.isEmpty()) {
            char current = sStack.pop();
            if (tStack.isEmpty() || tStack.pop() != current) {
                return false;
            }
        }
        return sStack.isEmpty() && tStack.isEmpty();

    }

    public static void main(String[] args) {
        String s = "ab##";
        String t = "c#d#";
        // // if (removeBackspace(s).equals(removeBackspace(t)))
        // // System.out.println("true");
        // // else
        // // System.out.println("false");
        System.out.println(backspaceCompare(s, t));
    }
}