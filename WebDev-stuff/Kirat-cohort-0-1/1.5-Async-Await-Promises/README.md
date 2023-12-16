# Offline lec 1.5

## Async functions vs Sync functions

| What does synchronous mean              | What does asynchronous mean                              |
| --------------------------------------- | -------------------------------------------------------- |
| Together, one after another, sequential | Opposite of synchronous                                  |
| Only one thing is happening at a time   | happens in parts, things are happening parallely somehow |
|                                         | Multiple things are context switching with each other    |

- Context switching
  - So JS is also single threaded but it can delegate tasks to other threads thereby doing more than one work at a time like we humans do
  - so like human brains which is single threaded we can only do one thing at a time, but while boiling water we can chop some veggies then again bring some potatoes and again start chopping, etc etc and as such we can do some context switching in our work, but at a time we can only do single work
  - Some other ways can be we can call another person to do the work, so while we chop the veg, the other person can go boil the water or bring something. So somehow our brain can context switch, and **the same is true for javascript it can context switch and delegate task to other threads**

## Synchronous vs Asynchronous task completion for the task of creating noodles

### Synchronous

waiting for every task one by one till it finishes

1. first boiling water and waiting till it boils - 5min
2. then opening maggi packet - 2min
3. then chopping vegetables - 10min
4. going to buy ketchup at shop - 20min
total time 22mins

- So in Synchronous 

### Asynchronous

not waiting for every task but context switching between tasks or parallelizing tasks

1. first boiling water and just turns on the gas and doesn't wait - 2s
2. tells other person to buy ketchup at shop
3. checking water again - 1s
4. then chopping vegetables - 8min
5. ketchup arrived and still cutting veggies - 2min extra = 10min
total time 12mins

- context switching between 1, 2, 3 tasks
