include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(ProgramIntegration_X_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(ProgramIntegration_X_default_default_XC8_FILE_TYPE_assemble)
add_library(ProgramIntegration_X_default_default_XC8_assemble OBJECT ${ProgramIntegration_X_default_default_XC8_FILE_TYPE_assemble})
    ProgramIntegration_X_default_default_XC8_assemble_rule(ProgramIntegration_X_default_default_XC8_assemble)
    list(APPEND ProgramIntegration_X_default_library_list "$<TARGET_OBJECTS:ProgramIntegration_X_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(ProgramIntegration_X_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(ProgramIntegration_X_default_default_XC8_assemblePreprocess OBJECT ${ProgramIntegration_X_default_default_XC8_FILE_TYPE_assemblePreprocess})
    ProgramIntegration_X_default_default_XC8_assemblePreprocess_rule(ProgramIntegration_X_default_default_XC8_assemblePreprocess)
    list(APPEND ProgramIntegration_X_default_library_list "$<TARGET_OBJECTS:ProgramIntegration_X_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(ProgramIntegration_X_default_default_XC8_FILE_TYPE_compile)
add_library(ProgramIntegration_X_default_default_XC8_compile OBJECT ${ProgramIntegration_X_default_default_XC8_FILE_TYPE_compile})
    ProgramIntegration_X_default_default_XC8_compile_rule(ProgramIntegration_X_default_default_XC8_compile)
    list(APPEND ProgramIntegration_X_default_library_list "$<TARGET_OBJECTS:ProgramIntegration_X_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(ProgramIntegration_X_default_image_7Ym3xONt ${ProgramIntegration_X_default_library_list})

set_target_properties(ProgramIntegration_X_default_image_7Ym3xONt PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${ProgramIntegration_X_default_output_dir}")
target_link_libraries(ProgramIntegration_X_default_image_7Ym3xONt PRIVATE ${ProgramIntegration_X_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
ProgramIntegration_X_default_link_rule( ProgramIntegration_X_default_image_7Ym3xONt)


