package Spring_2025.ASSIGNMENTS;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Task_G {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        String[] trains = new String[n];
        String[] locations = new String[n];
        String[] times = new String[n];
        int[] ind = new int[n];

        for (int i = 0; i < n; i++){
            ind[i] = i;
            String[] dataT = in.readLine().split(" ");
            trains[i] = dataT[0];
            locations[i] = dataT[4];
            times[i] = dataT[6];
        }

        for (int k = 0; k < n-1; k++){
            boolean flag = true;
            for (int j = 0; j < n-1; j++) {
                if (trains[ind[j]].compareTo(trains[ind[j+1]]) > 0 || (trains[ind[j]].compareTo(trains[ind[j+1]]) == 0 && times[ind[j]].compareTo(times[ind[j+1]]) < 0)){
                    flag = false;
                    int temp = ind[j];
                    ind[j] = ind[j+1];
                    ind[j+1] = temp;
                }
            }
            if(flag){
                break;
            }
        }

        for (int l = 0; l < n; l ++){
            System.out.printf("%s will departure for %s at %s%n", trains[ind[l]], locations[ind[l]], times[ind[l]]);
        }

        in.close();
    }
}

