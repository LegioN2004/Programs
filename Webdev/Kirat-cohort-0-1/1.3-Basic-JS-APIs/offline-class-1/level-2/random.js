function calculateSum() {
  let a = 0;
  for (let i = 0; i < 100000; i++) {
    a = a + i;
  }
  return a;
}

const beforeTime = new Date();
const beforeTimeinMs = beforeTime.getTime();

calculateSum();

const afterTime = new Date();
const afterTimeinMs = afterTime.getTime();

console.log(afterTimeinMs - beforeTimeinMs);

// sasta ghadi
function currentTime() {
  console.clear(); // to clear the tty output everytime
  console.log(
    new Date().getHours() +
      ":" +
      new Date().getMinutes() +
      ":" +
      new Date().getSeconds(),
  );
}
// setInterval(currentTime, 1000)
setInterval(currentTime, 1000);
