
package Trabalho_01;

public class SpamDetector {
    
    public static int Detector(String S){
        
        
        int sum = 0;
        
            Lista lista = new Lista();
            String[][] matriz = lista.getMatriz();
            
        for (String[] matriz1 : matriz) {
            if (S.contains(matriz1[0])) {
                sum += Integer.parseInt(matriz1[1]);
            }
        }
           
        
        return sum;
    }
    
}
