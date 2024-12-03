package com.trabalhofinal;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

public class CadastroController {

    @FXML private TextField usuarioNomeField;
    @FXML private TextField usuarioLoginField;
    @FXML private TextField usuarioSenhaField;

    @FXML private TextField vacaNomeField;
    @FXML private TextField vacaBrincoField;
    @FXML private TextField vacaRacaField;   
    
    private final Dao<Usuario> usuarioDao = new Dao<>(Usuario.class);
    private final Dao<Vaca> vacaDao = new Dao<>(Vaca.class);
    
    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }
    
    public void AbrirLogin() throws Exception {
        App.setRoot("Login");
    }

    @FXML
    public void salvarUsuario() {
        String nome = usuarioNomeField.getText();
        String login = usuarioLoginField.getText();
        String senha = usuarioSenhaField.getText();
        
        if(nome == null || login == null || senha ==null){
            mostrarAlerta(AlertType.WARNING, "Aviso", "Preencha todos os campos!");
            return;
        }
        
        try {
        
        Usuario usuarioExistente = usuarioDao.buscarPorChave("login", login);
        if (usuarioExistente != null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "O usuário já está registrado.");
            return;
        }

        Usuario usuario = new Usuario(nome, login, senha);
        usuarioDao.inserir(usuario);
        limparCamposUsuario();
        
        mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Usuario salvo com sucesso!");
        
        AbrirMenu();
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro desconhecido: " + e.getMessage());
        }
       
    }

    @FXML
    public void salvarVaca() {
        String nome = vacaNomeField.getText();
        String brinco = vacaBrincoField.getText();
        String raca = vacaRacaField.getText();
        
        if(nome == null || brinco == null || raca ==null){
            mostrarAlerta(AlertType.WARNING, "Aviso", "Preencha todos os campos!");
            return;
        }
        
        try {
        
        Vaca vacaExistente = vacaDao.buscarPorChave("brinco", brinco);
        if (vacaExistente != null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "O brinco já está registrado para outra vaca.");
            return;
        }

        Vaca vaca = new Vaca(nome, brinco, raca);
        vacaDao.inserir(vaca);
        limparCamposVaca();
        
        mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Vaca salva com sucesso!");
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro desconhecido: " + e.getMessage());
        }
    }
    
    @FXML
    private void limparCamposUsuario() {
        usuarioNomeField.clear();
        usuarioLoginField.clear();
        usuarioSenhaField.clear();
    }
    @FXML
    private void limparCamposVaca() {
        vacaNomeField.clear();
        vacaBrincoField.clear();
        vacaRacaField.clear();
    }
    
    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}

