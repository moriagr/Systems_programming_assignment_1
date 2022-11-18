#prog1: $(OBJECTS)
#	gcc -o -Wall prog1 $(OBJECTS)
REC_OBJECTS=advancedClassificationRecursion.c BasicClassification.c
LOOP_OBJECTS=advancedClassificationLoop.c BasicClassification.c
MAIN_OBJECTS=main.c NumClass.h
#LIB_OBJECTS=NumClass.h
AR=ar
CC=gcc
FLAGS= -Wall -g
.PHONY: clean all

loops:	$(LOOP_OBJECTS)
	$(AR) -rcs libclassloops.a $(LOOP_OBJECTS)

recursives:	$(REC_OBJECTS)
	$(AR) -rcs libclassrec.a $(REC_OBJECTS)

recursived:	$(REC_OBJECTS)
	$(CC) -shared -o libclassrec.so $(REC_OBJECTS)

loopd:	$(LOOP_OBJECTS)
	$(CC) -shared -o libclassloops.so $(LOOP_OBJECTS)

libclassloops.a:	$(LOOP_OBJECTS)
	$(AR) -rcs libclassloops.a $(LOOP_OBJECTS)

libclassrec.a:	$(REC_OBJECTS)
	$(AR) -rcs libclassrec.a $(REC_OBJECTS)

libclassloops.so:	$(LOOP_OBJECTS)
		$(CC) -shared -o libclassloops.so $(LOOP_OBJECTS)

libclassrec.so:	$(REC_OBJECTS)
		$(CC) -shared -o libclassrec.so $(REC_OBJECTS)

mains:	$(MAIN_OBJECTS) libclassrec.a
	$(CC) $(FLAGS) -o mains $(MAIN_OBJECTS) libclassrec.a

maindloop:	$(MAIN_OBJECTS)
	$(CC) $(FLAGS) -o maindloop $(MAIN_OBJECTS) ./libclassloops.so

maindrec:	$(MAIN_OBJECTS)
	$(CC) $(FLAGS) -o maindrec $(MAIN_OBJECTS) ./libclassrec.so

all:	libclassloops.a libclassloops.so libclassrec.a libclassrec.so mains maindloop maindrec

clean:
	rm -f *.o *.a *.so *.gch *DSYM mains maindloop maindrec

