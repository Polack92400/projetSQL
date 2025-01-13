CC=gcc

CFLAGS= -Wall -Werror -g

DIR=src/

TARGET=program

SRCS=src/main.c

OBJS=$(SRCS:.c=.o)

TODELETE=$(DIR)*.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) $(TODELETE) 
