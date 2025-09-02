    # 42 C++ Module 01 — ex04: Sed is for losers

    Programme qui lit un fichier et produit `<filename>.replace` où toutes les occurrences de `s1`
    sont remplacées par `s2` (sans regex).

    ## Usage
    ```bash
    ./sed_is_for_losers <filename> <s1> <s2>
    ```

    > Remarque: `s1` ne peut pas être vide (sinon il n'y a rien à remplacer).

    ## Compilation
    ```bash
    make
    ```

    ## Test rapide
    ```bash
    echo -e "hello
hello world" > input.txt
    ./sed_is_for_losers input.txt hello bonjour
    cat input.txt.replace
    # -> "bonjour"
    # -> "bonjour world"
    ```

    ## Arborescence
    ```
    ex04/
    ├── Makefile
    └── src
        └── main.cpp
    ```
