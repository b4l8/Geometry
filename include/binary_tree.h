namespace BinaryTree{
template<typename T>
struct node{
  T key_value;
  node* left;
  node* right;
};

template <typename T>
class btree{
 public:
  btree(){
    root = nullptr;
    size_ = 0;
  }

  ~btree(){
    destroyTree();
  }

  void insert(T key) {
    if(root!=nullptr) {
      insert(key,root);
    } else {
      root = new node;
      root->key_value = key;
      root->right = nullptr;
      root->left = nullptr;
      ++size_;
    }
  }

  node* search(T key) {
    search(key , root);
  }

  void destroyTree(){
    destroyTree(root);
  }

  bool empty() {
    return root==nullptr;
  }

 private:
  size_t compute_size(node* leaf) {
    if(leaf == nullptr) {
      return 0;
    } else {
      return (1+compute_size(leaf->left)+compute_size(leaf->right);
    }
  }

  void destroyTree(node* leaf){
    if(leaf!=nullptr){
      destroyTree(leaf->left);
      destroyTree(leaf->right);
      delete leaf;
      --size_;
    }
  }

  void insert(T key,node* leaf){
    if(key < leaf->key_value) {
      insert(key , leaf->left);
    } else {
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = nullptr;
      leaf->left->right = nullptr;
    } else if (key >= leaf->key_value) {
      if (leaf->right!=nullptr) {
        insert(key,leaf->right)
      } else {
        leaf->right = new node;
        leaf->right->key_value = key;
        leaf->right->left = nullptr;
        leaf->right->right = nullptr;
      }
    }
  }

  node* search(T key, node* leaf) {
    if(leaf != nullptr) {
      if(key == leaf->key_value) {
        return leaf;
      } else if (key < leaf->key_value) {
        return search(key , leaf->left);
      } else if (key >= leaf->key_value) {
        return search(key, leaf->right);
      }
    } else return nullptr;
  }
  node *root;
  size_t size_;
};

}