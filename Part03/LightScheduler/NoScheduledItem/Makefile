TARGET= lightschedulerteset

FAKETIMESERVICE_DIR= ../FakeTimeService
LIGHTCONTROLLERSPY_DIR= ../LightControllerSpy

SRCS= LightSchedulerTest.cpp \
      LightScheduler.c \
      $(FAKETIMESERVICE_DIR)/FakeTimeService.c \
      $(LIGHTCONTROLLERSPY_DIR)/LightControllerSpy.c

INCLUDE_FILES= LightScheduler.h \
               $(FAKETIMESERVICE_DIR)/FakeTimeService.h \
               $(LIGHTCONTROLLERSPY_DIR)/LightControllerSpy.h

INCLUDES= -I$(FAKETIMESERVICE_DIR) \
          -I$(LIGHTCONTROLLERSPY_DIR)
            
CC= g++
CFLAGS= -Wall
INCLUDES+= -I/usr/include/CppUTest
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a
CPPUTESTRUN_OPTION= -c
.SILENT: $(TARGET) clean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET) $(CPPUTESTRUN_OPTION)

clean:
	@rm $(TARGET)