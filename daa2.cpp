#include <bits/stdc++.h>
#include <iostream>
#include <algorithm> // Include this for 'sort'
#include <chrono>
#include <iomanip>
#include <vector>  
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left, *right;

    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Function to store the Huffman codes
void printCodes(struct MinHeapNode* root, string str, unordered_map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        codes[root->data] = str; // Store the code for this character
    }
    printCodes(root->left, str + "0", codes);
    printCodes(root->right, str + "1", codes);
}

struct compare {
    bool operator()(MinHeapNode* a, MinHeapNode* b) {
        return (a->freq > b->freq);
    }
};

void HuffmanCode(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *temp;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; i++) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }

    // Store the Huffman codes in a map
    unordered_map<char, string> codes;
    printCodes(minHeap.top(), "", codes);

    // Print the codes in the order of the input characters
    for (int i = 0; i < size; i++) {
        cout << data[i] << ": " << codes[data[i]] << endl;
    }
}

int main() {
    int size;
    cout << "Enter the number of unique characters: ";
    cin >> size;

    char* data = new char[size];
    int* freq = new int[size];

    cout << "Enter the characters: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }

    cout << "Enter the frequencies corresponding to the characters: ";
    for (int i = 0; i < size; i++) {
        cin >> freq[i];
    }

    HuffmanCode(data, freq, size);

    delete[] data; // Free allocated memory
    delete[] freq; // Free allocated memory

    return 0;
}
