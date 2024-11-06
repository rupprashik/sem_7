#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue to create a min-heap based on frequency
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to print the Huffman codes
void printCodes(Node* root, string str) {
    if (!root) return;
    
    if (root->ch != '#') // '#' signifies internal nodes in Huffman Tree
        cout << root->ch << ": " << str << endl;
    
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build the Huffman Tree and print Huffman codes
void huffmanEncoding(unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    
    // Create leaf nodes for each character and push to min-heap
    for (auto& pair : frequencies) {
        minHeap.push(new Node(pair.first, pair.second));
    }
    
    // Build Huffman Tree
    while (minHeap.size() > 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        
        // '#' represents an internal node
        int sum = left->freq + right->freq;
        Node* newNode = new Node('#', sum);
        newNode->left = left;
        newNode->right = right;
        
        minHeap.push(newNode);
    }
    
    // Print the Huffman Codes
    printCodes(minHeap.top(), "");
}

int main() {
    unordered_map<char, int> frequencies;
    frequencies['a'] = 5;
    frequencies['b'] = 9;
    frequencies['c'] = 4;
    frequencies['d'] = 19;
    frequencies['e'] = 16;
    frequencies['f'] = 8;
    
    cout << "Huffman Codes:\n";
    huffmanEncoding(frequencies);
    
    return 0;
}
