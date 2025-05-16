package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
public class Task_A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int[] n_s = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        long[] a = Arrays.stream(in.readLine().split(" ")).mapToLong(Integer::parseInt).toArray();
        int i = 0;
        int j = n_s[0] - 1;
        while (i < j){
            if (a[i]+a[j] == n_s[1]){
                break;
            } else if(a[i]+a[j] < n_s[1]){
                i++;
            } else {
                j--;
            }
        }
        if (i < j){
            System.out.println((i+1) + " " + (j+1));
        } else {
            System.out.println(-1);
        }
        in.close();
    }
}