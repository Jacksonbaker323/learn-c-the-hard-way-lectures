CC = clang
CFLAGS = -Wall -Wextra $(shell pkg-config --cflags glib-2.0)
LDLIBS = $(shell pkg-config --libs glib-2.0)

TARGET = ex25
SRCS = ex25.c

# Build executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDLIBS)

clean:
	rm -f $(TARGET)
