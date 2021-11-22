public static void main(String[] args) throws IOException{
		int n = readInt(); List<Integer> comb = new ArrayList();
		getComb(1, n, comb);
	}
	static void getComb(int i, int n, List<Integer> comb) {
		if(i > n) {
			System.out.println(comb);
			return;
		}
		getComb(i+1, n, comb); //don't choose i
		comb.add(i);
		getComb(i+1, n, comb); //choose i
		comb.remove(comb.size()-1);
	}
