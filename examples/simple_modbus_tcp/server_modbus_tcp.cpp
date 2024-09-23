#include "industrialli_hub.hpp"

industrialli_hub hub;

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(172,16,82,40);

/* Cria um servidor na porta 502.
 */
EthernetServer server(502);

void setup(){
    hub.begin();

    Ethernet.init();
    Ethernet.begin(mac, ip);
    
    /* Inicializa o servidor modbus tcp.
     */
    modbus_server.begin(&server);
    
    /* Inicializa alguns registradores modbus.
     */
    modbus_server.create_status_coil(0, HIGH);
    modbus_server.create_status_coil(1, LOW);
    modbus_server.create_status_coil(2, HIGH);
    modbus_server.create_status_coil(3, LOW);
    modbus_server.create_status_coil(4, HIGH);
    modbus_server.create_status_coil(5, HIGH);
    modbus_server.create_status_coil(6, HIGH);
    modbus_server.create_status_coil(7, LOW);
    modbus_server.create_status_coil(8, HIGH);
    modbus_server.create_status_coil(9, LOW);
    modbus_server.create_status_coil(10, HIGH);

    modbus_server.create_holding_register(0, 2000);
    modbus_server.create_holding_register(1, 2001);
    modbus_server.create_holding_register(2, 2002);
    modbus_server.create_holding_register(3, 2003);
    modbus_server.create_holding_register(4, 2004);
    modbus_server.create_holding_register(5, 2005);
    modbus_server.create_holding_register(6, 2006);
    modbus_server.create_holding_register(7, 2007);
    modbus_server.create_holding_register(8, 2008);
    modbus_server.create_holding_register(9, 2009);
    modbus_server.create_holding_register(10, 2010);
}

void loop(){
        /* A função task() é responsável por receber, processar
         * e responder as requisições modbus dos clientes.
     	 */
	modbus_server.task();
}