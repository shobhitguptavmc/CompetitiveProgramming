#include "avl_tree.cpp"

template <class K, class V>
class avl_map {
public:
    struct node {
        K key; V value;
        node(K k, V v) : key(k), value(v) { }
        bool operator <(const node &other) const { return key < other.key; } };
    avl_tree<node> tree;
    V& operator [](K key) {
        typename avl_tree<node>::node *n = tree.find(node(key, V(0)));
        if (!n) n = tree.insert(node(key, V(0)));
        return n->item.value;
    }
};
