
package Lista_01.data;

class Data{

  int Dia, Mes, Ano;
  char Separador;

  Data(){
    Ano = 2024;
    Mes = 04;
    Dia = 16;
  }
  Data(int ano){
    this.Ano = ano;
    Mes = 1;
    Dia = 1;
  }
  Data(int dia, int mes, int ano){
    this.Dia = dia;
    this.Mes = mes;
    this.Ano = ano;
  }

  String formatarData(char Separador){
    if(Separador == '/'){
      return Dia + "/" + Mes + "/" + Ano;
    }
    else if(Separador == '-'){
      return Dia + "-" + Mes + "-" + Ano;
    }
    else{
      return "Formato de data inválido";
    }
  }
  
  }