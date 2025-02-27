package stupid.recursive;

public class Recursive {
    public static void main(String args[]) {

        System.out.println(isPalP("racecar"));

    }

    public static int Rsum(int k) {
        if (k == 1)
            return 1;

        return k + Rsum(k - 1);
    }

    public static boolean isPalR(String s) {
        if (s.length() < 2)
            return true;
        if (s.charAt(0) == s.charAt(s.length() - 1)) {
            return isPalR(s.substring(1, s.length() - 1));
        }
        return false;
    }

    public static boolean isPal(String str) {
        String s = str;
        while (s.length() > 1) {
            if (s.charAt(0) != s.charAt(s.length() - 1)) {
                return false;
            }
            s = s.substring(1, s.length() - 1);
        }
        return true;
    }

    public static boolean isPalP(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

}
