/**
 * @file find_cycle_linked_list.cpp
 * @brief Detect and find a cycle in a linked list
 * using floyd Tortoise and hare
 * algo[https://en.wikipedia.org/wiki/Cycle_detection]
 * @details in order to check if a cycle exists in a linked list you can use a
 * two pointer algorithm where one pointer(hare) moves twice fast then
 * other(tortoise). If they point to the same node means that a cycle exists and
 * if put the hare pointer back to the beginnig of the list and keep mooving
 * them, they will meet again at the first node of the cycle
 * @author [Lusca] (https://github.com/ImLusca)
 */

#include <cassert>        // for assert
#include <iostream>       // for IO operations
#include <unordered_map>  // for std::unordered_map
#include <vector>         // for std::vector

/**
 * @namespace operations_on_datastructures
 * @brief Operations on Data Structures.
 */
namespace operations_on_datastructures {

/**
 * @namespace find_cycle_linked_list
 * @brief Functions for the find_cycle_linked_list implementation.
 */
namespace find_cycle_linked_list {

/**
 * @brief A Node struct for a singly linked list.
 */
struct Node {
    int64_t data;
    Node* next;
};

Node* InitializeLinkedListFromVector(std::vector<int64_t> vet) {
    Node *head = NULL, *lastNode = NULL;

    std::unordered_map<int, Node*>
        mp;  // Using a hashmap to know if a node was alredy inserted in list

    for (int i = 0; i < vet.size(); i++) {
        Node* newNode = new Node();
        newNode->data = vet[i];
        newNode->next = NULL;

        if (mp.find(newNode->data) != mp.end()) {
            lastNode->next = mp.at(newNode->data);  // Link to an previous node
                                                    // with the same data value
            free(newNode);  // newNode no longer will be necessary
            break;
        } else {
            mp.insert({newNode->data, newNode});
        }

        if (lastNode) {
            lastNode->next = newNode;  // if lastNode is not null, set its next
                                       // pointer to this node pointer;
        }
        if (!head) {
            head =
                newNode;  // if not defined yet, stores the first node pointer
        }
    }

    return head;
}

/**
 * @brief finds and return the first node of a cycle in a linked list if it
 * exists
 *
 * @return Node*: The first node of the cycle
 */
Node* findCycleLinkedList(Node* head) {
    Node *tortoise = head, *hare = head;
    int hasCycle = 0;

    while (tortoise != NULL && hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            hasCycle = 1;
            break;
        }
    }

    if (!hasCycle) {
        return NULL;
    }

    tortoise = head;

    while (tortoise != hare) {
    }
}

}  // namespace find_cycle_linked_list
}  // namespace operations_on_datastructures