package Spring_2025.ASSIGNMENTS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringJoiner;

public class Task_C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] n_k = in.readLine().split(" ");
        int k = Integer.parseInt(n_k[1]);

        String[] nums = in.readLine().split(" ");

        StringJoiner s1 = new StringJoiner(" ");
        for (int i = k - 1; i >= 0; i--) {
            s1.add(nums[i]);
        }
        System.out.println(s1);
    }
}
