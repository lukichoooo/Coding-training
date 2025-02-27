package fatest;
public class FuckJava {
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
        int p = arr[(l + r) / 2]; // select middle element as pivot

        arr[(l + r) / 2] = arr[r];
        arr[r] = p;

        int i = l;
        // "left wall" we will move it to the right and put values lesser than pivot in
        // it
        // and in the end pivot will go to the right of the left wall since its bigger
        // than them all

        for (int j = l; j < r; j++) { // j is an index to move through whole array (not to the end "r" coz we have
                                      // pivot there)
            if (arr[j] < p) {

                int temp = arr[j];
                arr[j] = arr[i]; // swap values on i and j
                arr[i] = temp;

                i++; // if (arr[j] < pivot) we place arr[j] on index "left wall" (i) value on j
                // i only moves when (j < pivot) while j always moves
                // "i" is just a WALL and behind it are already pertitioned elements
                // keep in mind, "i" is not on the element that was swapped, thats on "i-1"
            }
        }
        arr[r] = arr[i]; // i-1 has the last value which was less than pivot, so we put pivot on i
        arr[i] = p;

        return i; // returning index of pivot (the sorted value)
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
