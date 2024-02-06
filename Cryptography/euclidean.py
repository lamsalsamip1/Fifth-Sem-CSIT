def gcdEuclid(a, b): 
    if a == 0 : 
        return b 
     
    return gcdEuclid(b%a, a)


num1=int(input("Enter first number: "))
num2=int(input("Enter second number: "))
print(f"GCD is : {gcdEuclid(num1,num2)}")