CC = clang
CFLAGS = -Wall -Wextra 


TARGET = ex25
SRCS = ex25.c

# Build executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -O3 -o $(TARGET) $(SRCS)

debug:
	$(CC) $(CFLAGS) -O0 -g -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
