ARCH = $(shell uname -m)

ifeq ($(ARCH), x86_64)
TARGETS = hello_x86-64
else ifeq (arm, $(findstring arm,$(ARCH)))
TARGETS = hello_arm
else
$(error Unsupported architecture "$(ARCH)")
endif


all: $(TARGETS)

hello_arm: hello_arm.s
	gcc $^ -o $@

hello_x86-64: hello_x86-64.s
	nasm -f elf64 -o hello_x86-64.o hello_x86-64.s
	ld -o hello_x86-64  hello_x86-64.o

clean:
	-rm -f hello_arm hello_x86-64 *.o

.PHONY: all clean
