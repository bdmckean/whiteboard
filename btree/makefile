# Makes cache simulator 
#Compiler
CC=gcc
#Compiler Flags
CC_FLAGS -std=c99 -Wall  -g 

all: btree_test 

btree_test: btree_test.c btree.c
	$(CC) $(CC_FLAGS) btree_test.c btree.c

clean:
	rm *.o cache_sim



