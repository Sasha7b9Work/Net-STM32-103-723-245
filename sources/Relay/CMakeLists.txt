# (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by

project (Relay)

message("------------------------------------------------------------------------ ${PROJECT_NAME}")

include_directories(
    ../common/_VS_KEIL/CMSIS/
    ../common/_VS_KEIL/std_includes/
    ../common/STM32Cube_F1/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc/
    ../common/STM32Cube_F1/Middlewares/ST/STM32_USB_Device_Library/Core/Inc/
    ../common/STM32Cube_F1/Drivers/STM32F1xx_HAL_Driver/Inc/
    ../common/STM32Cube_F1/Drivers/CMSIS/Device/ST/STM32F1xx/Include/
    src/Hardware/HAL/
    src/Hardware/CDC/
    src/
)

add_definitions(-DSTM32F103xB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MP -Wall")

add_compile_options(
    /wd4514    # 'function' : unreferenced inline function has been removed
    /wd4623    # default constructor was implicitly defined as deleted
    /wd4626    # assignment operator was implicitly defined as deleted
    /wd4820    # 'xxx': '4' bytes padding added after data member 'yyy'
    /wd5027    # move assignment operator was implicitly defined as deleted
    /wd5045    # Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
    /wd5220    # a non-static data member with a volatile qualified type no longer implies
    /wd5264
    /wd26812   # The enum type %type% is unscoped. Prefer 'enum class' over 'enum' (Enum.3)
)

file(GLOB STM32F1                   ../common/STM32Cube_F1/Drivers/STM32F1xx_HAL_Driver/Src/*.c
                                    ../common/STM32Cube_F1/Drivers/STM32F1xx_HAL_Driver/Inc/*.h)
file(GLOB SRC                       src/*.*)
file(GLOB DISPLAY                   src/Display/*.*)
file(GLOB DISPLAY_FONT              src/Display/Font/*.*)
file(GLOB HARDWARE                  src/Hardware/*.*)
file(GLOB HARDWARE_CMSIS            src/Hardware/CMSIS/*.*)
file(GLOB HARDWARE_CDC              src/Hardware/CDC/*.*)
file(GLOB HARDWARE_HAL              src/Hardware/HAL/*.*)
file(GLOB HARDWARE_MODULES_BH1750   src/Hardware/Modules/BH1750/*.*)
file(GLOB HARDWARE_MODULES_BME280   src/Hardware/Modules/BME280/*.*)
file(GLOB HARDWARE_MODULES_CG_ANEM  src/Hardware/Modules/CG-Anem/*.*)
file(GLOB HARDWARE_MODULES_HC12     src/Hardware/Modules/HC12/*.*)
file(GLOB HARDWARE_MODULES_ST7735   src/Hardware/Modules/ST7735/*.*)
file(GLOB MENU                      src/Menu/*.*)
file(GLOB MENU_PAGES                src/Menu/Pages/*.*)
file(GLOB SETTINGS                  src/Settings/*.*)
file(GLOB UTILS                     src/Utils/*.*)
file(GLOB UTILS_TEXT                src/Utils/Text/*.*)

source_group(STM32F1                    FILES ${STM32F1})
source_group(src                        FILES ${SRC})
source_group(Display                    FILES ${DISPLAY})
source_group(Display/Font               FILES ${DISPLAY_FONT})
source_group(Hardware                   FILES ${HARDWARE})
source_group(Hardware/CMSIS             FILES ${HARDWARE_CMSIS})
source_group(Hardware/CDC               FILES ${HARDWARE_CDC})
source_group(Hardware/HAL               FILES ${HARDWARE_HAL})
source_group(Hardware/Modules/BH1750    FILES ${HARDWARE_MODULES_BH1750})
source_group(Hardware/Modules/BME280    FILES ${HARDWARE_MODULES_BME280})
source_group(Hardware/Modules/CG-Anem   FILES ${HARDWARE_MODULES_CG_ANEM})
source_group(Hardware/Modules/HC12      FILES ${HARDWARE_MODULES_HC12})
source_group(Hardware/Modules/ST7735    FILES ${HARDWARE_MODULES_ST7735})
source_group(Menu                       FILES ${MENU})
source_group(Menu/Pages                 FILES ${MENU_PAGES})
source_group(Settings                   FILES ${SETTINGS})
source_group(Utils                      FILES ${UTILS})
source_group(Utils/Text                 FILES ${UTILS_TEXT})

set_source_files_properties(
    ${STM32F1} ${HARDWARE_CMSIS}
    src/Hardware/CDC/usbd_desc.c
    src/Hardware/CDC/usb_device.c
    src/Hardware/CDC/usbd_conf.c
    PROPERTIES HEADER_FILE_ONLY TRUE
)

add_library(
    ${PROJECT_NAME}
    ${STM32F1}
    ${SRC}
    ${DISPLAY}
    ${DISPLAY_FONT}
    ${HARDWARE}
    ${HARDWARE_CMSIS}
    ${HARDWARE_CDC}
    ${HARDWARE_HAL}
    ${HARDWARE_MODULES_BH1750}
    ${HARDWARE_MODULES_BME280}
    ${HARDWARE_MODULES_CG_ANEM}
    ${HARDWARE_MODULES_HC12}
    ${HARDWARE_MODULES_ST7735}
    ${MENU}
    ${MENU_PAGES}
    ${SETTINGS} 
    ${UTILS}
    ${UTILS_TEXT}
)
