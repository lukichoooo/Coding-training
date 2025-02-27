class Item {
    constructor(name, value, weight, quantity) {
        this.name = name;
        this.value = value;
        this.weight = weight;
        this.quantity = quantity;
    }
    toString() {
        return " " + this.name;
    }

    getPerformance() {
        return this.value / this.weight;
    }
}

class Bag {
    constructor(capacity) {
        this.capacity = capacity;
        this.bag = [];
    }

    addItem(item) {
        if (this.getTotalWeight() + item.weight <= this.capacity) {
            this.bag.push(item);
        } else {
            console.log(`Cannot add ${item.name}, not enough capacity.`);
        }
    }

    getTotalWeight() {
        return this.bag.reduce((total, item) => total + item.weight, 0);
    }

    toString() {
        return this.bag.map(item => item.toString()).join(', ');
    }
}

const items = [
    new Item('Pen', 1.5, 0.02, 10),
    new Item('Bottle', 10, 0.5, 5),
    new Item('Notebook', 5, 0.3, 7),
    new Item('Laptop', 1000, 2.5, 2),
    new Item('Phone', 500, 0.2, 3),
    new Item('Headphones', 150, 0.3, 4),
    new Item('Charger', 25, 0.1, 6)
];

var arr = [];

// putting each values "worth" in an array
for (let i = 0; i < items.length; i++) {
    arr[i] = (items[i].value / items[i].weight);
}
// sorting the array depending on "worth"

console.log(items.toString());

quickSort(arr, 0, 6);

console.log(arr);


const bag = new Bag(5);

for (let i = 0; i < items.length; i++) {

}




// sorting function
function quickSort(arr, l, r) {
    if (l < r) {
        let j = partition(arr, l, r);
        quickSort(arr, j + 1, r);
        quickSort(arr, l, j - 1);
    }
}

function partition(arr, l, r) {
    let j = r, i = l, mid = Math.floor((l + r) / 2);

    [arr[r], arr[mid]] = [arr[mid], arr[r]];    // swap pivot with the last element in array

    while (i < j) {
        while (arr[i] > arr[r] && i < r)
            i++;
        while (arr[j] < arr[r] && j >= l)
            j--;
        if (i < j) {
            [arr[i], arr[j]] = [arr[j], arr[i]];
        }
    }

    [arr[j], arr[r]] = [arr[r], arr[j]];

    return j;
}
