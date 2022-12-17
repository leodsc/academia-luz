#include <stdio.h>
#include <stdlib.h>
#include "lib/utils.h"
#include "lib/colors.h"

void binarySearchTreeMenu() {
  int choice;
  int defaultNodes[15] = {
    25, 15, 50, 10, 22, 4, 12, 18, 24, 35, 70, 31, 44, 66, 90
  };
  Tree *tree = createBinarySearchTree();

  do {
    puts(blue_bg("Qual operação deseja fazer?"));
    puts("1 - Inserir nó");
    puts("2 - Mostrar Arvóre");
    puts("3 - Procurar por valor");
    puts("4 - Remover nó");
    puts("5 - Contruir árvore");
    puts("6 - Excluir todos os nós");
    puts("0 - Voltar");

    int value;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        puts("Qual o valor do novo nó?");
        scanf("%d", &value);
        insertTreeNode(tree, value);
        printf("Valor %d adicionado!\n", value);
        break;
      case 2:
        int order;
        puts("Qual algoritmo de travessia deseja usar?");
        puts("1 - Pré-ordem");
        puts("2 - Ordem");
        puts("3 - Pós-ordem");
        scanf("%d", &order);
        
        if (tree->root != NULL) {
        if (order == 1) {
          preOrder(tree->root);
        } else if (order == 2) {
          showTreeOrder(tree->root);
        } else {
          posOrder(tree->root);
        }
        }
        puts("");
        break;
      case 3:
        puts("Qual o valor que você deseja procurar?");
        scanf("%d", &value);
        TreeNode *node = searchSpecificValue(tree->root, value);
        if (node != NULL) {
          printf(green_fg("Valor encontrado: %d\n"), node->value);
        } else {
          puts(red_bg("Valor não encontrado!"));
        }
        break;
      case 4:
        puts("Qual valor deseja remover?");
        scanf("%d", &value);
        TreeNode* removedNode = removeNodeFromTree(tree, value);
        if (removedNode != NULL) {
          printf("Valor %d foi removido!\n", value);
        } else {
          puts("Valor não existe");
        }
        
        break;
      case 5:
        for (int i = 0; i < 15; i++) {
          insertTreeNode(tree, defaultNodes[i]);
        }
        puts("Árvore contruída");
        break;
      case 6:
        eraseAllNodesFromTree(tree);
        puts("Árvore excluída");
        break;
    }

  } while (choice != 0);
}

void stackMenu() {
  int choice;
  Stack *s = createStack();

  do {
    puts("Qual operação deseja fazer?");
    puts("1 - Adicionar um valor");
    puts("2 - Remover último valor");
    puts("3 - Ver array");
    puts("4 - Ver topo");
    puts("5 - Voltar");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        int value;
        puts("Digite um valor: ");
        scanf("%d", &value);
        push(s, value);
        break;
      case 2:
        if (s->size > 1) {
          int v = pop(s);
          printf("Valor removido: %d\n", v);
        } else {
          puts(red_bg("Stack está vazia!"));
        }
        break;
      case 3:
        showStack(s);
        break;
      case 4:
        Node *node = top(s);
        if (node == NULL) {
          puts(red_bg("Stack está vazia!"));
        } else {
          printf("Valor no topo é: %d\n", node->value);
        }
        break;
    }
    
  } while (choice != 5);
}

void queueMenu() {
  int choice;
  Queue q = queue();
  do {
    puts("Qual operação deseja fazer?");
    puts("1 - Adicionar um valor");
    puts("2 - Remover primeiro valor");
    puts("3 - Ver array");
    puts("4 - Ver primeiro elemento");
    puts("5 - Voltar");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        int value;
        puts("Digite um valor: ");
        scanf("%d", &value);
        enqueue(&q, value);
        break;
      case 2:
        int head = first(&q);
        Node *node = dequeue(&q);
        if (node != NULL) {
          printf("Elemento %d foi excluído!\n", head);
        } else {
          puts("Fila está vazia!");
        }
        break;
      case 3:
        showQueue(&q);
        break;
      case 4:
        printf("O primeiro elemento é: %d\n", first(&q));
        break;
    }

  } while (choice != 5);
}

void linkedListMenu() {
  int choice;
  LinkedList l = linkedList();
  do {
    puts("Qual operação deseja fazer?");
    puts("1 - Adicionar um valor");
    puts("2 - Remover o primeiro valor");
    puts("3 - Remover um valor");
    puts("4 - Ver linked list");
    puts("5 - Ver elemento");
    puts("6 - Ver posição");
    puts("7 - Adicionar na posição");
    puts("0 - Sair");

    scanf("%d", &choice);

    int value;
    switch(choice) {
      case 1:
        puts("Digite um valor: ");
        scanf("%d", &value);
        addLinkedList(&l, value);
        break;
      case 2:
        value = removeFromPositionLinkedList(&l, 0);
        printf("Valor %d foi removido\n", value);
        break;
      case 3:
        puts("Digite a posição (inicio em 0): ");
        scanf("%d", &value);
        value = removeFromPositionLinkedList(&l, value);
        printf("%d, \n", value);
        break;
      case 4:
        showLinkedList(&l);
        break;
      case 5:
        puts("Digite o valor que deseja procurar: ");
        scanf("%d", &value);
        int position = getElementFromLinkedList(&l, value);
        if (position != -1) {
          printf("Elemento está na posição %d\n", position);
        } else {
          puts("Elemento não está na lista encadeada");
        }
        break;
      case 6:
        puts("Digite a posição (inicio em 0): ");
        scanf("%d", &value);
        Node* item = getPosition(&l, value);
        if (item != NULL) {
          printf("O valor é: %d\n", item->value);
        } else {
          puts("Essa posição está vazia dentro da lista!");
        }
        break;
      case 7:
        // fixme
        int pos;
        puts("Digite a posição (inicio em 0): ");
        scanf("%d", &pos);
        puts("Digite o valor: ");
        scanf("%d", &value);
        addAtLinkedList(&l, value, pos);
        break;
    }

  } while (choice != 0);
}

void menu() {
  int choice;
  do {
    puts("Digite qual estrutura de dados quer testar:");
    puts("1 - Stack");
    puts("2 - Queue");
    puts("3 - Linked list");
    puts("4 - Binary Search Tree (BTS)");
    puts("0 - Sair");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        stackMenu(); break;
      case 2:
        queueMenu(); break;
      case 3:
        linkedListMenu(); break;
      case 4:
        binarySearchTreeMenu(); break;
    }
  } while (choice != 0);

  puts("Fechando programa...");
}

int main() {
  menu();
  return 0;
}
