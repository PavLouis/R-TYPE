/*
** EPITECH PROJECT, 2022
** SF
** File description:
** SFserveurTCP
*/

#include "EntityTypes.hpp"
#include "Loader.hpp"
#include "NetworkException.hpp"
#include "RT_Enemy.hpp"
#include "RT_Position.hpp"
#include "Registry.hpp"
#include "commande.hpp"
#include "getEntity.hpp"
#include "sfClient.hpp"

#include <SFML/Network.hpp>
#include <cstring>
#include <iostream>
#include <mutex>

#include <cstdlib>
#include <iostream>

std::string getInfoStepByStep(char *infoArry, char c) noexcept;
void getProjectilInfo(EntityTypes type, sf::Packet &receivedPacket, int id,
                      rt::Registry *r, Loader *t);
void getEnemyInfo(EntityTypes type, sf::Packet &receivedPacket, int id,
                  rt::Registry *r, Loader *t);

//////////////////////////////////////////////////////////////
///@brief connection Tcp client to server
///@param sfIpAddress SF ip adress
///@param int Int for server Port
//////////////////////////////////////////////////////////////
int ClientCom::connectionTCP(const sf::IpAddress &remoteAddress,
                             unsigned short port) {
  sf::TcpSocket socket;
  sf::Socket::Status status = socket.connect(remoteAddress, port);

  if (status != sf::Socket::Done) {
    return 84;
  }
  std::string token = "OK";
  char data[100];
  std::string dataStr;
  std::size_t received;
  int J = 0;

  memset(data, 0, 100);
  while (token.compare(dataStr) != 0) {
    if (dataStr.length() == 0)
      if (socket.receive(data, 100, received) != sf::Socket::Done) {
        throw NetworkException(
            "ERROR ON COMMUNICATION WITH SERV FROM CLIENT TCP!");
      }
    dataStr = getInfoStepByStep(data, '$');
    if (dataStr.find('j') != std::string::npos)
      J = dataStr[dataStr.find('j') + 1] - '0';
  }
  return J;
}

//////////////////////////////////////////////////////////////
///@brief handleInformation from packect received
///@param sfPacket received packet from server
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
//////////////////////////////////////////////////////////////
inline void handleInformation(sf::Packet &receivedPacket, rt::Registry *r,
                              Loader *t) {
  sf::Int8 type(-1);

  while (receivedPacket.getDataSize() > 0 && type != -2) {
    // use data received
    sf::Int16 j(-1);
    float x(-1);
    float y(-1);
    while (receivedPacket >> j >> type) {
      if (type == MOVE) {
        if (receivedPacket >> x >> y) {
          if ((int)j < infoFromServ.positions.size()) {
            infoFromServ.mut.lock();
            infoFromServ.positions.at((int)j).x = x;
            infoFromServ.positions.at((int)j).y = y;
            infoFromServ.mut.unlock();
          }
        }
      } else if (type == kill) {
        std::cout << "c'est tuer mec\n";
      } else {
        getEnemyInfo((EntityTypes)type, receivedPacket, j, r, t);
        getProjectilInfo((EntityTypes)type, receivedPacket, j, r, t);
      }
    }
    receivedPacket.clear();
  }
}

//////////////////////////////////////////////////////////////
///@brief manage UDP communication from server
///@param stdstring IP server
///@param unsignedshort for server Port
///@param sfInt8 Index
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
//////////////////////////////////////////////////////////////
int ClientCom::communicationUDP(std::string IP, unsigned short port, sf::Int8 jx,
                              rt::Registry *r, Loader *t) {
  sf::UdpSocket socket;
  std::string message = "Hi, I am j" + std::to_string(jx) + " " +
                        sf::IpAddress::getLocalAddress().toString();
  char buffer[BUFFER_SIZE];
  std::size_t received = 0;
  sf::IpAddress sender;
  sf::IpAddress tmpSender;
  sf::Packet receivedPacket;
  sf::Clock clock;
  sf::Clock clockRecup;
  unsigned short tmpPort = port;

  infoFromServ.mut.lock();
  infoFromServ.j = jx;
  infoFromServ.mut.unlock();
  socket.setBlocking(0);
  while (1) {
    if (clock.getElapsedTime().asMilliseconds() >= 168) {
      sf::Int8 move = 0;
      sf::Int8 shot = 2;
      infoFromServ.mut.lock();
      infoFromServ.packetForServ << sf::Int8(END);
      socket.send(infoFromServ.packetForServ, IP, port);
      infoFromServ.packetForServ.clear();
      infoFromServ.mut.unlock();
      clock.restart();
    }
    tmpPort = port;
    tmpSender = sender;
    socket.receive(receivedPacket, tmpSender, tmpPort);
    handleInformation(receivedPacket, r, t);
  }
}

//////////////////////////////////////////////////////////////
///@brief manage communication with server
///@param int Int for server Port
///@param charpointer IP server
///@param sfInt8 Index
///@param r Registry that store every Components Type
///@param Loader loader for texture load from file
//////////////////////////////////////////////////////////////
void communicationServ(int port, const char *ip, rt::Registry *r,
                       Loader *t) {
  ClientCom cl;
  int jx = cl.connectionTCP(ip, port);

  if (jx == 84)
    throw NetworkException("ERROR ON COMMUNICATION WITH SERV FROM CLIENT TCP!");
  cl.communicationUDP(ip, port + 1, jx, r, t);
}
