package Lista_07.Funcionario;

public class Gerente implements Funcionario{

  private double salarioMes;

  public Gerente(double salarioMes) {
    this.salarioMes = salarioMes;
  }

  @Override
  public double calcularSalario() {
    return GetSalarioMes() + (GetSalarioMes() * 0.1);
  }

  public double GetSalarioMes() {
    return salarioMes;
  }

  public void SetSalarioMes(double salarioMes) {
    this.salarioMes = salarioMes;
  }

}
