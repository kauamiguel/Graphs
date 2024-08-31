class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.key = value
        
class BinaryTree:
    
    def __init__(self):
            self.root = None
 
    def insert(self, root, key):
        if root is None:
            return Node(key)
        
        if key < root.key:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
            
        return root
        
    def in_order(self,root):
        if root:
            self.in_order(root.left)
            print(root.key, end=" ")
            self.in_order(root.right)
            
bt = BinaryTree()
bt.root = bt.insert(bt.root, 5)
bt.root = bt.insert(bt.root, 15)
bt.root = bt.insert(bt.root, 2)
bt.root = bt.insert(bt.root, 7)
bt.root = bt.insert(bt.root, 12)
bt.root = bt.insert(bt.root, 18)
bt.in_order(bt.root)