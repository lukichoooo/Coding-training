function quickSort(arr, l, r) {
  if (l < r) {
    var j = partition(arr, l, r);
    quickSort(arr, l, j - 1);
    quickSort(arr, j + 1, r);
  }
}

function partition(arr, l, r) {
  let p = arr[l];
  let i = l,
    j = r;
  while (i < j) {
    while (arr[i] <= p && i < r) i++; // put everything <= Pivot behind indexes of J
    while (arr[j] > p && j >= l) j--; // put everything > Pivot after indexes of I
    if (i < j) swap(arr, i, j);
  }
  swap(arr, l, j);  // swap thoe indexes in array
  return j; // now j is where Pivot is
}

function swap(arr, i, j) {
  let temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// Main
console.log("hii");

let arr = [2, 4343, 636, 643, 5, 23, 1, 2, 34];
quickSort(arr, 0, arr.length - 1);

console.log(arr); // Output the sorted array
