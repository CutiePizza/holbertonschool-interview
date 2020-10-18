#!/usr/bin/python3
"""
Utf8 validation module
"""


def validUTF8(data):
    """
    Check if data is a validate utf8 or not
    """
    n_bytes = 0
    for num in data:
        num_b = format(num, '#010b')[-8:]
        if n_bytes == 0:
            for bit in num_b:
                if bit == '0':
                    break
                n_bytes += 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num_b[0] == '1' and num_b[1] == '0'):
                return False
        n_bytes -= 1
    return n_bytes == 0
