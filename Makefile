CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = src/framework.c src/http_request.c src/http_response.c src/template.c src/utils.c examples/hello.c
OBJS = $(SRCS:.c=.o)

TARGET = hello.cgi

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
