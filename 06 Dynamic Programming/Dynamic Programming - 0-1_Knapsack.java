import java.util.*;
import java.io.*;
public class knapsack {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static item[] items;
	public static void main(String[] args) throws IOException{
		int N = readInt(), W = readInt(); items = new item[N];
		for(int i=0; i<N; i++) {
			int v = readInt(), w = readInt();
			items[i] = new item(v, w);
		}
		System.out.println(Knapsack(W));
	}
	static int Knapsack(int W) {
		int[] dp = new int[W+1];
		for(int i=0; i<items.length; i++) {
			for(int j=W; j>=items[i].w; j--) {
				dp[j] = Math.max(dp[j], items[i].v + dp[j-items[i].w]);
			}
		}
		return dp[W];
	}
	static class item {
		int v, w;
		public item(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}
