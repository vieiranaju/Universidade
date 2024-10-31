package Lista_04.círculo;

public class Circulo {
    
    private Double raio;
    
    public Circulo(){
        raio = 1.0;
    }
    public Circulo(Double raio){
        this.raio = raio;
    }
    
    public void setRaio(Double raio){
        this.raio = raio;
    }
    
    public Double getRaio(){
        return raio;
    }
    
    public Double calcularArea(){
        return raio*raio*3.14;
    }
    
}
