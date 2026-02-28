#include <unordered_map>
class Node {
  public:
    int val;
    Node *next{};
    Node *random{};

    Node(int _val) : val(_val) {}
};

class Solution {
  public:
    Node *copyRandomList(Node *head) {
        std::unordered_map<Node *, Node *> copied_nodes;
        auto *current = head;

        while (current != nullptr) {
            copied_nodes[current] = new Node(current->val);
            current = current->next;
        }

        current = head;
        while (current != nullptr) {
            copied_nodes[current]->next = copied_nodes[current->next];
            copied_nodes[current]->random = copied_nodes[current->random];
            current = current->next;
        }

        return copied_nodes[head];
    }
};
