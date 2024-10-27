def normalizar_para_gnf(producoes):
    novas_producoes = producoes.copy()
    intermediarias = {}

    def substituir_primeiro_terminal(prod, novas_producoes):
        if prod[0].islower():
            nova_variavel = f"Z{prod[0].upper()}"
            if nova_variavel not in novas_producoes:
                novas_producoes[nova_variavel] = [prod[0]]
            return nova_variavel + prod[1:]
        return prod

    # Substituir primeiros terminais por variáveis
    novas_producoes_temp = {}
    for s, v in novas_producoes.items():
        novas_producoes_temp[s] = []
        for prod in v:
            nova_prod = substituir_primeiro_terminal(prod, novas_producoes)
            novas_producoes_temp[s].append(nova_prod)

    novas_producoes = novas_producoes_temp.copy()

    # Reescrever produções para que comecem com terminais
    while True:
        modificou = False
        novas_producoes_temp = {}
        for s, v in novas_producoes.items():
            novas_producoes_temp[s] = []
            for prod in v:
                if prod[0].isupper():
                    if prod[0] not in novas_producoes:
                        novas_producoes_temp[s].append(prod)  
                        continue
                    modificou = True
                    substituicoes = novas_producoes[prod[0]]
                    for substituicao in substituicoes:
                        novas_producoes_temp[s].append(substituicao + prod[1:])
                else:
                    novas_producoes_temp[s].append(prod)
        if not modificou:
            break
        novas_producoes = novas_producoes_temp.copy()

    novas_producoes = {s: [prod for prod in v if prod] for s, v in novas_producoes.items()}
    novas_producoes = {s: [prod for prod in v if not (s == prod[0] and len(prod) == 1)] for s, v in novas_producoes.items()}
    novas_producoes = {s: v for s, v in novas_producoes.items() if v}

    return novas_producoes, intermediarias