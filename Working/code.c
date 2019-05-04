#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cmnd[50];
    char hoten[50];
    float taikhoan;
} KhachHang;

KhachHang Nhap() {
    KhachHang khachhang;
    printf("Nhap CMND: ");
    fgets(khachhang.cmnd, 50, stdin);
    printf("Nhap Hoten: ");
    fgets(khachhang.hoten, 50, stdin);
    printf("Nhap tai khoan: ");
    scanf("%f", &khachhang.taikhoan);
    getchar();
    return khachhang;
}

void Xuat(KhachHang khachhang) {
    printf("CMND: %s", khachhang.cmnd);
    printf("Ho ten: %s", khachhang.hoten);
    printf("Tai khoan: %.3f\n", khachhang.taikhoan);
}

int main(void) {

    int N, i;
    KhachHang* listKhachHang;

    printf("Nhap so khach hang: ");
    scanf("%d", &N);
    getchar();

    listKhachHang = malloc(N * sizeof(KhachHang));

    for (i = 0; i < N; i++) {
        listKhachHang[i] = Nhap();
    }

    for (i = 0; i < N; i++) {
        printf("============ Khach hang thu %d ============\n", i + 1);
        Xuat(listKhachHang[i]);
    }

    free(listKhachHang);
    return 0;
}