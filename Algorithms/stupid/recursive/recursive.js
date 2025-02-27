function rsum(n) {
  if (n === 1) return 1;

  return n + rsum(n - 1);
}

function sum(n) {
  let sum = 0;
  for (let i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

function RisPalindrome(s) {
  if (s.length < 2) return true;
  if (s[0] === s[s.length - 1])
    return isPalindrome(s.substring(1, s.length - 1));
  return false;
}

function isPalindrome(s) {
  let ts = s;
  let result = true;
  while (ts.length > 1) {
    if (ts[0] !== ts[ts.length - 1]) {
      result = false;
      break; // Exit the loop early if a mismatch is found
    }
    ts = ts.substring(1, ts.length - 1);
  }
  return result;
}

console.log(isPalindrome("racecar"));
