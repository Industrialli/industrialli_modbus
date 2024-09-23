#include "industrialli_hub.hpp"

industrialli_hub hub;
/* Cria um cliente para se conectar com um servidor.
 */
EthernetClient client;

uint8_t mac[]  = {0xDE, 0xAD, 0xBE, 0x68, 0x68, 0x6C};

void setup(){
	hub.begin();

    Ethernet.init();
    Ethernet.begin(mac);

    /* Se conecta no servidor com IP 172.16.82.40 na 
     * porta 502 (servidor modbus tcp).
     */
    client.connect("172.16.82.40", 502);

    /* Inicializa o cliente modbus tcp.
     */
    modbus_client.begin(&client);
 
    /* Cria um registrador do tipo holding com endereço 121
     * e valor 0 para armazenar a leitura obtida do servidor.
     */
    modbus_client.create_holding_register(121, 0);
}

void loop(){
    /* Envia uma requisição para escrever o valor 100 no 
     * registrador de endereço 121 do servidor.
     */
    modbus_client.write_single_register(121, 100);
    delay(500);

    /* Envia uma requisição para ler o valor atual do
     * registrador 121 do servidor.
     */
    modbus_client.read_holding_registers(121, 1);
    delay(500);
}