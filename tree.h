#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct Node {
	int data; // данные в узле
	struct Node * left; // левый ребенок 
	struct Node * right; // правый ребенок
} Node;

void tree_print(Node * tree, int level) {
//печать дерева
    if (tree) {
	// дерево не пустое
        tree_print(tree->left, level + 1);
        for (int i = 0; i < level; i++)
            printf("   ");
        printf("%d\n", tree->data);
        tree_print(tree->right, level + 1);
    }
}

void print(Node * tree) {
	tree_print(tree, 0);
	printf("\n");
}

Node * tree_add(Node * tree, int d) {
// добавить данные в дерево 
	// дерева нет, это первй узел
	if (tree == NULL) {
		Node * t = malloc(sizeof(Node));
		t->data = d;
		t->left = t->right = NULL;
		return t;
	}
	if (d < tree->data) {
		tree->left = tree_add(tree->left, d);
	}
	if (d > tree->data) {
		tree->right = tree_add(tree->right, d);
	}
	return tree;
}

Node * search(Node * tree, int d) {
// Если дерево пусто или ключ корня равен искомому ключу, то возвращается указатель на корень
	int i = 0;
	if ((tree == NULL) || (tree->data == d)) {
		i = i + 1;
		if (tree == NULL)
			printf("Не существует\n");
		else
			printf("Cуществует\n");
		return tree;
	}
// Поиск нужного узла
    	if (d < tree->data)
        	return search(tree->left, d);
    	else 
		return search(tree->right, d);
}	


// Функция удаления вершины дерева
Node * tree_delete(Node * tree, int d) {

  	Node *p, *p2;

  	if (!tree) {
		printf("Вершина не существует\n"); 
		return tree; /* вершина не найдена */
	}
  	if(tree->data == d) { /* удаление корня */
    /* это означает пустое дерево */
    		if(tree->left == tree->right){
      			free(tree);
      			return NULL;
    		}
    /* или если одно из поддеревьев пустое */
    		else if(tree->left == NULL) {
      			p = tree->right;
      			free(tree);
      			return p;
    		}
    		else if(tree->right == NULL) {
      			p = tree->left;
      			free(tree);
      			return p;
    		}
    /* или есть оба поддерева */
    		else {
      			p2 = tree->right;
      			p = tree->right;
      			while(p->left) 
				p = p->left;
      			p->left = tree->left;
      			free(tree);
      			return p2;
    		}
  	}	
  	if(tree->data < d) 
		tree->right = tree_delete(tree->right, d);
  	else 
		tree->left = tree_delete(tree->left, d);
  	return tree;
}
