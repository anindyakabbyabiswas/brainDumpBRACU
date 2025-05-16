package Spring_2025.ASSIGNMENTS;

import java.util.Scanner;
import java.util.StringJoiner;
public class Task_E {
    public static void bubbbleSortMod(int[] num){
        for (int k = 0; k < num.length-1; k++){
            boolean flag = true;
            for (int j = 0; j < num.length-1-k; j++) {
                if (num[j] > num[j+1]){
                    flag = false;
                    int temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
            }
            if(flag){
                break;
            }
        }
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] num = new int[n];
        for (int i = 0; i < n;  i++){
            num[i] = in.nextInt();
        }
        bubbbleSortMod(num);

        StringJoiner numString = new StringJoiner(" ");

        for (int i = 0; i < n;  i++){
            numString.add(String.valueOf(num[i]));
        }
        System.out.println(numString);
    }
}
