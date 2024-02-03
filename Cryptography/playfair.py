def generate_key_square(key):
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    key_square = [[None for _ in range(5)] for _ in range(5)]

    key = key.replace(" ", "").upper()
    key += alphabet
    key = dict.fromkeys(key)  # remove duplicates

    row, col = 0, 0
    for letter in key:
        if letter == 'J':  # skip 'J'
            continue
        key_square[row][col] = letter
        if col == 4:
            if row == 4:
                break
            row += 1
            col = 0
        else:
            col += 1
    return key_square


def find_in_key_square(key_square, letter):
    for row in range(5):
        for col in range(5):
            if key_square[row][col] == letter:
                return row, col
    return None


def playfair_cipher_encrypt(text, key):
    key_square = generate_key_square(key)
    text = text.upper().replace(" ", "")
    if len(text) % 2 != 0:
        text += "X"  # if odd length, append 'X' at the end

    encrypted_text = ""
    for i in range(0, len(text), 2):
        row1, col1 = find_in_key_square(key_square, text[i])
        row2, col2 = find_in_key_square(key_square, text[i+1])
        if row1 == row2:
            encrypted_text += key_square[row1][(col1+1)%5] + key_square[row2][(col2+1)%5]
        elif col1 == col2:
            encrypted_text += key_square[(row1+1)%5][col1] + key_square[(row2+1)%5][col2]
        else:
            encrypted_text += key_square[row1][col2] + key_square[row2][col1]
    return encrypted_text

def playfair_cipher_decrypt(cipher, key):
    key_square = generate_key_square(key)
    cipher = cipher.upper().replace(" ", "")

    decrypted_text = ""
    for i in range(0, len(cipher), 2):
        row1, col1 = find_in_key_square(key_square, cipher[i])
        row2, col2 = find_in_key_square(key_square, cipher[i+1])
        if row1 == row2:
            decrypted_text += key_square[row1][(col1-1)%5] + key_square[row2][(col2-1)%5]
        elif col1 == col2:
            decrypted_text += key_square[(row1-1)%5][col1] + key_square[(row2-1)%5][col2]
        else:
            decrypted_text += key_square[row1][col2] + key_square[row2][col1]
    return decrypted_text

text= input("Enter the plaintext: ")
key = "MONARCHY"
encrypted_text = playfair_cipher_encrypt(text, key)
print(f"Original text: {text}")
print(f"Encrypted text: {encrypted_text}")
decrypted_text = playfair_cipher_decrypt(encrypted_text, key)
print(f"Decrypted text: {decrypted_text}")