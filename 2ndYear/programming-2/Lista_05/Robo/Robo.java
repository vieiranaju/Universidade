package Lista_05.Robo;

public abstract class Robo {

    private Integer codigo;
    private String nome;
    private Ponto p;
    
    public Robo(){
        codigo = 0;
        nome = " ";
        p = new Ponto(0,0);
    }
    
    public Robo(Integer codigo, String nome, int x, int y){
        this.codigo = codigo;
        this.nome = nome;
        p = new Ponto(x, y);
    }
    
    public void andarFrente(){
        p.setX(p.getX() + 1);
    }
    public void andarAtras(){
        p.setX(p.getX() - 1);
    }
    
    public void andarCima(){
        p.setY(p.getY() +1 );
    }
    
    public void andarBaixo(){
        p.setY(p.getY() - 1 );
    }
    
    public Integer getCodigo(){
        return codigo;
    }
    
    public String getNome(){
        return nome;
    }
    
    public Ponto getPonto(){
        return p;
    }
    
    public void setCodigo(Integer codigo){
        this.codigo = codigo;
    }
    
    public void setNome(String nome){
        this.nome = nome;
    }
    
    public abstract String toString( );
    
    public abstract void resetar();
    
}
