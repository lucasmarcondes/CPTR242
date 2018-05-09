
typedef int ItemType;

enum Color { RED, BLACK };

struct TreeNode {
    ItemType info;
    Color color;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

class RBTree {
  public:
    RBTree();   // constructor
    ~RBTree();  // destructor
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);

  private:
    TreeNode* root;
};
