// execution context matlab jab bhi hum fn chalayenge, then wo fnc apna ek khudka imaginary container bana lega jisme uski paas teen cheeze honge and they are as follows:
// 1. variables
// 2. functions inside  that parent function
// 3. lexical environment of that function
// ye jo container hai imaginary ise hi execution context kehte hai

function abcd() {
  var a = 12;
  function def() {
    var b = 13;
  }
}
