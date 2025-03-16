########################################################################
## Script 03 - Internet Consumption by Weekday - Frequency Table and Chart
## Based on 168 sample data loaded from CSV (18/11/2024)
## Results exported as CSV and PNG
########################################################################

# Set working directory
setwd("~/Importantes/Faculdade/02/Probabilidade e Estatistica/R/activity-3-weekday-internet-consumption")

# Load required libraries
library(dplyr)
library(ggplot2)

# Load the dataset
dados <- read.csv("dados_monitoramento_x.csv", sep = ";", dec = ",")

# Define the order of weekdays
levels_weekdays <- c("sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday")

# Convert weekday column to ordered factor
dados$weekday <- factor(dados$weekday, levels = levels_weekdays)

# Group data by weekday and calculate total Mbits per day
tabela_frequencia <- dados %>%
  group_by(weekday) %>%
  summarise(total_mbits = sum(mbits))

# Show frequency table
print(tabela_frequencia)

# Export frequency table to CSV
write.table(tabela_frequencia, file = "script3_tbf_Mbits_Semana.csv", sep = ";", dec = ",", na = "", quote = TRUE, row.names = FALSE)

# Create bar chart
grafico_barras <- ggplot(tabela_frequencia, aes(x = weekday, y = total_mbits)) +
  geom_bar(stat = "identity", fill = "skyblue", color = "blue") +
  ggtitle("Internet Consumption by Weekday") +
  xlab("Weekday") +
  ylab("Total Mbits") +
  labs(caption = "Source: Author") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, hjust = 1))

# Show chart
print(grafico_barras)

# Export bar chart to PNG
ggsave("script3_grf_Mbits_Semana.png", plot = grafico_barras, width = 10, height = 6, units = "in", dpi = 300)
