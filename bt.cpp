#include <iostream>
using namespace std;
//Cài đặt cây biểu thức cho biểu thức trên lớp ngày 3/12/2024, và in ra biểu thức theo các cách biểu diễn Trung tố, hậu tố, và tiền tố.
//bieu thuc:     a*5-b*c^6/d+(h-f)*e^0.5
//Định nghĩa và khai báo các hàm sau:
// Cài đặt thuộc tính cho 1 node trên cây 
struct BieuThuc{        // node cua tree
    string data;
    BieuThuc* left;
    BieuThuc* right;
    //val la gia tri du lieu duoc them vao
    BieuThuc(string val){
        data=val;
        //khoi tao con trai, con phai
        left = nullptr;
        right = nullptr;
    }
};
// Cài đặt hàm khởi tạo cây (không được bỏ qua hàm kiểm tra rỗng)
void initbt(BieuThuc *T){
    T=nullptr;
}
//ktr cay rong
int isEmpty(BieuThuc *T){
    return T==nullptr;
}
// Cài đặt hàm nhập phần tử (bổ sung) vào cây 
void insertNode(BieuThuc *t, string val){
    BieuThuc *p=new BieuThuc(val);
    //neu cay rong ->khoi tao
    if (isEmpty){
        t=p;
    }else{
        if(val<t->data){
            insertNode(t->left,val);    //chen vao con trai
        }else{
            insertNode(t->right,val);   //chen vao con phai
        }
    }
}
// In các phần tử trên cây theo 3 giải thuật duyệt 
void inorder(BieuThuc *t){  //duyet giua
    if(isEmpty(t)) return;
    inorder(t->left);
    cout <<" " << t->data;
    inorder(t->right);
}
void preorder(BieuThuc *t){
    if(isEmpty(t)) return;
    cout <<" " << t->data;
    preorder(t->left);
    preorder(t->right);
}
void postorder(BieuThuc *t){
    if(isEmpty(t)) return;
    postorder(t->left);
    postorder(t->right);
    cout <<" " << t->data;
}
int main(){
    BieuThuc* root = nullptr;

    // Tạo cây biểu thức (giả sử theo thứ tự tạo phù hợp với cấu trúc biểu thức)
    root = new BieuThuc("+");
    root->left = new BieuThuc("-");
    root->right = new BieuThuc("*");

    root->left->left = new BieuThuc("*");
    root->left->right = new BieuThuc("*");
    root->left->left->left = new BieuThuc("a");
    root->left->left->right = new BieuThuc("5");

    root->left->right->left = new BieuThuc("b");
    root->left->right->right = new BieuThuc("/");
    root->left->right->right->left = new BieuThuc("^");
    root->left->right->right->left->left = new BieuThuc("c");
    root->left->right->right->left->right = new BieuThuc("6");
    root->left->right->right->right = new BieuThuc("d");

    root->right->left = new BieuThuc("-");
    root->right->right = new BieuThuc("^");
    root->right->left->left = new BieuThuc("h");
    root->right->left->right = new BieuThuc("f");
    root->right->right->left = new BieuThuc("e");
    root->right->right->right = new BieuThuc("0.5");
    
    cout << "trung to (Inorder): ";
    inorder(root);
    cout << endl;

    cout << "tien to (Preorder): ";
    preorder(root);
    cout << endl;

    cout << "hau to (Postorder): ";
    postorder(root);
    cout << endl;
}