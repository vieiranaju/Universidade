package Lista_05.Pixel;

public class Pixel extends Ponto{
    
    private String cor;

    public Pixel(){
        cor = "preta";
        setX(0);
        setY(0);
    }
    
    public Pixel(int x, int y){
        cor = "preta";
        setX(x);
        setY(y);
    }
    
    public Pixel(int x, int y, String cor){
        this.cor = cor;
        setX(x);
        setY(y);
    }
    
    
    public void setCor(String cor){
        this.cor = cor;
    }
    
    public String getCor(){
        return cor;
    }
}
