#include "http_request.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char *url_decode(const char *src) {
    char *dest = malloc(strlen(src) + 1);
    char *d = dest;
    while (*src) {
        if (*src == '%') {
            if (isxdigit(src[1]) && isxdigit(src[2])) {
                char hex[3] = { src[1], src[2], '\0' };
                *d++ = (char)strtol(hex, NULL, 16);
                src += 3;
            } else {
                *d++ = *src++;
            }
        } else if (*src == '+') {
            *d++ = ' ';
            src++;
        } else {
            *d++ = *src++;
        }
    }
    *d = '\0';
    return dest;
}

void cgi_req_parse(cgi_request *req) {
    req->param_count = 0;

    const char *query = getenv("QUERY_STRING");
    if (!query || *query == '\0') {
        return;
    }

    char *query_dup = strdup(query);
    char *token = strtok(query_dup, "&");

    while (token && req->param_count < CCGI_MAX_PARAMS) {
        char *equal = strchr(token, '=');
        if (equal) {
            *equal = '\0';
            char *key_decoded = url_decode(token);
            char *value_decoded = url_decode(equal + 1);

            req->params[req->param_count].key = key_decoded;
            req->params[req->param_count].value = value_decoded;
            req->param_count++;
        }
        token = strtok(NULL, "&");
    }

    if (token != NULL) {
        fprintf(stderr, "Too many parameters, truncated\n");
    }

    free(query_dup);
}

const char *cgi_req_get_param(const cgi_request *req, const char *key) {
    for (int i = 0; i < req->param_count; i++) {
        if (strcmp(req->params[i].key, key) == 0) {
            return req->params[i].value;
        }
    }
    return NULL;
}

void cgi_req_cleanup(cgi_request *req) {
    for (int i = 0; i < req->param_count; i++) {
        free(req->params[i].key);
        free(req->params[i].value);
    }
}
