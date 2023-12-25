let date = new Date();
let day = date.getDay();

let days = [
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
];

const element = days[day];
console.log("Today is: " + element);

// Time part
let hour = date.getHours();
let mins = date.getMinutes();
let secs = date.getSeconds();

// making the time output 12 hr with am/pm
let prepend = hour >= 12 ? " PM" : "AM";
hour = hour >= 12 ? hour - 12 : hour;

// edge cases when hour can be 0
if (hour === 0 && prepend === "PM") {
  if (mins === 0 && secs === 0) {
    hour = 12;
    prepend = "noon";
  } else {
    hour = 12;
    prepend = "PM";
  }
}
if (hour === 0 && prepend === "AM") {
  if (mins === 0 && secs === 0) {
    hour = 12;
    prepend = "midnight";
  } else {
    hour = 12;
    prepend = "AM";
  }
}

console.log(
  "Current time is : " + hour + prepend + "AM : " + mins + ": " + secs,
);
