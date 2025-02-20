import java.util.Arrays;
import java.util.Random;

public class BinarySearch {
    static boolean binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1, mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }

    // uses more space, Space Complexity: O(log n)
    // this is because it has to give the return value to the previous call of recursive function
    static boolean altBinarySearch(int[] arr, int left, int right, int target) {
        if (left > right) {
            return false; // Not found
        }

        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true; // Found target
        else if (arr[mid] > target) {
            return altBinarySearch(arr, left, mid - 1, target);
        } else
            return altBinarySearch(arr, mid + 1, right, target);

    }

    public static void main(String[] args) {

        Random rand = new Random();

        int arr[] = new int[20];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = rand.nextInt(100);
        }

        arr[0] = 77;

        Arrays.sort(arr);

        System.out.println(Arrays.toString(arr));

        System.out.println(altBinarySearch(arr, 0, arr.length - 1, 77) ? "yes" : "no");
    }
}
