all: 
	gcc Sources/arquivo.c Sources/QuickSort_lib.c main.c 
a:
	./a.out 2 1000000 semente1.txt
b:
	./a.exe 1 100 semente1.txt