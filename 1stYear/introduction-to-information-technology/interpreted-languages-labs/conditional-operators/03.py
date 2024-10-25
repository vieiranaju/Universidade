a = 1
b = 2
c = 3
menor = a

# condições
if menor > b:
    menor = b
if menor > c:
    menor = c

if a == b or c == b or a == c:
    print("Existem dois números iguais")

print("O menor é", menor)
