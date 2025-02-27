public class QuickSort {
    public static void main(String args[]) {
        int[] arr = { 12, 11, 13, 5, 6, 7, 32523532, 13 };

        System.out.println("Given Array");
        printArray(arr);

        quickSort(arr, 0, arr.length - 1);

        System.out.println("\nSorted array");
        printArray(arr);
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void quickSort(int[] arr, int l, int r) {
        if (l < r) {
            int j = partition(arr, l, r);
                quickSort(arr, j + 1, r);
                quickSort(arr, l, j - 1);
        }
    }

    public static int partition(int[] arr, int l, int r) {
        int p = arr[l];
        int i = l, j = r;

        while (i < j) {
            while (arr[i] <= p && i < r)  // here should be arr[i] <= p, because j is swapping 
                i++;
            while (arr[j] > p && j >= l)
                j--;
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[l];
        arr[l] = arr[j];
        arr[j] = temp;

        return j;
    }

}
