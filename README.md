# SegmentadorSOM
* Autor: Manoel Jorge Ribeiro Neto
* e-mail: manoeljorge.neto@gmail.com
* Programa SegmentadorSOM, que utiliza o algoritmo SOM de Kohonen.


* Para compilar:
  * $ make clean
  * $ make all -j\<n\>
  * onde \<n\> é, normalmente, o número de threads de seu processador.


* Uso:
  * $ ./SegmentadorSOM [-t|--train] \<arquivo_dados\> (treina informando dados)
  * $ ./SegmentadorSOM [-t|--train] \<arquivo_dados\> \<arquivo_configs\> (treina informando dados e configurações)
  * $ ./SegmentadorSOM [-v|--version] (versão do programa, simples)
  * $ ./SegmentadorSOM [-V|--Version] (versão do programa, verbosa)
  * $ ./SegmentadorSOM [-?|-h|--help] (exibe esta ajuda)
  * $ ./SegmentadorSOM [-c|--cake] (para ganhar um bolo)
  * $ ./SegmentadorSOM \<sem argumento\> (faz a execução padrão)


* Observações:
  * Os arquivos de dados e configurações são no formato CSV (comma-separated values);
  * O programa ainda não faz nenhuma verificação de validade nos arquivos de dados e configurações. Ou seja, ele espera
    que os arquivos já estejam corretos. Lembre-se disso antes de criar e/ou editar os arquivos!
