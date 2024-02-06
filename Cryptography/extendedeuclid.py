def extended_euclidean(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = extended_euclidean(b % a, a)
        return gcd, y - (b // a) * x, x

def multiplicative_inverse(a, p):
    gcd, x, _ = extended_euclidean(a, p)
    if gcd == 1:
        return x % p
    else:
        return None


a = 5
p = 11
print(f"The multiplicative inverse of {a} under modulo {p} is {multiplicative_inverse(a, p)}")