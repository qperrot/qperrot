import requests

# from send_request import send_request
import config
import sys

sys.path.append("../")
sys.path.append("../lib")


def get_base_url() -> str:
    """
    Return the base URL of the server
    """
    return "http://localhost:{}/".format(config.SERVER_PORT)


def test_get() -> str:
    req = requests.get(get_base_url())
    if req.status_code != 200:
        return "Bad status code."
    if req.headers["Content-Length"] != "4867":
        return "Bad Content-Length"
    if req.headers["Content-Language"] != "en":
        return "Bad Content-Language"
    return ""


def test_get_dir_index() -> str:
    req = requests.get(get_base_url() + "index/")
    if req.status_code != 200:
        return "Bad status code."
    if req.headers["Content-Length"] != "4867":
        return "Bad Content-Length"
    return ""


def test_get_dir_not_allowed() -> str:
    req = requests.get(get_base_url() + "upload/yh.html")
    # if (req.status_code != 403):
    if req.status_code != 404:
        return "Bad status code."
    return ""


def test_wrong_post() -> str:
    req = requests.post(get_base_url())
    if req.status_code != 405:
        return "Bad status code."
    return ""


def test_too_big_request() -> str:
    payload = "a" * 1025
    req = requests.post(get_base_url() + "nop/test.txt", data=payload)
    if req.status_code != 413:
        return "Bad status code: {}, expected: {}".format(req.status_code, 413)
    return ""


def test_custom_404() -> str:
    req = requests.get(get_base_url() + "b")
    if req.status_code != 404:
        return "Bad status code"
    return ""


def test_404() -> str:
    req = requests.get(
        get_base_url() + "doidjodoeijdosejfoejfseoifjseiofjsejfsejfesjfseofsejiseofj"
    )
    if req.status_code != 404:
        return "Bad status code"
    return ""


def test_autoindex() -> str:
    req = requests.get(get_base_url() + "images")
    if req.status_code != 200:
        return "Bad status code"
    return ""


def test_two_puts() -> str:
    req = requests.put(get_base_url() + "nop/c.txt", data="1")
    if req.status_code != 201:
        return "Bad status code on first creation: {}, expected: {}".format(
            str(req.status_code), "201"
        )
    req = requests.put(get_base_url() + "nop/c.txt", data="2")
    if req.status_code != 200:
        return "Bad status code on update: {}, expected: {}".format(
            str(req.status_code), "200"
        )
    return ""


def test_multiple_ports() -> str:
    req = requests.get(get_base_url())
    if req.headers["Content-Length"] != "4867":
        return "Bad Content-Length"
    req = requests.get("http://localhost:{}/".format(config.SERVER_PORT2))
    if req.status_code != 405:
        return "Bad status code on update: {}, expected: {}".format(
            str(req.status_code), "405")
    return ""


def test_different_index() -> str:
    req = requests.get(get_base_url())
    if req.headers["Content-Length"] != "4867":
        return "Bad Content-Length"
    req = requests.get(get_base_url() + "index/")
    if req.headers["Content-Length"] != "4867":
        return "Bad Content-Length"
    return ""


def test_head() -> str:
    req = requests.head(get_base_url())
    if req.status_code != 200:
        return "Bad status code: {}, expected: {}".format(str(req.status_code), "200")
    if len(req.text) > 0:
        return "Head returned some content."
    return ""


def test_multiple_get() -> str:
    for i in range(100):
        req = requests.get(get_base_url())
        if req.status_code != 200 or req.headers["Content-Length"] != "4867":
            return "Bad request at {}th iteration.".format(i + 1)
    return ""



#######################


# CGI
# PUT avec chunk
# Multiple GET
# CONNECT
