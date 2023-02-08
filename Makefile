COMP = gcc -c -ansi
LINK = gcc

.PHONY: all clean

all: twitter

twitter: main.o\
		user.o\
		linkedList.o\
		hashTable.o\
		utils.o
	$(LINK) *.o -o twitter

main.o: main.c
	$(COMP) main.c

user.o: user.c
	$(COMP) user.c

linkedList.o: linkedList.c
	$(COMP) linkedList.c

hashTable.o: hashTable.c
	$(COMP) hashTable.c

utils.o: utils.c
	$(COMP) utils.c

clean:
	rm -rf *.o twitter