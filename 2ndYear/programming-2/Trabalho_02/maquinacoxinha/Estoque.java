package com.mycompany.maquinacoxinha;

public class Estoque {
    private Integer coxinhas;
    
    public Estoque(){
        coxinhas = 0;
    }
    
    public void venderUm(){
        if(coxinhas>0){
            coxinhas--;
        }
    }
    
    public void abastecer(int coxinhas){
        this.coxinhas = this.coxinhas + coxinhas;
    }
    
    public void vender(int quantia){
        if(coxinhas>=quantia){
            coxinhas = coxinhas - quantia;
        }
    }
    
    public void zerar(){
        coxinhas = 0;
    }
    
    public Integer getCoxinhas(){
        return coxinhas; 
    }
    
}
