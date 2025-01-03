CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS= $(shell pkg-config --cflags check) $(shell pkg-config --libs check) -lpthread -lm
BUILD=./

MATRIX_LIB=s21_matrix.a
MATRIX_ALL_C=./*.c
MATRIX_ALL_H=./*.h 

TESTS_RUNNER=s21_matrix_tests_runner
TESTS_ALL_C=./tests/*.c
TESTS_ALL_H=./tests/*.h

PRJ_CODE_ALL=$(MATRIX_ALL_C) $(MATRIX_ALL_H) $(TESTS_ALL_C) $(TESTS_ALL_H)

VALGRIND=valgrind --leak-check=full --show-reachable=no

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
TFLAGS += -lsubunit -lrt 
endif

all: test

$(MATRIX_LIB): clean
	$(CC) $(CFLAGS) -c $(MATRIX_ALL_C) 
	ar rcs $(BUILD)$(MATRIX_LIB) ./*.o
	ranlib $(BUILD)$(MATRIX_LIB) 
	rm -f ./*.o

test: clean clang $(MATRIX_LIB)
	$(CC) $(CFLAGS) $(TESTS_ALL_C) $(BUILD)$(MATRIX_LIB)  $(TFLAGS) -o $(BUILD)$(TESTS_RUNNER)
	$(BUILD)$(TESTS_RUNNER)

clean:
	rm -f $(BUILD)*.o $(BUILD)$(MATRIX_LIB) $(BUILD)$(TESTS_RUNNER) \
		  $(BUILD)*.gcda $(BUILD)*.gcno $(BUILD)*.gcov
	rm -rf $(BUILD)report_lcov
	rm -rf $(BUILD)report_gcov


clang:
	cp ../materials/linters/.clang-format ./ 
	clang-format -i $(PRJ_CODE_ALL)
	clang-format -n $(PRJ_CODE_ALL)
	rm -f ./.clang-format

lcov_report:
	$(CC) $(CFLAGS) --coverage $(TESTS_ALL_C) $(MATRIX_ALL_C) \
							$(TFLAGS) -o $(BUILD)$(TESTS_RUNNER)			
	$(BUILD)$(TESTS_RUNNER)

	rm -rf $(BUILD)report_lcov
	mkdir $(BUILD)report_lcov
	lcov -t "$(TESTS_RUNNER)" -c -d $(BUILD) \
					-o $(BUILD)report_lcov/$(TESTS_RUNNER)_report_lcov.info 
	genhtml -o $(BUILD)report_lcov $(BUILD)report_lcov/$(TESTS_RUNNER)_report_lcov.info
	open $(BUILD)report_lcov/index.html
	rm -f $(BUILD)*.gcda $(BUILD)*.gcno

gcov_report:
	$(CC) $(CFLAGS) --coverage $(TESTS_ALL_C) $(MATRIX_ALL_C) \
							$(TFLAGS) -o $(BUILD)$(TESTS_RUNNER)			
	$(BUILD)$(TESTS_RUNNER)
	gcov -o  $(BUILD)*.gcno
	rm -rf $(BUILD)report_gcov
	mkdir $(BUILD)report_gcov
	gcovr -r $(BUILD) --exclude 'tests/' --exclude 's21_is_a_good_matrix.c' --exclude 's21_helpers.c' --html --html-details \
				-o $(BUILD)report_gcov/$(TESTS_RUNNER)_report_gcov.html
	open $(BUILD)report_gcov/$(TESTS_RUNNER)_report_gcov.html
	rm -f $(BUILD)*.gcda $(BUILD)*.gcno $(BUILD)*.gcov

valgrind:
	$(VALGRIND) $(BUILD)$(TESTS_RUNNER)
