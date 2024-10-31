package Lista_04.círculo;

public class Cilindro extends Circulo {
    
    private Double altura;
    
    public Cilindro(Double altura, Double raio){
        super(raio);
        this.altura = altura;
    }
    
    public Cilindro(){
        setRaio(0.0);
        altura = 0.0;
    }
    
    
    @Override
    public Double calcularArea(){
        return 2*(getRaio()*getRaio()*3.14) + 2*(3.14 * getRaio() * altura);
    }
    
}
