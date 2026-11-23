#pragma once
#include <iostream>
#include "Gridmodel.h" // links Gridzone struct from Gridmodel.h
using namespace std;

struct Bstnode
{
    Gridzone data; // uses Gridzone from Gridmodel.h
    Bstnode* left;
    Bstnode* right;

    Bstnode(const Gridzone& z) // takes Gridzone from Gridmodel.h
    {
        data = z;
        left = nullptr;
        right = nullptr;
    }
};
struct Avlnode
{
    Gridzone data; // uses Gridzone from Gridmodel.h
    Avlnode* left;
    Avlnode* right;
    int height;
    Avlnode(const Gridzone& z) // takes Gridzone from Gridmodel.h
    {
        data = z;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
class Usageanalytics // instantiated and used inside main.cpp
{
private:
    Bstnode* bstRoot;
    Avlnode* avlRoot;
    Bstnode* insertBST(Bstnode* node, const Gridzone& zone); // uses Gridzone from Gridmodel.h
    Gridzone* searchBST(Bstnode* node, int zoneID) const; // returns Gridzone from Gridmodel.h
    void inOrderBST(Bstnode* node) const;
    void destroyBST(Bstnode* node);

    int getHeight(Avlnode* node) const;
    int getBalance(Avlnode* node) const;
    int maxVal(int a, int b) const;
    Avlnode* rightRotate(Avlnode* y);
    Avlnode* leftRotate(Avlnode* x);
    Avlnode* insertAVL(Avlnode* node, const Gridzone& zone); // uses Gridzone from Gridmodel.h
    void rangeQueryAVL(Avlnode* node, double minLoad, double maxLoad) const;
    void inOrderAVL(Avlnode* node) const;
    void destroyAVL(Avlnode* node);
public:
    Usageanalytics();
    ~Usageanalytics();
    void archiveZoneBST(const Gridzone& zone); // called from main.cpp with Gridzone from Gridmodel.h
    Gridzone* findArchivedZone(int zoneID) const; // returns Gridzone from Gridmodel.h to main.cpp
    void displayBSTArchive() const; // called from main.cpp
    void indexZoneAVL(const Gridzone& zone); // called from main.cpp with Gridzone from Gridmodel.h
    void searchUsageRange(double minLoad, double maxLoad) const; // called from main.cpp
    void displaySortedUsageAVL() const; // called from main.cpp
};