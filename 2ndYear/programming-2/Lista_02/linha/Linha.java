
package Lista_02.linha;

class Linha {

  int comprimento;

  Linha(){
    comprimento = 0;
  }

  Linha(int comprimento){
    this.comprimento = comprimento;
  }

  void desenhar(){
    for(int i = 0; i < comprimento; i++){
      System.out.print("-");
    }
    System.out.println();
  }
  
}
