CFLAGS=-Wall -O2 -ansi

# Compile
fib: main_fib.o fib.o bmp.o timing.o
	$(CC) -o fib $?

# Run program
runall:
	./fib 7 10 10 10 100 100 fib7.bmp
	./fib 9 10 10 10 500 500 fib9.bmp
	./fib 25 10 10 10 10000 10000 fib25.bmp
	./fib 26 10 10 10 20000 20000 fib26.bmp

# Clean
clean:
	@rm -rf *.o *bmp
