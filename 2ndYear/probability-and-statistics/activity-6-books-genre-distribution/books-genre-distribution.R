########################################################################
## Script 06 - Book Genre Distribution Analysis (25/11/2024)
## Using CSV file with Top 100 Trending Books to build a bar chart
## Result exported as PNG
########################################################################

# Set working directory
setwd("C:/Users/vieir/OneDrive/Documentos/Importantes/Faculdade/02/Probabilidade e Estatistica/R/activity-6-books-genre-distribution")

# Load required libraries
library(ggplot2)
library(dplyr)

# Load dataset
dados_livros <- read.csv("Top-100_Trending_Books.csv", sep = ",", stringsAsFactors = FALSE)

# Count books by genre
dados_genero <- dados_livros %>%
  group_by(genre) %>%
  summarise(Quantidade_Livros = n()) %>%
  ungroup() %>%
  arrange(desc(Quantidade_Livros)) 

# Keep top 10 genres, group others into "Outros"
top_generos <- dados_genero %>% slice(1:10)
outros_generos <- dados_genero %>% slice(-c(1:10)) %>%
  summarise(genre = "Outros", Quantidade_Livros = sum(Quantidade_Livros))

# Merge data
dados_reduzidos <- bind_rows(top_generos, outros_generos)

# Create bar chart
grafico_genero <- ggplot(dados_reduzidos, aes(x = reorder(genre, Quantidade_Livros), y = Quantidade_Livros, fill = genre)) +
  geom_bar(stat = "identity", color = "black", alpha = 0.8) +
  coord_flip() +
  scale_fill_brewer(palette = "Set3") +
  ggtitle("Book Genre Distribution (Top 100)") +
  xlab("Genre") +
  ylab("Number of Books") +
  labs(caption = "Source: Top-100_Trending_Books.csv") +
  theme_minimal(base_size = 14) +
  theme(
    plot.title = element_text(hjust = 0.5, size = 18, face = "bold"),
    axis.text.y = element_text(size = 12),
    legend.position = "none"
  )

# Show chart
print(grafico_genero)

# Export chart as PNG
ggsave("grafico_genero.png", plot = grafico_genero, width = 12, height = 8, units = "in", dpi = 300)
