# Sculptor 3D - C++

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-3D%20Graphics%20%7C%20Voxels-orange)

Um projeto orientado a objetos desenvolvido em **C++** para a criação de esculturas tridimensionais representadas por matrizes virtuais de *voxels* (elementos de volume em 3D), permitindo exportar o resultado para visualização em softwares de modelagem 3D (formato `.off`).

---

## 📌 Sobre o Projeto

Este programa permite desenhar e manipular geometrias e cores em um espaço tridimensional programável. Cada célula da matriz representa um **Voxel** (um pixel tridimensional), contendo propriedades de transparência (canal alpha) e cor (RGB).

Através da classe gerenciadora `Sculptor`, é possível desenhar formas geométricas primitivas, tais como:
* Cubos e blocos (`putBox` / `cutBox`)
* Esferas (`putSphere` / `cutSphere`)
* Elipsoides (`putEllipsoid` / `cutEllipsoid`)
* Voxels individuais (`putVoxel` / `cutVoxel`)

Ao final da execução das operações, o programa gera um arquivo `.off` que pode ser visualizado em softwares como o **Geomview** ou **MeshLab**.

---

## ⚙️ Estrutura de Dados

### Estrutura Voxel
Cada elemento da matriz 3D é composto pela seguinte estrutura:

```cpp
struct Voxel {
  float r, g, b; // Cores: Vermelho, Verde e Azul [0.0 a 1.0]
  float a;       // Transparência (Alpha)
  bool show;     // Estado: Incluído (true) ou Desativado (false)
};
```

---

## 🚀 Funcionalidades Principais

* **Alocação Dinâmica 3D:** Criação flexível de matrizes de tamanho $N_x \times N_y \times N_z$.
* **Definição de Cor:** Aplicação de cores RGBA personalizadas para os próximos elementos adicionados.
* **Adição e Remoção de Formas:**
  * **Voxel:** Inclusão/remoção pontual.
  * **Box:** Criação de paralelepípedos e remoção de regiões em bloco.
  * **Sphere:** Geração de esferas perfeitas a partir de centro e raio.
  * **Ellipsoid:** Geração de elipsoides com raios independentes nos eixos $X, Y, Z$.
* **Exportação `.off`:** Algoritmo automatizado que mapeia os voxels visíveis e exporta vértices e faces no padrão OFF.

---

## 📁 Como Executar

### Pré-requisitos
* Compilador C++ (g++, clang ou similar compatível com C++11 ou superior).
* [MeshLab](https://www.meshlab.net/) ou [Geomview](http://www.geomview.org/) (para visualização dos arquivos gerados).

### Compilação e Execução

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/seu-usuario/sculptor-3d.git
   cd sculptor-3d
   ```

2. **Compile o código-fonte:**
   ```bash
   g++ -std=c++11 main.cpp Sculptor.cpp -o sculptor
   ```

3. **Execute o programa:**
   ```bash
   ./sculptor
   ```

4. O arquivo `sculpture.off` (ou o nome definido no código) será gerado no diretório atual. Abra-o no **MeshLab** para visualizar sua escultura 3D!

---

## 💻 Exemplo de Uso

```cpp
#include "Sculptor.h"

int main() {
    // Cria um espaço de trabalho 3D de 50x50x50 voxels
    Sculptor sculptor(50, 50, 50);

    // Define a cor vermelha opaca (R, G, B, Alpha)
    sculptor.setColor(1.0, 0.0, 0.0, 1.0);
    
    // Desenha um bloco base
    sculptor.putBox(10, 40, 10, 40, 10, 15);

    // Define a cor azul
    sculptor.setColor(0.0, 0.0, 1.0, 1.0);

    // Desenha uma esfera no centro
    sculptor.putSphere(25, 25, 30, 10);

    // Grava a escultura no formato OFF
    sculptor.writeOFF("sculpture.off");

    return 0;
}
```

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++
* **Paradigma:** Programação Orientada a Objetos (POO)
* **Gerenciamento de Memória:** Alocação dinâmica de ponteiros (`new` / `delete`)

---

## 📄 Licença

Este projeto está sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.
