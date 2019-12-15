all : kvs

static_kvs : put.o get.o open.o close.o test_static.o
	gcc -o static_kvs put.c get.c open.c close.c test_static.c

static : test_static.o put.o get.o open.o close.o
	gcc -c put.c get.c open.c close.c
	ar rcs static.a put.o get.o open.o close.o
	gcc -c test_static.c
	gcc -static -o test_static test_static.o ./static.a

clean:
	rm -f *.o KVSall: KVSall:KVS
