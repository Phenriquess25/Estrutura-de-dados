# Comparação de Desempenho entre Lista e Árvore Binária

Este projeto tem como objetivo comparar o número de **comparações** realizadas durante buscas em duas estruturas de dados diferentes — **Lista Encadeada** e **Árvore Binária de Busca (BST)** — utilizando um conjunto de números aleatórios.
Os resultados são salvos em um arquivo `.csv` e visualizados graficamente no **R**.

---

## 📁 Estrutura do Projeto

```
├── codigo.c          # Código-fonte em C que gera o arquivo CSV
├── codigo.R         # Código em R que lê o CSV e gera o gráfico
└── README.md         # Instruções de uso
```

---

## ⚙️ Parte 1 — Gerar os Dados (C)

### Pré-requisitos

* Compilador C (como `gcc`).
* Sistema operacional com suporte a linha de comando (Linux, macOS ou Windows via terminal).

### Execução

1. **Compile o código:**

   ```bash
   gcc codigo.c -o comparacao
   ```

2. **Execute o programa:**

   ```bash
   ./comparacao
   ```

3. Após a execução, o arquivo **`dados.csv`** será criado no mesmo diretório.
   Ele contém três colunas:

   | numero | comparacoes_lista | comparacoes_arvore |
   | ------ | ----------------- | ------------------ |
   | 1234   | 576               | 14                 |

---

## 📊 Parte 2 — Gerar o Gráfico (R)

### Pré-requisitos

* Ter o **R** instalado ([download aqui](https://cran.r-project.org/)).
* Ter as bibliotecas **tidyverse** e **ggplot2** instaladas.

Para instalar as bibliotecas, execute no console do R:

```r
install.packages("tidyverse")
install.packages("ggplot2")
```

### Execução

1. Certifique-se de que o arquivo `dados.csv` está no mesmo diretório do script `analise.R`.

2. Execute o script no R (ou no RStudio):

   ```r
   source("codigo.R")
   ```

3. O R irá:

   * Ler o arquivo `dados.csv`;
   * Gerar um gráfico comparando o número de comparações feitas por **Lista** e **Árvore**;
   * Exibir o gráfico na tela.

---

## 📈 Interpretação do Gráfico

* **Eixo X:** números pesquisados.
* **Eixo Y:** número de comparações realizadas.
* **Curva “Lista”:** tendência de crescimento linear.
* **Curva “Árvore”:** tendência logarítmica, refletindo maior eficiência conforme o aumento dos dados.

---

## 🧩 Observação

* O programa em C usa `rand()` e `srand(time(NULL))` para embaralhar os números, portanto cada execução gera um resultado ligeiramente diferente.
* O gráfico pode ser exportado manualmente pelo RStudio ou com a função `ggsave("grafico.png")`.

---

## ✨ Autores

Projeto acadêmico desenvolvido para fins didáticos por **[Jader Rogerio dos Santos Neto | Guilherme Nunes Alves | Carlos Antunis Bonfim de Silva Santos | Pedro Henrique Santos da Silva | Carlos Leonardo Rodrigues Novaes Carvalho]**.
Linguagens utilizadas: **C** e **R**.


