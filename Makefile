exec = paradox.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./paradox.out /usr/local/bin/paradox

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o