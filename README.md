# Mandelbrot_QT

An interactive C++ project which displays the Multibrot-sets and their corrseponding Julia-sets. 
Tested and developed on Windows 10 64-bit version. 
![Image not available](https://github.com/maxulfves/Mandelbrot_QT/blob/main/Teasers/Mandelbrot_And_Julia.PNG)

## Dependencies:
- https://download.qt.io/official_releases/online_installers/

## How to use: 
- Use the slider to select the exponent of the multibrot set. (2 = Mandelbrot) The range is [0, 10.0]
- Select the starting value of the Julia-set by clicking on a point in the multibrot set. The Julia set is updated when the mousebutton is released. 

## How to build:
- Download the QT Creator and open the .pro file in the repository. It shouldn't be more complicated than that. 

## How to run: 
- Press the run button in the QT Creator

## Tips:
- Points close to the edge of the Multibrot-sets gives the best looking Julia-sets. 
- The Julia-sets don't look that estetic when the Mulibrot-set has a non-integer exponent. 

## Bugs & left to fix:
- Sometimes a race condition occurs when changing the exponent or starting value. Should be examined. 
- Make the task bar more useful. 
- Perhaps the window should be scaleable. Might be too much work for a demo. Should be examined. 
- Test the functionallity on another setup.
- Add zoom-functionality for the Mandelbrot set. Might too heavy for a normal CPU to handle as the scaling factor increases, in which case it should be pre-rendered. 

![Image not available](https://github.com/maxulfves/Mandelbrot_QT/blob/main/Teasers/Multibrot.PNG)
