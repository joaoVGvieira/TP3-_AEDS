all: 
	gcc Sources/arquivo.c Sources/QuickSort_lib.c main.c 
a:
	./a.out 5 1000000 QuickSort_saida_semente5.txt
b:
	./a.exe 1 100 semente1.txt