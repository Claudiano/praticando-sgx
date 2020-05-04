
# Step 1: Build using script
wget -q https://raw.githubusercontent.com/linux-on-ibm-z/scripts/master/Protobuf/3.11.4/build_protobuf.sh
bash build_protobuf.sh

#Step 2: Install the build dependencies
export SOURCE_ROOT=/$HOME/ferramentas/

sudo apt-get update  
sudo apt-get install -y autoconf automake g++-4.8 git gzip libtool make

sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 10

#Step 3: Build and install
cd $SOURCE_ROOT
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v3.11.4
git submodule update --init --recursive
./autogen.sh
./configure
make
sudo make install
sudo ldconfig


#Step 4: Run tests
cd $SOURCE_ROOT/protobuf
make check

#Step 5: Verify installation
protoc --version
