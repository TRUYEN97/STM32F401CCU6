################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Reader/MyPin.cpp \
../Core/Src/Reader/SensorReader.cpp 

OBJS += \
./Core/Src/Reader/MyPin.o \
./Core/Src/Reader/SensorReader.o 

CPP_DEPS += \
./Core/Src/Reader/MyPin.d \
./Core/Src/Reader/SensorReader.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Reader/%.o Core/Src/Reader/%.su Core/Src/Reader/%.cyclo: ../Core/Src/Reader/%.cpp Core/Src/Reader/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Reader

clean-Core-2f-Src-2f-Reader:
	-$(RM) ./Core/Src/Reader/MyPin.cyclo ./Core/Src/Reader/MyPin.d ./Core/Src/Reader/MyPin.o ./Core/Src/Reader/MyPin.su ./Core/Src/Reader/SensorReader.cyclo ./Core/Src/Reader/SensorReader.d ./Core/Src/Reader/SensorReader.o ./Core/Src/Reader/SensorReader.su

.PHONY: clean-Core-2f-Src-2f-Reader

