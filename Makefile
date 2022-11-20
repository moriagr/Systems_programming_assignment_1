REC_OBJECTS=advancedClassificationRecursion.c BasicClassification.c
LOOP_OBJECTS=advancedClassificationLoop.c BasicClassification.c
MAIN_OBJECTS=main.c NumClass.h
AR=ar
CC=gcc
FLAGS= -Wall -g
.PHONY: clean all

loops:	libclassloops.a

recursives:	libclassrec.a

recursived:	libclassrec.so

loopd:	libclassloops.so

libclassloops.a:	advancedClassificationLoop.o BasicClassification.o
	$(AR) -rcs libclassloops.a advancedClassificationLoop.o BasicClassification.o

libclassrec.a:	advancedClassificationRecursion.o BasicClassification.o
	$(AR) -rcs libclassrec.a advancedClassificationRecursion.o BasicClassification.o

libclassrec.so:	$(REC_OBJECTS)
		$(CC) -shared -o libclassrec.so $(REC_OBJECTS)

libclassloops.so:	$(LOOP_OBJECTS)
		$(CC) -shared -o libclassloops.so $(LOOP_OBJECTS)

mains:	main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

maindloop:	main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec:	main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

advancedClassificationLoop.o:	advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o:	advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c

BasicClassification.o:	BasicClassification.c NumClass.h
	$(CC) $(FLAGS) -c BasicClassification.c

all:	libclassloops.a libclassloops.so libclassrec.a libclassrec.so mains maindloop maindrec

clean:
	rm -f *.o *.a *.so *.gch mains maindloop maindrec

