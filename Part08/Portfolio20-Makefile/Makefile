TARGET= PortfolioTest
CC= g++
GOOGLETEST_OPTION= --gtest_catch_exceptions=0
CXXFLAGS= -Wall --std=c++0x

INCLUDE_DIRS= -I/usr/local/include/gtest \
              -I/usr/local/include/gmock \
		      -I/usr/local/include/boost

LIBS= /usr/local/lib/libgmock.a \
      /usr/local/lib/libgtest.a \
	  -lpthread

INCLUDE_FILES= DateTestConstants.h \
               Holding.h \
			   Portfolio.h \
			   PurchaseRecord.h

SOURCES= main.cpp \
         Holding.cpp \
		 HoldingTest.cpp \
		 Portfolio.cpp \
		 PortfolioTest.cpp 

OBJECTS= $(SOURCES:.cpp=.o)
.PHONY: clean

all:$(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) $(SOURCES) $(INCLUDE_FILES)
	@echo "Building Executable..."
	@$(CC) $(CXXFLAGS) $(OBJECTS) -o $@ $(INCLUDE_DIRS) $(LIBS)
	@echo "Running Test..."
	@./$(TARGET) $(GOOGLETEST_OPTION)

.cpp.o:
	@echo "Compiling $<..."
	@$(CC) $(CXXFLAGS) $< -c -o $@

clean:
	@rm *.o
	@rm $(TARGET)
