interface Person {
  name: string;
  age?: number;
  greet(phrase: string): void;
}

class Employee implements Person {
  name: string;
  hello?: string;

  constructor(n: string, a: string) {
    this.name = n;
    this.hello = a;
  }

  greet(phrase: string) {
    console.log(`${phrase} ${this.name}`);
  }
}
