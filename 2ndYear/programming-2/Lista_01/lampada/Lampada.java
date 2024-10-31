
package Lista_01.lampada;

class Lampada {

  boolean campo;

  Lampada() {
    campo = false;
  }

  void acender() {
    campo = true;
  }

  void apagar() {
    campo = false;
  }

  void mostrarEstado() {
    System.out.println("Estado: " + campo);
  }
}
