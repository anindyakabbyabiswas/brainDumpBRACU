package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Task_C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int[] n_k = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] a = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int i = 0;
        int j = 0;
        int sum = 0;
        int max = 0;
        while (i < n_k[0] && j < n_k[0]){
            sum += a[i];
            if (sum <= n_k[1]){
                max = Math.max(max, i-j+1);
            }
            if (sum >= n_k[1]){
                sum -= a[j];
                j++;
            }
            i++;
        }
        System.out.println(max);
        in.close();
    }
}
