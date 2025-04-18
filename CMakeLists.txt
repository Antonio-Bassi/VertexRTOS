# CMake Settings
cmake_minimum_required(VERSION 3.21)
# Project Settings
project(VTXRTOS)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Project)

# MCU Specific settings
set(MCU_MANUFACTURER ARM)
set(MCU_FAMILY STM32F4xx)
set(MCU_MODEL  STM32F411xx)
set(ARCH_TYPE  CORTEX_M)
set(CPU_PARAMETERS
    -mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard)

# MCU Startup firmware and Linker Script
# @NOTE: These are specific for Cortex-M4 device family.
set(STARTUP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/Arch/${MCU_MANUFACTURER}/${ARCH_TYPE}/${MCU_MODEL}/Src/startup_${MCU_MODEL}.s)
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/Arch/${MCU_MANUFACTURER}/${ARCH_TYPE}/${MCU_MODEL}/${MCU_MODEL}_FLASH.ld)
set(EXECUTABLE ${CMAKE_PROJECT_NAME})
enable_language(C CXX ASM)

# Language Settings
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Project Includes
set(DRIVER_INCLUDE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/Inc)
set(ARCH_INCLUDE_DIR    
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/${MCU_MANUFACTURER}/${ARCH_TYPE}/${MCU_MODEL}/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Arch/${MCU_MANUFACTURER}/${ARCH_TYPE}/core)
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_DIR}/Inc)

#Project sources
file(GLOB_RECURSE DRIVER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/Src/*.c)
file(GLOB_RECURSE PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Project/Src/*.c)
file(GLOB_RECURSE ARCH_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/Arch/${MCU_MANUFACTURER}/${ARCH_TYPE}/${MCU_MODEL}/Src/*.c)

# Executable Files
add_executable( ${PROJECT_SOURCES}
                ${EXECUTABLE}
                ${DRIVER_SOURCES}
                ${ARCH_SOURCES}
                ${STARTUP_SCRIPT}
)

target_compile_definitions(${EXECUTABLE} PRIVATE DEBUG STM32F411xE)
target_include_directories(${EXECUTABLE} PRIVATE ${DRIVER_INCLUDE_DIR} ${ARCH_INCLUDE_DIR} ${PROJECT_INCLUDE_DIR})
target_compile_options(${EXECUTABLE} PRIVATE ${CPU_PARAMETERS}
    -Wall
    -Wextra
    -Wpedantic
    -Wno-unused-parameter
    $<$<COMPILE_LANGUAGE:CXX>:
        -Wno-volatile
        -Wold-style-cast
        -Wuseless-cast
        -Wsuggest-override>
    $<$<CONFIG:Debug>:-O0 -g3 -ggdb>
    $<$<CONFIG:Release>:-O3 -g0>)

target_link_options(${EXECUTABLE} PRIVATE
    -T${LINKER_SCRIPT}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    --specs=nosys.specs
    -Wl,--start-group
    -lc
    -lm
    -lstdc++
    -Wl,--end-group
    -Wl,--print-memory-usage)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}>
    ${EXECUTABLE}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}>
    ${EXECUTABLE}.bin)