#!/usr/bin/python3
"""
lockboxes problem
"""


def canUnlockAll(boxes):
    """lockboxes"""
    myDict = {}
    key_list = []
    myDict[0] = True
    for i in range(1, len(boxes)):
        myDict[i] = False
    key_list.append(boxes[0])
    for i in key_list:
        for j in i:
            myDict[j] = True
            i.remove(j)
            if j < len(boxes):
                key_list.append(boxes[j])
    if False in myDict.values():
        return (False)
    else:
        return (True)
