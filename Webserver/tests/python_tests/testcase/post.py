import sys
import os

sys.path.append("../")
from send_request import send_request
import config


# test rfc7230 section 5.4 Host


def test_post_not_allowed() -> str:
    request_header = "POST / HTTP/1.1\r\nHost: xx\r\n\r\n"
    http_response = send_request(request_header)
    if http_response.status != 405:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "405"
        )
    return ""


def test_post() -> str:
    request_header = "POST /nop/post.html HTTP/1.1\r\nHost: xx\r\nContent-Length: 12\r\n\r\nPOST REQUEST\r\n\r\n"
    http_response = send_request(request_header)
    if http_response.status != 201:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "201"
        )
    if http_response.headers["Location"] != "./www/upload/post.html":
        return "Bad Location header: {}, expected: {}".format(
            http_response.headers["Location"], "./www/upload/post.html"
        )
    try:
        f = open("../../www/upload/post.html", "r")
    except:
        return "Error: file not created"
    line = f.readline()
    print(line)
    f.close()
    if line != "POST REQUEST":
        return "Bad content: {}, expected: {}".format(line, "POST REQUEST")

    request_header = "POST /nop/post.html HTTP/1.1\r\nHost: xx\r\nContent-Length: 22\r\n\r\n, ANOTHER POST REQUEST\r\n\r\n"
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    try:
        f = open("../../www/upload/post.html", "r")
    except:
        return "Error: file not created"
    line = f.readline()
    print(line)
    f.close()
    if line != "POST REQUEST, ANOTHER POST REQUEST":
        return "Bad content: {}, expected: {}".format(
            line, "POST REQUEST, ANOTHER POST REQUEST"
        )
    return ""



def test_cgi_auth_headers() -> str:
    request_header = (
        request_header
    ) = "GET /j/date.php HTTP/1.1\r\nHost:{}\r\nAuthorization: {}\r\n\r\n".format(
        config.SERVER_NAME, config.AUTH_KEY
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "226"
        )
    return ""
