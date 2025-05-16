package Spring_2025.ASSIGNMENT_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Task_E {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int[] n_q = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] a = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        StringBuilder result = new StringBuilder();
        for (int c = 0; c < n_q[1]; c++){
            int[] x_y = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            if (x_y[0] > a[n_q[0]-1] || x_y[1] < a[0])
                result.append(0).append("\n");
            else {
                int left = 0;
                int right = n_q[0]-1;
                int ind1 = 0;
                while (left <= right){
                    int mid = left + (right - left) / 2;
                    if (x_y[0] > a[mid]){
                        left = mid + 1;
                    } else {
                        ind1 = mid;
                        right = mid - 1;
                    }
                }

                left = 0;
                right = n_q[0]-1;
                int ind2 = 0;
                while (left <= right){
                    int mid = left + (right - left) / 2;

                    if (x_y[1] < a[mid]){
                        right = mid - 1;
                    } else {
                        ind2 = mid;
                        left = mid + 1;
                    }
                }

                result.append(ind2 - ind1 + 1).append("\n");
            }




        }
        System.out.println(result);


        in.close();
    }
}
