
public class LogMain {

    static int logn(int n) {
        int i = 0;
        while (n > 1) {
            n /= 2;
            i++;
        }
        return i;
    }

    public static void main(String[] args) {
        System.out.println("log(16) = " + logn(16));
    }
}