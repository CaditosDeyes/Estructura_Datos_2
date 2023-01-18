from sympy.crypto.crypto import encipher_affine, decipher_affine

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

letter_to_index = dict(zip(alphabet, range(len(alphabet))))
index_to_letter = dict(zip(range(len(alphabet)), alphabet))

def caesar(start_text, shift_amount, cipher_direction):
    end_text = ""
    if cipher_direction == "decodificar":
        shift_amount *= -1
    for char in start_text:
        if char in alphabet:
            position = alphabet.index(char)
            new_position = position + shift_amount
            end_text += alphabet[new_position]
        else:
            end_text += char
    print(f"El resultado de la {cipher_direction}d es: {end_text}")
    
def afin(msg,result,direction):
    clave=(5,1)
    if result==1:
        codi=encipher_affine(msg, clave)
    else:
        codi=decipher_affine(msg, clave)
    print(f"El resultado de la {direction}d es: {codi}")
        
def vigenere(mesg,direction):
    codi = ''
    key="platano"
    
    if direction=="codificar":
        mensaje = [mesg[i:i + len(key)] for i in range(0, len(mesg), len(key))]
        
        for split in mensaje:
            i=0
            for letter in split:
                numero=(letter_to_index[letter] + letter_to_index[key[i]]) % len(alphabet)
                codi += index_to_letter[numero]
                i+=1
    else:
        mensaje = [mesg[i:i + len(key)] for i in range(0, len(mesg), len(key))]
        
        for split in mensaje:
            i=0
            for letter in split:
                numero=(letter_to_index[letter] - letter_to_index[key[i]]) % len(alphabet)
                codi += index_to_letter[numero]
                i+=1
        
    print(f"El resultado de la {direction}d es: {codi}")
    
should_end = False
    
while not should_end:
    opc=input("Sleccione que cifrado desea usar:\n 'cesar'\n 'afin'\n 'vigenere'\n R= ")
    if opc=="cesar":
        direction = input("Escriba 'codificar' para cifrar, escriba 'decodificar' para descifrar:\n")
        if (direction == "codificar" or direction == "decodificar"):
            text = input("Escribe tu mensaje:\n").lower()
            try:
                shift = int(input("Seleccione numero de rotaciones:\n"))
                shift = shift % 26
            except ValueError:
                print("Introduzca solo números como valor de cambio")
                continue
            caesar(start_text=text, shift_amount=shift, cipher_direction=direction)
            
    elif opc == "afin":
        direction = input("Escriba 'codificar' para cifrar, escriba 'decodificar' para descifrar:\n")
        if (direction == "codificar" or direction == "decodificar"):
            text = input("Escribe tu mensaje:\n").lower()
            if direction == "codificar":
                result=1
            elif direction == "decodificar":
                result=2
            afin(text,result,direction)
            
    elif opc == "vigenere":
        direction = input("Escriba 'codificar' para cifrar, escriba 'decodificar' para descifrar:\n")
        if (direction == "codificar" or direction == "decodificar"):
            text = input("Escribe tu mensaje:\n").lower()
            vigenere(text,direction)
            
    else:
        print("Por favor seleccione una opcion valida")
    restart = input("Escribe 'sí' si quieres volver a ir. De lo contrario escriba 'no'.\n")
    if restart == "no" or restart == "n" or restart == "":
        should_end = True
        print("Adios")