#include "../include/framework.h"
#include <stdio.h>

int business_logic(const cgi_request *req, cgi_response *res) {
    const char *username = cgi_req_get_param(req, "username");

    printf("Content-Type: text/html\r\n\r\n");
    printf("<html><body>\n");

    if (username) {
        printf("<h1>Hello, %s!</h1>\n", username);
    } else {
        printf("<h1>Hello, World!</h1>\n");
    }

    printf("</body></html>\n");

    return 0;
}
