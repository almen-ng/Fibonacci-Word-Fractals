#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for integral constants of directions: up, down, left, and right */
typedef enum {
    up,
    down,
    left,
    right
} direction;

/* Pointer reference to character array storying fibonacci word */
char* fibonacci_word;
/* Index for concatenation */
int index_concatenation = 0;

/* Draw line function */
/* Takes in x-coordinate of position, y-coordiante of position, direction, step size, width of pixel, RGB pointer to image, RGB segment */
void draw(int x, int y, direction dir, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (dir == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (dir == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (dir == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (dir == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}

/* Calculation of the size of the fibonacci word using recurssion */
int calculation_of_size(int n){
  if (n == 1 || n == 2 ){
    return 1;
  }
  return calculation_of_size(n - 1) + calculation_of_size(n - 2);
}

/* Concatenate the fibonacci word in fibonacci_word using recurssion */
void concatenation(int n){
  if (n == 1){
    fibonacci_word[index_concatenation] = '1';
    index_concatenation++;
  }
  else if (n == 2){
    fibonacci_word[index_concatenation] = '0';
    index_concatenation++;
  }
  else{
    concatenation(n - 1);
    concatenation(n - 2);
  }
}

/* Main */
int fib(int n, int x, int y, int step, RGB bc, RGB fc, int w, int h, RGB * image){
  direction direction = up; /* Default direction is upwards */
  int index_fibonacci_word;
  int size_of_fibonacci_word;
  int index_pixel;
  int steps = 1;

  size_of_fibonacci_word = calculation_of_size(n);
  /* Allocating memory for the fibonacci word */
  fibonacci_word = malloc(sizeof(char)*(size_of_fibonacci_word) + 1);
  concatenation(n);

  /* If memory is unable to be allocated */
  if (!(fibonacci_word) || !(image)){
    return 0;
  }

  /* Set the background colour of the image */
  for (index_pixel = 0; index_pixel < w * h; index_pixel++){
    image[index_pixel] = bc;
  }

  
  for (index_fibonacci_word = 0; index_fibonacci_word < size_of_fibonacci_word; index_fibonacci_word++){
    /* If drawing would be out of bounds, return 0 */
    if ((x + step) < 0 || (x + step) > h || (y + step) < 0 || (y + step) > w){
      return 0;
    }

    /* Draw segment */
    draw (x, y, direction, step, w, image, fc);
    steps += 1;

    /* Updating the x and y coordinates */
    switch(direction){
      case up:
        x += step;
        break;
      case down:
        x -= step;
        break;
      case left:
        y -= step;
        break;
      case right:
        y += step;
        break;
    }

    /* If statement determining the direction of the next segment */
    if (fibonacci_word[index_fibonacci_word] == '0'){
      if ((index_fibonacci_word + 1) % 2 == 0){
        switch (direction){
          case up:
            direction = left;
            break;
          case down:
            direction = right;
            break;
          case left:
            direction = down;
            break;
          case right:
            direction = up;
            break;
        }
      }
      else if ((index_fibonacci_word + 1) % 2 != 0){
        switch (direction){
          case up:
            direction = right;
            break;
          case down:
            direction = left;
            break;
          case left:
            direction = up;
            break;
          case right:
            direction = down;
            break;
        }
      }
    }
  }
  return steps;
}
