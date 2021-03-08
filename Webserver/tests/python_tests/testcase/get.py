import sys

sys.path.append("../")
from send_request import send_request
import config

# test rfc7230 section 5.4 Host


def test_get_dir_no_index() -> str:
    request_header = "GET /error HTTP/1.1\r\nHost: {}\r\n\r\n".format(config.SERVER_NAME)
    http_response = send_request(request_header)
    if http_response.status != 404:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "404"
        )
    return ""


def test_get_dir_autoindex() -> str:
    request_header = "GET /nop HTTP/1.1\r\nHost: {}\r\n\r\n".format(config.SERVER_NAME2)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


def test_get_dir_index() -> str:
    request_header = "GET / HTTP/1.1\r\nHost: {}\r\n\r\n".format(config.SERVER_NAME2)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    if req.headers["Content-Length"] != "467":
        return "Bad Content-Length"
    return ""


def test_content_neg_lang() -> str:
    request_header = "GET / HTTP/1.1\r\nHost: {}\r\nAccept-Language: en\r\n\r\n".format(config.SERVER_NAME2)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    if http_response.headers["Content-Length"] != "466":
        return "Bad Content-Length"
    if http_response.headers["Content-Language"] != "en":
        return "Missing Content-Language header"
    return ""


def test_content_neg_lang_double() -> str:
    request_header = "GET / HTTP/1.1\r\nHost: {}\r\nAccept-Language: en, fr\r\n\r\n".format(config.SERVER_NAME2)
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    if http_response.headers["Content-Length"] != "466":
        return "Bad Content-Length"
    if http_response.headers["Content-Language"] != "en":
        return "Missing Content-Language header"
    return ""


def test_content_neg_charset() -> str:
    request_header = (
        "GET / HTTP/1.1\r\nHost: {}\r\nAccept-Charset: utf-45\r\n\r\n".format(config.SERVER_NAME2)
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    if http_response.headers["Content-Length"] != "466":
        return "Bad Content-Length"
    return ""


def test_content_neg_charset_utf8() -> str:
    request_header = (
        "GET / HTTP/1.1\r\nHost: {}\r\nAccept-Charset: utf-8 \r\n\r\n".format(config.SERVER_NAME2)
    )
    http_response = send_request(request_header)
    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    if http_response.headers["Content-Length"] != "470":
        return "Bad Content-Length"
    if http_response.headers["Content-Type"] != "text/html; charset=utf-8":
        return "Expected Content-Language header with value of 'text/html; charset=utf-8', actual: {}".format(
            http_response.headers["Content-Type"]
        )
    return ""
