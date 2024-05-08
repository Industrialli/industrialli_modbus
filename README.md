# Modbus-RTU

### Funções

Segue abaixo as funções genéricas do protocolo Modbus para gerenciamento de registradores.

<details>
<summary>create_status_coil</summary>

Inicializa um registrador do tipo coil.

**Parâmetros:**
- uint16_t index: index do coil. valores possiveis \[1, 10000\] 
- bool: value: valor do coil. valores possiveis \[0, 1\]

**Retorno:** void

**Exemplo**
```cpp
modbus.create_status_coil(11, 1);
```
</details>
  
<details>
<summary>create_input_coil</summary>

Inicializa um registrador do tipo discrete input coil.

**Parâmetros:**

- uint16_t index: index do coil.
- bool: value: valor do coil.

**Retorno:** void

**Exemplo**
```cpp
  modbus.create_input_coil(11, 1);
```
</details>

<details>
<summary>create_input_register</summary>

Inicializa um registrador do tipo input.

**Parâmetros:**

- uint16_t index: index do registrador.
- uint16_t: value: valor do registrador.

**Retorno:** void

**Exemplo**
```cpp
  modbus.create_input_register(15, 1332);
```
</details>

<details>
<summary>create_holding_register</summary>

Inicializa um registrador do tipo holding.

**Parâmetros:**

- uint16_t index: index do registrador.
- uint16_t: value: valor do registrador.

**Retorno:** void

**Exemplo**
```cpp
  modbus.create_holding_register(12, 5543);
```
</details>

<details>
<summary>set_status_coil</summary>

Atualiza um registrador do tipo coil.

**Parâmetros:**
- uint16_t index: index do coil.
- bool: value: valor do coil.

**Retorno:** void

**Exemplo**
```cpp
modbus.set_status_coil(11, 1);
```
</details>
  
<details>
<summary>set_input_coil</summary>

Atualiza um registrador do tipo discrete input coil.

**Parâmetros:**

- uint16_t index: index do coil.
- bool: value: valor do coil.

**Retorno:** void

**Exemplo**
```cpp
  modbus.set_input_coil(11, 1);
```
</details>

<details>
<summary>set_input_register</summary>

Atualiza um registrador do tipo input.

**Parâmetros:**

- uint16_t index: index do registrador.
- uint16_t: value: valor do registrador.

**Retorno:** void

**Exemplo**
```cpp
  modbus.set_input_register(15, 1332);
```
</details>

<details>
<summary>set_holding_register</summary>

Atualiza um registrador do tipo holding.

**Parâmetros:**

- uint16_t index: index do registrador.
- uint16_t: value: valor do registrador.

**Retorno:** void

**Exemplo**
```cpp
  modbus.set_holding_register(12, 5543);
```
</details>

<details>
<summary>get_status_coil</summary>

Retorna o valor de um registrador do tipo coil.

**Parâmetros:**
- uint16_t index: index do coil. valores possiveis \[1, 10000\] 

**Retorno:** bool: value: valor do coil. valores possiveis \[0, 1\]

**Exemplo**
```cpp
bool value = modbus.get_status_coil(11);
```
</details>
  
<details>
<summary>get_input_coil</summary>

Retorna o valor de um registrador do tipo discrete input coil.

**Parâmetros:**

- uint16_t index: index do coil.

**Retorno:** bool: value: valor do coil.

**Exemplo**
```cpp
bool value = modbus.get_input_coil(11);
```
</details>

<details>
<summary>get_input_register</summary>

Retorna o valor de um registrador do tipo input.

**Parâmetros:**

- uint16_t index: index do registrador.

**Retorno:** uint16_t: value: valor do registrador.

**Exemplo**
```cpp
uint16_t value = modbus.set_input_register(15);
```
</details>

<details>
<summary>get_holding_register</summary>

Retorna o valor de um registrador do tipo holding.

**Parâmetros:**

- uint16_t index: index do registrador.

**Retorno:** uint16_t: value: valor do registrador.

**Exemplo**
```cpp
uint16_t value = modbus.get_holding_register(12);
```
</details>

## Servidor

### Funções

Segue abaixo as funções específicas do servidor Modbus RTU.

<details>
<summary>begin</summary>
Inicializa um servidor Modbus RTU.

**Parâmetros:**

- HardwareSerial *_serial: endereço de memória referente a conexão serial.

**Retorno:** void

**Exemplo**
```cpp
rs485_usart2_serial.begin(9600);
modbus.begin(&rs485_usart2_serial);
```
</details>

<details>
<summary>set_server_address</summary>
Define o endereço do servidor Modbus RTU.

**Parâmetros:**

- uint8_t _server_address: endereço do servidor.

**Retorno:** void

**Exemplo**
```cpp
modbus.set_server_address(10);
```
</details>

<details>
<summary>get_server_address</summary>
Retorna o endereço do servidor Modbus RTU.

**Parâmetros:** void

**Retorno:** uint8_t _server_address: endereço do servidor.
</details>

