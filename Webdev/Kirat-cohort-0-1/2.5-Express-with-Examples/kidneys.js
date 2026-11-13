// new code- hospital having a kidney shop
// const user = {
//     name: "Hello",
//     kidneys: {
//       healthy: false,
//     },
// }
// const users = [user];

const express = require("express");
const app = express();
const users = [
  {
    name: "John",
    kidneys: [
      {
        healthy: false,
      },
    ],
  },
];

app.use(express.json());

// getting all the data
app.get("/", function (req, res) {
  const johnKidney = users[0].kidneys;
  const noOfKidneys = johnKidney.length;
  let noOfHealthyKidneys = 0;
  for (let i = 0; i < johnKidney.length; i++) {
    if (johnKidney[i].healthy) {
      noOfHealthyKidneys = noOfHealthyKidneys + 1;
    }
  }
  const noOfUnhealthyKidneys = noOfKidneys - noOfHealthyKidneys;
  // const newArray = users.filter(function () {
  //   return users[0].kidneys.length;
  // });
  res.json({
    noOfKidneys,
    noOfHealthyKidneys,
    noOfUnhealthyKidneys,
  });
});

// updating the healthy status
app.post("/", function (req, res) {
  const isHealthy = req.body.isHealthy;
  users[0].kidneys.push({
    healthy: isHealthy,
  });
  res.json({
    msg: "Done!",
  });
});

// replacing all the kidneys
app.put("/", function (req, res) {
  for (let i = 0; i < users[0].kidneys.length; i++) {
    users[0].kidneys[i].healthy = true; // if some kidneys were unhealthy then it became healthy(replaced) and if it were already healthy it didn't change
  }
  res.json({});
});

// removing all the nUnhealthyKidneys
app.delete("/", function (req, res) {
  if (isThereAtleastOneUnhealthyKidney()) {
    const newKidneys = [];
    // only if atleast one kidney is there to do this or else send 411
    for (let i = 0; i < users[0].kidneys.length; i++) {
      if (users[0].kidneys[i].healthy) {
        newKidneys.push({
          healthy: true,
        });
      }
    }
    users[0].kidneys = newKidneys;
    res.json({ msg: "done" });
  } else {
    res.status(411).json({ message: "You have no bad kidneys" });
  }
});

function isThereAtleastOneUnhealthyKidney() {
  let atleastOneUnhealthyKidney = false;
  for (let i = 0; i < users[0].kidneys.length; i++) {
    if (!users[0].kidneys[i].healthy) {
      atleastOneUnhealthyKidney = true;
    }
  }
  return atleastOneUnhealthyKidney;
}

app.listen(3000, function () {
  console.log("listening on port 3000");
});

// const express = require("express");
// const app = express();

// const users = [
//   {
//     name: "John",
//     kidneys: [
//       {
//         healthy: false,
//       },
//     ],
//   },
// ];

// app.use(express.json());

// app.get("/", function (req, res) {
//   const johnKidneys = users[0].kidneys;
//   const numberOfKidneys = johnKidneys.length;
//   let numberOfHealthyKidneys = 0;
//   for (let i = 0; i < johnKidneys.length; i++) {
//     if (johnKidneys[i].healthy) {
//       numberOfHealthyKidneys = numberOfHealthyKidneys + 1;
//     }
//   }
//   const numberOfUnhealthyKidneys = numberOfKidneys - numberOfHealthyKidneys;
//   res.json({
//     numberOfKidneys,
//     numberOfHealthyKidneys,
//     numberOfUnhealthyKidneys,
//   });
// });

// app.post("/", function (req, res) {
//   const isHealthy = req.body.isHealthy;
//   users[0].kidneys.push({
//     healthy: isHealthy,
//   });
//   res.json({
//     msg: "Done!",
//   });
// });

// // 411
// app.put("/", function (req, res) {
//   for (let i = 0; i < users[0].kidneys.length; i++) {
//     users[0].kidneys[i].healthy = true;
//   }
//   res.json({});
// });

// // removing all the unhealhty kidneys
// app.delete("/", function (req, res) {
//   if (isThereAtleastOneUnhealthyKidney()) {
//     const newKidneys = [];
//     for (let i = 0; i < users[0].kidneys.length; i++) {
//       if (users[0].kidneys[i].healthy) {
//         newKidneys.push({
//           healthy: true,
//         });
//       }
//     }
//     users[0].kidneys = newKidneys;
//     res.json({ msg: "done" });
//   } else {
//     res.status(411).json({
//       msg: "You have no bad kidneys",
//     });
//   }
// });

// function isThereAtleastOneUnhealthyKidney() {
//   let atleastOneUnhealthyKidney = false;
//   for (let i = 0; i < users[0].kidneys.length; i++) {
//     if (!users[0].kidneys[i].healthy) {
//       atleastOneUnhealthyKidney = true;
//     }
//   }
//   return atleastOneUnhealthyKidney;
// }
// app.listen(3000);
