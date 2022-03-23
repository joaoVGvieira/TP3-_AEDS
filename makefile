all: 
	gcc Sources/arquivo.c Sources/QuickSort_lib.c main.c 
a:
	./a.out 5 10000 semente10.txt
b:
	./a.exe 1 100 semente1.txt