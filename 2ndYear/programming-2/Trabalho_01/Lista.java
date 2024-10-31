
package Trabalho_01;
    
    public class Lista {
        
        
        String matriz[][];
        
        Lista(){
            matriz = new String[][]{
                
                    { "foi depositado", "5" },
                    { "resgate o seu premio", "10" },
                    { "resgate de bonus para", "15" },
                    { "resgate em 24h", "8" },
                    { "emprestimo de ate", "17" },
                    { "pontos vencem hoje", "15" },
                    { "voce foi selecionado", "5" },
                    { "resgate agora em", "12" },
                    { "tentativa de entrega frustrada", "9" },
                    { "voce ganhou", "10" }
                
            };
        }
        
        
        public String[][] getMatriz(){
            return matriz;
        }
    
    
}

