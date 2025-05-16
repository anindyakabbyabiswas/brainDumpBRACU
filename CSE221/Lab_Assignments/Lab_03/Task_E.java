package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintWriter;

public class Task_E {
    public static int binaryTree(int[] A, int[] B, int l, int r, int count) {
        if (l > r){
            return count;
        }

        int m = (l + r )/ 2;
        B[count] = A[m];
        count++;
        count = binaryTree(A, B, l, m-1, count);
        count = binaryTree(A, B, m+1, r, count);
        return count;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(in.readLine());
        int[] A = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] B = new int[N];
        out.println(binaryTree(A, B, 0, N-1, 0));
        for(int b: B){
            out.print(b + " ");
        }
        out.flush();
        out.close();
        in.close();
    }

}
