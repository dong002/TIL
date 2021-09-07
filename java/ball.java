public class ball{
	double radius = 2.0;
	double getVolume() {
		return 4/3*3.14*radius*radius*radius;
	}

public static void main(String[] args) {
	ball myball = new ball();
    myball.radius = 3.0;
    myball.getVolume();
    System.out.print(myball);
}
}