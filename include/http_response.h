#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

typedef struct {
    // ヘッダ、ボディ、テンプレ埋め込み用変数 など
} cgi_response;

void cgi_res_init(cgi_response *res);
void cgi_res_send(const cgi_response *res);

#endif
