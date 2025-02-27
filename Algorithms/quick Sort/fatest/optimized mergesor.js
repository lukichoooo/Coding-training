

function partition(arr, l, r) {
    [arr[Math.floor((l + r) / 2)], arr[r]] = [arr[r], arr[Math.floor((l + r) / 2)]];    // swapping pivot with last element

    let lw = l;

    for (let i = l; i < r; i++) {
        if (arr[i] < arr[r]) {
            [arr[lw], arr[i]] = [arr[i], arr[lw]];
            lw++;
        }
    }
    [arr[lw], arr[r]] = [arr[r], arr[lw]];  // put pivot a the end of lw
    return lw;
}

function quickSort(arr, l, r) {
    if (l < r) {
        let k = partition(arr, l, r);
        quickSort(arr, l, k - 1);
        quickSort(arr, k + 1, r);
    }
}

function binarySearch(arr, l, r, target) {
    while (l <= r) {
        let mid = Math.floor((l + r) / 2);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

let arr = [2, 3, 1, 35, 4, 44, 6, 5];
quickSort(arr, 0, arr.length - 1)
console.log(arr);

let i = binarySearch(arr, 0, arr.length - 1, 1)
console.log(i);