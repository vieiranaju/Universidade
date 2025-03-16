########################################################################
## Script 04 - Student Grades by Class - Boxplot Visualization
## Based on 70 sample data distributed across 5 classes (18/11/2024)
## Result exported as PNG
########################################################################

# Set working directory
setwd("~/Importantes/Faculdade/02/Probabilidade e Estatistica/R/activity-4-boxplot-student-grades")

# Load required libraries
library(ggplot2)
library(tidyr)
library(dplyr)

# Load dataset
dados <- read.csv("Notas_Alunos_Turmas.csv", sep = ";")

# Convert data from wide to long format
dados_long <- pivot_longer(dados, cols = everything(), names_to = "Turma", values_to = "Notas", values_drop_na = TRUE)

# Calculate mean and median per class
media_mediana <- dados_long %>%
  group_by(Turma) %>%
  summarise(
    media = mean(Notas, na.rm = TRUE),
    mediana = median(Notas, na.rm = TRUE)
  )

# Create boxplot with extra visual indicators
grafico_boxplot <- ggplot(dados_long, aes(x = Turma, y = Notas, fill = Turma)) +
  geom_boxplot(outlier.color = "darkred", outlier.size = 3, alpha = 0.7) +
  geom_point(data = media_mediana, aes(y = media), color = "darkorange", size = 4, shape = 17) +
  geom_point(data = media_mediana, aes(y = mediana), color = "darkgreen", size = 4, shape = 16) +
  geom_text(data = media_mediana, aes(y = media, label = sprintf("Mean: %.2f", media)), 
            vjust = -0.8, color = "darkorange", size = 3.5, fontface = "bold") +
  geom_text(data = media_mediana, aes(y = mediana, label = sprintf("Median: %.2f", mediana)), 
            vjust = 1.2, color = "darkgreen", size = 3.5, fontface = "bold") +
  scale_fill_brewer(palette = "Set2") +
  ggtitle("Student Grades Comparison by Class") +
  xlab("Class") +
  ylab("Grades") +
  labs(caption = "Source: Professor Fernando Legore") +
  theme_minimal(base_size = 14) +
  theme(
    plot.title = element_text(hjust = 0.5, size = 18, face = "bold"),
    axis.text.x = element_text(angle = 45, hjust = 1),
    legend.position = "none",
    panel.grid.major = element_line(color = "gray80"),
    panel.grid.minor = element_blank()
  )

# Show boxplot
print(grafico_boxplot)

# Export plot as PNG
ggsave("grafico_boxplot_notas_turmas.png", plot = grafico_boxplot, width = 10, height = 6, units = "in", dpi = 300)
