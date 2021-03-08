import sys
import os

sys.path.append("../")
from send_request import send_request
import config
from http.client import HTTPResponse
import socket


def test_chunked_201() -> str:
    request_header = "POST /nop/try.txt HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n5\r\ntest\n\r\n0\r\n\r\n"
    http_response = send_request(request_header)

    if http_response.status != 201:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "201"
        )
    if http_response.headers["Content-Length"] != "5":
        return "Bad Content-Length"
    return ""


def test_chunked_200() -> str:
    request_header = "POST /nop/try.txt HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n5\r\ntest\n\r\n0\r\n\r\n"
    http_response = send_request(request_header)

    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


def test_ChunkBadHex() -> str:
    request_header = "POST /nop/try.txt HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n5\r\ntest\n\r\n000;dude\r\njhhdsqhgshg\r\n0\r\n\r\n"
    http_response = send_request(request_header)

    if http_response.status != 400:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "400"
        )
    return ""


def test_DecodeEmptyBodyInPieces() -> str:
    request_header = "POST /nop/try.txt HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n0\r\n\r\n"
    http_response = send_request(request_header)

    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


def test_DecodeThreeChunksOnePiece() -> str:
    request_header = "POST /nop/try.txt HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\nF\r\nHello, World!!!\r\n7\r\nIt's me\r\n0\r\n\r\n"
    http_response = send_request(request_header)

    if http_response.status != 200:
        return "Bad status code: {}, expected: {}".format(
            str(http_response.status), "200"
        )
    return ""


# TEST FOR TIME OUT

# def test_DecodeBadTrailer() -> str:
#     request_header = "POST /post/print.cgi HTTP/1.1\r\nHost: localhost\r\nTransfer-encoding: chunked\r\n\r\n0\r\nX-Foo Bar\r\n\r\n"
#     http_response = send_request(request_header)

#     if http_response.status != 400:
#         return "Bad status code: {}, expected: {}".format(
#             str(http_response.status), "400"
#         )
#     return ""
