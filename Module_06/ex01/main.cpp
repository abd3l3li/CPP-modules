#include "Serializer.hpp"

int main()
{
    Serializer::Data data = {1337, "Hi there!"};
    uintptr_t raw = Serializer::serialize(&data);
    Serializer::Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original Data address: " << &data << std::endl;
    std::cout << "Serialized Data address: " << raw << std::endl;
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data content: " << deserializedData->i << ", " << deserializedData->s << std::endl;
}