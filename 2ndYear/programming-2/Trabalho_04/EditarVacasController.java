package com.trabalhofinal;

import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

public class EditarVacasController {

    @FXML private ComboBox<String> vacaComboBox;
    @FXML private TextField vacaNomeField;
    @FXML private TextField vacaRacaField;
    
    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }

    private final Dao<Vaca> vacaDao = new Dao<>(Vaca.class);

    public void initialize() {
        carregarVacas();
    }

    private void carregarVacas() {
        vacaComboBox.getItems().clear();
        vacaDao.listarTodos().forEach(vaca -> vacaComboBox.getItems().add(vaca.getBrinco()));
    }

    @FXML
    public void selecionarVaca() {
        String brinco = vacaComboBox.getValue();
        if (brinco == null) return;

        Vaca vaca = vacaDao.buscarPorChave("brinco", brinco);
        if (vaca != null) {
            vacaNomeField.setText(vaca.getNome());
            vacaRacaField.setText(vaca.getRaca());
        }
    }

    @FXML
    public void editarVaca() {
        String brinco = vacaComboBox.getValue();
        if (brinco == null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Selecione uma vaca.");
            return;
        }

        String novoNome = vacaNomeField.getText();
        String novaRaca = vacaRacaField.getText();

        try {
            Vaca vacaAtualizada = new Vaca(brinco, novoNome, novaRaca);
            vacaDao.alterar("brinco", brinco, vacaAtualizada);
            mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Vaca atualizada com sucesso!");
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro ao atualizar vaca: " + e.getMessage());
        }
    }
    
    @FXML
    public void apagarVaca() {
        String brinco = vacaComboBox.getValue();
        if (brinco == null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Selecione uma vaca para apagar.");
            return;
        }

        try {
            vacaDao.deletar("brinco", brinco);
            carregarVacas(); 
            vacaNomeField.clear();
            vacaRacaField.clear();
            mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Vaca apagada com sucesso!");
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro ao apagar vaca: " + e.getMessage());
        }
    }

    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}
