// clf; x = [1: 0.2: 2 * %pi]; y = sin(x); plot2d(x,y, leg="sin(x)");


// clf; x = [1: 0.2: 2 * %pi]; y = sin(x); plot2d(x,y);

// clf; x = [1: 0.2: 2 * %pi]; y = sin(x); plot2d(x,y,4, leg="sin(x)");

// clf; x = [0: 0.1: 2 * %pi]; plot(x, sin(x), style = 3); xtitle("A plot of sine curve"); xlabel("Angle(radians)"); ylabel("sin(x)");


clf; x = [0; 0.1; 2 * %pi]; 
y1 = sin(x);
 y2 = cos(x);
  plot(x, y1, 'r-', x, y2, 'b-');
   xtitle("A plot of sine and cosine curves", "Angle (radians)", "Value"); 
   legend("sin(x)", "cos(x)");
   xlabel("Angle (radians)"); ylabel("Value");
