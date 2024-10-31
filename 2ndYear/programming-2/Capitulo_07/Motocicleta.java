
package Capitulo_07.Veiculo;

public class Motocicleta extends Veiculo {
    
    private Integer cilindradas;
    
    public Motocicleta(String marca, Integer ano, Double valor, Integer cilindradas){
     super(marca, ano, valor);
     this.cilindradas = cilindradas;
    }
       
    @Override
    public Double calcularIPVA(){
        
        Double IPVA  = getValor() * 0.02; 
        return IPVA; 
}
    
}
