################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ContratException.cpp \
../src/Ordonnanceur.cpp \
../src/Processus.cpp \
../src/ProcessusTest.cpp \
../src/fileTesteur.cpp 

OBJS += \
./src/ContratException.o \
./src/Ordonnanceur.o \
./src/Processus.o \
./src/ProcessusTest.o \
./src/fileTesteur.o 

CPP_DEPS += \
./src/ContratException.d \
./src/Ordonnanceur.d \
./src/Processus.d \
./src/ProcessusTest.d \
./src/fileTesteur.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../TP1/header -I../TP1/TP1/header -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


