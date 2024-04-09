function filtersUser(user) {
    return user.filter(function (x) { return x.age >= 18; });
}
console.log(filtersUser([
    {
        firstName: 'first',
        lastName: 'first',
        age: 1,
    },
    {
        firstName: 'second',
        lastName: 'second',
        age: 18,
    },
]));
