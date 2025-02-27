function logn(n) {
    let i = 0;
    while (n > 1) {
        i++;
        n /= 2;
    }
    return i;
}

console.log("log(16) = " + logn(16));