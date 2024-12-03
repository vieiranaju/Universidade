package com.trabalhofinal;

import java.time.LocalDate;
import java.time.format.TextStyle;
import java.util.Locale;
import java.util.Map;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TextField;

import java.util.stream.Collectors;

public class VisualizarProduçãoVacaController {

    @FXML private TableView<Producao> tabelaProducao;
    @FXML private TableColumn<Producao, String> colunaProducaoVaca;
    @FXML private TableColumn<Producao, String> colunaProducaoData;
    @FXML private TableColumn<Producao, Double> colunaProducaoQuantidade;

    @FXML private ComboBox<String> comboBrincoFiltro;
    @FXML private ComboBox<String> comboMesesFiltro;
    @FXML private DatePicker dataPicker;
    @FXML private TextField campoTotalProducao; 

    private final Dao<Producao> producaoDao = new Dao<>(Producao.class);
    private final Dao<Vaca> vacaDao = new Dao<>(Vaca.class);

    public void AbrirMenu() throws Exception {
        App.setRoot("Menu");
    }

    public void initialize() {
        configurarTabela();
        carregarDados();
        carregarComboBrinco();
        carregarComboMes();
    }

    private void configurarTabela() {
        colunaProducaoVaca.setCellValueFactory(new PropertyValueFactory<>("vacaBrinco"));
        colunaProducaoData.setCellValueFactory(new PropertyValueFactory<>("data"));
        colunaProducaoQuantidade.setCellValueFactory(new PropertyValueFactory<>("quantidade"));
    }

    private void carregarDados() {
        ObservableList<Producao> producoes = FXCollections.observableArrayList(producaoDao.listarTodos());
        tabelaProducao.setItems(producoes);
        atualizarTotalProducao(producoes);
    }

    private void carregarComboBrinco() {
        ObservableList<String> brincos = FXCollections.observableArrayList(
            vacaDao.listarTodos().stream()
                .map(Vaca::getBrinco)
                .collect(Collectors.toList())
        );
        comboBrincoFiltro.setItems(brincos);
    }

    private void carregarComboMes() {
        ObservableList<String> meses = FXCollections.observableArrayList(
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
        );
        comboMesesFiltro.setItems(meses);
    }

    @FXML
    public void filtrarProducoesPorVaca() {
        String brincoSelecionado = comboBrincoFiltro.getValue();

        if (brincoSelecionado == null || brincoSelecionado.isEmpty()) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Selecione um brinco para filtrar.");
            return;
        }

        ObservableList<Producao> producoesFiltradas = FXCollections.observableArrayList(
            producaoDao.listarTodos().stream()
                .filter(producao -> producao.getVacaBrinco() != null && producao.getVacaBrinco().equalsIgnoreCase(brincoSelecionado))
                .collect(Collectors.toList())
        );

        if (producoesFiltradas.isEmpty()) {
            mostrarAlerta(AlertType.INFORMATION, "Informação", "Nenhuma produção encontrada para o brinco selecionado.");
        }

        tabelaProducao.setItems(producoesFiltradas);
        atualizarTotalProducao(producoesFiltradas);
    }

    @FXML
    public void filtrarProducoesPorPeriodo() {
        LocalDate data = dataPicker.getValue();

        if (data == null) {
            mostrarAlerta(AlertType.WARNING, "Aviso", "Preencha o campo de data.");
            return;
        }

        ObservableList<Producao> producoesFiltradas = FXCollections.observableArrayList(
            producaoDao.listarTodos().stream()
                .filter(producao -> producao.getData() != null && producao.getData().equals(data))
                .collect(Collectors.toList())
        );

        if (producoesFiltradas.isEmpty()) {
            mostrarAlerta(AlertType.INFORMATION, "Informação", "Nenhuma produção encontrada para o período.");
        }

        tabelaProducao.setItems(producoesFiltradas);
        atualizarTotalProducao(producoesFiltradas);
    }

    @FXML
    public void filtrarProducoesPorMes() {
        String mesSelecionado = comboMesesFiltro.getValue();

        if (mesSelecionado == null) {
            mostrarAlerta(AlertType.WARNING, "Atenção", "Selecione um mês para filtrar.");
            return;
        }

        ObservableList<Producao> producoesFiltradas = FXCollections.observableArrayList(
            producaoDao.listarTodos().stream()
                .filter(producao -> {
                    if (producao.getData() != null) {
                        LocalDate dataProducao = producao.getData();
                        String mesProducao = dataProducao.getMonth().getDisplayName(TextStyle.FULL, Locale.getDefault());
                        return mesProducao.equalsIgnoreCase(mesSelecionado);
                    }
                    return false;
                })
                .collect(Collectors.toList())
        );

        if (producoesFiltradas.isEmpty()) {
            mostrarAlerta(AlertType.INFORMATION, "Informação", "Nenhuma produção encontrada para o mês selecionado.");
        }

        tabelaProducao.setItems(producoesFiltradas);
        atualizarTotalProducao(producoesFiltradas);
    }

    @FXML
    public void mostrarTodasProducoes() {
        carregarDados();
    }

    private void atualizarTotalProducao(ObservableList<Producao> producoes) {
        double total = producoes.stream()
            .mapToDouble(Producao::getQuantidade)
            .sum();
        campoTotalProducao.setText(String.format("%.2f", total));
    }
    
    @FXML
    public void filtrarProducoesPorVacaEMes() {
        String mesSelecionado = comboMesesFiltro.getValue();
        String brincoSelecionado = comboBrincoFiltro.getValue();

        if (mesSelecionado == null || mesSelecionado.isEmpty()) {
            mostrarAlerta(AlertType.WARNING, "Atenção", "Selecione um mês para filtrar.");
            return;
        }

        if (brincoSelecionado == null || brincoSelecionado.isEmpty()) {
            mostrarAlerta(AlertType.WARNING, "Atenção", "Selecione um brinco para filtrar.");
            return;
        }

        ObservableList<Producao> producoesFiltradas = FXCollections.observableArrayList(
            producaoDao.listarTodos().stream()
                .filter(producao -> {
                    if (producao.getVacaBrinco() != null && producao.getData() != null) {
                        LocalDate dataProducao = producao.getData();
                        String mesProducao = dataProducao.getMonth().getDisplayName(TextStyle.FULL, Locale.getDefault());
                        return producao.getVacaBrinco().equalsIgnoreCase(brincoSelecionado) &&
                               mesProducao.equalsIgnoreCase(mesSelecionado);
                    }
                    return false;
                })
                .collect(Collectors.toList())
        );

        if (producoesFiltradas.isEmpty()) {
            mostrarAlerta(AlertType.INFORMATION, "Informação", "Nenhuma produção encontrada para a vaca e mês selecionados.");
        }

        tabelaProducao.setItems(producoesFiltradas);
        atualizarTotalProducao(producoesFiltradas);
    }

    private void mostrarAlerta(AlertType tipo, String titulo, String mensagem) {
        Alert alert = new Alert(tipo);
        alert.setTitle(titulo);
        alert.setHeaderText(null);
        alert.setContentText(mensagem);
        alert.showAndWait();
    }
}
