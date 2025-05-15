#include "framework.h"

int main(void) {
    cgi_request req;
    cgi_response res;

    cgi_req_parse(&req);
    cgi_res_init(&res);

    business_logic(&req, &res);

    cgi_res_send(&res);

    return 0;
}
