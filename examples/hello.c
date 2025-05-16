#include "../include/framework.h"
#include <stdio.h>

int business_logic(const cgi_request *req, cgi_response *res) {
    const char *username = cgi_req_get_param(req, "username");

    // 本文の出力だけ行う（ヘッダはフレームワーク側で出力済み）
    printf("<html><body>\n");

    if (username) {
        printf("<h1>Hello, %s!</h1>\n", username);
    } else {
        printf("<h1>Hello, World!</h1>\n");
    }

    printf("</body></html>\n");

    return 0;
}
