package Lista_07.Jogo;

public class Inimigo implements IPersonagem{
    Ponto p;
    
    public Inimigo(int x, int y){
        p = new Ponto(x,y); 
    }
    
    public Inimigo(){
        p = new Ponto(0,0); 
    }
    
    @Override
     public Ponto getPosicao(){
         
         return p;
     };    
}
