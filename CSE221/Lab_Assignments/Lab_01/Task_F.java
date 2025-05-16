package Spring_2025.ASSIGNMENTS;

import java.util.Scanner;
public class Task_F {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int[] ind = new int[n];
        int[] id = new int[n];
        int[] marks = new int[n];


        for (int i = 0; i < n;  i++){
            ind[i] = i;
            id[i] = in.nextInt();
        }

        for (int i = 0; i < n; i++){
            marks[i] = in.nextInt();
        }


        int swaps = 0;
        for (int i = 0; i < n-1; i++){
            int tempInd = i;
            for (int j = i+1; j < n; j++) {
                if (marks[ind[tempInd]] < marks[ind[j]] || (marks[ind[tempInd]] == marks[ind[j]] && id[ind[tempInd]] > id[ind[j]])) {
                    tempInd = j;
                }
            }
            if (i != tempInd){
                swaps++;
                int temp = ind[i];
                ind[i] = ind[tempInd];
                ind[tempInd] = temp;
            }
        }

        System.out.println("Minimum swaps: "+ swaps);
        for (int i = 0; i < n; i++){
            System.out.println("ID: "+id[ind[i]]+" "+"Mark: "+marks[ind[i]]);
        }

    }
}
