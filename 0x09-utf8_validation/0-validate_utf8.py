#!/usr/bin/python3
"""
Utf8 validation module
"""


def validUTF8(data):
    """
    Check if data is a validate utf8
    """
    n_bytes = 0
    for num in data:
        num = bin(num)[2:].zfill(8)
        if n_bytes:
            if num.startswith("10"):
                n_bytes -= 1
            else:
                return False
        else:
            n_bytes = num.find("0")
            if n_bytes == -1 or n_bytes == 1 or n_bytes > 4:
                return False
            if n_bytes:
                n_bytes -= 1
    return (n_bytes == 0)