<details>
<summary>task</summary>
Recebe, processa e responde um frame de requisição do cliente.

**Parâmetros:** void

**Retorno:** void

**Exemplo**
```cpp
void loop(){
  modbus.task();
}
```
</details>

## Cliente

### Funções

Segue abaixo as funções específicas do cliente Modbus RTU.

<details>
<summary>begin</summary>
Inicializa um cliente Modbus RTU.

**Parâmetros:**

- HardwareSerial *_serial: endereço de memória referente a conexão serial.

**Retorno:** void

**Exemplo**
```cpp
rs485_usart2_serial.begin(9600);
modbus.begin(&rs485_usart2_serial);
```
</details>

<details>
<summary>read_coils</summary>
Envia uma requisição Modbus RTU do tipo read coils para um servidor.

**Parâmetros:**

- uint8_t _address: endereço do servidor.
- uint16_t _starting_address: endereço de inicio da leitura dos registradores do tipo status coil.
- uint16_t _quantity_of_coils: quantidade de registradores do tipo status coil que serão lidos a partir do endereço de início.

**Retorno:** void

**Exemplo**
```cpp
modbus.read_coils(10, 0, 32);
```
</details>

<details>
<summary>read_input_coils</summary>
Envia uma requisição Modbus RTU do tipo read input coils para um servidor.

**Parâmetros:**

- uint8_t _address: endereço do servidor.
- uint16_t _starting_address: endereço de inicio da leitura dos registradores do tipo input coil.
- uint16_t _quantity_of_coils: quantidade de registradores do tipo input coil que serão lidos a partir do endereço de início.

**Retorno:** void

**Exemplo**
```cpp
modbus.read_input_coils(10, 0, 32);
```
</details>

<details>
<summary>read_holding_registers</summary>
Envia uma requisição Modbus RTU do tipo read holding registers para um servidor.

**Parâmetros:**

- uint8_t _address: endereço do servidor.
- uint16_t _starting_address: endereço de inicio da leitura dos registradores do tipo holding.
- uint16_t _quantity_of_registers: quantidade de registradores do holding que serão lidos a partir do endereço de início.

**Retorno:** void

**Exemplo**
```cpp
modbus.read_holding_registers(10, 0, 32);
```
</details>

<details>
<summary>read_input_registers</summary>
Envia uma requisição Modbus RTU do tipo read input registers para um servidor.

**Parâmetros:**

- uint8_t _address: endereço do servidor.
- uint16_t _starting_address: endereço de inicio da leitura dos registradores do tipo input.
- uint16_t _quantity_of_registers: quantidade de registradores do input que serão lidos a partir do endereço de início.

**Retorno:** void

**Exemplo**
```cpp
modbus.read_input_registers(10, 0, 32);
```
</details>

<details>
<summary>write_single_coil</summary>
Envia uma requisição Modbus RTU do tipo write single coil para um servidor.

**Parâmetros:**

- uint8_t _address: Endereço do servidor.
- uint16_t _coil_address: endereço do coil.
- uint16_t _value: valor do coil.

**Retorno:** void

**Exemplo**
```cpp
modbus.write_single_coil(10, 5, 0xFF00);
```
</details>

<details>
<summary>write_single_register</summary>
Envia uma requisição Modbus RTU do tipo write single register para um servidor.

**Parâmetros:**

- uint8_t _address: Endereço do servidor.
- uint16_t _register_address: endereço do registrador do tipo holding.
- uint16_t _value: valor do registrador.

**Retorno:** void

**Exemplo**
```cpp
modbus.write_single_register(10, 5, 6454);
```
</details>


<details>
<summary>write_multiple_coils</summary>
Envia uma requisição Modbus RTU do tipo write nultiple coils para um servidor.

**Parâmetros:**

- uint8_t _address: endereço do servidor.
- uint16_t _starting_address: endereço de inicio dos registradores do tipo coil que serão alterados os valores.
- uint8_t* _values: vetor boleano que contem os novos valores dos registradores do tipo coil.
- uint16_t _quantity_of_coils: quantidade de registradores do tipo coil que terão seus valores atualizados.

**Retorno:** void

**Exemplo**
```cpp
uint8_t values[5] = {0,1,1,0,1};
modbus.write_multiple_coils(10, 0, values, 5);
```
</details>

<details>
<summary>write_multiple_registers</summary>
Envia uma requisição Modbus RTU do tipo write nultiple registers para um servidor.

**Parâmetros:**

- uint8_t _address: endereço do servidor.
- uint16_t _starting_address: endereço de inicio dos registradores do tipo holding que serão alterados os valores.
- uint16_t* _values: vetor que contem os novos valores dos registradores do tipo holding.
- uint16_t _quantity_of_coils: quantidade de registradores do tipo holding que terão seus valores atualizados.

**Retorno:** void

**Exemplo**
```cpp
uint8_t values[5] = {423,22,324,2,1};
modbus.write_multiple_registers(10, 0, values, 5);
```
</details>
