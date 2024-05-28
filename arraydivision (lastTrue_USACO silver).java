import java.io.*;
import java.util.StringTokenizer;

public class arraydivision {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());
		int length = Integer.parseInt(st.nextToken());
		long k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(r.readLine());

		long[] input = new long[length];
		long sum = 0;

		for(int a = 0; a< length; a++){
			input[a] = Integer.parseInt(st.nextToken());
			sum+= input[a];
		}
		
		//pw.print(workOrNot(6, input, k));
		pw.print(lastTrue(0, sum, input, k)+1);
		pw.close();
	}
	public static boolean workOrNot(long maxVal, long[] arr, long want){
		long cur = 0;
		int arrs = 1;
		for(int i = 0; i< arr.length; i++){
			if(arr[i]>maxVal) return false;
			cur+=arr[i];
			if(cur > maxVal){
				arrs++;
				cur = arr[i];
			}
		}
		if(arrs <= want){
			return true;
		}
		return false;
	}
	public static long lastTrue(long lo, long hi, long[] arr, long want) {  
		// This question case: we are looking for last false, then plus one

		// if none of the values in the range work, return lo - 1
		lo--;
		while (lo < hi) {
			// find the middle of the current range (rounding up)
			long mid = lo + (hi - lo + 1) / 2;
			if (!workOrNot(mid,arr,want)) {
				// if mid works, then all numbers smaller than mid also work
				lo = mid;
			} else {
				// if mid doesn't work, greater values would not work either
				hi = mid - 1;
			}
		}
		return lo;
	}
}
