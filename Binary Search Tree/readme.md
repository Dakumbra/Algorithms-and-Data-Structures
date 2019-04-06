
This project is a BST research tree. The program is designed to test the effectiveness of asymmetric or symmetric deltetes in a binary search tree.

In asymmetric method the program uses a single type of deleteion, either by consistently deleting the predecessor or consistently deleting the successor. The symmetric method is tested by alternating between predecessor and successor deletes. There is a random insertion done after each delete to keep the number of nodes the same. After 100,000 delete/insert pairs the internal path length (IPL) averages are printed and then graphed to give data on the effect of these different methods on the balance of the tree. As described in the attached report, a symmetric method yields a more balanced tree after deletes and insertions.

In addition to a regular BST structure this program includes private variables that keep track of the size of the tree and a vector that
keeps a list of all values in the tree. The vector is helpful in finding a random node value to delete.
