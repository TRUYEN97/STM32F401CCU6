################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Common/ISR/TimeTickerForISR.cpp 

OBJS += \
./Core/Src/Common/ISR/TimeTickerForISR.o 

CPP_DEPS += \
./Core/Src/Common/ISR/TimeTickerForISR.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Common/ISR/%.o Core/Src/Common/ISR/%.su Core/Src/Common/ISR/%.cyclo: ../Core/Src/Common/ISR/%.cpp Core/Src/Common/ISR/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Common-2f-ISR

clean-Core-2f-Src-2f-Common-2f-ISR:
	-$(RM) ./Core/Src/Common/ISR/TimeTickerForISR.cyclo ./Core/Src/Common/ISR/TimeTickerForISR.d ./Core/Src/Common/ISR/TimeTickerForISR.o ./Core/Src/Common/ISR/TimeTickerForISR.su

.PHONY: clean-Core-2f-Src-2f-Common-2f-ISR
