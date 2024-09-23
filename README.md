[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# Modbus
Modbus é um dos protocolos de comunicação mais amplamente utilizados na automação industrial. Desenvolvido na década de 1970 pela Modicon, agora parte da Schneider Electric, o Modbus oferece uma estrutura simples e robusta para a troca de dados entre dispositivos em um ambiente industrial. Uma de suas variantes mais comuns é o Modbus RTU (Remote Terminal Unit), uma implementação serial do protocolo que utiliza a transmissão de dados em formato binário. Essa versão é especialmente popular em sistemas que exigem comunicação confiável e eficiente entre dispositivos em distâncias moderadas.

## Diagrama de classe
Diagrama de classe básico, contendo apenas os métodos públicos acessiveis ao usuário. As classes se encontram no diretório includes/ e seus métodos no diretório src/.

<p align="center">
  <img src="https://github.com/Industrialli/industrialli_modbus/blob/Arduino/class_diagram.png" />
</p>

## Diagrama de sequência
O fluxo da comunicação entre cliente e servidor via modbus é bastante simples. Basicamente o cliente, ao executar uma das seguintes funções modbus: read_coils, read_input_coils, read_holding_registers, read_input_registers, write_single_coil, write_single_register, write_multiple_coils e write_multiple_registers, ira enviar uma requisição para os servidores. Todos os servidores irão receber a mensagem através da função task(), está ira processar e responder somente se a requisição for destinada a ela.

<p align="center">
  <img src="https://github.com/Industrialli/industrialli_modbus/blob/Arduino/sequence_diagram.png" />
</p>

## Diagrama de conexões

<p align="center">
  <img src="https://github.com/Industrialli/industrialli_modbus/blob/Arduino/industrialli_hub_rs485.png" />
</p>
