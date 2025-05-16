package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintWriter;

public class Task_C {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        long[] a_b = Arrays.stream(in.readLine().split(" ")).mapToLong(Long::parseLong).toArray();

        a_b[0] %= 107;
        if (a_b[0] == 0){
            out.println(0);
        } else{
            long result = 1;
            while (a_b[1]>0) {
                if ((a_b[1] % 2) != 0) {
                    result = (result * a_b[0]) % 107;
                }
                a_b[1] /= 2;
                a_b[0] = (a_b[0] * a_b[0]) % 107;

            }
            out.write(String.valueOf(result));

        }
        out.flush();
        out.close();
        in.close();
    }
}
