TARGET= Calculator
TARGET_TEST= CalculatorTest
CC=g++
CXXFLAGS= -Wall
LIBS= -lcppunit

SRCS= main.cpp \
      Calculator.cpp

INCS= Calculator.h

TEST_SRCS= Calculator.cpp \
           CalculatorTest.cpp \
		   CalculatorTestMain.cpp

TEST_INCS= $(INCS) \
           CalculatorTest.h \

all: $(TARGET) $(TARGET_TEST)
	
$(TARGET): $(SRCS) $(INCS)	
	@echo "Building Target : $(TARGET) ..."
	@$(CC) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	@echo "Running Target..."
	@echo "================="
	@./$(TARGET)

$(TARGET_TEST): $(SRCS) $(TEST_SRCS) $(TEST_INCS)
	@echo ""
	@echo "Building Target Test : $(TARGET_TEST) ..."
	@$(CC) $(CXXFLAGS) -o $(TARGET_TEST) $(TEST_SRCS) $(LIBS)
	@echo "Running Target Test..."
	@echo "======================"
	@./$(TARGET_TEST)

clean:
	@-rm $(TARGET)
	@-rm $(TARGET_TEST)