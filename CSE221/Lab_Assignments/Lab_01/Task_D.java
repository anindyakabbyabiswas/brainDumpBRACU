package Spring_2025.ASSIGNMENTS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Task_D {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());
        for (int i = 0; i < n; i++){
            Long x = Long.parseLong(in.readLine());
            System.out.println((x * x + x)/2);
        }

    }
}
