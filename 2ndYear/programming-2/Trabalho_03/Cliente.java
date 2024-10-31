package com.mycompany.cadastroclientes;

public class Cliente {
    private static int contadorCodigo = 0; 
    private int codigo;
    private String nome;
    private Endereco endereco;
    private String telefone;

    public Cliente() {
        this.codigo = ++contadorCodigo; 
        this.nome = "";
        this.endereco = null;
        this.telefone = "";
    }
    
    public Cliente(String nome, Endereco endereco, String telefone) {
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.codigo = ++contadorCodigo;
    }

    // Getters
    public int getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public String getTelefone() {
        return telefone;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "codigo=" + codigo +
                ", nome='" + nome + '\'' +
                ", endereco=" + endereco +
                ", telefone='" + telefone + '\'' +
                '}';
    }
}

