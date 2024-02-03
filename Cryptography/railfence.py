
def encrypt(plaintext,k):

    flag=0
    row=0
    enc=[[" " for i in range(len(s))] for j in range(k)]
    for i in range(len(plaintext)):
        enc[row][i]=s[i]
        if row==0:
            flag=0
        elif row==k-1:
            flag=1
        if flag==0:
            row+=1
        else:
            row-=1

    for i in range(k):
        print("".join(enc[i]))

    ct=[]
    for i in range(k):
        for j in range(len(s)):
            if enc[i][j]!=' ':
                ct.append(enc[i][j])
    cipher="".join(ct)
    return cipher
    

def rail_fence_cipher_decrypt(cipher, key):
    rail = [['\n' for i in range(len(cipher))] for j in range(key)]
    
    dir_down = None
    row, col = 0, 0
    
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False
            
        rail[row][col] = '*'
        col += 1
        
        if dir_down:
            row += 1
        else:
            row -= 1
            
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if ((rail[i][j] == '*') and (index < len(cipher))):
                rail[i][j] = cipher[index]
                index += 1
                
    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False
            
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
            
        if dir_down:
            row += 1
        else:
            row -= 1
    return "".join(result)

s=input("Enter string: ")
k=int(input("Enter key: "))


cipher = encrypt(s,k)
print("Cipher Text: ",cipher)

print("Decrypted Text: ",rail_fence_cipher_decrypt(cipher, k))