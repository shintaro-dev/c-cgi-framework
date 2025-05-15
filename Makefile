CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = src/framework.c src/http_request.c src/http_response.c examples/hello.c
OBJS = $(SRCS:.c=.o)

TARGET = hello.cgi

PUBLIC_HTML = ~/public_html
CGI_BIN = $(PUBLIC_HTML)/cgi-bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

deploy: $(TARGET)
	# CGIファイルをcgi-binへ
	cp $(TARGET) $(CGI_BIN)/
	# 静的HTMLをpublic_htmlへ
	cp public/*.html $(PUBLIC_HTML)/

clean:
	rm -f $(OBJS) $(TARGET)
