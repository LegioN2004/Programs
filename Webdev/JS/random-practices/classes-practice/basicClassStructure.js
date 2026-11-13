class hello {
  constructor(a, b, c) {
    this.first = a;
    this.second = b;
    this.third = c;
  }
  hi(a) {
    if (a == 2) {
      console.log(`ananda is a goru ${a}`);
    } else {
      console.log("ananda is stil a grou");
    }
  }
}

let dog = new hello("doggie", 4, "bhow"); // this is how we create an object
dog.hi(2);
