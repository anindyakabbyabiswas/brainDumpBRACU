package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Task_B {
    public static long pairSum(long[] arr, int l, int r) {
        if (l >= r){
            return 0;
        }
        int m = l + (r-l)/2;
        long sumL = pairSum(arr, l, m);
        long sumR = pairSum(arr, m+1, r);

        long lMax = Long.MIN_VALUE;
        for (int i = l; i <= m; i++) {
             if (lMax < arr[i]){
                 lMax = arr[i];
             }
        }

        long rMax = 0;
        for (int j = m+1; j <= r; j++) {
            long RTemp = arr[j] * arr[j];
            if (rMax < RTemp){
                rMax = RTemp;
            }
        }
        return Math.max(Math.max(sumL, sumR), lMax+rMax);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int N = Integer.parseInt(in.readLine());
        long[] A = Arrays.stream(in.readLine().split(" ")).mapToLong(Long::parseLong).toArray();

        long result = pairSum(A, 0, N - 1);

        out.println(result);

        out.flush();
        out.close();
        in.close();
    }
}
