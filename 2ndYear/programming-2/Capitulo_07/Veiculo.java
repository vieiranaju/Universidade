
package Capitulo_07.Veiculo;

public abstract class Veiculo {
    
    private String marca;
    private Integer ano;
    private Double valor;
    private Double IPVA;
    
    public Veiculo(String marca, Integer ano, Double valor){
        this.marca = marca;
        this.ano = ano;
        this.valor = valor;
    }
    
    public Double getValor(){
        return valor;
    }
    
    public void setValor(Double valor){
        this.valor = valor;
    }
    
    public Integer getAno(){
        return ano;
    }
    
    public void setAno(Integer ano){
        this.ano = ano;
    }
    
    public String getMarca(){
        return marca;
    }
    
    public void setMarca(String marca){
        this.marca = marca;
    }
    
    public Double getIPVA(){
        return IPVA;
    }
    
    public void setIPVA(Double IPVA){
        this.IPVA = IPVA;
    }
    
    public abstract Double calcularIPVA();
    
}
