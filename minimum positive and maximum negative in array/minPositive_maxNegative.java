import java.util.Random;

public class minPositive_maxNegative {
    public static void main(String[] args) {

        Random random = new Random();

        int[] arr = new int[20];
        for (int i = 0; i < 20; ++i) {
            arr[i] = random.nextInt(200) - 100;
        }
    
        int minP = 0x7FFFFFFF;
        int maxN = 0x80000000;
        for (int i = 0; i < arr.length; ++i) {
            if(arr[i] > 0){
    
            if(arr[i] < minP){
                minP = arr[i];
            }
        } else {
            if(arr[i] > maxN){
                maxN = arr[i];
            }
        }
    }
    System.out.println("Min positive: " + minP + " Max negative: " + maxN);
    }
}