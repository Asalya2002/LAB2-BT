// LAB2-BT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    // Конструктор
    BinaryTree() : root(nullptr) {}

    // Получение корня дерева
    Node* getRoot() const {
        return root;
    }

    // Добавление узла в дерево
    void addNode(int key) {
        Node* newNode = new Node(key);

        if (root == nullptr) {
            root = newNode;
            std::cout << "Node " << key << "added to the tree." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                std::cout << "Node " << key << "added to the tree." << std::endl;
                return;
            }
            else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                std::cout << "Node " << key << "added to the tree." << std::endl;
                return;
            }
            else {
                q.push(current->right);
            }
        }
    }

    // Удаление узлов с заданным ключом
    void removeNodes(int key) {
        if (root == nullptr) {
            std::cout << "The tree is empty." << std::endl;
            return;
        }

        Node* parent = nullptr;
        Node* current = root;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            current = q.front();
            q.pop();

            if (current->key == key) {
                break;
            }

            parent = current;

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        if (current == nullptr) {
            std::cout << "Key node" << key << " is not found in the tree." << std::endl;
            return;
        }

        if (parent == nullptr) {
            root = nullptr; // Удаляем корень
        }
        else if (parent->left == current) {
            parent->left = nullptr;
        }
        else {
            parent->right = nullptr;
        }

        delete current;
        std::cout << "Nodes with key " << key << " removed from the tree. " << std::endl;
    }

    // Рекурсивная функция для печати дерева в горизонтальном виде
    void print(Node* root, int space) {
        if (root == nullptr) {
            return;
        }

        int COUNT = 3;  // Расстояние между уровнями узлов

        space += COUNT;

        print(root->right, space);

        std::cout << std::endl;
        for (int i = COUNT; i < space; i++) {
            std::cout << " ";
        }
        std::cout << root->key << "\n";

        print(root->left, space);
    }

    // Печать дерева в горизонтальном виде
    void print() {
        if (root == nullptr) {
            std::cout << "The tree is empty." << std::endl;
            return;
        }

        std::cout << "Binary tree (horizontal view):" << std::endl;
        print(root, 0);
    }
};

int main() {
    BinaryTree tree;

    tree.addNode(50);
    tree.addNode(30);
    tree.addNode(20);
    tree.addNode(40);
    tree.addNode(70);
    tree.addNode(60);
    tree.addNode(80);

    std::cout << "Binary tree (horizontal view):" << std::endl;
    tree.print();

    tree.removeNodes(30);
    tree.print(tree.getRoot(), 0); // Печатаем после первого удаления

    return 0;
}
