/* *
 * Program Name: Mảng - Xóa phần tử theo giá trị
 * Author: Võ Văn Khánh Quốc
 * Clean code: taiprogramer
 * - Without any WARRANTY -
 */
#include <stdio.h>

void nhapMang(int mangSoNguyen[], int soPhantu);
void xuatMang(int mangSoNguyen[], int soPhantu);
void xoaPhanTuTheoGiaTri(int mangSoNguyen[], int* soPhanTu, int giaTriMuonXoa);
void xoaPhanTuTheoViTri(int mangSoNguyen[], int* soPhanTu, int viTriXoa);

int main() {
  int soPhantu, giaTriMuonXoa;
  printf("Nhap so phan tu mang: ");
  scanf("%d", &soPhantu);

  int mangSoNguyen[soPhantu];
  nhapMang(mangSoNguyen, soPhantu);
  xuatMang(mangSoNguyen, soPhantu);

  printf("Nhap gia tri muon xoa: ");
  scanf("%d", &giaTriMuonXoa);
  xoaPhanTuTheoGiaTri(mangSoNguyen, &soPhantu, giaTriMuonXoa);
  xuatMang(mangSoNguyen, soPhantu);
}

void nhapMang(int mangSoNguyen[], int soPhantu) {
  int i;
  for (i = 0; i < soPhantu; i++) {
    printf("Nhap phan tu thu %d : ", i + 1);
    scanf("%d", &mangSoNguyen[i]);
  }
}

void xuatMang(int mangSoNguyen[], int soPhantu) {
  printf("Gia tri hien tai cua mang la:\n");
  int i;
  for (i = 0; i < soPhantu; i++)
    printf("%d ", mangSoNguyen[i]);

  printf("\n");
}

void xoaPhanTuTheoGiaTri(int mangSoNguyen[], int* soPhanTu, int giaTriMuonXoa) {
  int i;
  for (i = 0; i < *soPhanTu; i++) {
    if (mangSoNguyen[i] == giaTriMuonXoa) {
      xoaPhanTuTheoViTri(mangSoNguyen, soPhanTu, i);
      i--; // Back to check
    }
  }
}

void xoaPhanTuTheoViTri(int mangSoNguyen[], int* soPhanTu, int viTriXoa) {
  int i;
  for (i = viTriXoa; i < *soPhanTu; i++)
    mangSoNguyen[i] = mangSoNguyen[i + 1];

  *soPhanTu = *soPhanTu - 1;
}