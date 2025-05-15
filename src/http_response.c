#include "http_response.h"
#include <stdio.h>

void cgi_res_init(cgi_response *res) {
    fprintf(stderr, "Response initialized (dummy)\n");
}

void cgi_res_send(const cgi_response *res) {
    printf("Content-Type: text/html\r\n\r\n");
    printf("<h1>Hello, World!</h1>\n");
}
