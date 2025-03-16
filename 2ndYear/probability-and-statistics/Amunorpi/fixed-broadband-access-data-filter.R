library(dplyr)  # Para manipulação de dataframes (%>% e select())

# Definindo o diretório de trabalho
setwd("C:\\Users\\vieir\\Downloads\\Amunorpi")

# ===============================
# Processando: 0_Municipios_Amunorpi_e_Dados_IBGE.csv
# ===============================
Municipios_Amunorpi <- read.csv("Municipios_Amunorpi.csv", sep = ";", dec = ",")
Municipios_Amunorpi <- Municipios_Amunorpi %>%
  select("Código.IBGE.Município")  # Mantendo apenas a coluna de código IBGE

# ===============================
# Função para filtrar dados pelos municípios da Amunorpi
# ===============================
filtrar_dados <- function(arquivo_entrada, arquivo_saida) {
  df <- read.csv(arquivo_entrada, sep = ";", dec = ",")
  df_filtrado <- df %>%
    filter(Código.IBGE.Município %in% Municipios_Amunorpi$Código.IBGE.Município) %>%
    select(-"Grupo.Econômico", - "Empresa", -"CNPJ", -"Porte.da.Prestadora")
  
  write.csv(df_filtrado, file = arquivo_saida, row.names = FALSE, fileEncoding = "UTF-8")
}

# ===============================
# Processando cada arquivo
# ===============================
filtrar_dados("Acessos_Banda_Larga_Fixa_2022.csv", "Acessos_Banda_Larga_Fixa_2022_filtrado.csv")
filtrar_dados("Acessos_Banda_Larga_Fixa_2023.csv", "Acessos_Banda_Larga_Fixa_2023_filtrado.csv")
filtrar_dados("Acessos_Banda_Larga_Fixa_2024.csv", "Acessos_Banda_Larga_Fixa_2024_filtrado.csv")
filtrar_dados("Densidade_Banda_Larga_Fixa.csv", "Densidade_Banda_Larga_Fixa_filtrado.csv")

# ===============================
# Processamento concluído
# ===============================
cat("\nTodos os arquivos foram processados e salvos!\n")
