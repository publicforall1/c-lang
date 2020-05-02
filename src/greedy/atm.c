/*
Trong máy rút tiền tự động ATM, ngân hàng đã chuẩn bị sẵn các loại tiền có
mệnh giá 500.000 đồng, 200.000 đồng, 100.000 đồng, 50.000 đồng, 20.000 đồng
và 10.000 đồng. Giả sử mỗi loại tiền đều có số lượng không hạn chế. Khi có một
khách hàng cần rút một số tiền n đồng (tính chẵn đến 10.000 đồng). Hãy tìm một
phương án trả tiền sao cho trả đủ n đồng và số tờ giấy bạc phải trả là ít nhất.
*/

#include <stdio.h>

/* Mirror from BNC */
typedef long long int int64var;

void withdraw(int64var amount) {
    if (amount % 10000 != 0)
        return (void)printf("KHONG RUT DUOC\n");

    const int64var money[6] = {500000, 200000, 100000, 50000, 20000, 10000};
    int need[6];
    for (size_t i = 0; i < 6; i++)
        need[i] = 0;

    size_t i = 0;
    while (amount != 0) {
        if (amount < money[i]) {
            ++i;
        } else {
            need[i] = need[i] + 1;
            amount -= money[i];
        }
    }
    for (size_t i = 0; i < 6; i++) {
        if (need[i] == 0)
            continue;

        printf("%lld VND: %d\n", money[i], need[i]);
    }
}

int main(void) {
    int64var n;
    scanf("%lld", &n);
    withdraw(n);
    return 0;
}
