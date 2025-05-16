package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Task_D {
    public static long exponentialMODRevisited(long a, long n, long mod) {
        long nTemp = n;
        long aTemp = a % mod;
        long count = 1;
        a = aTemp;
        if (a == 1){
            return n % mod;
        }
        long res = a;
        while (n > 1) {
            count += count;
            res = (res + (res * a)) % mod;
            a = (a * a) % mod;
            n >>= 1;
        }
        if (nTemp > count){
            res = (res + (a * exponentialMODRevisited(aTemp, nTemp- count, mod))) % mod;
        }
        return res;
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
