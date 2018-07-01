// drawheart.cpp : 定義主控台應用程式的進入點。
//


#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
char* m = "yYYy";
const int W = 61;
const int H = 61;
int A[W][H] = { 0 };
void fill(int x, int y, int f, int e)
{
	if (x >= 0 && x<W && y >= 0 && y<H)
	if (A[x][y] == e)
	{
		A[x][y] = f;
		fill(x + 1, y, f, e);
		fill(x - 1, y, f, e);
		fill(x, y + 1, f, e);
		fill(x, y - 1, f, e);
	}
}
int main()
{

	int theda;
	int x, y;
	int a = 15;
	for (theda = 0; theda <= 360; theda += 1)
	{
		double angle = theda * 3.14 / 180.;
		x = a * (1 - sin(angle))*cos(angle);
		y = a * (1 - sin(angle))*sin(angle);
		x += 25;
		y += 40;
		A[y][x] = 1;
	}
	fill(0, 0, 1, 0);
	int j = 0;
	for (x = W; x >= 0; x--)
	{
		for (y = 0; y < H; y++)
		{
			if (A[x][y]){ cout << m[j]; j = (j + 1) % strlen(m); }
			else cout << "-";
		}
		cout << endl;
	}
	return 0;
}