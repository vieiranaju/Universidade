package com.trabalhofinal;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;

import java.util.stream.Collectors;

public class VisualizarVacasController {

    @FXML private TableView<Vaca> tabelaVacas;
    @FXML private TableColumn<Vaca, String> colunaVacaNome;
    @FXML private TableColumn<Vaca, String> colunaVacaBrinco;
    @FXML private TableColumn<Vaca, String> colunaVacaRaca;
    
    @FXML private ComboBox<String> comboRacaFiltro;
    
    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }

    private final Dao<Vaca> vacaDao = new Dao<>(Vaca.class);

    public void initialize() {
        configurarTabela();
        carregarDados(); 
    }

    private void configurarTabela() {
        colunaVacaNome.setCellValueFactory(new PropertyValueFactory<>("nome"));
        colunaVacaBrinco.setCellValueFactory(new PropertyValueFactory<>("brinco"));
        colunaVacaRaca.setCellValueFactory(new PropertyValueFactory<>("raca"));
    }

    private void carregarDados() {
        ObservableList<Vaca> vacas = FXCollections.observableArrayList(vacaDao.listarTodos());
        tabelaVacas.setItems(vacas);

        ObservableList<String> racas = FXCollections.observableArrayList(
            vacas.stream().map(Vaca::getRaca).distinct().collect(Collectors.toList())
        );
        comboRacaFiltro.setItems(racas);
    }

    @FXML
    public void filtrarPorRaca() {
        String racaSelecionada = comboRacaFiltro.getValue();
        if (racaSelecionada == null || racaSelecionada.isEmpty()) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Selecione uma raça para filtrar.");
            return;
        }

        ObservableList<Vaca> vacasFiltradas = FXCollections.observableArrayList(
            vacaDao.listarTodos().stream()
                .filter(vaca -> vaca.getRaca().equalsIgnoreCase(racaSelecionada))
                .collect(Collectors.toList())
        );

        if (vacasFiltradas.isEmpty()) {
            mostrarAlerta(AlertType.INFORMATION, "Informação", "Nenhuma vaca encontrada para essa raça.");
        }

        tabelaVacas.setItems(vacasFiltradas);
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
