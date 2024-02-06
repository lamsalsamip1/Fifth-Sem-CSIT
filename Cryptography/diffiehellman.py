
import random


def find_primitive(n):
    for r in range(1, n):
        li = []
        for x in range(n-1):
            val = pow(r, x, n)
            if val not in li:
                li.append(val)
            else:
                break
        if len(li) == n-1:
            return r


def generate_prime():
    while True:
        num = random.getrandbits(12) 
        if all(num % i != 0 for i in range(2, num)):
            return num


p = generate_prime()


g = find_primitive(p)


a = random.randint(1, p)

# Alice calculates public key A
A = pow(g, a, p)

# Bob generates private key b
b = random.randint(1, p)

# Bob calculates public key B
B = pow(g, b, p)

# Alice and Bob exchange public keys and calculate shared secret
shared_secret_Alice = pow(B, a, p)
shared_secret_Bob = pow(A, b, p)

print("Shared secret from Alice's perspective:", shared_secret_Alice)
print("Shared secret from Bob's perspective:", shared_secret_Bob)