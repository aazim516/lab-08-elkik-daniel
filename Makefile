main: main.o imagehelpers.o funcs.o
	g++ -o main main.o imagehelpers.o funcs.o

main.o: main.cpp funcs.h imagehelpers.h

funcs.o: funcs.cpp funcs.h imagehelpers.h

imagehelpers.o: imagehelpers.cpp imagehelpers.h

clean:
	rm -f main.o funcs.o imagehelpers.o
