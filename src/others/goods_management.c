/**
 * Program Name: Quản lí hàng hóa
 * Author: taiprogramer
 * Requirements: ../shared/De07_hk2_17-18.pdf
 * Data: ../shared/Ban_hang.txt
 * Telegram: t.me/taiprogramer
 * Comment: Được viết bằng cả trái tim của một anh chàng rất đẹp trai!
 * Lasted Update: 16:56, 26/04/2019, Viet Nam
 *  - Change Code Style -> Clean Code
 *  - Errors Handler -> Good Program
 * Contributions:
 *  - ...
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char Mahang[10];
    char Tenhang[30];
    int soluong;
    long dongia;
} hanghoa;

hanghoa* read_from_file(int* tongSoHangHoa, const char* fileName);
void in_danh_sach(hanghoa listHangHoa[], int tongSoHangHoa);
void delete_hang_hoa(unsigned int j, hanghoa listHangHoa[], int* tongSoHangHoa);
void group_hang_hoa(hanghoa listHangHoa[], int* tongSoHangHoa);

int main(void) {

    int tongSoHangHoa = 0;
    hanghoa* listHangHoa = read_from_file(&tongSoHangHoa, "Ban_hang.txt");
    /*============ NULL CHECK ============*/
    if (!listHangHoa) {
        printf("NULL NULL NULL. Program will exit with status code = 1.\n");
        exit(1);
    }
    /*====================================*/
    group_hang_hoa(listHangHoa, &tongSoHangHoa);
    in_danh_sach(listHangHoa, tongSoHangHoa);
    free(listHangHoa);
    return 0;
}

hanghoa* read_from_file(int* tongSoHangHoa, const char* fileName) {
    int index = 0;
    FILE* file = fopen(fileName, "rt");
    hanghoa* listHangHoa = NULL;
    hanghoa* temp_ptr = NULL;
    char str_buffer[200];
    if (file) {
        listHangHoa = malloc(sizeof(hanghoa));
        /*============ NULL CHECK ============*/
        if (!listHangHoa) {
            printf("Can not malloc for 1 hang hoa.\n");
            fclose(file);
            return NULL;
        }
        /*====================================*/
        while (fgets(str_buffer, 200, file)) {
            sscanf(str_buffer, "%s%[a-zA-Z ]%d%ld", listHangHoa[index].Mahang,
                   listHangHoa[index].Tenhang, &listHangHoa[index].soluong,
                   &listHangHoa[index].dongia);
            ++index;
            temp_ptr = realloc(listHangHoa, (index + 1) * sizeof(hanghoa));
            /*============ NULL CHECK ============*/
            if (!temp_ptr) {
                printf("Can not realloc for %d hang hoa.\n", index);
                *tongSoHangHoa = index;
                return listHangHoa;
            } else {
                listHangHoa = temp_ptr;
            }
            /*====================================*/
        }
        *tongSoHangHoa = index;
        fclose(file);
        return listHangHoa;
    } else {
        printf("Can not open file.\n");
        return NULL;
    }
}

void in_danh_sach(hanghoa listHangHoa[], int tongSoHangHoa) {
    int i;
    /* in ra danh sách hàng hóa */
    printf(
        "+----+-------+---------------------+-------+--------+------------+\n");
    printf("|%-4s|%-7s|%-21s|%-7s|%-8s|%-12s|\n", "STT", "Ma hang", "Ten hang",
           "SLuong", "DGia", "Thanh tien");
    printf(
        "+----+-------+---------------------+-------+--------+------------+\n");
    /* duyệt từ đầu đến cuối và in ra thôi. Easy Game :)) */

    for (i = 0; i < tongSoHangHoa; ++i) {
        printf("|%-4d|%-7s|%-21s|%7d|%8ld|%12ld|\n", i + 1,
               listHangHoa[i].Mahang, listHangHoa[i].Tenhang,
               listHangHoa[i].soluong, listHangHoa[i].dongia,
               listHangHoa[i].soluong * listHangHoa[i].dongia);
        printf("+----+-------+---------------------+-------+--------+----------"
               "--+\n");
    }
}

void delete_hang_hoa(unsigned int j, hanghoa listHangHoa[],
                     int* tongSoHangHoa) {
    int i;
    for (i = j; i < *tongSoHangHoa - 1; ++i) {
        listHangHoa[i] = listHangHoa[i + 1];
    }
    --(*tongSoHangHoa);
}

void group_hang_hoa(hanghoa listHangHoa[], int* tongSoHangHoa) {
    int i, j;
    for (i = 0; i < *tongSoHangHoa - 1; ++i) {
        for (j = i + 1; j < *tongSoHangHoa; ++j) {
            if (strcmp(listHangHoa[i].Mahang, listHangHoa[j].Mahang) == 0) {
                listHangHoa[i].soluong += listHangHoa[j].soluong;
                delete_hang_hoa(j, listHangHoa, tongSoHangHoa);
                /* j lùi lại để bắt đầu duyệt từ vị trí của phần tử vừa xóa */
                --j;
            }
        }
    }
}