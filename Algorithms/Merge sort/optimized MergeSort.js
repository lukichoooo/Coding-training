function mergeSort(arr) {
  if (arr.length <= 1) return arr;

  const mid = Math.floor(arr.length / 2);
  const right = arr.slice(mid);
  const left = arr.slice(0, mid);

  return merge(mergeSort(left), mergeSort(right));
}

function merge(left, right) {
  let i = 0,
    l = 0,
    r = 0;
  let result = new Array(left.length + right.length);

  // Merge elements from both halves in sorted order
  while (l < left.length && r < right.length) {
    result[i++] = left[l] < right[r] ? left[l++] : right[r++];
  }

  while (l < left.length) result[i++] = left[l++];
  while (r < right.length) result[i++] = right[r++];

  return result;
}

// More optimized version
function mergeSortIterative(arr) {
  let width = 1, n = arr.length;
  let temp = new Array(n);

  while (width < n) {
    for (let i = 0; i < n; i += 2 * width) {
      mergeIterative(arr, temp, i, Math.min(i + width, n), Math.min(i + 2 * width, n));
    }
    [arr, temp] = [temp, arr]; // Swap arrays
    width *= 2;
  }
  return arr;
}

function mergeIterative(arr, temp, left, mid, right) {
  let l = left, r = mid, i = left;

  while (l < mid && r < right) {
    temp[i++] = arr[l] < arr[r] ? arr[l++] : arr[r++];
  }

  while (l < mid) temp[i++] = arr[l++];
  while (r < right) temp[i++] = arr[r++];
}


var arr = [35, 2, 36, 44, 5, 5, 7, 111, 9, 10];

console.log(mergeSort(arr));
