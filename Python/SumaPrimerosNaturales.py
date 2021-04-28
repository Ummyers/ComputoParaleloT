from viztracer import VizTracer
import threading
import time


sumaTotal = 0

## output_file = <Nombre del archivo de salida.html>
with VizTracer(output_file="grafica.html") as tracer: 

	def sumIntervalo(idHilo,tamIntervalo,numHilos):
		print('El chingado hilo!')
		global sumaTotal
		print('El chingado hilo, otra vez! ')

		for i in range(idHilo,tamIntervalo,numHilos):
		    sumaTotal+=i
		    print('>>>>La suma es: ',sumaTotal, 'idHilo',idHilo)
		print('lol')

## threading.Thread(name = <<Nombre del hilo>>, target = <<>>)
	# t = threading.Thread(name='Ejecuta my_service', target=my_service)
	# w = threading.Thread(name='worker', target=worker)
	# w2 = threading.Thread(target=worker)  # use default name

	hilo1 = threading.Thread(name = 'Hilo_1',target=sumIntervalo, args=(1,100,3))
	# time.sleep(0.001)
	hilo2 = threading.Thread(name = 'Hilo_2',target=sumIntervalo, args=(2,100,3))
	hilo3 = threading.Thread(name = 'Hilo_3',target=sumIntervalo, args=(3,100,3))

	# w.start()
	# t.start()
	# w2.start()
	# time.sleep(0.1)
	hilo1.start()
	hilo2.start()
	hilo3.start()
	print('La suma total es: ', sumaTotal)


idHilo = 1
tamIntervalo = 100
numHilos = 2
suma = 0

for j in range(idHilo,tamIntervalo,numHilos):
	suma+=j

idHilo = 2  

for k in range(idHilo,tamIntervalo,numHilos):
    suma+=k


print('<Fuera de hilos>La suma es: ', suma)
print('<Fuera de hilos>La suma total es: ', sumaTotal)
    