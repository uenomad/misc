### Fully associative cache

A memory block can occupy any of the cache lines.

### Data eviction (desalojo)

Is the process to replace a data cache block when space for a new line is required.

### Inclusive cache

This means that all cache lines that are currently in L1 are contained in L2 and L3 cache as well (same for all lines in L2 that are also present in L3).

### Victim cache

Is a non-incluse cache cache that holds evicted data (the victim) from a lower level cache, but not reads data from DRAM. That lower level cache would retrieve the data directly from DRAM in case the victim cache doesn't hold the requested data.

### Types of cache instructions

| Request (solicitudes)    | Description                                                                                                                                                                                                                                                                                                                     |
|--------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Read                     | La CPU quiere leer un valor de memoria que se encuentra en otro nivel de jerarquía de memoria. Entonces se procede a traer el bloque de datos a la memoria local.                                                                                                                                                               |
| Write                    | La CPU quiere escribir un valor en memoria. Dependiendo del protocolo de coherencia esto puede significar distintas acciones, como adquiri la propiedad exclusiva (RFO), invalidar el bloque en otras cachés o compartirlo con las demás.                                                                                       |
| Invalidate               | La CPU quiere invalidar la copia del bloque de memoria que tienen las cachés de otras CPUs.                                                                                                                                                                                                                                     |
| Write-back               | Cuando una CPU modifica un bloque que se encuentra en un estado modificado o exclusivo, y desea escribirlo de vuelta a memoria principal antes de reemplazarlo en caché. Esto garantiza que los cambios realizados en la caché se propaguen correctamente a la memoria principal y a otras cachés que tengan copias del bloque. |
| Read-for-Ownership (RFO) | vvv                                                                                                                                                                                                                                                                                                                             |

### Ready-for-ownership (RFO)

En un sistema de caché coherente, cuando un procesador necesita leer un valor de memoria que se encuentra en la caché de otro procesador, realiza una solicitud RFO. Esta solicitud implica que el procesador desea leer el valor y también adquirir la propiedad exclusiva de ese bloque de caché. Si el bloque de caché se encuentra en estado modificado o exclusivo en la caché del otro procesador, este debe invalidar o compartir el bloque y luego enviarlo al procesador solicitante.

En el contexto de una RFO (Read For Ownership) request, hacer un "hit" significa que la solicitud de adquirir la propiedad de un bloque de caché obtiene éxito. En otras palabras, si una RFO request realiza un hit, significa que el bloque de caché que se desea adquirir ya está presente en la caché del procesador solicitante.

En un hit de RFO, el procesador adquiere la propiedad del bloque de caché de inmediato y puede proceder a realizar las operaciones de lectura o escritura necesarias en ese bloque sin tener que esperar por la transferencia desde otra caché o la memoria principal. Esto resulta en una menor latencia y un acceso más rápido a los datos, lo cual es beneficioso para el rendimiento del sistema.

Por otro lado, si la solicitud RFO realiza un miss, significa que el bloque de caché solicitado no se encuentra en la caché local del procesador. En este caso, el procesador debe enviar una solicitud al siguiente nivel de la jerarquía de caché (por ejemplo, la caché L2 o la caché L3) o incluso a la memoria principal para obtener el bloque necesario. Una vez que se recibe el bloque solicitado, se adquiere la propiedad y se pueden realizar las operaciones de lectura o escritura requeridas.