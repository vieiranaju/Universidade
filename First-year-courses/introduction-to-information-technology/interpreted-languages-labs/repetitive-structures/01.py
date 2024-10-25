n = 1
while n != -1:
    n = int(input("Digite um número (ou -1 para sair): "))
    
    if n != -1:
        m = int(input("Digite um divisor: "))
        
        if n % m == 0:
            print(f"{n} é múltiplo de {m}")
        else:
            print("Não é múltiplo!")
