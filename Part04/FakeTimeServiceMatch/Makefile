TARGET= faketimeservicetest

SRCS= FakeTimeServiceTest.cpp \
      FakeTimeService.c

INCLUDE_FILES= FakeTimeService.h \
               TimeService.h

CC= g++
CFLAGS= -Wall
INCLUDES= -I/usr/include/CppUTest
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