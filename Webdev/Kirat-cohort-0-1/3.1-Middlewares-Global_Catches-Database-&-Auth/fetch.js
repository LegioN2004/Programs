async function getAnimalData() {
  // alert("helooo, this button is being triggered"); // alert lets us get native alerts in the browser
  // console.log(
  //   fetch("https://fakerapi.it/api/v1/persons").then(function (response) {
  //     // this response.json also returns a promise so we need to use .then
  //     response.json().then(function (finalData) {
  //       console.log(finalData);
  //     });
  //   }),
  // );
  const response1 = await fetch("https://fakerapi.it/api/v1/persons");
  const response2 = await response1.json();
  console.log(response2);
}
