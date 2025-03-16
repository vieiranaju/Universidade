###########################################
### CSV Data Import Test - 07/11/2024 ###
###########################################

# Declarando uso da Biblioteca
library(dplyr)

# Carregando Dados de Monitoramento
dados_monitoramento <- read.csv("dados_monitoramento_2.csv", sep=";", dec=",")

# Dados Consolidados
dados_tabulados <- dados_monitoramento %>% group_by(weekday)
