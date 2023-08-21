# Motor controll
![circuit.png](https://i.postimg.cc/NFmQ7Cxh/circuit.png)
Control de la velocidad y dirección de giro de un motor de corriente directa usando un potenciometro.

### Hardware usado
- Kit de desarrollo ESP32.
- Motor CD.
- Fuente 12 V.
- Placa de expansión para ESP32 (opcional).
- Potenciometro 10 K $\Omega$.

### Software y librerias
- Arduino IDE o Arduino CLI.
- Ticker library.
- screen (opcional).

### Configuración
|pin|función|
|---|---|
| 32|pin 1 del motor|
| 33|pin 2 del motor|
|  4|lectura del potenciometro|

### Funcionamiento 
1. La placa ESP se encarga de leer el valor del potenciometro en un rango de `0` a `510`.
2. Usando una resolucion de `8` bits y una frecuencia de `5 KHz`, el motor gira usando dos salidas PWM:
    1. El motor gira en **sentido antihorario** si el valor es menor a `255` en un rango entre `255` y `0`.
    2. El motor gira en **sentido horario** si el valor es mayor a `255` en un rango entre `0` y `255`.
    3. El motor permanece **apagado** si el valor es igual a `255`.
3. Usando la libreria Ticker se envian datos por el puerto serie separados por comas:
    1. El primer dato correspondiente a la velocidad esperada por el motor (entre `-130` y `130` rpm [datos proporcionados por el fabricante] segun el sentido del giro del motor).
    2. El segundo dato corresponde al voltaje que emula salida PWM (entre `0` y `12` V sindo negativa cuando el valor del potenciometro es menor a 255 y positiva cuando es mayor a 255).

