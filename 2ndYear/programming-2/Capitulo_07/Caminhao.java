package Capitulo_07.Veiculo;

public class Caminhao extends Veiculo{
    
    
    public Caminhao(String marca, Integer ano, Double valor){
        super(marca, ano, valor);
    }
       
    @Override
    public Double calcularIPVA(){
        
        Double IPVA  = getValor() * 0.04; 
        return IPVA; 
}
    
}
