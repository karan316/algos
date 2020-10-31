
public class StringShift {

    public static String rightShift(String str) {
        char[] ch = str.toCharArray();
        char temp = ch[ch.length - 1];
        for (int i = ch.length - 2; i >= 0; i--) {
            ch[i + 1] = ch[i];
        }
        ch[0] = temp;
        str = new String(ch);
        return str;
    }

    public static String leftShift(String str) {
        char[] ch = str.toCharArray();
        char temp = ch[0];
        for (int i = 0; i < ch.length - 1; i++) {
            ch[i] = ch[i + 1];
        }
        ch[ch.length - 1] = temp;
        str = new String(ch);
        return str;
    }

    public static void main(String[] args) {
        String s = "abc";
        int[][] shift = { { 0, 1 }, { 1, 2 } };
        int final_shift = 0;
        for (int i = 0; i < shift.length; i++) {
            if (shift[i][0] == 0) {
                final_shift -= shift[i][1];
            }

            if (shift[i][0] == 1) {
                final_shift += shift[i][1];
            }
        }
        if (final_shift == 0) {
            System.out.println(s);
        } else if (final_shift < 0) {
            while (final_shift != 0) {
                s = leftShift(s);
                final_shift++;
            }
            System.out.println(s);
        } else if (final_shift > 0) {
            while (final_shift != 0) {
                s = rightShift(s);
                final_shift--;
            }
            System.out.println(s);
        }
    }
}