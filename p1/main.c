#include <stdio.h>

int main(void) {
    int N;
    int found = 0; // 가능한 경우가 있는지 확인하는 변수

    // 1. 금액 N 입력 받기
    scanf("%d", &N);

    // 2. 삼중 for문을 이용한 모든 경우의 수 탐색
    // A 상품 (900원)
    for (int a = 1; a * 900 < N; a++) {
        // B 상품 (750원)
        for (int b = 1; (a * 900) + (b * 750) < N; b++) {
            // C 상품 (200원)
            for (int c = 1; (a * 900) + (b * 750) + (c * 200) <= N; c++) {
                
                // 합계 계산
                int total = (a * 900) + (b * 750) + (c * 200);

                // 조건 체크
                if (total == N) { // 잔돈이 남지 않음
                    if (b % 2 == 0) { // B 상품은 짝수 개
                        if (c < a || c < b) { // C의 수량이 A보다 작거나 B보다 작음
                            printf("%d %d %d\n", a, b, c);
                            found = 1; // 가능한 조합을 찾았음을 표시
                        }
                    }
                }
            }
        }
    }

    // 3. 만족하는 결과가 하나도 없는 경우
    if (found == 0) {
        printf("none\n");
    }

    return 0;
}
