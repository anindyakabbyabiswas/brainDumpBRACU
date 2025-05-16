package Spring_2025.ASSIGNMENT_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Task_D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        for (int tc = 0; tc < t; tc++){
            String s = in.readLine();
            int left = 0;
            int right = s.length() - 1;
            if (s.charAt(right) == '0'){
                System.out.println(-1);
            } else {
                while (left <= right){
                    int mid = (left + right) / 2;
                    if (s.charAt(mid) == '0') {
                        left = mid + 1;
                        if (s.charAt(mid) == '1')
                            break;
                    } else
                        right = mid - 1;
                }
                System.out.println(left+1);
            }
        }
        in.close();
    }
}
