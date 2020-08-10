"""
Interview task
"""
def minOperations(n):
    copyAll = 1
    past = 0
    i = 0
    for j in range(1, n//2):
        if n % j == 0:
            i = j
    past = i
    if (past == n):
        print("haha")
        return (past + copyAll)
    else:
        copyAll += 1
        while (past != i):
            past += 1
        return (past + copyAll + 1)
            



if __name__ == "__main__":
    n = 4
    print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))

    n = 5
    print("Min number of operations to reach {} characters: {}".format(n, minOperations(n)))


