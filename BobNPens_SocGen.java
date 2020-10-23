import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int s = sc.nextInt();
	    ArrayList<int[]> arr = new ArrayList<int[]>(s);
	    while(s-- > 0){
	        int[] temp = new int[3];
	        for(int i = 0; i < 3; i++){
	            temp[i] = sc.nextInt();
	        }
	        arr.add(temp);
	    }
	    System.out.println(solve(arr, n));
	}
	public static int solve(ArrayList<int[]> arr, int n){
	    if(arr == null || arr.size() == 0 || n == 0){
	        return -1;
	    }
	    Collections.sort(arr, (a,b) -> a[1] + a[2] - b[1] - b[2]);
	    int i = 0, cost = 0;
	    while(n > 0){
	        if(n < arr.get(i)[0]){
	            cost += n*arr.get(i)[1] + arr.get(i)[2];
	            n = 0;
	            break;
	        }
	        else{
	            n = n -arr.get(i)[0];
	            cost += arr.get(i)[0]*arr.get(i)[1] + arr.get(i)[2];
	        }
	        i++;
	    }
	    return cost;
	}
}
