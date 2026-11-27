#include "Usageanalytics.h" // links declarations from Usageanalytics.h and Gridzone from Gridmodel.h
Usageanalytics::Usageanalytics()
{
    bstRoot = nullptr;
    avlRoot = nullptr;
}
Usageanalytics::~Usageanalytics()
{
    destroyBST(bstRoot);
    destroyAVL(avlRoot);
}
void Usageanalytics::destroyBST(Bstnode* node)
{
    if (node == nullptr)
    {
        return;
    }
    destroyBST(node->left);
    destroyBST(node->right);
    delete node;
}
void Usageanalytics::destroyAVL(Avlnode* node)
{
    if (node == nullptr)
    {
        return;
    }
    destroyAVL(node->left);
    destroyAVL(node->right);
    delete node;
}
Bstnode* Usageanalytics::insertBST(Bstnode* node, const Gridzone& zone) // receives Gridzone from Gridmodel.h
{
    if (node == nullptr)
    {
        return new Bstnode(zone);
    }
    if (zone.zoneID < node->data.zoneID) // compares zoneID from Gridmodel.h
    {
        node->left = insertBST(node->left, zone);
    }
    else if (zone.zoneID > node->data.zoneID) // compares zoneID from Gridmodel.h
    {
        node->right = insertBST(node->right, zone);
    }
    else
    {
        node->data = zone;
    }
    return node;
}
Gridzone* Usageanalytics::searchBST(Bstnode* node, int zoneID) const // returns Gridzone pointer from Gridmodel.h
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (zoneID == node->data.zoneID) // checks zoneID from Gridmodel.h
    {
        return &(node->data);
    }
    if (zoneID < node->data.zoneID) // checks zoneID from Gridmodel.h
    {
        return searchBST(node->left, zoneID);
    }
    return searchBST(node->right, zoneID);
}
void Usageanalytics::inOrderBST(Bstnode* node) const
{
    if (node == nullptr)
    {
        return;
    }
    inOrderBST(node->left);
    cout << "Zone ID: " << node->data.zoneID << " | Name: " << node->data.zoneName << " | Load: " << node->data.currentLoad << " kW" << endl; // prints Gridzone fields from Gridmodel.h
    inOrderBST(node->right);
}
int Usageanalytics::getHeight(Avlnode* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}
int Usageanalytics::maxVal(int a, int b) const
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int Usageanalytics::getBalance(Avlnode* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
Avlnode* Usageanalytics::rightRotate(Avlnode* y)
{
    Avlnode* x = y->left;
    Avlnode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}
Avlnode* Usageanalytics::leftRotate(Avlnode* x)
{
    Avlnode* y = x->right;
    Avlnode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
Avlnode* Usageanalytics::insertAVL(Avlnode* node, const Gridzone& zone) // receives Gridzone from Gridmodel.h
{
    if (node == nullptr)
    {
        return new Avlnode(zone);
    }
    if (zone.currentLoad < node->data.currentLoad) // compares currentLoad from Gridmodel.h
    {
        node->left = insertAVL(node->left, zone);
    }
    else if (zone.currentLoad > node->data.currentLoad) // compares currentLoad from Gridmodel.h
    {
        node->right = insertAVL(node->right, zone);
    }
    else
    {
        if (zone.zoneID < node->data.zoneID) // tie-breaks using zoneID from Gridmodel.h
        {
            node->left = insertAVL(node->left, zone);
        }
        else if (zone.zoneID > node->data.zoneID) // tie-breaks using zoneID from Gridmodel.h
        {
            node->right = insertAVL(node->right, zone);
        }
        else
        {
            node->data = zone;
            return node;
        }
    }

    node->height = 1 + maxVal(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && zone.currentLoad < node->left->data.currentLoad) // checks currentLoad from Gridmodel.h
    {
        return rightRotate(node);
    }
    if (balance < -1 && zone.currentLoad > node->right->data.currentLoad) // checks currentLoad from Gridmodel.h
    {
        return leftRotate(node);
    }
    if (balance > 1 && zone.currentLoad > node->left->data.currentLoad) // checks currentLoad from Gridmodel.h
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && zone.currentLoad < node->right->data.currentLoad) // checks currentLoad from Gridmodel.h
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void Usageanalytics::rangeQueryAVL(Avlnode* node, double minLoad, double maxLoad) const
{
    if (node == nullptr)
    {
        return;
    }
    if (minLoad < node->data.currentLoad) // checks currentLoad from Gridmodel.h
    {
        rangeQueryAVL(node->left, minLoad, maxLoad);
    }
    if (node->data.currentLoad >= minLoad && node->data.currentLoad <= maxLoad) // checks currentLoad from Gridmodel.h
    {
        cout << "Zone ID: " << node->data.zoneID << " | Name: " << node->data.zoneName << " | Load: " << node->data.currentLoad << " / " << node->data.maxCapacity << " kW" << endl; // prints Gridzone fields from Gridmodel.h
    }
    if (maxLoad > node->data.currentLoad) // checks currentLoad from Gridmodel.h
    {
        rangeQueryAVL(node->right, minLoad, maxLoad);
    }
}
void Usageanalytics::inOrderAVL(Avlnode* node) const
{
    if (node == nullptr)
    {
        return;
    }
    inOrderAVL(node->left);
    cout << "Load: " << node->data.currentLoad << " kW | Zone: " << node->data.zoneName << " (ID: " << node->data.zoneID << ")" << endl; // prints Gridzone fields from Gridmodel.h
    inOrderAVL(node->right);
}
void Usageanalytics::archiveZoneBST(const Gridzone& zone) // receives Gridzone from Gridmodel.h
{
    bstRoot = insertBST(bstRoot, zone);
}
Gridzone* Usageanalytics::findArchivedZone(int zoneID) const // returns Gridzone pointer from Gridmodel.h
{
    return searchBST(bstRoot, zoneID);
}
void Usageanalytics::displayBSTArchive() const
{
    cout << "\nBST Zone Archive (Sorted by ID)" << endl;
    if (bstRoot == nullptr)
    {
        cout << "Archive is empty." << endl;
        return;
    }
    inOrderBST(bstRoot);
}
void Usageanalytics::indexZoneAVL(const Gridzone& zone) // receives Gridzone from Gridmodel.h
{
    avlRoot = insertAVL(avlRoot, zone);
}
void Usageanalytics::searchUsageRange(double minLoad, double maxLoad) const
{
    cout << "\nZones Consuming Between " << minLoad << " kW and " << maxLoad << " kW" << endl;
    if (avlRoot == nullptr)
    {
        cout << "No zones indexed yet." << endl;
        return;
    }
    rangeQueryAVL(avlRoot, minLoad, maxLoad);
}
void Usageanalytics::displaySortedUsageAVL() const
{
    cout << "\nAVL Usage Ranking (Lowest to Highest kW)" << endl;
    if (avlRoot == nullptr)
    {
        cout << "No zones indexed yet." << endl;
        return;
    }
    inOrderAVL(avlRoot);
}