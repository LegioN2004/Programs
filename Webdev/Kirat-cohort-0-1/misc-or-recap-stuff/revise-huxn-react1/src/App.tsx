
function App() {
  const userObject = [
    {
      name: "milinda",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "tera baap",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "tera maaa",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "tera chacha",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "tera lund",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "milinda",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "milinda",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
    {
      name: "milinda",
      country: "india",
      address: "nothing",
      phoneNumber: 1983790,
    },
  ];

  return (
    <>
      <div>Hello</div>
      <div>
        {userObject.map(({name, address, country}) => {
          return (
            <>
            <div key={Math.random()}>
              <h1>{name}</h1>
              <h2>{country}</h2>
              <p>{address}</p>
            </div>
            </>
          )
        })}
      </div>
    </>
  );
}

export default App;
