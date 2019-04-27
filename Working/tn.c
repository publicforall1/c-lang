/* Program will work fine if our mind works fine. - taiprogramer */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define REALLY_THINKING_SIGNAL 1
#define PLANG_NUM 6.625e-34
#define PI 3.1415926535

/* Code Style Set */
#define TRUE 1
#define FALSE 0
#define SHOW printf
#define GET_INT(address) scanf("%d", address)
#define GET_FLOAT(address) scanf("%f", address)
#define GET_DOUBLE(address) scanf("%ld", address)
#define GET_CHAR(address) scanf("%c", address)
#define GET_STR_WITHOUT_SPACE(address) scanf("%s", address)
#define GET_STR_INCLUDE_SPACE(address) scanf(" %[a-zA-Z ]", address)
/* @ Warnings
 * - GET_STR_INCLUDE_SPACE:
 * It can lead to buffer overflow
 * ...
 * */

struct SinhVien {
  int MSSV;
  char HoTen[50];
  float diemTB;
};

/* Function Prototype */
bool isNull(void* ptr);

int main() {
  int i, n = 5, index = 0;
  struct SinhVien* listSV = malloc(n * sizeof(struct SinhVien));

  if (isNull(listSV))
    exit(1);

  while (TRUE) {
    int mssv;
    struct SinhVien* tempList;
    if (index == n) {
      n += 5;
      tempList = realloc(listSV, n * sizeof(struct SinhVien));
      if (isNull(tempList) == FALSE)
        listSV = tempList;
    }

    SHOW("MSSV: ");
    GET_INT(&mssv);
    if (mssv == -1)
      break;
    listSV[index].MSSV = mssv;
    SHOW("HoTen: ");
    GET_STR_INCLUDE_SPACE(listSV[index].HoTen);
    SHOW("DiemTB: ");
    GET_FLOAT(&listSV[index].diemTB);
    ++index;
  }

  for (i = 0; i < index; ++i) {
    SHOW("---- Sinh vien thu %d ----\n", i + 1);
    SHOW("MSSV: %d\nHoTen: %s\nDiemTB: %.3f\n", listSV[i].MSSV, listSV[i].HoTen,
         listSV[i].diemTB);
  }

  free(listSV);
  return 0;
}

bool isNull(void* ptr) {
  if (ptr == NULL)
    return TRUE;
  else
    return FALSE;
}