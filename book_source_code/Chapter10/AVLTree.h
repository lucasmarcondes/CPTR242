
typedef int ItemType;

struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

class AVLTreeADT {
  public:
    AVLTreeADT();   // constructor
    ~AVLTreeADT();  // destructor
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);

  private:
    TreeNode* root;
};
