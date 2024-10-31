
package Trabalho_01;

import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        System.out.println("Insira o Caminho para o arquivo que deseja verificar: ");
        String caminho = scanner.nextLine();
        
        LeitorArquivos ler = new LeitorArquivos();
        String string = ler.lerArquivo(caminho); 
        
        int sum = SpamDetector.Detector(string);
        
        
        if(sum < 5){
            System.out.println("Não é Suspeito!");
        }
        else if(sum <30){
            System.out.println("Fracamente Suspeito!");
        }else if(sum < 70){
            System.out.println("Potencialmente Suspeito!");
        }else{
            System.out.println("Spam !!");
        }
        
    
  }
    
}
