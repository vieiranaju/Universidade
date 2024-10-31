package Lista_05.Robo;

public class RoboPlutoniano extends RoboMarciano{
    
    int balas;
    
    public RoboPlutoniano(Integer codigo, String nome, int x, int y, int balas){
        super(codigo, nome, x, y);
        this.balas = balas;
    }
    public RoboPlutoniano(){
        super(0, " ", 0, 0);
    }
    
    @Override
    public void setPosicao(int x, int y){
        getPonto().setX(x);
        getPonto().setY(y);
    }
    
    @Override
    public String toString(){
        return "Sou um robo Plutoniano!";
    }
    
    @Override
    public void resetar(){
        getPonto().setX(0); 
        getPonto().setY(0); 
    }
    
    public int getBalas(){
        return balas;
    }
    
    public void setBalas(int balas){
        this.balas = balas;
    }
    
    public void atirar(){
        
        if(balas != 0){
            balas = balas - 1;
        }else{
            System.out.println("Não há balas restantes, recarregue!");
        }
    }
    
    public void recarregar(){
        balas = 20;
    }
    
}
