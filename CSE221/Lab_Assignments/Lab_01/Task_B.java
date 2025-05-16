package Spring_2025.ASSIGNMENTS;

import java.util.Scanner;

public class Task_B {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++){
            String[] calc = in.nextLine().split(" ");
            float num = 0;
            if (calc[2].equals("+")){
                num = Float.parseFloat(calc[1]) + Float.parseFloat(calc[3]);
            } else if (calc[2].equals("-")){
                num = Float.parseFloat(calc[1]) - Float.parseFloat(calc[3]);
            } else if (calc[2].equals("/")){
                num = Float.parseFloat(calc[1]) / Float.parseFloat(calc[3]);
            } else if (calc[2].equals("*")){
                num = Float.parseFloat(calc[1]) * Float.parseFloat(calc[3]);
            }
            System.out.println(num);
        }
        in.close();
    }
}
