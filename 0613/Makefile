all: test-minus-c test-float-c test-byteorder-c test-double-c test-same-c test-gmp-c test-gmp-cpp homework

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

test-gmp-c:
	gcc -o test-gmp1 test-gmp.c -lgmp
	./test-gmp1

test-gmp-cpp:
	g++ -o test-gmp2 test-gmp.cpp -lgmpxx -lgmp
	./test-gmp2

homework:
	gcc -o test-minus-16 test-minus-16.c
	./test-minus-16
	gcc -o test-float-2625 test-float-2625.c
	./test-float-2625
	gcc -o test-byteorder-csi test-byteorder-csi.c
	./test-byteorder-csi
	gcc -o test-qe test-qe.c -lm
	./test-qe
	python ./1system.py
	g++ -o integrate integrate.cpp `pkg-config gsl --cflags --libs`
	./integrate
