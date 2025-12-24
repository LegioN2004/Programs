var cities = [];
var totalCities = 4;

function setup() {
    createCanvas(500, 400); // Creates a 400x300 pixel canvas
    for (let i = 0; i < totalCities; i++) {
        // createVector(x, y) is an object that holds x and y coordinates
        var v = createVector(random(width), random(height)); // Creates a vector with random x, y coordinates
        cities[i] = v; // Adds the vector to the cities array
    }
}

function draw() {
    background(0);
    fill(255);
    for (let i = 0; i < cities.length; i++) {
        ellipse(cities[i].x, cities[i].y, 8, 8); // Draws a circle at each city's coordinates
    }

    stroke(255);
    strokeWeight(2);
    noFill();
    // Draw lines connecting the cities
    beginShape();
    for (let i = 0; i < cities.length; i++) {
        vertex(cities[i].x, cities[i].y); // Draws a circle at each city's coordinates
    }
    endShape();
}
