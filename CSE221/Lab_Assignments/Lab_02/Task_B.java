package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_2;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Task_B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] N = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int m = Integer.parseInt(in.readLine());
        int[] M = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        StringBuilder result = new StringBuilder();

        int i = 0;
        int j = 0;
        int ind = 0;
        while (i < n && j < m){
            if (N[i] < M[j]){
                 result.append(N[i]).append(" ");
                i++;
            } else{
                result.append(M[j]).append(" ");
                j++;
            }
            ind++;
        }

        for (int k = i ; k<n; k++){
            result.append(N[k]).append(" ");
        }
        for (int k = j ; k<m; k++){
            result.append(M[k]).append(" ");
        }

        System.out.println(result);
        in.close();
    }
}


