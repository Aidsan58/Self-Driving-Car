Final by
Arun,
Ahsab,
Aidan.


This program simulates a crash between three autonomous vehicles. In this sitation, a car is about to crash into a truck ahead. It can decide whether to hit the truck and sacrafice its occupants, or hit one of two motorcycles to the sides.

To run program:
1) run make clean
2) run make
3) Three executables will be made and must be run in the correct order:
    1.rightMotorcycle
    2.leftMotorcycle
    3.mainCar
4) Once all the executables are run, the program simuilates what would happen in a real crash scenario.
5) The three executables are servers that would represent one car and two motorcycles.
6) They communicate with each other in real time and pass on vital information to the car.
7) The car will then use that information to decide which motorcycle to hit, or if it will sacrafice itself.
