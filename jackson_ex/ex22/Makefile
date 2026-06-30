CFLAGS = -Wall -g
TARGET = ex22

all: $(TARGET)

$(TARGET): ex22_main.c ex22.o
	clang $(CFLAGS) ex22_main.c ex22.o -o $(TARGET)

ex22.o: ex22.c ex22.h
	clang $(CFLAGS) -c ex22.c -o ex22.o

clean:
	rm -f *.o $(TARGET)
