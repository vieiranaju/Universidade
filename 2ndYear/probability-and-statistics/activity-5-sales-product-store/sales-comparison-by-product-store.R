########################################################################
## Script 05 - Sales Comparison by Product and Store (25/11/2024)
## Using CSV file with sales data to build a grouped bar chart
## Result exported as PNG
########################################################################

# Set working directory
setwd("C:/Users/vieir/OneDrive/Documentos/Importantes/Faculdade/02/Probabilidade e Estatistica/R/activity-5-sales-product-store")

# Load required libraries
library(ggplot2)
library(dplyr)
library(tidyr)

# Load dataset
dados_vendas <- read.csv("BaseVendas.csv", sep = ",")

# Group data by Product and Store, summing total quantity sold
dados_agrupados <- dados_vendas %>%
  group_by(Produto, Loja) %>%
  summarise(Quantidade_Total = sum(Quantidade.Vendida, na.rm = TRUE)) %>%
  ungroup()

# Create grouped bar chart
grafico_produto_loja <- ggplot(dados_agrupados, aes(x = Produto, y = Quantidade_Total, fill = Loja)) +
  geom_bar(stat = "identity", position = position_dodge(), color = "black", alpha = 0.8) +
  scale_fill_brewer(palette = "Paired") +
  ggtitle("Sales Comparison by Product and Store") +
  xlab("Product") +
  ylab("Quantity Sold") +
  labs(caption = "Source: BaseVendas.csv") +
  theme_minimal(base_size = 14) +
  theme(
    plot.title = element_text(hjust = 0.5, size = 18, face = "bold"),
    axis.text.x = element_text(angle = 45, hjust = 1),
    legend.title = element_text(face = "bold"),
    legend.position = "top"
  )

# Show chart
print(grafico_produto_loja)

# Export chart as PNG
ggsave("grafico_produto_loja.png", plot = grafico_produto_loja, width = 12, height = 8, units = "in", dpi = 300)
