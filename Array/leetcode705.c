struct List {
    int val;
    struct List * next;
};

void listPush(struct List * head, int x) {
    struct List * tmp = malloc(sizeof(struct List));
    tmp->val = x;
    tmp->next = head->next;
    head->next = tmp;
}

void listDelete(struct List * head, int x) {
    for (struct List * it = head; it->next; it = it->next) {
        if (it->next->val == x) {
            struct List * tmp = it->next;
            it->next = tmp->next;
            free(tmp);
            break;
        }
    }
}

bool listContains(struct List* head, int x) {
    for (struct List* it = head; it->next; it = it->next) {
        if (it->next->val == x) {
            return true;
        }
    }
    return false;
}


void listFree(struct List * head) {
    while (head->next) {
        struct List * tmp = head->next;
        head->next = tmp->next;
        free(tmp);
    }
}

const int base = 769;

int hash(int key) {
    return key % base;
}

typedef struct {
    struct List * data;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* ret = malloc(sizeof(MyHashSet));
    ret->data = malloc(sizeof(struct List) * base);
    for (int i = 0; i < base; i++) {
        ret->data[i].val = 0;
        ret->data[i].next = NULL;
    }
    return ret;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = hash(key);
    if (!listContains(&(obj->data[index]), key)) {
        listPush(&(obj->data[index]), key);
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = hash(key);
    listDelete(&(obj->data[index]), key);
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int h = hash(key);
    return listContains(&(obj->data[h]), key);
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < base; i ++) {
        listFree(&(obj->data[i]));
    }
    free(obj->data);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
