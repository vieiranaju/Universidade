package Lista_07.Jogo;

public class Heroi implements IPersonagem{
    
    Ponto p;
    
    public Heroi(int x, int y){
        p = new Ponto(x,y); 
    }
    
    public Heroi(){
        p = new Ponto(0,0); 
    }
    
    @Override
     public Ponto getPosicao(){
         
         return p;
     };
    
}