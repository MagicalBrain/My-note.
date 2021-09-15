#include "HYSensorClient.h"
//#include "HYGRPCClient.h"
#include "HYWebSocketClient.h"

using namespace hy;

HYSensorClient::Ptr hy::HYSensorClient::Connect(const std::string& uri)
{
	if (uri.substr(0, 5) == "ws://")
	{
		HYWebSocketClient::Ptr client(new HYWebSocketClient);
		if (client->connect(uri))//.substr(5)))
			return client;
	}
	//else if (uri.substr(0, 7) == "grpc://")
	//{
	//	HYGRPCClient::Ptr client(new HYGRPCClient);
	//	if (client->connect(uri.substr(7)))
	//		return client;
	//}
	//else
	//{
	//	HYGRPCClient::Ptr client(new HYGRPCClient);
	//	if (client->connect(uri))
	//		return client;		
	//}
	return nullptr;
}
