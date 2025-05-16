package Spring_2025.ASSIGNMENTS;

import java.util.Scanner;

public class Task_A {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        for (int i=0; i < n; i++){
            int num = in.nextInt();
            in.nextLine();
            if(num % 2 == 0){
                System.out.printf("%d  is an Even number.\n", num);
            } else {
                System.out.printf("%d  is an Odd number.\n", num);
            }
        }
        in.close();
    }
}
