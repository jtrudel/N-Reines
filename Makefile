CC = g++ 
CXXFLAGS = -std=c++11 -g -Wall -O2
LDFLAGS = -O2
#DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
#POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

PROG = solution

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRCS := $(wildcard $(SRCDIR)/*.cpp)
INCS := $(wildcard $(SRCDIR)/*.h)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TARGET := $(BINDIR)/$(PROG)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
