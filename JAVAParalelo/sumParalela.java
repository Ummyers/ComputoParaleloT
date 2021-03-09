//Clase extendida de Thread
class miHilo extends Thread{
	int suma;
	int intervalo;
	int tam; 

	//Metodo de construcción
	public miHilo(int intervalo, int tam){
		suma = 0;
		this.intervalo = intervalo;
		this.tam = tam; 
	}

	@Override
	public void run(){
		// int limDerecho = intervalo+tam;
		int sumaIntervalo = 0;
		for (int i = intervalo; i<=tam; i++) {
			sumaIntervalo += i;
		}
		this.setSum(sumaIntervalo);
        System.out.println("La suma del hilo es: "+sumaIntervalo);
	}


	public void setSum(int s){
        this.suma = s;
    }

	public int getSum(){
        return suma;
    }
}//END miHilo

//Clase donde se implementa la suma de los primeros 1 000 000 000 números naturales. 
//El primer argumento determina el número de hilos por crear.

public class sumParalela{
    public static void main(String[] args) {
    	System.out.print("Inicio de hilo principal\n");
        // String nh = String[1];
        int numHilos = Integer.parseInt(args[0]);
        int sumaTotal = 0;
        int limD = 100;
        int inc = limD/numHilos;
        System.out.println("inc: "+inc);
        int der = 0;
        int izq = 0;
    	System.out.println("Número de hilos es: " + numHilos);
        //Quiero sumar los primeros 
        try
        {
            for (int i=0;i<numHilos;i++) {
                der = i*inc; 
                izq = der+inc-1;
                System.out.println("der: " + der + "izq: "+izq);
                miHilo H = new miHilo(der,izq);
                H.start();
                Thread.sleep(100);
                sumaTotal = sumaTotal + H.getSum();
                H.setSum(0);
                Thread.sleep(100);
                
            } 
            sumaTotal = sumaTotal + limD;  

        }catch(InterruptedException e){}
        System.out.println("La suma total es: "+sumaTotal);
    	//Se crea hilo
    	// miHilo H = new miHilo(1,5);    
    	// H.s tart();

    	/* Es tan rápido el acceso al atributo del objeto 
    	* que se debe detener el hilo principal uno segundo
    	* ya que de otra manera no se obtine lo correspondiente 
    	*/
    	try
        {
            Thread.sleep(1000); // 1000 milisegundos
        }catch(InterruptedException e){}

    	// int sum = H.getSum();
    	// System.out.println("Suma main:" + sum);
    	    	
    }
}