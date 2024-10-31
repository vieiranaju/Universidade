
package Lista_01.data;

public class Main {
  public static void main(String[] args) {

    char separador1 = '/', separador2 = '-';
    
    Data data = new Data();
    System.out.println(data.formatarData(separador1));
    Data data2 = new Data(2024);
    System.out.println(data2.formatarData(separador2));
    Data data3 = new Data(17, 04, 2024);
    System.out.println(data3.formatarData(separador1));
  }

}
