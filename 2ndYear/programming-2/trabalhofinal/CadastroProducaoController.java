package com.trabalhofinal;

import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TextField;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import java.time.LocalDate;

public class CadastroProducaoController {

    @FXML private ComboBox<String> vacaComboBox;
    @FXML private DatePicker dataDatePicker;
    @FXML private TextField quantidadeTextField;

    private final Dao<Vaca> vacaDao = new Dao<>(Vaca.class);
    private final Dao<Producao> producaoDao = new Dao<>(Producao.class);
    
    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }

    public void initialize() {
        carregarVacas();
    }

    private void carregarVacas() {
        vacaComboBox.getItems().clear();
        vacaDao.listarTodos().forEach(vaca -> vacaComboBox.getItems().add(vaca.getBrinco()));
    }

    @FXML
    public void gravarProducao() {
        String brincoVaca = vacaComboBox.getValue();
        LocalDate data = dataDatePicker.getValue();
        String quantidadeStr = quantidadeTextField.getText();

        if (brincoVaca == null || data == null || quantidadeStr.isEmpty()) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Preencha todos os campos.");
            return;
        }

        try {
            double quantidade = Double.parseDouble(quantidadeStr);
            Vaca vaca = vacaDao.buscarPorChave("brinco", brincoVaca);
            if (vaca == null) {
                mostrarAlerta(AlertType.ERROR, "Erro", "Vaca não encontrada.");
                return;
            }

            Producao producao = new Producao(vaca, data, quantidade);
            producaoDao.inserir(producao);

            mostrarAlerta(AlertType.INFORMATION, "Sucesso", "Produção cadastrada com sucesso!");
            limparCampos();

        } catch (NumberFormatException e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Quantidade inválida.");
        }
    }

    @FXML
    public void cancelarCadastro() {
        limparCampos();
    }

    private void limparCampos() {
        vacaComboBox.setValue(null);
        dataDatePicker.setValue(null);
        quantidadeTextField.clear();
    }

    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}
