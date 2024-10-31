package Lista_07.Jogo;

public class Jogo {
    
    Heroi heroi;
    Inimigo inimigo;
    
    public Jogo(int x, int y, int x1, int y1){
        heroi = new Heroi(x, y);
        inimigo = new Inimigo(x1, y1);
    }
    
    public Jogo(){
        heroi = new Heroi(0, 0);
        inimigo = new Inimigo(0, 0);
    }
    
    
    public Boolean colidiu(){
        
        return heroi.getPosicao() == inimigo.getPosicao();
    }
    
}
