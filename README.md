# SegmentadorSOM
* Autor: Manoel Jorge Ribeiro Neto
* e-mail: manoeljorge.neto@gmail.com
* Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.


* Pré-requisitos:
  * Utilitários básicos para desenvolvimento de software;
  * Bibliotecas Boost (https://www.boost.org).
    * Para instalar os pré-requisitos, no Debian, Ubuntu e distros derivadas:
      * $ sudo apt install build-essential
      * $ sudo apt install libboost-all-dev


* Para compilar:
  * $ make clean
  * $ make all -j\<n\>
    * onde \<n\> é, normalmente, o número de threads de seu processador.


* Uso:
  * $ ./SegmentadorSOM [-t|--train] \<arquivo_dados\> (treina informando dados)
  * $ ./SegmentadorSOM [-t|--train] \<arquivo_dados\> \<arquivo_configs\> (treina informando dados e configurações)
  * $ ./SegmentadorSOM [-t|--train] \<arquivo_dados\> \<arquivo_configs\> \<arquivo_arranjo\> (salva o arranjo treinado no arquivo especificado)
  * $ ./SegmentadorSOM [-m|--map] \<arquivo_dados\> (gera um mapa contextual, informando dados)
  * $ ./SegmentadorSOM [-m|--map] \<arquivo_dados\> \<arquivo_arranjo\> (gera um mapa contextual, informando dados e o arranjo treinado)
  * $ ./SegmentadorSOM [-v|--version] (versão do programa, simples)
  * $ ./SegmentadorSOM [-V|--Version] (versão do programa, verbosa)
  * $ ./SegmentadorSOM [-?|-h|--help] (exibe esta ajuda)
  * $ ./SegmentadorSOM [-c|--cake] (para ganhar um bolo)
  * $ ./SegmentadorSOM \<sem argumento\> (faz a execução padrão)


* Observações:
  * Os arquivos de dados e configurações são no formato CSV (comma-separated values);
  * O arquivo onde o arranjo de neurônios do SOM é salvo é do tipo binário;
  * O programa não faz nenhuma verificação de validade nos arquivos. Ou seja, ele espera que os arquivos já estejam
    corretos. Além disso, ele não verifica a existência de arquivo com mesmo nome ao criar um novo, sobrescrevendo o
    antigo. Lembre-se disso antes de criar ou editar os arquivos!
