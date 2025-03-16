########################################################################
## Script 02 - Frequency Table and Bar Chart by Age Group (11/11/2024)
## Generates 200 random ages and builds a frequency table (CSV) and bar chart (PNG)
########################################################################

# Load ggplot2 library
library(ggplot2)

# Generate random sample of ages between 12 and 68
set.seed(123) # For reproducibility
idades <- sample(12:68, 200, replace = TRUE)

# Create age intervals of 10 years
breaks <- seq(10, 70, by = 10)
labels <- paste(breaks[-length(breaks)], breaks[-1] - 1, sep = "-")

# Categorize ages into intervals
idade_categorias <- cut(idades, breaks = breaks, labels = labels, right = FALSE)

# Generate frequency table
tabela_frequencia <- table(idade_categorias)

# Convert table to dataframe
df_frequencia <- as.data.frame(tabela_frequencia)
colnames(df_frequencia) <- c("Age.Group", "Frequency")

# Print frequency table
print(df_frequencia)

# Create bar chart
grafico_barras <- ggplot(df_frequencia, aes(x = Age.Group, y = Frequency)) +
  geom_bar(stat = "identity", fill = "skyblue", color = "black") +
  ggtitle("Bar Chart of Frequency by Age Group") +
  xlab("Age Group") +
  ylab("Frequency") +
  labs(caption = "Source: Author") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, hjust = 1))

# Display chart
print(grafico_barras)

# Export frequency table to CSV
write.table(df_frequencia, file = "script2_age_frequency_table.csv", sep=";", dec=",", na="", quote=TRUE, row.names=FALSE)

# Export chart to PNG
ggsave("script2_age_frequency_chart.png", plot = grafico_barras, width = 10, height = 6, units = "in", dpi = 300)
