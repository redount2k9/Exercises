#include <iostream>

using std::cout;

struct listNode {
    int studentNum;
    int grade;
    listNode *next;

};

typedef listNode *studentCollection;

void addRecord(studentCollection &sc, int studNum, int gr) {
    listNode *newNode = new listNode;
    newNode->studentNum = studNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
    delete newNode;
}

void removeRecord(studentCollection &sc, int studNum) {
    listNode *loopPtr = sc;
    listNode *prev = new listNode;
    if ( sc && sc->studentNum == studNum ) {
        sc = sc->next;
        return;
    }
    while(loopPtr && loopPtr->studentNum != studNum) {
        prev = loopPtr;
        loopPtr = loopPtr->next;
    }
    if ( loopPtr == NULL )
        return;
    prev->next = loopPtr->next;
    delete loopPtr, prev;

}

double averageRecord(studentCollection sc) {
    if (sc == NULL)
        return 0;
    int current = 0;
    double sum = 0;
    listNode *loopPtr = sc;
    while(loopPtr) {
        sum += loopPtr->grade;
        current++;
        loopPtr = loopPtr->next;
    }
    double average = sum / current;
    delete loopPtr;
    return average;
}



int main() {
    studentCollection sc;
    listNode *node1 = new listNode;
    node1->studentNum = 1001;
    node1->grade = 78;
    listNode *node2 = new listNode;
    node2->studentNum = 1012;
    node2->grade = 93;
    listNode *node3 = new listNode;
    node3->studentNum = 1076;
    node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    removeRecord(sc, 1012);
    while(sc) {
        cout << sc->grade << '\n';
        sc = sc->next;
    }

}
