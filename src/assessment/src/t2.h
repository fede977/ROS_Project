#ifndef T2_H
#define T2_H

struct Node{
    int x;
    int y;
    double costSoFar;
    double distance;
    Node *previous = NULL;
};

extern std::vector<Node*> path;
#endif