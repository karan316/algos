import java.util.Scanner;

class Hotel {
    private int frequency;
    private String name;

    public Hotel(int frequency, String name) {
        this.frequency = frequency;
        this.name = name;
    }
}

class Pair {
    private int first;
    private int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    int getFirst() {
        return first;
    }

    int getSecond() {
        return second;
    }

};

// incomplete
public class SmallestLexString {
    // static void swap(char a, char b) {
    // char temp;
    // temp = a;
    // a = b;
    // b = temp;
    // }
    static boolean containsPair(Pair pair[], int m, int n) {
        for (int i = 0; i < pair.length; i++) {
            if (pair[i].getFirst() == m && pair[i].getSecond() == n) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s = "abagfiab";
        String t = "cbacbcda";

        char s_char[] = s.toCharArray();
        char t_char[] = t.toCharArray();
        int k = 4;
        int n = 8;
        Pair pair[] = new Pair[] { new Pair(0, 1), new Pair(1, 2), new Pair(3, 4), new Pair(4, 5) };

        for (int i = 0; i < n; i++) {
            if (s_char[i] > t_char[i]) {
                char temp = s_char[i];
                s_char[i] = t_char[i];
                t_char[i] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s_char[i] > t_char[j] && containsPair(pair, i, j)) {
                    char temp1 = t_char[i];
                    t_char[i] = t_char[j];
                    t_char[j] = temp1;

                    char temp2 = s_char[i];
                    s_char[i] = t_char[j];
                    t_char[j] = temp2;
                }
            }
        }
        System.out.println(new String(s_char));
    }

}