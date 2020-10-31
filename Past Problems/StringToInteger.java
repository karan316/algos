
public class StringToInteger {
    public static void main(String[] args) {
        String str = "-4193 with words";
        char[] ch = str.toCharArray();
        char[] int_string = { Character.MIN_VALUE };
        for (int i = 0; i < ch.length; i++) {
            if (Character.isWhitespace(ch[i]) && ch[i] != '-' && ch[i] != '+' && Character.isLetter(ch[i])) {
                continue;
            }
            int_string[i] = ch[i];
        }
        String integer = new String(ch);
        System.out.println(integer);
    }
}