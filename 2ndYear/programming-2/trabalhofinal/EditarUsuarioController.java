package com.trabalhofinal;

import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

public class EditarUsuarioController {

    @FXML private ComboBox<String> usuarioComboBox;
    @FXML private TextField usuarioNomeField;
    @FXML private TextField usuarioSenhaField;
    
    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }

    private final Dao<Usuario> usuarioDao = new Dao<>(Usuario.class);

    public void initialize() {
        carregarUsuarios();
    }

    // Método para carregar os usuários na ComboBox
    private void carregarUsuarios() {
        usuarioComboBox.getItems().clear();
        usuarioDao.listarTodos().forEach(usuario -> usuarioComboBox.getItems().add(usuario.getLogin()));
    }
    
    @FXML
    public void selecionarUsuario() {
        String login = usuarioComboBox.getValue();
        if (login == null) return;

        Usuario usuario = usuarioDao.buscarPorChave("login", login);
        if (usuario != null) {
            usuarioNomeField.setText(usuario.getNome());
            usuarioSenhaField.setText(usuario.getSenha());
        }
    }

    @FXML
    public void editarUsuario() {
        String login = usuarioComboBox.getValue();
        if (login == null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Selecione um usuário.");
            return;
        }

        String novoNome = usuarioNomeField.getText();
        String novaSenha = usuarioSenhaField.getText();

        try {
            Usuario usuarioAtualizado = new Usuario(novoNome, login, novaSenha);
            usuarioDao.alterar("login", login, usuarioAtualizado);
            mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Usuário atualizado com sucesso!");
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro ao atualizar usuário: " + e.getMessage());
        }
    }
    
    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
    
    @FXML
    public void apagarUsuario() {
        String usuario = usuarioComboBox.getValue();
        if (usuario == null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Selecione uma vaca para apagar.");
            return;
        }

        try {
            usuarioDao.deletar("login", usuario);
            carregarUsuarios(); 
            usuarioNomeField.clear();
            usuarioSenhaField.clear();
            mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Usuario apagada com sucesso!");
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro ao apagar usuario: " + e.getMessage());
        }
    }
}
