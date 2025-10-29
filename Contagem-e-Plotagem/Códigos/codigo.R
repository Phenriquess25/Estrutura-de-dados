# ==============================================
# CÓDIGO FINAL - PARTE 1
# NÚMEROS X COMPARAÇÕES
# ==============================================
# Objetivo: comparar o número de comparações feitas
# entre duas estruturas de dados — Lista e Árvore —
# ao processar diferentes quantidades de números.
# ==============================================

# ---- Carregando as bibliotecas necessárias ----
# 'tidyverse' inclui o ggplot2 e outras ferramentas úteis
library(tidyverse)
library(ggplot2)

# ---- Lendo o conjunto de dados ----
# O arquivo 'dados.csv' deve conter, no mínimo, as colunas:
#   numero, comparacoes_lista, comparacoes_arvore
dados <- read.csv("dados.csv")

# ---- Criando o gráfico ----
# A função ggplot() inicia o gráfico com os dados e o eixo X
ggplot(dados, aes(x = numero)) +

  # Adiciona os pontos referentes às comparações da LISTA
  geom_point(aes(y = comparacoes_lista, color = "Lista")) +

  # Adiciona os pontos referentes às comparações da ÁRVORE
  geom_point(aes(y = comparacoes_arvore, color = "Árvores")) +

  # Adiciona uma linha suavizada (curva de tendência) para a LISTA
  # 'se = FALSE' desativa a faixa de erro; 'loess' ajusta suavemente os dados
  geom_smooth(
    aes(y = comparacoes_lista, color = "Lista"),
    se = FALSE, color = "black", size = 0.5, method = "loess"
  ) +

  # Adiciona uma linha suavizada para a ÁRVORE
  geom_smooth(
    aes(y = comparacoes_arvore, color = "Árvores"),
    se = FALSE, color = "black", size = 0.5, method = "loess"
  ) +

  # ---- Ajusta os rótulos e legendas ----
  labs(
    title = "Média de Comparações",
    x = "Números",  # Eixo X
    y = "Comparações: Listas vs. Árvores",  # Eixo Y
    caption = "Construção própria",  # Texto pequeno no rodapé
    color = "Estrutura de Dados"  # Título da legenda de cores
  )

# ==============================================
# Interpretação esperada:
# Cada ponto representa o número de comparações realizadas
# para um determinado tamanho de entrada (número).
# As curvas suavizadas ajudam a visualizar a tendência:
# se a estrutura é mais ou menos eficiente conforme o crescimento dos dados.
# ==============================================
