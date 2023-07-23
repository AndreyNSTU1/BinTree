#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


// Удалить из дерева вершины, значениями которых являются простые числа.

typedef struct BinTree // Создание структуры бинарного дерева
{
    int data;
    struct BinTree* right;
    struct BinTree* left;
} BinTree;



BinTree* NewTree(int data_element) // Создание нового бинарного дерева
{
    BinTree* NewTree =(BinTree*) malloc(sizeof(BinTree));
    NewTree->data = data_element;
    NewTree->right = NULL;
    NewTree->left = NULL;
    return NewTree;
}

void Print(BinTree* Tree) // Вывод бинарного дерева
{
    if (Tree != NULL)
    {
        if (Tree->left != NULL)
            Print(Tree->left);
        printf("%d\n", Tree->data);
        if (Tree->right != NULL)
            Print(Tree->right);
    }
}

BinTree* add_right_tree(BinTree* Tree, BinTree* Tree_right) // Добавление правой ветви.
{
    if (Tree->right != NULL) // Поиск последнего значения в правой ветви основного дерева.
        add_right_tree(Tree->right, Tree_right);
    else
        Tree->right = Tree_right; // Добавление ветви в правую ветвь основного дерева.
    return Tree;
}

BinTree* add_left_tree(BinTree* Tree, BinTree* Tree_left) // Добавление левой ветви.
{
    if (Tree->left != NULL) // Поиск последнего значения в левой ветви основного дерева.
        add_left_tree(Tree->left, Tree_left);
    else
        Tree->left = Tree_left; // Добавление ветви в левую ветвь основного дерева.
    return Tree;
}
BinTree* Insert(BinTree* Tree, int data_element) // Включение вершины в бинарное дерево
{
    if (Tree == NULL)
        return NewTree(data_element);
    if (data_element < Tree->data)
    {
        Tree->left = Insert(Tree->left, data_element);
    }
    else if (data_element > Tree->data)
    {
        Tree->right = Insert(Tree->right, data_element);
    }
    return Tree;
}
void printTree(struct BinTree* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

void tree_input_and_output() // Ввод и вывод бинарного дерева.
{
    BinTree* Tree = NULL;

    int heads_amount = 0;
    int head = 0;

    printf("Введите количество вершин дерева.\n");
    scanf_s("%d", &heads_amount);

    for (int i = 0; i < heads_amount; i++)
    {
        printf("Введите значение вершины дерева.\n");
        scanf_s("%d", &head);
        if (i == 0)
            Tree = Insert(Tree, head);
        else
            Insert(Tree, head);
    }


    printf("\n");
    printf("Дерево\n");
    printTree(Tree,0);
}

int main()
{
    setlocale(LC_ALL, "rus");
    tree_input_and_output();
    return 0;
}



