import java.util.*;
import java.io.*;
public class Alex_And_Animal_Rights {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static char[][] grid;
	static int [] dx = {1,-1,0,0}, dy = {0,0,1,-1};
	static int R, C;
	public static void main(String[] args) throws IOException{
		R = readInt(); C = readInt();
		grid = new char[R][C];
		for(int i=0; i<R; i++) grid[i] = readLine().toCharArray();
		int cnt = 0;
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(dfs(i, j) == true) cnt++;
			}
		}
		System.out.println(cnt);
	}
	static boolean dfs(int x, int y){
		boolean money = false;
		if(grid[x][y] == 'M') money = true; // change to the object
		grid[x][y]  = 'X';
		for(int i = 0; i < 4; i ++){
			int mx = dx[i] + x, my = dy[i] + y;
			if(mx < 0 || my < 0 || mx >= R || my >= C || grid[mx][my] == 'X' || grid[mx][my] == '#') continue;
			if(dfs(mx, my)) money = !dfs(mx, my);
		}
		return money;
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
