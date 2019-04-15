binary_tree *delete_node_bst(binary_tree *bt, int key)
{
    // ETAPA 1: EXECUTAR PADRÃO BST DELETE
    if (bt == NULL) {
        return bt;
    }

    // Se a chave a ser apagada é menor que a
    // chave do bt, então está na subárvore esquerda
    if (key < bt->item) {
        bt->left = delete_node_bst(bt->left, key);
    }
    // Se a chave a ser apagada for maior que a chave
    // chave do bt, então está na subárvore direita
    else if(key > bt->item) {
        bt->right = delete_node_bst(bt->right, key);
    }

    // se a chave é a mesma que a chave do bt, então
    // ele é o nó a ser deletado
    else {
        // node with only one child or no child
        if (bt->left == NULL) {
            binary_tree *temp = bt->right;
            free(bt);
            return temp;
        } else if (bt->right == NULL) {
            binary_tree *temp = bt->left;
            free(bt);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right sbtree)
        binary_tree *temp = min_value_node(bt->right);

        // Copy the inorder successor's content to this node
        bt->item = temp->item;

        // Delete the inorder successor
        bt->right = delete_node_bst(bt->right, temp->item);
    }

    // ETAPA 2: Atualizar a altura do node atual
    return bt;
}
