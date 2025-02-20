// Generate an array of 20 random numbers (0-99)
let arr = Array.from({ length: 20 }, () => Math.floor(Math.random() * 100));

arr.push(77);  // Add 77 to the array
arr.sort((a, b) => a - b); // Sort numerically

console.log(arr); // Print sorted array

function binarySearch(arr, target) {
    let left = 0, right = arr.length - 1;

    while (left <= right) {
        let mid = left + Math.floor((right - left) / 2);

        if (arr[mid] === target) return true; // Found target
        else if (arr[mid] > target) right = mid - 1; // Search left half
        else left = mid + 1; // Search right half
    }
    return false; // Not found
}


// uses more space,  Space Complexity: O(log n) 
// this is because it has to give the return value to the previous call of recursive function
function altBinarySearch(arr, left, right, target) {
    if (left > right) {
        return false; // Not found
    }

    let mid = left + Math.floor((right - left) / 2);

    if (arr[mid] === target) return true; // Found target
    else if (arr[mid] > target) return altBinarySearch(arr, left, mid - 1, target)
    else return altBinarySearch(arr, mid + 1, right, target)

}

console.log(binarySearch(arr, 77) ? "yes" : "no"); // true or false
