class string {
  constructor(a) {
    this.first = a;
  }
  fix() {
    let fixed = this.first.replace(/[ \t\r\n\f\v]+/g, "").trim();
    console.log(fixed);
  }
}

let p = new string("10 + 2 * ( 6 - (4 + 1) / 2) + 7");
p.fix();
