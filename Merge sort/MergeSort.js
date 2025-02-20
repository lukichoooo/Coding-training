
function mergeSort(arr) {
    if (arr.length <= 1) {
        return arr;
    }

    let mid = Math.floor(arr.length / 2);
    let left = arr.slice(0, mid);
    let right = arr.slice(mid);

    return merge(mergeSort(left), mergeSort(right));

}

function merge(left, right) {
    let array = [];
    let r = 0, l = 0;

    for (let i = 0; i < left.length && r < right.length; i++) {
        if (left[l] < right[r]) {
            array[i] = left[l];
            l++;
        } else {
            array[i] = right[r];
            r++;
        }
    }

    while (l < left.length) {
        array.push(left[l]);
        l++;
    }
    while (r < right.length) {
        array.push(right[r]);
        r++;
    }
    return array;
}

let arr = [12, 11, 13, 5, 6, 7];
console.log(mergeSort(arr));