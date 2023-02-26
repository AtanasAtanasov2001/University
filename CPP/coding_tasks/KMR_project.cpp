#include <iostream>
#include <cstring>

void firstLayer(std::string data, size_t length) {
    std::string header = "firstLayerHeader -> ";
    std::cout << header;
    std::cout << data << " "<< length << "\n";
}
void secondLayer(std::string data, size_t length) {
    std::string header = "secondLayerHeader -> ";
    size_t size = header.size() + length;
    std::cout << header;
    std::cout << data << " "<< length <<  "\n";
    firstLayer(header + data, size);
}
void thirdLayer(std::string data,size_t length) {
    std::string header = "thirdLayerHeader -> ";
    size_t size = header.size() + length;
    std::cout << header;
    std::cout << data<< " "<< length<< "\n";
    secondLayer(header + data, size);
}
void fourthLayer(std::string data,size_t length) {
    std::string header = "fourthLayerHeader -> ";
    size_t size = header.size() + length;
    std::cout << header;
    std::cout << data<< " "<< length<< "\n";
    thirdLayer(header + data, size);
}
void fifthLayer(std::string data, size_t length) {
    std::string header = "fifthLayerHeader -> ";
    size_t size = header.size() + length;
    std::cout << header;
    std::cout << data<< " "<< length<<"\n";
    fourthLayer(header + data, size);
}
void sixthLayer(std::string data, size_t length) {
    std::string header = "sixthLayerHeader -> ";
    size_t size = header.size() + length;
    std::cout << header;
    std::cout << data<< " "<< length <<"\n";
    fifthLayer(header + data, size);
}
void seventhLayer(std::string data, size_t length) {
    std::string header = "seventhLayerHeader -> ";
    size_t size = header.size() + length;
    std::cout << header;
    std::cout << data << " " << length<< "\n";
    sixthLayer(header + data, size);
}


int main(){
    std::string data;
    std::cout << "Please enter the data for the function!" << "\n";
    std::cin >> data;
    seventhLayer(data, data.size());

    return 0;
}