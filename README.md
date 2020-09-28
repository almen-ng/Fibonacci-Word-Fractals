# Fibonacci-Word-Fractals

## Background Information

A Fibonacci word, similar to how Fibonacci numbers are formed by repeated addition, is the repeated concatenation of binary digits.

### Example

>F<sub>1</sub> = 0\
>F<sub>2</sub> = 1\
>F<sub>3</sub> = F<sub>2</sub>F<sub>1</sub> = 10\
>F<sub>4</sub> = F<sub>3</sub>F<sub>2</sub> = 101\
>F<sub>5</sub> = F<sub>4</sub>F<sub>3</sub> = 10110\
>.\
>.\
>.\
>F<sub>n</sub> = F<sub>n-1</sub>F<sub>n-2</sub>

## Purpose

Produces a .bmp image corresponding to the nth Fibonacci word.

## Algorithm

The program will take in an integer _n_ and iterate through each digit of the nth Fibonacci word, drawing the segment, then determining in which direction the next segment should be drawn; turning left 90 degrees if the digit is even and right if it is odd. The initial segment must be drawn upwards.

## Makefile Parameters

~~~
./fib n x y step w h image
~~~

where:

* _n_ - integer representing which Fibonacci word you want to draw
* _x_ - x-coordinate of the initial position
* _y_ - y-coordinate of the initial position
* _step_ - number of pixels for each segment
* _w_ - width of image in pixels
* _h_ - length of image in pixels
* _image_ - name of the outputed .bmp image

## How to Run the Program

To run the program, you would have to have gcc and make installed. 
To run the make file, follow these commands in terminal:
~~~
make
~~~
OR
~~~
make fib
make runall
make clean
~~~


## Sample Results
<p>n=7, x=10, y=10, step=10, w=100, h=100</p>
<table><tr><td>
    <img src="/images/fib7.png" />
</td></tr></table>

<p>n=9, x=10, y=10, step=10, w=500, h=500</p>
<table><tr><td>
    <img src="/images/fib9.png" />
</td></tr></table>

<p>n=25, x=10, y=10, step=10, w=10000, h=10000</p>
<table><tr><td>
    <img src="/images/fib25.png" />
</td></tr></table>

<p>n=26, x=10, y=10, step=10, w=20000, h=20000</p>
<table><tr><td>
    <img src="/images/fib26.png" />
</td></tr></table>
