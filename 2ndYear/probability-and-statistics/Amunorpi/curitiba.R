library(dplyr)  # Para manipulação de dataframes (%>% e select())

# Definindo o diretório de trabalho
setwd("C:\\Users\\vieir\\Downloads\\Amunorpi")

# ===============================
# Processando: 0_Municipios_Amunorpi_e_Dados_IBGE.csv
# ===============================
Municipios_Amunorpi <- read.csv("curitiba.csv", sep = ";", dec = ",")
Municipios_Amunorpi <- Municipios_Amunorpi %>%
  select("Código.IBGE.Município")  # Mantendo apenas a coluna de código IBGE

# ===============================
# Função para filtrar dados pelos municípios da Amunorpi
# ===============================
filtrar_dados <- function(arquivo_entrada, arquivo_saida) {
  df <- read.csv(arquivo_entrada, sep = ",", dec = ".")
  df_filtrado <- df %>%
    filter(Código.IBGE.Município %in% Municipios_Amunorpi$Código.IBGE.Município)
  
  write.csv(df_filtrado, file = arquivo_saida, row.names = FALSE, fileEncoding = "UTF-8")
}

# ===============================
# Processando cada arquivo
# ===============================
filtrar_dados("dados_mesclados_movel.csv", "dados_mesclados_movel_curitiba.csv")


# ===============================
# Processamento concluído
# ===============================
cat("\nTodos os arquivos foram processados e salvos!\n")