#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "http_request.h"
#include "http_response.h"

int business_logic(const cgi_request *req, cgi_response *res);

#endif
