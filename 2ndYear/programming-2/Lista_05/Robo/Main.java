package Lista_05.Robo;

public class Main {
    
     public static void main(String Args[]){
        
        Robo[] robos = new Robo[3];
        
        robos[0] = new RoboMarciano(1, "um", 0, 0);
        robos[1] = new RoboSolar(2, "dois", 0, 0, true);
        robos[2] = new RoboPlutoniano(3, "tres", 0, 0, 10);
        
        for(int i = 0; i<3; i++){
            System.out.println(robos[i].toString());
        }
        
    }
    
}
