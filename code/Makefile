CFLAGS=-Wall -Wextra -Werror
EXIT=./objects/

all:store

store: store.o
	g++ $(CFLAGS) $(EXIT)online_store.o -o online_store

store.o:
	g++ $(CFLAGS) -c online_store.cpp -o $(EXIT)online_store.o

clean: 
	rm -rf $(EXIT)*.o online_store

rebuild:clean all