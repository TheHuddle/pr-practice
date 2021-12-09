all: hello_world

hello_world: main.c emulator.c
	gcc -Wall $^ -o hello_world

clean:
	rm hello_world

run: hello_world
	./hello_world
