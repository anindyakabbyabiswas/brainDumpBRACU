package Spring_2025.LAB_ASSIGNMENTS.ASSIGNMENT_3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Task_F {
    public static void preorderCreator(PrintWriter out, int[] inorderIndex, int[] preorder,  int pL, int pR, int rootIndex){

        if (pL > pR){
            return;
        }
        int rootValue = preorder[rootIndex];
        int rootPos = inorderIndex[rootValue-1];

        preorderCreator(out, inorderIndex, preorder, pL, rootPos - 1, rootIndex + 1);
        preorderCreator(out, inorderIndex, preorder,rootPos + 1, pR, rootIndex + (rootPos - pL) + 1);
        out.print(preorder[rootIndex] + " ");
        out.flush();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(in.readLine());
        int[] inorder = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] preorder = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] inorderIndex = new int[N];
        for (int i = 0; i < N; i++){
            inorderIndex[inorder[i]-1] = i;
        }
        preorderCreator(out, inorderIndex, preorder, 0, N-1, 0);
    }
}
