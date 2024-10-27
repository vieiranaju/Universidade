def remover_inuteis_e_inalcancaveis(producoes):
    terminais = {s for s, v in producoes.items() if any(all(c.islower() for c in p) for p in v)}
    while True:
        novos_terminais = terminais | {s for s, v in producoes.items() if any(all(c in terminais or c.islower() for c in p) for p in v)}
        if novos_terminais == terminais:
            break
        terminais = novos_terminais

    producoes = {s: v for s, v in producoes.items() if s in terminais}
    producoes = {s: [p for p in v if all(c in terminais or c.islower() for c in p)] for s, v in producoes.items()}

    inicial = next(iter(producoes))  
    acessiveis = {inicial}
    while True:
        novos_acessiveis = acessiveis | {c for s in acessiveis for p in producoes.get(s, []) for c in p if c.isupper()}
        if novos_acessiveis == acessiveis:
            break
        acessiveis = novos_acessiveis

    producoes = {s: v for s, v in producoes.items() if s in acessiveis}
    producoes = {s: [p for p in v if all(c in acessiveis or c.islower() for c in p)] for s, v in producoes.items()}
    return producoes

def remover_producoes_vazias(producoes):
    variaveis_vazias = {s for s, v in producoes.items() if '@' in v}
    while True:
        novas_variaveis_vazias = variaveis_vazias | {s for s, v in producoes.items() if any(all(c in variaveis_vazias or c == '@' for c in p) for p in v)}
        if novas_variaveis_vazias == variaveis_vazias:
            break
        variaveis_vazias = novas_variaveis_vazias

    novas_producoes = {}
    for s, v in producoes.items():
        novas_producoes[s] = []
        for prod in v:
            sub_prods = {prod}
            for var in variaveis_vazias:
                if var in prod:
                    sub_prods |= {p.replace(var, '') for p in sub_prods}
            novas_producoes[s].extend(sub_prods)

    novas_producoes = {s: [p for p in v if p != '@'] for s, v in novas_producoes.items()}
    return novas_producoes

def substituir_producoes_unitarias(producoes):
    while True:
        unitarias = {s: [p for p in v if len(p) == 1 and p.isupper()] for s, v in producoes.items()}
        if not any(unitarias.values()):
            break
        for s, v in unitarias.items():
            for u in v:
                if u in producoes:
                    producoes[s].extend(producoes[u])
            producoes[s] = [p for p in producoes[s] if p not in v]
    return producoes

