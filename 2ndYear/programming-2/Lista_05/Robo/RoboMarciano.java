package Lista_05.Robo;

public class RoboMarciano extends Robo {
    
    public RoboMarciano(Integer codigo, String nome, int x, int y){
        super(codigo, nome, x, y);
    }
    public RoboMarciano(){
        super(0, " ", 0, 0);
    }
    
    public void setPosicao(int x, int y){
        getPonto().setX(x);
        getPonto().setY(y);
    }
    
    @Override
    public String toString(){
        return "Sou um robo Marciano!";
    }
    
    @Override
    public void resetar(){
        getPonto().setX(0); 
        getPonto().setY(0); 
    }
    
}
