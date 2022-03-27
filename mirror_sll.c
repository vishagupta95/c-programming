// create mirror tree 
node* mirror(node* root) {
   node* m_root = NULL;
   if(!root) return NULL;
   m_root = getNewNode(root->value);
   m_root->left = mirror(root->right);
   m_root->right = mirror(root->left);
   return m_root;
}


void mirror_image(node *root)
{
    if(root != NULL)
    {
        node* temp;
        mirror_image(root->left);
        mirror_image(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
