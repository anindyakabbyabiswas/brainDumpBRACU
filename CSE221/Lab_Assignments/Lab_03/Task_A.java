import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class Task_A {
    public static long mergeSort(int[] arr, int left, int right){
        long count = 0;
        if (left < right){
            int mid = left + (right - left) / 2;
            count += mergeSort(arr, left, mid);
            count += mergeSort(arr, mid+1, right);
            count += merge(arr, left, mid, right);
        }
        return count;
    }
    public static long merge(int[] arr, int left, int mid, int right){
        int[] l_arr = new int[mid-left+1];
        int[] r_arr = new int[right-mid];
        int count = 0;

        for (int i = left; i <= mid; i++){
            l_arr[i-left] = arr[i];
        }
        for (int i = mid+1; i <= right; i++){
            r_arr[i-(mid+1)] = arr[i];
        }

        int i = 0,j = 0;
        int a = left;
        while (i < l_arr.length && j < r_arr.length ){
            if (l_arr[i] <= r_arr[j]){
                arr[a] = l_arr[i];
                i++;
            } else{
                arr[a] = r_arr[j];
                count += l_arr.length-i;
                j++;
            }
            a++;
        }

        while (i < l_arr.length){
            arr[a] = l_arr[i];
            i++;
            a++;
        }

        while (j < r_arr.length){
            arr[a] = r_arr[j];
            j++;
            a++;
        }
        return count;
    }
    public static long mergeSort(int[] arr){
        return mergeSort(arr, 0, arr.length-1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int N = Integer.parseInt(in.readLine());
        int[] A = Arrays.stream(in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        out.println(mergeSort(A));
        for (int i: A){
            out.print(i + " ");
        }
        out.flush();
        out.close();
        in.close();
    }
}
