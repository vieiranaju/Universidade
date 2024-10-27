import string

def normalizar_para_cnf(producoes):
    variaveis_intermediarias = iter(string.ascii_uppercase)
    novas_producoes = producoes.copy()
    
    novos_terminais = set()
    for s, v in producoes.items():
        for prod in v:
            for c in prod:
                if c.islower():
                    novos_terminais.add(c)
    
    for terminal in novos_terminais:
        nova_variavel = f"Z{terminal.upper()}"
        if nova_variavel not in novas_producoes:
            novas_producoes[nova_variavel] = [terminal]

    novas_producoes_temp = {}
    for s, v in list(novas_producoes.items()):
        novas_producoes_temp[s] = []
        for prod in v:
            if len(prod) == 1:
                novas_producoes_temp[s].append(prod)
            else:
                novo_prod = []
                for c in prod:
                    if c.islower():
                        nova_variavel = f"Z{c.upper()}"
                        novo_prod.append(nova_variavel)
                    else:
                        novo_prod.append(c)
                novas_producoes_temp[s].append("".join(novo_prod))

    novas_producoes = novas_producoes_temp.copy()

    intermediarias = {}
    
    def criar_novas_variaveis(prod):
        while len(prod) > 2:
            nova_variavel = next(variaveis_intermediarias)
            while nova_variavel in novas_producoes:
                nova_variavel = next(variaveis_intermediarias)
            novas_producoes[nova_variavel] = ["".join(prod[1:])]
            intermediarias[nova_variavel] = "".join(prod[1:])
            prod = [prod[0], nova_variavel]
        return prod

    producoes_modificadas = {}
    for s, v in list(novas_producoes.items()):
        producoes_modificadas[s] = []
        for prod in v:
            nova_prod = criar_novas_variaveis(list(prod))
            producoes_modificadas[s].append("".join(nova_prod))

    return producoes_modificadas, intermediarias
