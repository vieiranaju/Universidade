/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Lista_08;

public class cachorro {
    public void latir( ) {
        System.out.println("Au au");
    }
}

public class CachorroNutela extends cachorro {
    
    @Override
    protected void latir( ) {
        System.out.println("Ui ui ui ui");
    }
}