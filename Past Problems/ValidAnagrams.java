import java.util.Arrays;

public class ValidAnagrams {
    public static void main(String[] args) {
        String s = "anagram";
        String t = "nagaram";

        char[] s1 = s.toCharArray();
        char[] t1 = t.toCharArray();

        Arrays.sort(s1);
        Arrays.sort(t1);

        String s2 = new String(s1);
        String t2 = new String(t1);
        if (s2.equals(t2)) {
            System.out.println("true");
        } else {
            System.out.println("false");
        }

    }
}