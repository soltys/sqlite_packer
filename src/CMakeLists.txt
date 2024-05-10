set(EMBEDED_FILES "create_file_table.sql" "create_store_table.sql" "insert_key_value.sql")
add_custom_target(packer_resources SOURCES ${EMBEDED_FILES})
source_group("Embeded Files" REGULAR_EXPRESSION ".*sql.hpp$")
embed_resources(LIBRARY_RESOURCES_HPP CONTENT_AS_COMMENT FILES ${EMBEDED_FILES} )

add_executable(packer 
    main.cpp
    json.hpp 
    Utils.cpp
    Utils.h
    Packer.cpp
    Packer.h
    PackerArgument.h
    PackerArgument.cpp
    JsonPackSource.h
    JsonPackSource.cpp
    SqlitePackSink.h
    SqlitePackSink.cpp
    PackSource.h
    PackSink.h
    KeyValuePackType.hpp
    FilePackType.hpp
    options/Flags.hpp 
    options/getopt.cpp 
    options/getopt.h 
    ${LIBRARY_RESOURCES_HPP})
target_link_libraries(packer SQLiteCpp sqlite3)
target_include_directories(packer PRIVATE ${PROJECT_BINARY_DIR} SQLiteCpp sqlite3)
set_target_properties(packer PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "-f -i ${CMAKE_SOURCE_DIR}/example/example_data.json -o ${CMAKE_BINARY_DIR}/res.db")