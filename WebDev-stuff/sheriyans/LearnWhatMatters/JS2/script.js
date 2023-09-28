function abcd() {
		for(var i = 0; i < 12; i++){
				console.log(i); // this as well as the following 
		}
		console.log(i); // i here also prints so no errors

		for(let j = 0; j < 12; j++){
				console.log(j); // but only j here will run and
		}
		// console.log(j); // and if we use j here we'll get error like this "j not defined"
}

abcd();

var a = 12; // this gets added to the window object but the following b doesn't
let b = 12;
