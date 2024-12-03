package com.trabalhofinal;

import org.bson.codecs.pojo.annotations.BsonProperty;

public class Usuario {
    
    @BsonProperty(value="login") 
    private String login;
    
    @BsonProperty(value="nome") 
    private String nome;
    
    @BsonProperty(value="senha") 
    private String senha;
    
    public Usuario() {
    }
    
    public Usuario(String login, String nome, String senha){
        this.login = login; 
        this.nome = nome;
        this.senha = senha;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    
}
