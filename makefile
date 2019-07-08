.PHONY: all clean

build/list.o: src/list.c src/list.h
	gcc -c src/list.c -o build/list.o

build/dlist.o: src/dlist.c src/dlist.h
	gcc -c src/dlist.c -o build/dlist.o

lib/libvessels.a: build/dlist.o build/list.o
	ar rcs lib/libvessels.a build/dlist.o

app/list_demos: main/list_demos.c lib/libvessels.a
	gcc -iquote src -Llib -lvessels main/list_demos.c -o app/list_demos

all: app/list_demos


clean:
	-rm app/*
	-rm build/*
	-rm lib/*
	@echo "all clean"
