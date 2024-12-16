################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Model/EncodeModel.cpp \
../Core/Src/Model/ModelManagement.cpp \
../Core/Src/Model/SensorModel.cpp 

OBJS += \
./Core/Src/Model/EncodeModel.o \
./Core/Src/Model/ModelManagement.o \
./Core/Src/Model/SensorModel.o 

CPP_DEPS += \
./Core/Src/Model/EncodeModel.d \
./Core/Src/Model/ModelManagement.d \
./Core/Src/Model/SensorModel.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Model/%.o Core/Src/Model/%.su Core/Src/Model/%.cyclo: ../Core/Src/Model/%.cpp Core/Src/Model/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Model

clean-Core-2f-Src-2f-Model:
	-$(RM) ./Core/Src/Model/EncodeModel.cyclo ./Core/Src/Model/EncodeModel.d ./Core/Src/Model/EncodeModel.o ./Core/Src/Model/EncodeModel.su ./Core/Src/Model/ModelManagement.cyclo ./Core/Src/Model/ModelManagement.d ./Core/Src/Model/ModelManagement.o ./Core/Src/Model/ModelManagement.su ./Core/Src/Model/SensorModel.cyclo ./Core/Src/Model/SensorModel.d ./Core/Src/Model/SensorModel.o ./Core/Src/Model/SensorModel.su

.PHONY: clean-Core-2f-Src-2f-Model

