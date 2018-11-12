#file: makefile
a.out: mission1.o mission2.o mission3.o mission4.o mission5.o mission6.o main.o
	gcc mission1.o mission2.o mission3.o mission4.o mission5.o mission6.o main.o

main.o: main.c mission1.h mission2.h mission3.h mission4.h mission5.h mission6.h
	gcc -c main.c

mission1.o: mission1.c mission1.h
	gcc -c mission1.c

mission2.o: mission2.c mission2.h
	gcc -c mission2.c

mission3.o: mission3.c mission3.h
	gcc -c mission3.c

mission4.o: mission4.c mission4.h
	gcc -c mission4.c

mission5.o: mission5.c mission5.h
	gcc -c mission5.c

mission6.o: mission6.c mission6.h
	gcc -c mission6.c