f:
	gcc cmdls.c -o cmdls.o
	gcc cmdmkdir.c -o cmdmkdir.o
	gcc cmdrm.c -o cmdrm.o
	gcc cmddate.c -o cmddate.o
	gcc cmdcat.c -o cmdcat.o
	gcc assignment.c -o string.o
	./string.o


t:
	gcc cmdls.c -o cmdls.o
	gcc cmdmkdir.c -o cmdmkdir.o
	gcc cmdrm.c -o cmdrm.o
	gcc cmddate.c -o cmddate.o
	gcc cmdcat.c -o cmdcat.o
	gcc main.c -o main.o -pthread
	./main.o

clean :
	rm -rf string.o
	rm -rf cmdls.o
	rm -rf cmdmkdir.o
	rm -rf cmdrm.o
	rm -rf cmddate.o
	rm -rf cmdcat.o
	rm -rf main.o

	