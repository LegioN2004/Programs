function Callback(fn:any) {
	setTimeout(fn, 1000);
}

Callback(function () {
	console.log('ran after 1 second');
});
