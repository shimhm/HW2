all : kvs

_static : test_static.o put.o get.o open.o close.o
	gcc -c put.c get.c open.c close.c
	ar rcs static.a put.o get.o open.o close.o
	gcc -c test_static.c
	gcc -static -o test_static test_static.o ./static.a

_dll : test_dll.o put.o get.o open.o close.o
	gcc -c -fPIC put.c get.c open.c close.c
	gcc -shared -fPIC -o dll.so put.o get.o open.o close.o
	gcc -o test_dll test_dll.c -ldl


clean:
	rm -f *.o KVSall: KVSall:KVS
