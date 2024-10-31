package com.mycompany.maquinacoxinha;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;

public class PrincipalController {
    @FXML
    private TextField campoEstoque;
    
    @FXML
    private TextField campoEntrada;
    
    private Estoque estoque;
    
    @FXML
    private void initialize(){
        estoque = new Estoque(); 
        campoEstoque.setText(String.valueOf(estoque.getCoxinhas()));
    }
    
    @FXML
    private void venderUm(){
        if(estoque.getCoxinhas() == 0){
            Alert alert = new Alert(AlertType.ERROR);
            alert.setHeaderText(null);
            alert.setContentText("Não há Coxinhas para retirar");
            alert.show();
            return; 
        }
        estoque.venderUm();
        campoEstoque.setText(String.valueOf(estoque.getCoxinhas()));
    }
    
    @FXML
    private void vender(){
        Integer venda = Integer.valueOf(campoEntrada.getText());
        if(estoque.getCoxinhas() < venda){
            Alert alert = new Alert(AlertType.ERROR);
            alert.setHeaderText(null);
            alert.setContentText("Não há coxinhas o suficiente");
            alert.show();
            return; 
        }
        estoque.vender(venda);
        campoEstoque.setText(String.valueOf(estoque.getCoxinhas()));
    }
    
    @FXML
    private void abastecer(){
        Integer soma = Integer.valueOf(campoEntrada.getText());
        estoque.abastecer(soma);
        campoEstoque.setText(String.valueOf(estoque.getCoxinhas()));
    }
    
    @FXML
    private void zerar(){
        estoque.zerar();
        campoEstoque.setText(String.valueOf(estoque.getCoxinhas()));
    }
    
    
    @FXML
    private void sair(){
        Platform.exit();
        System.exit(0);
    }
}
