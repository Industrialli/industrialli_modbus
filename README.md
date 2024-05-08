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
rs485_usart2_serial.begin(9600);
modbus.begin(&rs485_usart2_serial);
```
</details>

## Cliente

### Funções

- begin
- send_request
- receive_response
- read_coils
- read_input_coils
- read_holding_register
- read_input_register
- write_single_coil
- write_single_register
- write_multiple_coils
- write_multiple_registers
