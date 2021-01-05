# Mandelbrot_QT

An interactive C++ project which displays the Multibrot-sets and their corrseponding Julia-sets. 
Tested and developed on Windows 10 64-bit version. 


## Dependencies:
- https://download.qt.io/official_releases/online_installers/

## How to use: 

- Use the slider to select the exponent in the equation 
Z_n+1 = Z_n ^ x + c
- Select the starting value of the Julia-set by clicking on a point in the mandelbrot set. The Julia set is updated when the mousebutton is released.

## How to build:
- Left as an excercise to the reader. (I don't know =/ )

## Bugs & left to fix:
- Correctly sync the point on the MB-set with the corresponding Julia-set. Right now it seems like it's shifted towards the center. 
- Sometimes a race condition occurs when changing the exponent or starting value. Should be examined. 
- Make the task bar more useful. 
- Perhaps the window should be scaleable. Might not be too much work for only a demo. Should be examined. 
- Test the functionallity on another setup.
