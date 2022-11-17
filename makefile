OBJECTS = main.c advancedClassificationLoop.c advancedClassificationRecursion.c BasicClassification.c
prog1: $(OBJECTS)
	gcc -o -Wall prog1 $(OBJECTS)