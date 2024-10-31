package com.mycompany.cadastroclientes;

import java.io.IOException;
import java.util.ArrayList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class PrimaryController {

    @FXML
    private TextField nomeField;
    @FXML
    private TextField cepField;
    @FXML
    private TextField ruaField;
    @FXML
    private TextField numeroField;
    @FXML
    private TextField cidadeField;
    @FXML
    private TextField estadoField;
    @FXML
    private TextField telefoneField;
    @FXML
    private Button buscarButton;
    @FXML
    private Button limparButton;
    @FXML
    private Button gravarButton;

    private Buscador buscador = new Buscador();
    
    private ArrayList<Cliente> clientesList = new ArrayList<>();

    @FXML
    private void buscarCep() {
        String cep = cepField.getText();
        try {
            Endereco endereco = buscador.buscar(cep);
            ruaField.setText(endereco.getRua());
            cidadeField.setText(endereco.getCidade());
            estadoField.setText(endereco.getEstado());
        } catch (IllegalArgumentException e) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Formato de CEP inválido.");
        } catch (IOException e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro ao buscar o CEP: " + e.getMessage());
        } catch (Exception e) {
            mostrarAlerta(AlertType.ERROR, "Erro", "Erro desconhecido: " + e.getMessage());
        }
    }

    @FXML
    private void limparCampos() {
        nomeField.clear();
        cepField.clear();
        ruaField.clear();
        numeroField.clear();
        cidadeField.clear();
        estadoField.clear();
        telefoneField.clear();
    }

    @FXML
    private void gravarCliente() {
        Cliente cliente = new Cliente();
        cliente.setNome(nomeField.getText());
        cliente.setTelefone(telefoneField.getText());
        cliente.setEndereco(new Endereco(cepField.getText(), ruaField.getText(), numeroField.getText(), cidadeField.getText(), estadoField.getText()));
        clientesList.add(cliente);
        mostrarAlerta(AlertType.CONFIRMATION, "Confirmação", "Cliente cadastrado com sucesso!");
       
        mostrarClientes(cliente);
    }

    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }

    private void mostrarClientes(Cliente cliente) {
        System.out.println("Cliente cadastrado:");
        System.out.println("Nome: " + cliente.getNome() + 
                           ", Telefone: " + cliente.getTelefone() + 
                           ", Endereco: " + cliente.getEndereco().getRua() + 
                           ", Numero: " + cliente.getEndereco().getNumero() +
                           ", Cidade: " + cliente.getEndereco().getCidade() + 
                           ", Estado: " + cliente.getEndereco().getEstado());
    }
}
