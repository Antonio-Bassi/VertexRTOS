set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR armv7-m)

# Default GCC settings
set(TOOLCHAIN_PREFIX arm-none-eabi-)
set(FLAGS "-fdata-sections -ffunction-sections --specs=nano.specs -Wl,--gc-sections")
set(CPP_FLAGS "-fno-rtti -fno-exceptions -fno-threadsafe-statics")

# Define the C compiler
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc ${FLAGS})
# Define the Assembly compiler
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
# Define the C++ compiler 
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++ ${FLAGS} ${CPP_FLAGS})

set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)

# Define the Extensible Linking File extension
set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_EXE_LINKER_FLAGS_INIT "-nostdlib")