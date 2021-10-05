Basecase:
F(-1) = 0;

Step:
F(i) = F(i-1)+4

Solution in closed form:
Testing for i = 3

F(3) = F(2) + 4 			= 16
F(2) = F(1) + 4 		= 12
F(1) = F(0) + 4 	= 8
F(0) = F(-1) + 4 = 4    (Basecase)
From this we can see that the complexity is 4i.

Worst case:
F(n) = 4n

This results in a worst case complexity of:
O(n)