
public class LongestCommonPrefix {
    public static void main(String[] args) {
        String[] strs = { "ca", "a" };
        int min = Integer.MAX_VALUE;
        String min_string = "";
        String common_prefix = "";
        for (int i = 0; i != strs.length; i++) {
            if (strs[i].length() < min) {
                min_string = strs[i];
                min = min_string.length();
                if (strs[i].equals(min_string) && i == strs.length - 1) {
                    System.out.println(strs[i]);
                    return;
                }
            }

        }
        while (min != 0) {
            for (int i = 0; i != strs.length; i++) {
                if (strs[i].startsWith(min_string.substring(0, min))) {
                    if (strs[strs.length - 1].startsWith(min_string.substring(0, min))
                            && !strs[strs.length - 1].equals(min_string)) {
                        common_prefix = min_string.substring(0, min);
                        System.out.println(common_prefix);
                        return;
                    }
                    if (strs[i].length() == min_string.length() && !strs[i].equals(min_string)) {
                        System.out.println(common_prefix);
                        return;
                    }

                }

            }
            min--;
        }
        System.out.println(common_prefix);

    }
}