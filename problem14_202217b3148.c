//IMPLEMENTATION OF TREE TRAVERSAL
int max_node = 15;
char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};
   
     D
    / \
   A   F
  / \   \
 E   B   R
        / \
       T   G
          / \
         Q   V
            /
           J
          /
         L
int get_right_child(int index)
{
    if (tree[index] != '\0' && ((2 * index) + 1) <= max_node)
        return (2 * index) + 1;
    return -1;
}
int get_left_child(int index)
{
    if (tree[index] != '\0' && (2 * index) <= max_node)
        return 2 * index;
    return -1;
}
int main()
{
    printf("Preorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");
    return 0;
}
