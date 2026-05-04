#include <stdio.h>

int main(void) {
    int N;
    bool found = false; 

    scanf("%d", &N);

    for (int a = 1; a * 900 < N; a++) {
        for (int b = 1; (a * 900) + (b * 750) < N; b++) {
            for (int c = 1; (a * 900) + (b * 750) + (c * 200) <= N; c++) {
                
                int total = (a * 900) + (b * 750) + (c * 200);

                // 조건 체크
                if (total == N) {
                    if (b % 2 == 0) {
                        if (c < a || c < b) {
                            printf("%d %d %d\n", a, b, c);
                            found = true; 
                        }
                    }
                }
            }
        }
    }
    if (!found) {
        printf("none\n");
    }

    return 0;
}
