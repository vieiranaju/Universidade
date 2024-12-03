package com.trabalhofinal;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

public class MenuController {
    
    @FXML private TextField usuarioLoginField;
    @FXML private TextField usuarioSenhaField;
    
    private final Dao<Usuario> usuarioDao = new Dao<>(Usuario.class);

    public void abrirTelaCadastroUsuario() throws Exception {
        App.setRoot("CadastroUsuario");
    }
    
    public void abrirTelaProducaoVaca() throws Exception {
        App.setRoot("visualizarProducaoVaca");
    }
    
    public void abrirTelaProducaoPeriodo() throws Exception {
        App.setRoot("visualizarProducaoPeriodo");
    }

    public void abrirTelaCadastroVaca() throws Exception {
        App.setRoot("CadastroVaca");
    }
    
    public void AbrirLogin() throws Exception {
        App.setRoot("Login");
    }
    
    public void AbrirMenu() throws Exception {
        String login = usuarioLoginField.getText();
        Usuario usuarioExistente = usuarioDao.buscarPorChave("login", login);
        String senha = usuarioSenhaField.getText();

        if (usuarioExistente == null || !usuarioExistente.getSenha().equals(senha)) {
            mostrarAlerta(Alert.AlertType.INFORMATION, "Informação", "Usuário ou senha incorretos!");
            return; 
        }

        App.setRoot("Menu");
    }
    
    public void abrirTelaCadastroProducao() throws Exception {
        App.setRoot("CadastroProducao");
    }
    
    public void login() throws Exception {
        App.setRoot("Login");
    }
    
    public void editarVaca() throws Exception {
        App.setRoot("EditarVaca");
    }
    public void visualizarVaca() throws Exception {
        App.setRoot("visualizarVaca");
    }
    
    public void editarUsuario() throws Exception {
        App.setRoot("EditarUsuario");
    }
    public void visualizarUsuario() throws Exception {
        App.setRoot("visualizarUsuario");
    }
    
    private void mostrarAlerta(Alert.AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}
