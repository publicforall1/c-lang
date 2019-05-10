#include <stdio.h>

void nhap_mang(int mang_so_nguyen[], int so_phan_tu);
void in_mang(int mang_so_nguyen[], int so_phan_tu);
int giao_mang(int a[], int b[], int ket_qua[], int so_phan_tu);
int hop_mang(int a[], int b[], int ket_qua[], int so_phan_tu);

int main(void) {

    int so_phan_tu;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &so_phan_tu);

    int a[so_phan_tu], b[so_phan_tu];
    int mang_giao[so_phan_tu], mang_hop[so_phan_tu * 2];

    printf("\n---- mang a ----\n");
    nhap_mang(a, so_phan_tu);
    printf("\n---- mang b ----\n");
    nhap_mang(b, so_phan_tu);

    in_mang(a, so_phan_tu);
    in_mang(b, so_phan_tu);

    int so_phan_tu_sau_khi_giao = giao_mang(a, b, mang_giao, so_phan_tu);

    printf("\n---- mang sau khi giao ----\n");
    in_mang(mang_giao, so_phan_tu_sau_khi_giao);

    int so_phan_tu_sau_khi_hop = hop_mang(a, b, mang_hop, so_phan_tu);

    printf("\n---- mang sau khi hop ----\n");
    in_mang(mang_hop, so_phan_tu_sau_khi_hop);

    return 0;
}

void nhap_mang(int mang_so_nguyen[], int so_phan_tu) {
    // nhập mảng với các phần tử tăng dần và không trùng
    // if a > b -> thêm phần tử vào mảng

    int vi_tri = 0;

    // phần tử đầu tiên thì thêm vào luôn khỏi cần kiểm tra điều kiện
    printf("Nhap phan tu thu %d: ", vi_tri + 1);
    scanf("%d", &mang_so_nguyen[vi_tri]);
    vi_tri++;

    while (vi_tri < so_phan_tu) {
        printf("Nhap phan tu thu %d: ", vi_tri + 1);
        int gia_tri_tam_thoi;
        scanf("%d", &gia_tri_tam_thoi);
        // nếu giá trị tạm thời lớn hơn giá trị trước đó thì thêm nó vào mảng
        if (gia_tri_tam_thoi > mang_so_nguyen[vi_tri - 1]) {
            mang_so_nguyen[vi_tri] = gia_tri_tam_thoi;
            vi_tri++;
        }
    }
};

void in_mang(int mang_so_nguyen[], int so_phan_tu) {
    for (int i = 0; i < so_phan_tu; i++)
        printf("%d ", mang_so_nguyen[i]);
    printf("\n");
};

int giao_mang(int a[], int b[], int ket_qua[], int so_phan_tu) {
    int vi_tri = -1;
    // duyệt mảng a, nếu có phần tử nào trong a
    // giống với phần tử trong b thì thêm phần tử đó vào ket_qua
    for (int i = 0; i < so_phan_tu; i++) {
        for (int j = 0; j < so_phan_tu; j++) {
            if (a[i] == b[j]) {
                vi_tri++;
                ket_qua[vi_tri] = a[i];
            }
        }
    }
    // số phần tử của mảng sau khi giao
    // tăng vị trí lên 1 đơn vị rồi trả về
    return ++vi_tri;
};

int hop_mang(int a[], int b[], int ket_qua[], int so_phan_tu) {
    int vi_tri = -1;
    // thêm toàn bộ mảng a vào ket_qua vì a chứa các
    // phần tử tăng dần và khác nhau
    for (int i = 0; i < so_phan_tu; i++) {
        vi_tri++;
        ket_qua[vi_tri] = a[i];
    }
    // duyệt mảng b, nếu có phần tử nào trong b
    // khác tất cả các phần tử trong a thì thêm nó vào mảng
    for (int i = 0; i < so_phan_tu; i++) {
        int flag = 0;
        for (int j = 0; j < so_phan_tu; j++) {
            if (b[i] == a[j])
                flag = 1;
        }
        if (flag == 0) {
            vi_tri++;
            ket_qua[vi_tri] = b[i];
        }
    }
    // số phần tử của mảng sau khi giao
    // tăng vị trí lên 1 đơn vị rồi trả về
    return ++vi_tri;
};