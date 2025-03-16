library(dplyr)

# Define o diretório de trabalho
setwd("C:\\Users\\vieir\\Downloads\\Amunorpi")

# ===============================
# Carregando os municípios da Amunorpi
# ===============================
Municipios_Amunorpi <- read.csv("Municipios_Amunorpi_e_Curitiba.csv", sep = ";", dec = ",")
Municipios_Amunorpi <- Municipios_Amunorpi %>% select(Código.IBGE.Município)

# ===============================
# Função para filtrar dados
# ===============================
filtrar_dados <- function(arquivo_entrada, arquivo_saida) {
  df <- read.csv(arquivo_entrada, sep = ";", dec = ",")
  
  # Verifica se a coluna "Código.IBGE.Município" existe antes de continuar
  if (!"Código.IBGE.Município" %in% colnames(df)) {
    stop(paste("Erro: Coluna 'Código.IBGE.Município' não encontrada no arquivo", arquivo_entrada))
  }
  
  df_filtrado <- df %>%
    filter(Código.IBGE.Município %in% Municipios_Amunorpi$Código.IBGE.Município) %>%
    select(-c(Grupo.Econômico, Empresa, CNPJ, Porte.da.Prestadora))
  
  write.csv(df_filtrado, file = arquivo_saida, row.names = FALSE, fileEncoding = "UTF-8")
}

# ===============================
# Lista de arquivos
# ===============================

filtrar_dados("Acessos_Telefonia_Movel_2022_1S.csv", "Acessos_Telefonia_Movel_2022_1S_filtrado.csv")
filtrar_dados("Acessos_Telefonia_Movel_2022_2S.csv", "Acessos_Telefonia_Movel_2022_2S_filtrado.csv")
filtrar_dados("Acessos_Telefonia_Movel_2023_1S.csv", "Acessos_Telefonia_Movel_2023_1S.csv_filtrado.csv")
filtrar_dados("Acessos_Telefonia_Movel_2023_2S.csv", "Acessos_Telefonia_Movel_2023_2S_filtrado.csv")
filtrar_dados("Acessos_Telefonia_Movel_2024_1S.csv", "Acessos_Telefonia_Movel_2024_1S_1S.csv_filtrado.csv")
filtrar_dados("Acessos_Telefonia_Movel_2024_2S.csv", "Acessos_Telefonia_Movel_2024_2S_filtrado.csv")

# ===============================
# Processamento concluído
# ===============================
cat("\nTodos os arquivos foram processados e salvos!\n")
