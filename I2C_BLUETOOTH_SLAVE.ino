/*Universidade Federal do Rio de Janeiro
  Departamento de Engenharia Eletrônica e de Computação
  Sistemas Operacionais Pedro Henrique Cruz Caminha
  Brenno Rodrigues de Carvalho da Silva
*/

// Wire - Version: Latest 
#include <Wire.h>
unsigned char i2c_adress = 0x1;//Valor deve ser alterado para cada dispositivo Slave na rede
char key = 0;//definindo uma chave de controle, 1 para enviar dados, 0 para não enviar


void setup() {
  Wire.begin(i2c_adress);// Definindo como Slave
  Wire.onRequest(sendKey); // register event
  Wire.onRequest(sendData); // register event
  Wire.onReceive(receiveKey);//register event
}

void loop() {
  delay(100);
  //área onde o arduino fará suas operações e coletará os dados de acordo com a função de cada slave
  //os dados a serem enviados devem ser concatenados em uma string
  //A chave deve ser alterada sempre que haver dados para serem enviados.
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveKey(int howMany) {
  char Key = Wire.read();    // receive byte as char
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void sendKey() {
  Wire.write(key); // respond with message of 1 byte
  // as expected by master
}
// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void sendData(char * data){
  Wire.write("%s",data);//enviando os dados desejados, não pode haver mais de 30bytes
}
