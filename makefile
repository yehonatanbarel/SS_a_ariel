CC=gcc
AR=ar
FLAGS= -Wall
OBJECTS_LIB_BASIC_LOOP=basicClassification.o advancedClassificationLoop.o
OBJECTS_LIB_BASIC_REC= basicClassification.o advancedClassificationRecursion.o
OBJECTS_MAIN=main.o

# 8
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec


# 1
loops: libclassloops.a

# 2
recursives: libclassrec.a

# 3 
recursived: libclassrec.so
#
# 4
loopd: libclassloops.so

# 5	
mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a
# 6
maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so
# 7
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so
# 1
libclassloops.a: $(OBJECTS_LIB_BASIC_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LIB_BASIC_LOOP) 
# 2
libclassrec.a: $(OBJECTS_LIB_BASIC_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB_BASIC_REC)

# 3
libclassrec.so: $(OBJECTS_LIB_BASIC_REC) 
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_BASIC_REC)
#4
libclassloops.so: $(OBJECTS_LIB_BASIC_LOOP) 
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB_BASIC_LOOP)


basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm


main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
# 9
clean:
	rm -f *.o *.a *.so maindloop mains maindrec

.PHONY: clean all
