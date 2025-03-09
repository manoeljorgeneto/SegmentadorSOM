# SegmentadorSOM
* Autor: Manoel Jorge Ribeiro Neto
* e-mail: manoeljorge.neto@gmail.com
* Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.


* O **algoritmo SOM** (_Self-Organizing Map_) é um tipo de **rede neural artificial**, que utiliza **aprendizagem de
  máquina competitiva e não-supervisionada** para gerar um mapa (normalmente bidimensional), que representa um conjunto
  de dados contidos em uma dimensão maior, preservando a sua estrutura topológica, facilitando a visualização e análise
  dos mesmos (https://en.wikipedia.org/wiki/Self-organizing_map).
* Este programa implementa o SOM, permitindo a visualização do mapa treinado pelo algoritmo, a partir de um conjunto de
  dados de treinamento, por um **mapa contextual**. A biblioteca que implementa o SOM é flexível o suficiente para
  permitir o emprego de outros métodos de visualização e interpretação do SOM descritos na literatura.
* Este programa serviu como parte do trabalho de conclusão de curso (TCC) deste autor para o bacharelado em Ciência da
  Computação pela UFAL (Universidade Federal de Alagoas). Os documentos do TCC e da apresentação realizada estão
  disponíveis neste repositório.


* Pré-requisitos:
  * Utilitários básicos para desenvolvimento de _software_;
  * Bibliotecas Boost (https://www.boost.org).
    * Para instalar os pré-requisitos no Debian, Ubuntu e distros derivadas:
      * `$ sudo apt install build-essential`
      * `$ sudo apt install libboost-all-dev`


* Para compilar:
  * `$ make clean`
  * `$ make all -j$(nproc)`
    * onde `$(nproc)` é, normalmente, o número de _threads_ de seu processador.


* Uso:
  * `$ ./SegmentadorSOM [-t|--train] <arquivo_dados>` (treina informando dados)
  * `$ ./SegmentadorSOM [-t|--train] <arquivo_dados> <arquivo_configs>` (treina informando dados e configurações)
  * `$ ./SegmentadorSOM [-t|--train] <arquivo_dados> <arquivo_configs> <arquivo_arranjo>` (salva o arranjo treinado no arquivo especificado)
  * `$ ./SegmentadorSOM [-t|--train] <arquivo_dados> <arquivo_configs> <arquivo_arranjo> <arquivo_mapa>` (salva o arranjo e o mapa contextual nos arquivos especificados)
  * `$ ./SegmentadorSOM [-m|--map] <arquivo_dados>` (gera um mapa contextual, informando dados)
  * `$ ./SegmentadorSOM [-m|--map] <arquivo_dados> <arquivo_arranjo>` (gera um mapa contextual, informando dados e o arranjo treinado)
  * `$ ./SegmentadorSOM [-m|--map] <arquivo_dados> <arquivo_arranjo> <arquivo_mapa>` (informa aonde salvar o mapa contextual)
  * `$ ./SegmentadorSOM [-v|--version]` (versão do programa, simples)
  * `$ ./SegmentadorSOM [-V|--Version]` (versão do programa, verbosa)
  * `$ ./SegmentadorSOM [-?|-h|--help]` (exibe esta ajuda)
  * `$ ./SegmentadorSOM [-c|--cake]` (para ganhar um bolo)
  * `$ ./SegmentadorSOM <sem argumento>` (faz a execução padrão)


* Observações:
  * Os arquivos de dados e configurações são no formato **CSV** (_comma-separated values_);
  * O arquivo onde o arranjo de neurônios do SOM é salvo após o treinamento é do tipo binário. Se não for especificado o
    nome do arquivo, este será salvo com o nome `arr.dat`;
  * O arquivo onde o mapa contextual é salvo é do tipo texto. Se não for especificado o nome do arquivo, este será salvo
    com o nome `mapa.txt`;
  * O programa não faz nenhuma verificação de validade nos arquivos. Ou seja, ele espera que os arquivos já estejam
    corretos. Além disso, ele não verifica a existência de arquivo com mesmo nome em sua criação, sobrescrevendo o
    antigo. Lembre-se disso antes de criar ou editar os arquivos!
