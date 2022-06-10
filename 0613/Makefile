all: test-minus-c test-float-c test-byteorder-c test-double-c test-same-c homework

test-minus-c:
	gcc -o test-minus test-minus.c
	./test-minus

test-float-c:
	gcc -o test-float test-float.c
	./test-float

test-byteorder-c:
	gcc -o test-byteorder test-byteorder.c
	./test-byteorder

test-double-c:
	gcc -o test-double test-double.c -lm
	./test-double

test-same-c:
	gcc -o test-same test-same.c
	./test-same

homework:
	python ./1system.py
	g++ -o integrate integrate.cpp `pkg-config gsl --cflags --libs`
	./integrate
