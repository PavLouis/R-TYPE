/*
** EPITECH PROJECT, 2022
** SF
** File description:
** SFserveur
*/

#include "sfServeur.hpp"
#include "commande.hpp"
#include <SFML/Network.hpp>
#include <cstring>
#include <iostream>
#include <mutex>
#include <thread>

#include <cstdlib>
#include <iostream>

struct waitForConection_t {
  sf::TcpSocket *client;
  int *nombreDeConextion;
  int *jX;
  std::mutex *mutexJX;
};

std::string getInfoStepByStep(char *infoArry, char c) noexcept;

//////////////////////////////////////////////////////////////
///@brief Wait for the connection of client
///@param waitForConection_t structure waitForConnection for client to server
//////////////////////////////////////////////////////////////
void waitConection(waitForConection_t yes) {
  yes.mutexJX->lock();
  int jX = *yes.jX += 1;
  yes.mutexJX->unlock();
  sf::TcpSocket *client = yes.client;
  *yes.nombreDeConextion += 1;
  std::string bienvenu = "bienvenu tu est j" + std::to_string(jX) + "$";
  char data[] = "met ton zizi dans ...$";

  if (client->send(bienvenu.c_str(), strlen(bienvenu.c_str())) !=
      sf::Socket::Done) {
    // erreur...
  } else
    std::cout << "il y a " << *yes.nombreDeConextion << " client de conecter"
              << std::endl;
  char fin[] = "OK$";
  while (1) {
    if (*yes.nombreDeConextion == 4) {
      if (client->send(fin, strlen(data)) != sf::Socket::Done) {
        // erreur...
      }
      break;
    }
  }
}

//////////////////////////////////////////////////////////////
///@brief Creation TCP-Connetion
///@param int Int for server Port
//////////////////////////////////////////////////////////////
int createTcpConnetion(int port) {
  std::thread threadArry[4];
  sf::TcpListener listener;
  int nombreDeCo = 0;
  int jX = 0;
  std::mutex mutexJX;
  waitForConection_t conextionStruct;
  conextionStruct.nombreDeConextion = &nombreDeCo;
  conextionStruct.jX = &jX;
  conextionStruct.mutexJX = &mutexJX;

  // lie l'écouteur à un port
  if (listener.listen(port) != sf::Socket::Done) {
    std::cout << "ereur port" << std::endl;
    return 84;
  }

  // accepte une nouvelle connexion
  sf::TcpSocket client[4];
  for (int i = 0; i < 4; i += 1) {
    if (listener.accept(client[i]) != sf::Socket::Done) {
      i -= 1;
      continue;
      // erreur...
    }
    conextionStruct.client = &client[i];
    threadArry[i] = std::thread(waitConection, conextionStruct);
  }
  for (int i = 0; i < 4; i += 1) {
    threadArry[i].join();
  }
  std::cout << "hummmmm\n";
  return 0;
}

class jComunication {
private:
public:
  unsigned short port2;
  sf::IpAddress sender;
  jComunication(/* args */) { port2 = 0; }

  ~jComunication();
};

void commandMoveForServer(sf::Packet &recoveryPacket, command_e command,
                          sf::Int8 jX);
void commandShotForServer(sf::Packet &recoveryPacket, command_e command,
                          sf::Int8 jX);

//////////////////////////////////////////////////////////////
///@brief Lunch different command to Server
///@param sfPacket Recovery Packet for data lost
///@param sfInt8 Index
//////////////////////////////////////////////////////////////
void launchCommand(sf::Int8 jX, sf::Packet &recoveryPacket) {
  command_e command;
  sf::Int8 x;

  while (1) {
    if (!(recoveryPacket >> x)) {
      std::cerr << "ERROR COMANDE\n";
      break;
    }
    command = (command_e)x;
    if (command == END)
      return;
    infoServ.players.at(jX).state = statePlayer::READY;
    commandMoveForServer(recoveryPacket, command, jX);
    commandShotForServer(recoveryPacket, command, jX);
  }
}

//////////////////////////////////////////////////////////////
///@brief get severals Information from client to server
///@param sfUdpSocket UdpSocket for update client
///@param unsignedshort Port for client information
///@param unsignedshort Port-array
///@param sfIpAddress SF ip adress
///@param sfClock clock
//////////////////////////////////////////////////////////////
void getInfoClient(sf::UdpSocket &socket, unsigned short port,
                   unsigned short portArry[4], sf::IpAddress senderArry[4],
                   sf::Clock &clock2) {
  sf::Packet recoveryPacket;
  sf::IpAddress sender;
  sf::Packet packetSend;

  socket.receive(recoveryPacket, sender, port);
  mut.lock();
  if (recoveryPacket.getDataSize() > 0) {
    sf::Int8 jX = -1;
    sf::Int8 shoot = -1;
    float moveX(0), moveY(0);
    if (recoveryPacket >> jX) {
    }
    jX -= 1;
    if (jX >= 0 && jX <= 3) {
      launchCommand(jX, recoveryPacket);
      portArry[jX] = port;
      senderArry[jX] = sender;
    }
    jX += 1;
  }
  bool val = false;
  if (clock2.getElapsedTime().asMilliseconds() >= 16) {
    val = true;
    clock2.restart();
  }
  for (int i = 0; i <= 3; i += 1) {
    for (size_t x = 0; x < NB_MAX_PLAYERS; x++) {
      packetSend << sf::Int16(x) << sf::Int8(MOVE) << infoServ.players.at(x).x
                 << infoServ.players.at(x).y; // SF::STRING
      if (val) {
        socket.send(packetSend, senderArry[i], portArry[i]);
        infoServ.mutEntity.lock();
        socket.send(infoServ.sendPacketEntity, senderArry[i], portArry[i]);
        infoServ.mutEntity.unlock();
      }
      packetSend.clear();
    }
  }
  infoServ.mutEntity.lock();
  infoServ.sendPacketEntity.clear();
  infoServ.mutEntity.unlock();
  packetSend.clear();
  recoveryPacket.clear();
  mut.unlock();
}
//////////////////////////////////////////////////////////////
///@brief Manage UdpServer for message and socketCreation
///@param unsignedshort Port for client information
//////////////////////////////////////////////////////////////
int UDPServer(unsigned short port) {
  unsigned short portArry[4] = {0};
  sf::IpAddress senderArry[4] = {"0.0.0.0"};

  // Create a socket and bind it to the port 30000
  sf::UdpSocket socket;
  socket.bind(port);

  // Receive a message from anyone
  sf::Clock clock2;
  socket.setBlocking(0);
  while (1) {
    getInfoClient(socket, port, portArry, senderArry, clock2);
  }
}

//////////////////////////////////////////////////////////////
///@brief Manage communication Fonction
///@param int Port for server connection
//////////////////////////////////////////////////////////////
void communication(int port) {
  createTcpConnetion(port);
  std::cout << "la conextion a été etablie il est temps de jouer\n";
  UDPServer(port + 1);
}
