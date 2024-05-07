# Modbus-RTU

### Funções
- **create_status_coil**

  Inicializa um registrador do tipo coil.
  
  **Parâmetros:**
    - **uint16_t index:** index do coil. valores possiveis \[1, 10000\] 
    - **bool: value:** valor do coil. valores possiveis \[0, 1\]

  **Retorno:** 

  **Exemplo**
  ```cpp
    modbus.create_status_coil(11, 1);
  ```
- create_input_coil
- create_input_register
- create_holding_register
- set_status_coil
- set_input_coil
- set_input_register
- set_holding_register
- get_status_coil
- get_input_coil
- get_input_register
- get_holding_register

## Servidor

### Funções
- begin
- set_server_address
- get_server_address
- task
- receive_request
- process_request
- send_normal_response
- send_echo_response

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
