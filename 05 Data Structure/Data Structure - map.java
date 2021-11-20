// HashMap:  Key is not sorted
// TreeMap: Key is sorted 

	public static void main(String[] args) throws IOException{
		HashMap<String, Integer> map1 = new HashMap<>();
		map1.put("hello", 5);
		map1.put("java", 10);
		System.out.println(map1);
		HashMap<String, List<Integer>> map2 = new HashMap<>();
		String para [] = {"hello", "java", "c++", "word", "hello", "java"};
		for(int i=0; i<para.length; i++) {
			String word = para[i];
			if(!map2.containsKey(word)) {
				map2.put(word, new ArrayList<>());
			}
			map2.get(word).add(i);
		}
		System.out.println(map2);
	}

	public static void main(String[] args) throws IOException{
		HashMap<String, Integer> map1 = new HashMap<>();
		map1.put("hello", 5);
		map1.put("java", 10);
		map1.put("world", 2);
		for(String key: map1.keySet()) {
			System.out.println("key = " + key + " value = " + map1.get(key));
		}
		for(int x : map1.values()) {
			System.out.println(x);
		}
		for(Map.Entry<String, Integer> x : map1.entrySet()) {
			System.out.println(x.getKey() + " " + x.getValue());
		}
	}
