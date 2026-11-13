async function asyncCoroutine() {
  console.log("Starting coroutine");
  const result1 = await new Promise(resolve => setTimeout(() => resolve("First result"), 1000));
  console.log(result1);

  const result2 = await new Promise(resolve => setTimeout(() => resolve("Second result"), 1000));
  console.log(result2);

  return "Coroutine done";
}

// Run the coroutine
asyncCoroutine().then(result => console.log(result));

