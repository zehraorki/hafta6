#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* right;
    struct node* left;
}node;

node* newRoot(int veri) {
    node *d=(node*)malloc(sizeof(node));
    d->right=NULL; d->left=NULL; d->data=veri;
    return d;
}

node* add(node* root,int veri) {
    if (root==NULL) {
        return newRoot(veri);
    }
    if (veri<root->data) {
        root->left=add(root->left,veri);
    }
    else if (veri>root->data) {
        root->right=add(root->right,veri);
    }
    return root;
}

void inOrder(node* root) {
    if (root==NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

node* search(node*root,int aranan) {
    if (root==NULL || root->data==aranan) {
        return root;
    }
    if (root->data<aranan) {
        return search(root->right,aranan);
    }
    if (root->data>aranan) {
        return search(root->left,aranan);
    }
}

void findMin(node*root) {
    while (root->left!=NULL) {
        root=root->left;
    }
    printf("En Kucuk Eleman: %d\n",root->data);
}
int main(){
    int arr[7]={40,20,60,10,30,50,70};
    node* root=NULL;
    for (int i=0;i<7;i++) {
        root=add(root,arr[i]);
    }
    inOrder(root);
    printf("\n");
    node* sonuc=search(root,30);
    if (sonuc!=NULL) {
        printf("30 degeri bulundu\n");
    }else {
        printf("30 degeri bulunamadi\n");
    }
    sonuc=search(root,100);
    if (sonuc!=NULL) {
        printf("100 degeri bulundu\n");
    }else {
        printf("100 degeri bulunamadi\n");
    }
    findMin(root);

    return 0;
}


/*

Kısa değerlendirme soruları
● 25 değeri eklenirse hangi düğümün altına yerleşir?
● Inorder fonksiyonunda printf() ilk satıra taşınırsa hangi dolaşma elde edilir?
● findMin() içinde left yerine right takip edilirse hangi değer bulunur?
 1-30'un soluna eklenir.
 2-Preorder
 3-En buyuk deger bulunur

 */