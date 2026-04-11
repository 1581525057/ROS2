CC = gcc
CFLAGS = -Wall -Wextra -ICore/Inc
LDLIBS = -lm
SRC_DIR = Core/Src
TESTS = test_protocol test_mecanum test_navigation

.PHONY: all run clean

all: $(TESTS)

test_protocol: tests/test_protocol.c $(SRC_DIR)/protocol.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

test_mecanum: tests/test_mecanum.c $(SRC_DIR)/mecanum.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

test_navigation: tests/test_navigation.c $(SRC_DIR)/navigation.c $(SRC_DIR)/mecanum.c
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

run: all
	./test_protocol && ./test_mecanum && ./test_navigation

clean:
	rm -f $(TESTS)
