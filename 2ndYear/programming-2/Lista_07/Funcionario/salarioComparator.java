package Lista_07.Funcionario;

import java.util.Comparator;
public class salarioComparator implements Comparator<Funcionario> {
  
    @Override
    public int compare(Funcionario a, Funcionario b) {
        if(a.calcularSalario() < b.calcularSalario()){
            return -1;
        }
        if(a.calcularSalario() == b.calcularSalario()){
            return 0;
        }
        return 1;
    }
}
