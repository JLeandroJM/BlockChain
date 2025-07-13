cmake_minimum_required(VERSION 3.21)
project(proyecto_proyecto_grupo_4)

set(CMAKE_CXX_STANDARD 14)

# Rutas de inclusión y enlace de OpenSSL
set(OPENSSL_ROOT_DIR /opt/homebrew/opt/openssl@3)
find_package(OpenSSL REQUIRED)

# Agregar las rutas de inclusión
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(
        proyecto_proyecto_grupo_4
        main.cpp
        blockchain/block.h
        blockchain/blockchain.h
        estructuras/forward_list.h
        estructuras/heap.h
        estructuras/hash.h
        blockchain/retiro.h
        estructuras/circular_array.h
        estructuras/vector.h
        estructuras/Iterator.h
        blockchain/usuario.h
        blockchain/sistema.h


        estructuras/double.h
        estructuras/trie.h interfaz/block.h interfaz/blockchain.h interfaz/button.h interfaz/clientes.h interfaz/funciones.h interfaz/label.h interfaz/login.h interfaz/register.h interfaz/registrosblock.h interfaz/TextInput.h interfaz/textshow.h interfaz/view.h interfaz/viewmanager.h blockchain/sistema.h estructuras/forward_list.h estructuras/IteratorF.h)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
# Enlazar la librería OpenSSL
target_link_libraries(proyecto_proyecto_grupo_4 OpenSSL::Crypto sfml-system
        sfml-window
        sfml-graphics
        sfml-audio)
