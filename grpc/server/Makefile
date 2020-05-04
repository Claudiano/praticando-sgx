LDFLAGS = -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl

CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = ./protos

vpath %.proto $(PROTOS_PATH)

all: objFolder server clean

server: mathtest.pb.o mathtest.grpc.pb.o server.o
	@ echo 'server executado'
	$(CXX) $^ $(LDFLAGS) -o ./compilers/$@

%.grpc.pb.cc: %.proto
	@ echo $< debud 1
	protoc -I=$(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<
	@ echo $< debud 1 fim

%.pb.cc: %.proto
	@ echo $< debud 2
	protoc -I=$(PROTOS_PATH) --cpp_out=. $<
	@ echo $< debud 2 fim


objFolder:
	@ echo 'criando pasta compuilers'
	@ mkdir -p compilers


clean:
	rm -f *.o *.pb.cc *.pb.h



