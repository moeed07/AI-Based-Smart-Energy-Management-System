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