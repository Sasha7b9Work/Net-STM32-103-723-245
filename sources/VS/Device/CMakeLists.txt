# (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by

project (Device)

#set(CMAKE_UNITY_BUILD OFF)

set(CMAKE_UNITY_BUILD_BATCH_SIZE 16)


include_directories(
    .
    Device
    ../../Device/src
    ../../Device/src/Hardware/CDC
    ../../Device/src/Hardware/HAL
    ../../common/_VS_KEIL/CMSIS
    ../../common/_VS_LIBS/STM32F1
    ../../VS/ThirdParty/wxWidgets/include
    ../../generated/ThirdParty/lib/vc_dll/mswud
    ../../generated/ThirdParty/lib/vc_lib/mswud
    ../../common/STM32Cube_F1/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
    ../../common/STM32Cube_F1/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    ../../common/STM32Cube_F1/Drivers/CMSIS/Device/ST/STM32F1xx/Include
    ../../common/STM32Cube_F1/Drivers/STM32F1xx_HAL_Driver/Inc
)

link_directories(
    ../../generated/ThirdParty/lib/vc_dll
    ../../generated/ThirdParty/lib/vc_lib
)

add_definitions(-DSTM32F103xB -DDEVICE -DGUI)

if(WIN32)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MP -Wall")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

    add_compile_options(
        /wd4365
        /wd4514
        /wd4623
        /wd4625
        /wd4626
        /wd4774
        /wd4820
        /wd4996
        /wd5026
        /wd5027
        /wd5039    # 'xxx': pointer or reference to potentially throwing function passed to extern C
                   # function under -EHc.
        /wd5045
        /wd5220
        /wd5267
    )
endif()

file(GLOB LIBS_STM32F1              ../../common/_VS_LIBS/STM32f1/*.*)
file(GLOB LIBS_STM32F1_INC          ../../common/STM32Cube_F1/Drivers/STM32F1xx_HAL_Driver/Inc/*.*)
file(GLOB LIBS_USBD                 ../../common/_VS_LIBS/USBD/*.*)
file(GLOB SRC                       *.h *.cpp
                                    ../../Device/src/defines.h
                                    ../../Device/src/Device.*)
file(GLOB DISPLAY                   ../../Device/src/Display/*.*)
file(GLOB DISPLAY_FONT              ../../Device/src/Display/Font/*.*)
file(GLOB HARDWARE                  ../../Device/src/Hardware/*.*)
file(GLOB HARDWARE_CDC              ../../Device/src/Hardware/CDC/*.*
                                                     Hardware/CDC/*.*)
file(GLOB HARDWARE_HAL              ../../Device/src/Hardware/HAL/*.*
                                                     Hardware/HAL/*.*)
file(GLOB HARDWARE_LAN                               Hardware/LAN/*.*)
file(GLOB HARDWARE_LAN_LIBNET                        Hardware/LAN/libnet/*.*)
file(GLOB HARDWARE_MODULES_BH1750   ../../Device/src/Hardware/Modules/BH1750/*.*)
file(GLOB HARDWARE_MODULES_BME280   ../../Device/src/Hardware/Modules/BME280/*.*)
file(GLOB HARDWARE_MODULES_CG_ANEM  ../../Device/src/Hardware/Modules/CG-Anem/*.*)
file(GLOB HARDWARE_MODULES_HC12     ../../Device/src/Hardware/Modules/HC12/*.*)
file(GLOB HARDWARE_MODULES_ST7735   ../../Device/src/Hardware/Modules/ST7735/*.*)
file(GLOB MENU                      ../../Device/src/Menu/*.*)
file(GLOB MENU_PAGES                ../../Device/src/Menu/Pages/*.*)
file(GLOB SETTINGS                  ../../Device/src/Settings/*.*)
file(GLOB UTILS                     ../../Device/src/Utils/*.*)
file(GLOB UTILS_TEXT                ../../Device/src/Utils/Text/*.*)

source_group(libs/STM32F1               FILES ${LIBS_STM32F1})
source_group(libs/STM32F1/Inc           FILES ${LIBS_STM32F1_INC})
source_group(libs/USBD                  FILES ${LIBS_USBD})
source_group(src                        FILES ${SRC})
source_group(Display                    FILES ${DISPLAY})
source_group(Display/Font               FILES ${DISPLAY_FONT})
source_group(Hardware                   FILES ${HARDWARE})
source_group(Hardware/CDC               FILES ${HARDWARE_CDC})
source_group(Hardware/HAL               FILES ${HARDWARE_HAL})
source_group(Hardware/LAN               FILES ${HARDWARE_LAN})
source_group(Hardware/LAN/libnet        FILES ${HARDWARE_LAN_LIBNET})
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
    Hardware/LAN/libnet/netserver.cpp
    Hardware/LAN/libnet/netbase.cpp
    Hardware/LAN/libnet/netclient.cpp
    Hardware/LAN/libnet/netpacket.cpp
    Hardware/LAN/ClientTCP.cpp
    Application.cpp
    Frame.cpp
    main_win.cpp
    PROPERTIES SKIP_UNITY_BUILD_INCLUSION ON
)


set_source_files_properties(
    ../../Device/src/Hardware/CDC/usbd_conf.c
    PROPERTIES HEADER_FILE_ONLY TRUE
)

add_executable( ${PROJECT_NAME}
    ${LIBS_STM32F1}
    ${LIBS_STM32F1_INC}
    ${LIBS_USBD}
    ${SRC}
    ${DISPLAY}
    ${DISPLAY_FONT}
    ${HARDWARE}
    ${HARDWARE_CDC}
    ${HARDWARE_HAL}
    ${HARDWARE_LAN}
    ${HARDWARE_LAN_LIBNET}
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

target_link_libraries(${PROJECT_NAME}
    wxbase32ud wxmsw32ud_core wxpngd wxzlibd
    Ws2_32 Comctl32 Rpcrt4
)
