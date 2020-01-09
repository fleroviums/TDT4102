def isFibonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    return b==n

for i in range(10):
    print(i, isFibonacciNumber(i))
