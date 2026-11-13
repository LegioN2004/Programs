function isLegal(a: number): boolean {
	if (a >= 18) {
		return true;
	} else {
		return false;
	}
}

console.log(isLegal(20));
console.log(isLegal(10));
