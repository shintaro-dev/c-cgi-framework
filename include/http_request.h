#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

typedef struct {
    // クエリパラメータ、セッションID など
} cgi_request;

void cgi_req_parse(cgi_request *req);

#endif
