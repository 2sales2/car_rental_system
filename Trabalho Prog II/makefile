CXX = g++
CXXFLAGS =-std=c++20 

SOURCES = \
	main.cpp \
	Agency.cpp \
	LegalPerson.cpp \
	NaturalPerson.cpp \
	Person.cpp \
	Car.cpp \
	RentRegister.cpp \
	Date.cpp\
	Payments.cpp\
	interfaceScreens.cpp


OBJECTS = $(SOURCES:.cpp=.o)
TARGET = rental_agency
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)