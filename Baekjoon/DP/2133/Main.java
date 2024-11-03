import java.util.*;

class Main {
    static long D[] = new long[5001];
    static long F[] = new long[5001];
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();
        System.out.println(solution(input));
	}
    private static int solution(int n) {
        D[0] = 1;
        D[2] = 3;
        F[0] = D[0] * 2;
        F[2] = D[2] * 2 + F[0];
        for (int i = 4; i <= n; i++) {
            if (i % 2 == 1)
                D[i] = 0;
            else {
                D[i] = (D[i-2]*D[2] + F[i-4]) % 1000000007;
                F[i] = (D[i]*2 + F[i-2]) % 1000000007;
            }
        }
        return (int)D[n];
    }
}
