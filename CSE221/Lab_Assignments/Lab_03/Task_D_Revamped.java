package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Task_D_Revamped {
    public static long exponentialMODRevisited(long a, long n, long mod) {
        a = a % mod;
        if (a == 1) return n % mod;
        if (a == 0) return 0;

        long res = 1;
        long sum = 0;
        while (n > 0) {
            if ((n & 1) == 0){
                sum = (sum + res) % mod;
                res = (res * a) % mod;
                n -= 1;
            } else{
                res = (res * (a+1)) % mod;
                a = (a * a) % mod;
                n >>= 1;
            }
        }
        return ((sum + res - 1) + mod)% mod;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int tc = Integer.parseInt(in.readLine());

        while (tc-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            long a = Long.parseLong(st.nextToken());
            long n = Long.parseLong(st.nextToken());
            long m = Long.parseLong(st.nextToken());
            long result = exponentialMODRevisited(a, n, m);
            sb.append(result).append("\n");
        }
        System.out.print(sb);
        in.close();
    }
}
