import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static int n, m, maxV = (int)1e5, tree[];
	public static void main(String[] args) throws IOException{	
		n = readInt(); m = readInt(); tree = new int[3*maxV];
		build(0, n-1, 1);
		for( ; m>0; m--) {
			char op = readCharacter(); int x = readInt(), y = readInt();
			if(op == 'M') update(0, n-1, x, y, 1);
			else pr.println(query(0, n-1, x, y, 1));
		}
		pr.close();
	}
	static void build(int l, int r, int idx)  throws IOException {
		if(l == r) { tree[idx] = readInt(); return; }
		int m = (l + r)/2;
		build(l, m, 2*idx); build(m+1, r, 2*idx+1); pushup(idx);
	}
	static void update(int l, int r, int pos, int val, int idx) {
		if(l == r) { tree[idx] = val; return; }
		int m = (l+r)/2;
		if(pos <= m) update(l, m, pos, val, 2*idx);
		else update(m+1, r, pos, val, 2*idx+1);
		pushup(idx);
	}
	static int query(int l, int r, int ql, int qr, int idx) {
		if(l == ql && r == qr) return tree[idx];
		int m = (l + r)/2;
		if(qr <= m) return query(l, m, ql, qr, 2*idx);
		else if(ql > m) return query(m+1, r, ql, qr, 2*idx+1);
		else return Math.min(query(l, m, ql, m, 2*idx), query(m+1, r, m+1, qr, 2*idx+1));
	}
	static void pushup(int idx) {
		tree[idx] = Math.min(tree[2*idx], tree[2*idx+1]);
	}
	static class node {
		int l, r, v;
		node(int l0, int r0, int v0) { l = l0; r = r0; v = v0; }
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
