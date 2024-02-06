def power(x, y, p):
    res = 1
    x = x % p
    while y > 0:
        if y & 1:
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def find_primitive(n):
    phi = n - 1
    prime_factors = find_prime_factors(phi)
    for r in range(2, phi + 1):
        flag = False
        for it in prime_factors:
            if power(r, phi // it, n) == 1:
                flag = True
                break
        if flag == False:
            return r
    return -1

def find_prime_factors(n):
    s = set()
    while n % 2 == 0:
        s.add(2)
        n = n // 2
    for i in range(3, int(math.sqrt(n)), 2):
        while n % i == 0:
            s.add(i)
            n = n // i
    if n > 2:
        s.add(n)
    return s

import math
n = 961
print("Primitive root of", n, "is", find_primitive(n))