################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Reader/IRQ/EncoderTask.cpp \
../Core/Src/Reader/IRQ/IRQTask.cpp \
../Core/Src/Reader/IRQ/RpmTask.cpp 

OBJS += \
./Core/Src/Reader/IRQ/EncoderTask.o \
./Core/Src/Reader/IRQ/IRQTask.o \
./Core/Src/Reader/IRQ/RpmTask.o 

CPP_DEPS += \
./Core/Src/Reader/IRQ/EncoderTask.d \
./Core/Src/Reader/IRQ/IRQTask.d \
./Core/Src/Reader/IRQ/RpmTask.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Reader/IRQ/%.o Core/Src/Reader/IRQ/%.su Core/Src/Reader/IRQ/%.cyclo: ../Core/Src/Reader/IRQ/%.cpp Core/Src/Reader/IRQ/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Reader-2f-IRQ

clean-Core-2f-Src-2f-Reader-2f-IRQ:
	-$(RM) ./Core/Src/Reader/IRQ/EncoderTask.cyclo ./Core/Src/Reader/IRQ/EncoderTask.d ./Core/Src/Reader/IRQ/EncoderTask.o ./Core/Src/Reader/IRQ/EncoderTask.su ./Core/Src/Reader/IRQ/IRQTask.cyclo ./Core/Src/Reader/IRQ/IRQTask.d ./Core/Src/Reader/IRQ/IRQTask.o ./Core/Src/Reader/IRQ/IRQTask.su ./Core/Src/Reader/IRQ/RpmTask.cyclo ./Core/Src/Reader/IRQ/RpmTask.d ./Core/Src/Reader/IRQ/RpmTask.o ./Core/Src/Reader/IRQ/RpmTask.su

.PHONY: clean-Core-2f-Src-2f-Reader-2f-IRQ

