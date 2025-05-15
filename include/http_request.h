#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#define CCGI_MAX_PARAMS 100

typedef struct {
    char *key;
    char *value;
} cgi_param;

typedef struct {
    cgi_param params[CCGI_MAX_PARAMS];
    int param_count;
} cgi_request;

void cgi_req_parse(cgi_request *req);
const char *cgi_req_get_param(const cgi_request *req, const char *key);
void cgi_req_cleanup(cgi_request *req);

#endif
