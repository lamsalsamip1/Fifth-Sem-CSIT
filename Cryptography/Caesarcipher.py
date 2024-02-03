
def caesar(text,mode):
    result=''
    for letter in text:
        if(letter.isalpha() and letter!=' '):
            code=ord(letter)-97 if letter.islower() else ord(letter)-65
            if(mode==1): #Encrypt
                enc=(code+3)%26
               
            else: #Decrypt
                enc=(code-3)%26
            out=chr(enc+97)if letter.islower() else chr(enc+65)
        else:
            out=letter
        result+=out
    return result



while True:
    choice= int(input('\n****CAESAR CIPHER****\n1.Encrypt\n2.Decrypt\n3.Exit\n********************\n'))
    if(choice==1):
        text=input('Enter the text to be encrypted: ')
        res=caesar(text,1)
        print(f"\nThe encrypted text is:{res}")
    elif(choice==2):
        text=input('Enter the text to be decrypted: ')
        res=caesar(text,2)
        print(f"\nThe decrypted text is:{res}")
    else:
        break