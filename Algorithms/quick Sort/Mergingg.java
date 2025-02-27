public class Mergingg {
    public static void main(String[] args) {
        int[] arr = { 12, 11, 13, 5, 6, 2 };

        System.out.println("Given Array");
        printArray(arr);

        quickSort(arr, 0, arr.length - 1);

        System.out.println("\nSorted array");
        printArray(arr);
    }

    public static void quickSort(int[] arr, int l, int r) {
        if (l < r) {
            int j = pertition(arr, l, r);
            quickSort(arr, j + 1, r);
            quickSort(arr, l, j - 1);
        }
    }

    public static int pertition(int[] arr, int l, int r) {
        int mid = (l + r) / 2;
        int i = l, j = r;

        int p = arr[mid];
        arr[mid] = arr[r];
        arr[r] = p; // putting pivot at last index so it doesnt get messy

        while (i < j) {
            if (p > arr[i] && i < r) // everything left must be less than pivot (arr[r])
                i++;
            if (p < arr[j] && j >= l) // everything right of p must be greater
                j--;
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                 // hmm lets go thtough it
            }
        }
        arr[j] = p; // putting pivot back at mid, and arr[r] back

        return j;
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
