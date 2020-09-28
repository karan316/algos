import java.util.*;

public class StringMatching {
    public static void main(String[] args) {
        String[] words = { "leetcoder", "leetcode", "od", "hamlet", "am" };
        List<String> substr = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i != j && words[j].contains(words[i])) {
                    substr.add(words[i]);
                    break;
                }
            }
        }

        System.out.println(substr);
    }
}