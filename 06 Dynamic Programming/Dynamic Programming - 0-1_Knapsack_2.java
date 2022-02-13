import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException, InterruptedException {
		int N = readInt(),  W = readInt(), dp[] = new int[W+1];
		for(int i=1; i<=N; i++) {
			int val = readInt(), cost = readInt();
			for(int j=W; j>=cost; j--)
				dp[j] = Math.max(dp[j], dp[j-cost] + val);
		}
		System.out.println(dp[W]);
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}
