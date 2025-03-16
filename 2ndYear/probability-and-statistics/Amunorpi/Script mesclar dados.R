# Instalar pacotes se necessário
if (!require("dplyr")) install.packages("dplyr", dependencies = TRUE)
if (!require("readr")) install.packages("readr", dependencies = TRUE)

# Carregar pacotes
library(dplyr)  
library(readr)  

# Definir o diretório onde os arquivos CSV estão salvos
setwd("C:\\Users\\vieir\\Downloads\\Amunorpi")

# Listar todos os arquivos CSV na pasta
df1 <- read_csv("Acessos_Telefonia_Movel_2022_1S_filtrado.csv")
df2 <- read_csv("Acessos_Telefonia_Movel_2022_2S_filtrado.csv")
df3 <- read_csv("Acessos_Telefonia_Movel_2023_1S_filtrado.csv")
df4 <- read_csv("Acessos_Telefonia_Movel_2023_2S_filtrado.csv")
df5 <- read_csv("Acessos_Telefonia_Movel_2024_1S_filtrado.csv")
df6 <- read_csv("Acessos_Telefonia_Movel_2024_2S_filtrado.csv")


# Mesclar os arquivos
dados_combinados <- bind_rows(df1, df2, df3, df4, df5, df6)

# Salvar o dataframe mesclado em um novo arquivo CSV (opcional)
write_csv(dados_combinados, "dados_mesclados_movel.csv")

# Mensagem de conclusão
cat("Mesclagem concluída! O arquivo final foi salvo como 'dados_mesclados.csv'.\n")
