package Spring_2025.ASSIGNMENTS;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Task_G_Mod {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String[][] data = new String[n][];

        for (int i = 0; i < n; i++){
            data[i] = in.readLine().split(" ");
        }

        Arrays.sort(data, Comparator.comparing((String[] arr) -> arr[0])
                .thenComparing((String[] arr) -> arr[6], Comparator.reverseOrder()));

        for (String[] i: data){
            System.out.println(String.join(" ", i));
        }

        in.close();
    }
}

