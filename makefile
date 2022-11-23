REC_OBJECTS=advancedClassificationRecursion.o basicClassification.o
LOOP_OBJECTS=advancedClassificationLoop.o basicClassification.o
MAIN_OBJECTS=main.c NumClass.h
AR=ar
CC=gcc
FLAGS= -Wall -g

all:	loops mains maindloop maindrec

loops:	libclassloops.a

recursives:	libclassrec.a

recursived:	libclassrec.so

loopd:	libclassloops.so

libclassloops.a:	$(LOOP_OBJECTS)
	$(AR) -rcs libclassloops.a $(LOOP_OBJECTS)

libclassrec.a:	$(REC_OBJECTS)
	$(AR) -rcs libclassrec.a $(REC_OBJECTS)

libclassrec.so:	$(REC_OBJECTS)
		$(CC) -shared -o libclassrec.so $(REC_OBJECTS)

libclassloops.so:	$(LOOP_OBJECTS)
		$(CC) -shared -o libclassloops.so $(LOOP_OBJECTS)

mains:	main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop:	main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so

maindrec:	main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

advancedClassificationLoop.o:	advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o:	advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c

BasicClassification.o:	basicClassification.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c basicClassification.c

.PHONY: clean all loops recursives recursived loopd

clean:
	rm -f *.o *.a *.so *.gch mains maindloop maindrec

