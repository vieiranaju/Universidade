package Capitulo_07.Veiculo;

public class Kombi extends Caminhao{
    
    public Kombi(String marca, Integer ano, Double valor){
        super(marca, ano, valor);
    }
       
    @Override
    public Double calcularIPVA(){
        
        if(getAno() < 2014){
            setIPVA(getValor() * 0.045);
            return getIPVA(); 
        }
        
        setIPVA(0.0);
        return getIPVA();
    
    }
}