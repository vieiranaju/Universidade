package com.trabalhofinal;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

public class VisualizarUsuariosController {

    @FXML private TableView<Usuario> tabelaUsuarios;
    @FXML private TableColumn<Usuario, String> colunaUsuarioNome;
    @FXML private TableColumn<Usuario, String> colunaUsuarioLogin;
    
    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }
    
    private final Dao<Usuario> usuarioDao = new Dao<>(Usuario.class);

    public void initialize() {
        configurarTabela();
        carregarDados(); 
    }

    private void configurarTabela() {
        colunaUsuarioNome.setCellValueFactory(new PropertyValueFactory<>("nome"));
        colunaUsuarioLogin.setCellValueFactory(new PropertyValueFactory<>("login"));
    }

    private void carregarDados() {
    ObservableList<Usuario> usuarios = FXCollections.observableArrayList(usuarioDao.listarTodos());
    if (usuarios.isEmpty()) {
        mostrarAlerta(AlertType.INFORMATION, "Nenhum Usuário Encontrado", "Não há usuários cadastrados.");
    }
    tabelaUsuarios.setItems(usuarios);
}


    @FXML
    public void mostrarTodasVacas() {
        carregarDados(); 
    }

    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}
