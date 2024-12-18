################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Model/Process/BaseModel.cpp \
../Core/Src/Model/Process/ContestModel.cpp \
../Core/Src/Model/Process/ErrorCode.cpp \
../Core/Src/Model/Process/LocationModel.cpp \
../Core/Src/Model/Process/TestModeModel.cpp \
../Core/Src/Model/Process/UserModel.cpp 

OBJS += \
./Core/Src/Model/Process/BaseModel.o \
./Core/Src/Model/Process/ContestModel.o \
./Core/Src/Model/Process/ErrorCode.o \
./Core/Src/Model/Process/LocationModel.o \
./Core/Src/Model/Process/TestModeModel.o \
./Core/Src/Model/Process/UserModel.o 

CPP_DEPS += \
./Core/Src/Model/Process/BaseModel.d \
./Core/Src/Model/Process/ContestModel.d \
./Core/Src/Model/Process/ErrorCode.d \
./Core/Src/Model/Process/LocationModel.d \
./Core/Src/Model/Process/TestModeModel.d \
./Core/Src/Model/Process/UserModel.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Model/Process/%.o Core/Src/Model/Process/%.su Core/Src/Model/Process/%.cyclo: ../Core/Src/Model/Process/%.cpp Core/Src/Model/Process/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Model-2f-Process

clean-Core-2f-Src-2f-Model-2f-Process:
	-$(RM) ./Core/Src/Model/Process/BaseModel.cyclo ./Core/Src/Model/Process/BaseModel.d ./Core/Src/Model/Process/BaseModel.o ./Core/Src/Model/Process/BaseModel.su ./Core/Src/Model/Process/ContestModel.cyclo ./Core/Src/Model/Process/ContestModel.d ./Core/Src/Model/Process/ContestModel.o ./Core/Src/Model/Process/ContestModel.su ./Core/Src/Model/Process/ErrorCode.cyclo ./Core/Src/Model/Process/ErrorCode.d ./Core/Src/Model/Process/ErrorCode.o ./Core/Src/Model/Process/ErrorCode.su ./Core/Src/Model/Process/LocationModel.cyclo ./Core/Src/Model/Process/LocationModel.d ./Core/Src/Model/Process/LocationModel.o ./Core/Src/Model/Process/LocationModel.su ./Core/Src/Model/Process/TestModeModel.cyclo ./Core/Src/Model/Process/TestModeModel.d ./Core/Src/Model/Process/TestModeModel.o ./Core/Src/Model/Process/TestModeModel.su ./Core/Src/Model/Process/UserModel.cyclo ./Core/Src/Model/Process/UserModel.d ./Core/Src/Model/Process/UserModel.o ./Core/Src/Model/Process/UserModel.su

.PHONY: clean-Core-2f-Src-2f-Model-2f-Process

