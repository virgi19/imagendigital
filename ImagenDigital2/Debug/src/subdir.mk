################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cara.cpp \
../src/Iluminacion.cpp \
../src/ImagenDigital2.cpp \
../src/Modelo3D.cpp \
../src/Normal.cpp \
../src/Punto3D.cpp 

OBJS += \
./src/Cara.o \
./src/Iluminacion.o \
./src/ImagenDigital2.o \
./src/Modelo3D.o \
./src/Normal.o \
./src/Punto3D.o 

CPP_DEPS += \
./src/Cara.d \
./src/Iluminacion.d \
./src/ImagenDigital2.d \
./src/Modelo3D.d \
./src/Normal.d \
./src/Punto3D.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


