public class Main {
    public static void main(String args[]) {
        int[] arr = { 12, 11, 13, 5, 6, 7, 32523532, 13 };

        System.out.println("Given Array");
        printArray(arr);

        mergeSort(arr, 0, arr.length - 1);

        System.out.println("\nSorted array");
        printArray(arr);
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void mergeSort(int arr[], int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, r, mid);
    }

    public static void merge(int[] arr, int start, int end, int mid) {

        int i = 0, r = mid + 1, l = start;

        int[] tarr = new int[end - start + 1];

        while (l <= mid && r <= end) {
            tarr[i++] = (arr[l] < arr[r]) ? arr[l++] : arr[r++];
        }
        while(l <= mid)
        tarr[i++] = arr[l++];
        while(r <= end)
        tarr[i++] = arr[r++];

        for (int k = 0; start <= end; k++) {
            arr[start++] = tarr[k];
        }
    }
}
