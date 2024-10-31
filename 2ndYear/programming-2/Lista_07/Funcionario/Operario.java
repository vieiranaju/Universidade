package Lista_07.Funcionario;

public class Operario implements Funcionario{

  private double salarioDia;
  private int diasTrabalhados;

  public Operario(double salarioDia, int diasTrabalhados) {
    this.salarioDia = salarioDia;
    this.diasTrabalhados = diasTrabalhados;
  }

  @Override
  public double calcularSalario() {
    return getSalarioDia() * getDiasTrabalhados();
  }

  public double getSalarioDia() {
    return salarioDia;
  }

  public void SetSalarioDia(double salarioDia) {
    this.salarioDia = salarioDia;
  }

  public int getDiasTrabalhados() {
    return diasTrabalhados;
  }

  public void SetdiasTrabalhados(int diasTrabalhados) {
    this.diasTrabalhados = diasTrabalhados;
  }
}
