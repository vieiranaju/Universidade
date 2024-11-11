import json
import sys

def lerJson(file_path):
    with open(file_path, 'r') as f:
        return json.load(f)

def lerTxt(input_file):
    with open(input_file, "r") as arquivo_txt:
        return arquivo_txt.readlines()

def buscar_transicao(estado_atual, turingMachine, read):
    for transition in turingMachine['transitions']:
        if transition['from'] == estado_atual and transition['read'] == read:
            return (transition["to"], transition["write"], transition["dir"])

    return None

def simularTM(turingMachine, entrada):
    estado_atual = turingMachine['initial']
    index = 0
    fita = list(entrada)
    simbolo_branco = turingMachine['white']

    while estado_atual not in turingMachine['final']:
        read = fita[index]

        transicao = (buscar_transicao(estado_atual, turingMachine, read))
        if transicao is None:
            break

        estado_atual, write, dir = transicao

        fita[index] = write

        if(dir=='R'):
            index += 1
        elif(dir == 'L'):
            index -=1

        if (index<0):
            fita.insert(0, simbolo_branco)
            index = 0
        elif(index>=len(fita)):
            fita.append(simbolo_branco)

    if estado_atual in turingMachine['final']:
        print(1)
    else:
        print(0)

    return "".join(fita).strip() 

def main(turingMachine_file, input_file, output_file):

    turingMachine = lerJson(turingMachine_file)
    entradas = lerTxt(input_file)

    if not entradas:
        return

    try:
        with open(output_file, 'w', newline='') as arquivo_saida:
            for input in entradas:
                input = input.strip()
                resultado = simularTM(turingMachine, input)
                arquivo_saida.write(f"{resultado}\n")
                
    except Exception as e:
        print(f"Erro no arquivo de saída {output_file}: {e}")


if __name__ == "__main__":
    if len(sys.argv) < 4:
        print("Uso: python simulador.py <arquivo_da_maquina_de_turing.json> <arquivo_de_entrada.in> <arquivo_de_saida.out>")
        sys.exit(1)
    
    turingMachine_file = sys.argv[1]
    input_file = sys.argv[2]
    output_file = sys.argv[3]
    main(turingMachine_file, input_file, output_file)