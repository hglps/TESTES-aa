void read() {
    while (1) {
        binary_tree *bt = NULL;
        char str[10000] = {0};
        int i = 0, item = 0, cont = 0, pos = 0, pointer = 0;
        char caracter;
        scanf("%d", &item);
        if (item == -1000) {
            break;
        }
        while (1) {
            scanf(" %c", &caracter);
            if (caracter != ' ') {
                str[i] = caracter;
                i++;
                if (caracter == '(') {
                    cont += 1;
                } else if (caracter == ')') {
                    cont -= 1;
                }
            }
            if (cont == 0) {
                break;
            }   
            
        }
        str[i] = '\0';
        bt = construct_binary_tree(str, &pos);
        search_sum(bt, item, 0, &pointer);
        if (pointer == 1) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }
}
