
package Lista_05.Robo;

public class RoboSolar extends Robo {
    
    private boolean raios;
    
    public RoboSolar(Integer codigo, String nome, int x, int y, boolean raios){
        super(codigo, nome, x, y);
        this.raios = raios;
    }
    public RoboSolar(){
        super(0, " ", 0, 0);
        raios = false;
    }
    
    public void setRaios(boolean raios){
        this.raios = raios;
    }
    public boolean getRaios(){
        return raios;
    }
    
    @Override
    public String toString(){
        return "Sou um robo Solar!";
    }
    
    @Override
    public void resetar(){
        getPonto().setX(0); 
        getPonto().setY(0); 
    }
    
}
