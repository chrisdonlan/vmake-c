.PHONY: all clean


build/llst.o: src/llst.c src/llst.h
	gcc -c src/llst.c -o build/llst.o

lib/libvessels.a: build/llst.o
	ar rcs lib/libvessels.a build/llst.o



app/llst_demo: main/llst_demo.c lib/libvessels.a
	gcc -iquote src -Llib -lvessels main/llst_demo.c -o app/llst_demo

all: app/llst_demo

clean:
	-rm app/*
	-rm build/*
	-rm lib/*
	@echo "all clean"
