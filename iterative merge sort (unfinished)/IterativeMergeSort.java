import java.util.Arrays;

public class IterativeMergeSort {
    public static void main(String args[]) {
        int[] arr = { 12, 11, 13, 5, 6, 7 };

        System.out.println("Given Array");
        printArray(arr);

        mergeSort(arr);

        System.out.println("\nSorted array");
        printArray(arr);
    }

    static void merge(int[] arr, int[] leftArr, int[] rightArr, int index) {
        int l = 0, r = 0;
        int i = index;

        while (l < leftArr.length && r < rightArr.length) {
            if (leftArr[l] < rightArr[r]) {
                arr[i++] = leftArr[l++];
            } else {
                arr[i++] = rightArr[r++];
            }
        }
        while (l < leftArr.length) {
            arr[i++] = leftArr[l++];
        }
        while (r < rightArr.length) {
            arr[i++] = rightArr[r++];
        }
    }

    static void mergeSort(int[] arr) {
        int size = arr.length;

        for (int cSize = 1; cSize < size; cSize *= 2) { // Size of each mini array
            for (int i = 0; i < size - cSize; i += 2 * cSize) { // Merge adjacent subarrays

                int leftSize = cSize;
                int rightSize = Math.min(cSize, size - i - cSize); // Ensure rightArr does not go out of bounds
                
                int[] leftArr = Arrays.copyOfRange(arr, i, i + leftSize);
                int[] rightArr = Arrays.copyOfRange(arr, i + leftSize, i + leftSize + rightSize);

                merge(arr, leftArr, rightArr, i);
            }
        }
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}