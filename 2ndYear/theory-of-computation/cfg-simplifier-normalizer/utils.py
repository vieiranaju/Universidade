def ler_gramatica(file_path):
    producoes = {}
    with open(file_path, 'r') as f:
        for linha in f:
            if '->' in linha:
                esquerda, direita = linha.strip().replace(' ', '').split('->')
                if esquerda in producoes:
                    producoes[esquerda].extend(direita.split('|'))
                else:
                    producoes[esquerda] = direita.split('|')
    return producoes

def escrever_etapa(etapa, descricao, producoes, f):
    f.write(f"\nEtapa {etapa}: {descricao}\n")
    for s, v in producoes.items():
        f.write(f"{s} -> {' | '.join(v)}\n")

def escrever_intermediarias(intermediarias, f):
    if intermediarias:
        f.write("\nVariáveis Intermediárias:\n")
        for s, v in intermediarias.items():
            f.write(f"{s} -> {''.join(v)}\n")
