package Lista_05.Circulo;


public class Circulo{
    
    private float raio;
    private Ponto p;
    
    public Circulo(){
        p = new Ponto(0,0);
        raio = 1;
    }
    
    public Circulo(int x, int y, float raio){
        p = new Ponto(x, y);
        this.raio = raio;
    }
    
    public String desenhar(){
        return "-";
    }
    
}
