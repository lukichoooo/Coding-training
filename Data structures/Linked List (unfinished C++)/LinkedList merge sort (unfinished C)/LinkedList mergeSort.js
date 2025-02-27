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

  peek() {
    if (this.isEmpty()) return null;
    return this.#head.getData();
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

  remove(index) {
    if (index === 0) return this.dequeue();
    else if (index >= this.#size)
      return console.log(index + " index is of bounds");
    else {
      let current = this.#head;
      for (let i = 0; i < index - 1; i++) {
        // current goes to current - 1
        current = current.getNext();
      }
      current.setNext(current.getNext().getNext());
      this.#size--;
    }
  }
}

const queue = new LinkedList();

queue.enqueue(25);
queue.enqueue(66);
queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(3);
queue.enqueue(300);
queue.enqueue(44);


queue.printList();

const sortedQueue = mergeSort(queue);

sortedQueue.printList();

function mergeSort(queue) {
  // devide a LinkedList untill its size == 1 merge and return it
  if (queue.getSize() <= 1) return queue;

  const leftQueue = new LinkedList(); // starts at 0 and ends at mid
  const rightQueue = new LinkedList(); // starts at mid and ends at size()
  let mid = queue.getSize() / 2;

  for (let i = 0; i < mid; i++) {
    leftQueue.enqueue(queue.dequeue());
  }
  while (!queue.isEmpty()) {
    rightQueue.enqueue(queue.dequeue());
  }

  return merge(mergeSort(leftQueue), mergeSort(rightQueue));
}

function merge(leftQueue, rightQueue) {
  // combine left and right halfs of a LinkedList while sorting it and return it
  const queue1 = new LinkedList();

  while (!leftQueue.isEmpty() && !rightQueue.isEmpty()) {
    if (leftQueue.peek() < rightQueue.peek())
      queue1.enqueue(leftQueue.dequeue());
    else queue1.enqueue(rightQueue.dequeue());
  }
  while (!leftQueue.isEmpty()) queue1.enqueue(leftQueue.dequeue());
  while (!rightQueue.isEmpty()) queue1.enqueue(rightQueue.dequeue());
  return queue1;
}
