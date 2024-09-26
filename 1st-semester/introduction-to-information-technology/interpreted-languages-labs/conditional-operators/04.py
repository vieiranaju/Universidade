# dados
nome = 'Felps'
idade = 479
senha = 'Tropidacris232'
i = 0

# analisar se é válido
if len(nome) >= 4:
    print("Nome válido")
    i += 1  # Incrementa o contador

if len(senha) >= 8:
    print("Senha válida")
    i += 1  # Incrementa o contador

if idade >= 15:
    print("Idade válida")
    i += 1  # Incrementa o contador

# conclusão
if i == 3:
    print("\nPode criar conta")
else:
    print("\nVocê não é real")
