
//Clase extendida de Thread
class miHilo extends Thread{
	@Override
	public void run(){
		for (int i = 0; i<=10; i++) {
			System.out.println("Iteración que va: "+ i);

		}
	}
}

public class PruebaHilos1{
    public static void main(String[] args) {
    	System.out.print("Hola de nuevo mundo \n");
    	miHilo H = new miHilo();    
    	H.start();
    	for (int i = 0; i<=10; i++) {
			System.out.println("@@Iteración que va: "+ i);

		}
    }
}