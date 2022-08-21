#include "tree.h"

int main() {
	
	int test_data[100];

	//чтение данных из файла
	FILE *fp;
	char name[] = "TestForTree.txt";
	if ((fp = fopen(name, "r")) == NULL) {
		printf("Не удалось открыть файл");
    		getchar();
    		return 1;
  	}
	int i = 0;
	while(!feof(fp)) {
		fscanf(fp, "%d", &test_data[i]);
		i = i + 1;
	}

	fclose(fp);
	getchar();

	Node * tree = NULL;
	print(tree);
	
	printf("Последовательно строим дерево\n");
	for (size_t k = 0; k < i; k++) {
		tree = tree_add(tree, test_data[k]);
		print(tree);
	}

	printf("Добавляем в дерево вершину 10\n");
	tree = tree_add(tree, 10);
	print(tree);
	
	printf("Добавляем в дерево вершину 20\n");
	tree = tree_add(tree, 20);
	print(tree);

	printf("Проверим, существует ли данная вершина:\n");
	search(tree, 20);

	printf("Удалим элемент из дерева\n");
	tree_delete(tree, 20);
	print(tree);

	
	return 0;
}
