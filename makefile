.PHONY: all clean

.SECONDEXPANSION:
build/%.o: src/$$*.c src/$$*.h
	gcc -Isrc -c src/$*.c -o build/$*.o

lib/libvessels.a: build/dlist.o build/list.o build/clist.o build/frames.o build/page.o
	ar rcs lib/libvessels.a build/*.o

app/list_demos: main/list_demos.c lib/libvessels.a
	gcc -iquote src -Llib -lvessels main/list_demos.c -o app/list_demos

all: app/list_demos


clean:
	-rm app/*
	-rm build/*
	-rm lib/*
	@echo "all clean"
