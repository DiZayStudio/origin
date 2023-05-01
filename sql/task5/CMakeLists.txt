cmake_minimum_required(VERSION 3.10)
project(PqxxPrj1)

set(PostgreSQL_ADDITIONAL_VERSIONS "15")
add_subdirectory("C:/libpqxx-7.7.5" libpqxx-build)
add_executable(PqxxPrj1 main.cpp)
target_compile_features(PqxxPrj1 PRIVATE cxx_std_17)
target_link_libraries(PqxxPrj1 pqxx)