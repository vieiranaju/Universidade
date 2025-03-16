library(dplyr)  

# Definindo o diretório de trabalho
setwd("C:\\Users\\vieir\\Downloads\\Amunorpi")

# ===============================
# Carregando os dados principais (dados_mesclados)
# ===============================
dados_mesclados <- read.csv("dados_mesclados_top4.csv", sep = ",", dec = ".")

# ===============================
# Carregando os dados de Municípios (Top4.csv)
# ===============================
Municipios_Amunorpi <- read.csv("Top4.csv", sep = ";", dec = ",", stringsAsFactors = FALSE)


# ===============================
# Mesclando os dados
# ===============================
dados_final <- dados_mesclados %>%
  left_join(Municipios_Amunorpi, by = "Código.IBGE.Município")  # Adiciona os dados do Top4 sem remover nada do principal

# ===============================
# Salvando os dados mesclados
# ===============================
write.csv(dados_final, "dados_mesclados_top4.csv", row.names = FALSE, fileEncoding = "UTF-8")

# Mensagem de conclusão
cat("\nMesclagem concluída! Dados de Top4 adicionados aos dados mesclados.\n")
