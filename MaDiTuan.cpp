#include<iostream>
#include<stdio.h>

#define MAX 8

int d1[8] = { -2,-2,-1,-1, 1, 1, 2, 2 };
int d2[8] = { -1, 1,-2, 2,-2, 2,-1, 1 };
int dem = 0;

bool Check(int BanCo[][MAX],int n, int x, int y)
{
    if (x < 0 || x >= n)
    {
        return false;
    }
    if (y < 0 || y >= n)
    {
        return false;
    }
    if (BanCo[x][y] != 0)
        return false;
    return true;
}

void XuatBanCo(int BanCo[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d  ", BanCo[i][j]);
        }
        printf("\n");
    }
}

void MaDiTuan(int BanCo[][MAX], int n, int i, int x, int y)
{
   
    for (int j = 0; j < 8; j++)  //xet 8 huong di
    {
        int x_new = x + d1[j];
        int y_new = y + d2[j];
        if (Check(BanCo, n, x_new, y_new))// neu vi tri moi con trong thi chon
        {
            BanCo[x_new][y_new] = i;
            if (i == n * n) //neu tim duoc buoc di cuoi cung thi in ket qua va thoat chuong trinh
            {
                dem++;
                printf("Cac buoc di la: \n");
                XuatBanCo(BanCo, n);
                exit(0);
            }
            else
            {
                MaDiTuan(BanCo, n, i + 1, x_new, y_new);
            }
            BanCo[x_new][y_new] = 0;
        }
    }
}

int main()
{
    int BanCo[MAX][MAX] = { 0 };
    BanCo[0][0] = 1;
    MaDiTuan(BanCo, 8, 2, 0, 0);
    if (dem == 0)
    {
        printf("Khong tim duoc thay duong di.\n");
    }
    
    return 0;
}