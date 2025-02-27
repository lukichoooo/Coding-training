class Node {
  #data;
  #next = null;

  constructor(data) {
    this.#data = data;
  }

  getData() {
    return this.#data;
  }

  getNext() {
    return this.#next;
  }

  setNext(node) {
    this.#next = node;
  }

  toString() {
    if (this.#next === null) {
      return this.#data;
    }
    return this.#data + " -> " + this.#next.getData();
  }
}

class LinkedList {
  #size = 0;
  #head = null;
  #tail = null;

  constructor() {}

  getSize() {
    return this.#size;
  }

  isEmpty() {
    return this.#size === 0;
  }

  enqueue(data) {
    const newNode = new Node(data);
    if (this.isEmpty()) {
      this.#head = this.#tail = newNode;
    } else {
      this.#tail.setNext(newNode); // Connect current tail to new node
      this.#tail = newNode; // Move tail to new node
    }
    this.#size++;
  }

  dequeue() {
    if (this.isEmpty()) return null;
    let result = this.#head.getData();
    this.#head = this.#head.getNext();
    this.#size--;

    if (this.#head === null) this.#tail = null;

    return result;
  }

  printList() {
    let current = this.#head;
    for (let i = 0; i < this.#size; i++) {
      console.log(i + " " + current.toString());
      current = current.getNext();
    }
    console.log("");
  }



  // extra methods

  remove(index){
    if(index === 0) return this.dequeue();
    else if (index >= this.#size) return console.log(index + " index is of bounds");
    else{
      let current = this.#head;
      for (let i = 0; i < index - 1; i++){  // current goes to current - 1
        current = current.getNext();
      }
      current.setNext(current.getNext().getNext());
      this.#size--;
    }
  }
  
}

const queue = new LinkedList();

queue.enqueue("apple");
queue.enqueue("orange");
queue.enqueue("dog");
queue.enqueue("cool huy");
queue.enqueue("bear");
queue.enqueue("cat");

queue.printList();


queue.dequeue();

queue.printList();

queue.remove(3);

queue.printList();

