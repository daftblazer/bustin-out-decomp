#ifndef SIMS_UNK80026864LIST_H
#define SIMS_UNK80026864LIST_H

// Doubly linked list of pointers (first node, last node, "owns its items" flag).
// It shares its clearing function (0x801B4760) with the screen objects' child list.
struct Unk80026864Node {
    void* item;
    Unk80026864Node* prev;
    Unk80026864Node* next;
};
struct Unk80026864List {
    Unk80026864List() {
        tail = 0;
        head = 0;
        owns = 1;
    }
    ~Unk80026864List() { fn_801B4760(); }
    void fn_801B4760();                 // clear
    void Clear() {
        if (head) {
            fn_801B4760();
        }
    }
    void fn_801B4600(void* item);       // append
    int fn_801B484C(void* item);        // contains
    void fn_801B4520(Unk80026864Node* node);   // remove a node
    void* RemoveHead() {
        Unk80026864Node* node = head;
        if (node == 0) {
            return 0;
        }
        void* item = node->item;
        fn_801B4520(node);
        return item;
    }

    Unk80026864Node* Head() const { return head; }
    Unk80026864Node* Tail() const { return tail; }

    Unk80026864Node* head;
    Unk80026864Node* tail;
    int owns;
};

#endif
