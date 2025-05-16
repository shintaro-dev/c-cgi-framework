CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = src/framework.c src/http_request.c src/http_response.c examples/hello.c
OBJS = $(SRCS:.c=.o)

TARGET = hello.cgi

# デプロイ先ディレクトリ
PUBLIC_HTML = ~/public_html
CGI_BIN = $(PUBLIC_HTML)/cgi-bin
EXAMPLES_HTML = $(PUBLIC_HTML)/examples

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

deploy: $(TARGET)
	# CGIデプロイ
	cp $(TARGET) $(CGI_BIN)/

	# フレームワーク共通HTMLデプロイ
	@if ls public/base/*.html 1> /dev/null 2>&1; then \
		cp public/base/*.html $(PUBLIC_HTML)/; \
	fi

	# examples用HTMLデプロイ
	@if ls public/examples/*.html 1> /dev/null 2>&1; then \
		mkdir -p $(EXAMPLES_HTML); \
		cp public/examples/*.html $(EXAMPLES_HTML)/; \
	fi

clean:
	rm -f $(OBJS) $(TARGET)