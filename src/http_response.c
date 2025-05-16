#include "http_response.h"
#include <stdio.h>

void cgi_res_init(cgi_response *res) {
    // 必須のレスポンスヘッダを出力
    printf("Content-Type: text/html\r\n\r\n");

    // デバッグ用のstderr出力（任意）
    fprintf(stderr, "Response initialized\n");
}

void cgi_res_send(const cgi_response *res) {
    // 実際のレスポンスボディ出力（仮）
    printf("<h1>Hello, World!</h1>\n");
}
