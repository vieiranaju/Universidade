package Lista_06.Reptiles;

abstract class Reptile{
	public final void layEggs(){ System.out.println("Reptile laying eggs");
	}
	
	public static void main(String[] args){
		Reptile reptile = new Lizard();
		reptile.layEggs();
	}
}
