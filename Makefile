
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
CFLAGS = -g
#CFLAGS = -g -I-/opt/homebrew/Cellar/jsoncpp/1.9.5/include/ -I/opt/homebrew/Cellar/libjson-rpc-cpp/1.4.1_1/include -I/opt/homebrew/Cellar/libmicrohttpd/0.9.75/include


# LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

#LDFLAGS = 	-ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl
LDFLAGS =  -L/opt/homebrew/lib/ -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h
INC_CL	=	JvTime.h vehicle.h motorcycle.h car.h
OBJ	=	JvTime.o motorcycle.o car.o vehicle.o

# rules.
#all: 	hw5Forest hw5Home hw5server hw5client 
all: leftMotorcycle rightMotorcycle mainCar hw5server

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

hw5client.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5server.h:		ecs36b_hw5.json
	jsonrpcstub ecs36b_hw5.json --cpp-server=hw5Server --cpp-client=hw5Client

hw5client.o:		hw5client.cpp hw5client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5client.cpp

hw5server.o:		hw5server.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) hw5server.cpp

#hw5Home.o:		hw5Home.cpp hw5server.h $(INC_CL) $(INC)
#	$(CC) -c $(CFLAGS) hw5Home.cpp

#hw5Forest.o:		hw5Forest.cpp hw5server.h $(INC_CL) $(INC)
#	$(CC) -c $(CFLAGS) hw5Forest.cpp

#hw5GrandmaHome.o:		hw5GrandmaHome.cpp hw5server.h $(INC_CL) $(INC)
#	$(CC) -c $(CFLAGS) hw5GrandmaHome.cpp

#hw5another.o:		hw5another.cpp hw5server.h $(INC_CL) $(INC)
#	$(CC) -c $(CFLAGS) hw5another.cpp

#leftMotorcycle.o:		leftMotorcycle.cpp hw5Server.h $(INC_CL)$(INC)
#		$(CC) -c $(CFLAGS) leftMotorcycle.cpp

vehicle.o:		vehicle.cpp vehicle.h $(INC)
	$(CC) -c $(CFLAGS) vehicle.cpp

leftMotorcycle.o:		leftMotorcycle.cpp hw5server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) leftMotorcycle.cpp

rightMotorcycle.o:		rightMotorcycle.cpp hw5server.h $(INC_CL) $(INC)
		$(CC) -c $(CFLAGS) rightMotorcycle.cpp

mainCar.o:		mainCar.cpp hw5server.h $(INC_CL) $(INC)
		$(CC) -c $(CFLAGS) mainCar.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

#person.o:	car.cpp car.h $(INC)
#	$(CC) -c $(CFLAGS) car.cpp

#thing.o:	motorcycle.cpp motorcycle.h $(INC)
#	$(CC) -c $(CFLAGS) motorcycle.cpp

hw5server:	 hw5server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o hw5server hw5server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

mainCar:	mainCar.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mainCar mainCar.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

leftMotorcycle:	leftMotorcycle.o ecs36b_JSON.o $(OBJ)
	$(CC) -o leftMotorcycle leftMotorcycle.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

rightMotorcycle:	rightMotorcycle.o ecs36b_JSON.o $(OBJ)
	$(CC) -o rightMotorcycle rightMotorcycle.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)
#hw5Home:	 hw5Home.o ecs36b_JSON.o $(OBJ)
#	$(CC) -o hw5Home hw5Home.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

#hw5Forest:	 hw5Forest.o ecs36b_JSON.o $(OBJ)
#	$(CC) -o hw5Forest hw5Forest.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

#hw5GrandmaHome:	 hw5GrandmaHome.o ecs36b_JSON.o $(OBJ)
#	$(CC) -o hw5GrandmaHome hw5GrandmaHome.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

#hw5client:	 hw5client.o ecs36b_JSON.o $(OBJ)
#	$(CC) -o hw5client hw5client.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core hw5client.h hw5server.h hw5client hw5server mainCar leftMotorcycle rightMotorcycle