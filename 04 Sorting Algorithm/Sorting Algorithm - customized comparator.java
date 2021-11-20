import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		student arr [] = new student[n];
		for(int i=0; i<n; i++) {
			String name = in.next(); 
			int grade = in.nextInt(), age = in.nextInt();
			double score = in.nextDouble();
			arr[i] = new student(name, grade, age, score);
		}
		Arrays.sort(arr, new ageComparator());
		for(int i=0; i<n; i++) {
			arr[i].print();
		}
	}
	static class ageComparator implements Comparator<student>{
		public int compare(student a, student b) {
			return Integer.compare(a.age, b.age);
		}
	}
	static class student {
		static String school;
		String name;
		int grade, age;
		double score;
		student(){ };
		student(String name, int grade, int age, double score) { 
			this.name = name; this.grade = grade; this.age = age; this.score = score; 
		}
		public void print() { System.out.println("name: " + name + " grade: " + grade + " age: " + age); }
	}
}
/*
3
Alice 10 15 96.5
Bob 10 14 93.8
Calvin 9 14 92.5
*/
