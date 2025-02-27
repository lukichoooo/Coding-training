
var arr = Array.from({length: 100}, () => Math.floor(Math.random() * 200) - 100);

var minP = 2147483648;
var maxN = -2147483648;

for (var i = 0; i < arr.length; i++) {
    if(arr[i] >= 0){
        if(arr[i] < minP){
            minP = arr[i];
        }
    } else {
        if(arr[i] > maxN){
            maxN = arr[i];
        }
    }
}

console.log("minP: " + minP + " maxN: " + maxN);
