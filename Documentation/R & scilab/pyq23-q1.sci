//graph for f(x) = x ^ 2n
clc
clear
clf
x=[-2:0.01:5]
y=(x.^2+2.*x).*exp(-x)
title("graph")
xlabel("x-axis")
ylabel("y-axis")
plot(x,y)
