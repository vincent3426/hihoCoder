#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[20000];
#define abs(a,b) a-b>0?a-b:b-a

void cmp(int src[], int &Cr, int &Cy, int &Cb) {
	int dst[3];
	bool flag = true;
	dst[0] = abs(Cr, Cy);
	dst[1] = abs(Cr, Cb);
	dst[2] = abs(Cy, Cb);
	sort(src, src + 3); // 升序
	sort(dst, dst + 3); // 升序
	for (int i = 0; i < 3; i++) {
		if (src[i] != dst[i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		Cr = 0;
		Cy = 0;
		Cb = 0;
	}
}

int main() {
	int src[3], sum = 0;
	scanf("%d %d %d", src, src + 1, src + 2);
	scanf("%s", str);
	const int len = strlen(str);
	int Cr = 0, Cy = 0, Cb = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'R') {
			Cr += 1;
		} else if (str[i] == 'Y') {
			Cy += 1;
		} else {
			Cb += 1;
		}
		sum = max(sum, Cr + Cy + Cb);
		cmp(src, Cr, Cy, Cb);
	}
	printf("%d", sum);
	return 0;
}
