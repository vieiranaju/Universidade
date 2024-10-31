package Lista_07.Funcionario;

import java.util.ArrayList;
import java.util.Collections;

public class Main {
  public static void main(String[] args) {

    ArrayList<Funcionario> lista = new ArrayList();
    lista.add(new Operario(522.44, 8));
    lista.add(new Operario(10.5, 5));
    lista.add(new Gerente(1055.0));
    lista.add(new Gerente(22055.0));

    for (Funcionario a : lista) {
      System.out.println(a.calcularSalario());
    }

    Collections.sort(lista, new salarioComparator());
    for (Funcionario a : lista) {
      System.out.println(a.calcularSalario());
    }
  }
}
