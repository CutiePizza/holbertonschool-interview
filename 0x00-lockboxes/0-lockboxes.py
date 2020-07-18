#!/usr/bin/python3
"""
lockboxes problem
"""


def canUnlockAll(boxes):
    """lockboxes"""
    myDict = {}
    key_list = []
    myDict[0] = True
    key_list.append(boxes[0])

    for i in key_list:
        for j in i:
            if j not in myDict:
                myDict[j] = True
                i.remove(j)
            else:
                i.remove(j)
                key_list.append(boxes[j])
    if len(myDict) != len(boxes):
        return (False)
    else:
        return (True)
