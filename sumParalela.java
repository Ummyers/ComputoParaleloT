//Clase extendida de Thread
class miHilo extends Thread{
	public int suma;

	@Override
	public void run(){
		sumaPrimeros sp = new sumaPrimeros();
		suma = sp.sumar(10,4);
		System.out.println("Suma Thread: "+suma);
		this.setSum(suma);
	}

	public void setSum(int s){
        this.suma = s;
    }

	public int getSum(){
        return suma;
    }
}


class sumaPrimeros{
	/*
	* limDerecho: Acota hasta que numero hará la suma
	*/
	public int sumar(int intervalo, int tam){
		//System.out.println("Inicio del intervalo: " + intervalo);
		int sumaIntervalo = 0;
		int limDerecho; 

		for (int i = 0; i<=10; i++) {
			sumaIntervalo += i;
		}
		System.out.println("Objeto clase sumaPrimeros: "+ sumaIntervalo);
		return sumaIntervalo;
	}
}

//Clase donde se implementa la suma de los primeros 1 000 000 000 números naturales. 
public class sumParalela{
    public static void main(String[] args) {
    	System.out.print("Inicio de hilo principal\n");
    	//Se crea hilo
    	miHilo H = new miHilo();    
    	H.start();
    	/* Es tan rápido el acceso al atributo del objeto 
    	* que se debe detener el hilo principal uno segundo
    	* ya que de otra manera no se obtine lo correspondiente 
    	*/
    	try
        {
            Thread.sleep(1000); // 1000 milisegundos
        }catch(InterruptedException e){}
    	int sum = H.getSum();
    	System.out.println("Suma main:" + sum);
    	    	
    }
}