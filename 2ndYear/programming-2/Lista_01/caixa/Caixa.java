
package Lista_01.caixa;

class Caixa{

  double largura, altura, profundidade;

  
  Caixa(double largura, double altura, double profundidade){
    this.largura = largura;
    this.altura = altura;
    this.profundidade = profundidade;
  }

  double calcularVolume(){
    return largura * altura * profundidade;
  }

}
