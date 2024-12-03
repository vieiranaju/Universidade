package com.trabalhofinal;

import java.time.LocalDate;

public class Producao {

    private Vaca vaca;
    private LocalDate data;
    private double quantidade;
    
    public Producao(){}

    public Producao(Vaca vaca, LocalDate data, double quantidade) {
        this.vaca = vaca;
        this.data = data;
        this.quantidade = quantidade;
    }

    public Vaca getVaca() {
        return vaca;
    }

    public void setVaca(Vaca vaca) {
        this.vaca = vaca;
    }

    public LocalDate getData() {
        return data;
    }

    public void setData(LocalDate data) {
        this.data = data;
    }

    public double getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(double quantidade) {
        this.quantidade = quantidade;
    }
    
    public String getVacaBrinco() {
        return vaca.getBrinco();  
    }
}
