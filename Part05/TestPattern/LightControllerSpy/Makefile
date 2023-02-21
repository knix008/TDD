TARGET= lightcontrollertest

LIGHTCONTROLLER_DIR= ../LightController
LIGHTDRIVER_DIR= ../LightDriver
LIGHTDRIVERSPY_DIR= ../LightDriverSpy

SRCS= LightControllerSpyTest.cpp \
      LightControllerSpy.c \
	  $(LIGHTDRIVER_DIR)/LightDriver.c

INCLUDE_FILES= $(LIGHTCONTROLLER_DIR)/LightController.h \
               $(LIGHTDRIVER_DIR)/LightDriver.h \
			   $(LIGHTDRIVERSPY_DIR)/LightDriverSpy.h \
               LightControllerSpy.h

INCLUDES= -I$(LIGHTCONTROLLER_DIR) \
          -I$(LIGHTDRIVER_DIR) \
		  -I$(LIGHTDRIVERSPY_DIR)

CC= g++
CFLAGS= -Wall
INCLUDES+= -I/usr/include/CppUTest
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a
CPPUTESTRUN_OPTION= -c
.SILENT: $(TARGET) clean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET) $(CPPUTESTRUN_OPTION)

clean:
	@rm $(TARGET)