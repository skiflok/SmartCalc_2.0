CC = gcc -std=c++17 -g
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I includes
GCOV_LIBS=--coverage

PATH_TESTS = ./tests
PATH_MODEL = ./model

PATH_DATA = $(PATH_MODEL)/data
PATH_KERNEL = $(PATH_MODEL)/kernel

PATH_CALC = $(PATH_KERNEL)/calculators

TEST = $(PATH_TESTS)/tests.cc
SRC = $(PATH_MODEL)/model.cc \
	$(PATH_KERNEL)/parser.cc $(PATH_KERNEL)/validator.cc \
	$(PATH_CALC)/calculator.cc $(PATH_CALC)/calculator_credit.cc $(PATH_CALC)/calculator_deposit.cc $(PATH_CALC)/calculator_plot.cc

HEADERS = $(PATH_MODEL)/*.h $(PATH_DATA)/*.h $(PATH_KERNEL)/*.h
OBJ = $(SRC:.cc=.o)
LIBA = smart_calc_v2.a
EXE = smart_calc_v2
ARCHIVE_DIR = smart_calc_v2


OS = $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAGS = -lm -lgtest -lstdc++ -lgtest_main
else
	LIBFLAGS =  -lstdc++ `pkg-config --cflags --libs gtest  --libs gtest_main`
endif

all: install

build: clean
	mkdir build
	cd ./build/ && qmake ../ && make

install: build
	cd ./build/ && make clean
	./build/smartCalc.app/Contents/MacOS/smartCalc

uninstall:
	rm -rf build/

dist:
	rm -rf $(ARCHIVE_DIR)
	mkdir $(ARCHIVE_DIR)
	mkdir $(ARCHIVE_DIR)/src
	cp -r ./view ./controller ./model ./tests dvi.html Makefile $(ARCHIVE_DIR)/src/
	tar cvzf $(ARCHIVE_DIR).tgz $(ARCHIVE_DIR)
	rm -rf $(ARCHIVE_DIR)

dvi:
	open dvi.html

clean:
	@rm -rf *.gcda *.o *.a *.gcno *.tgz *.info report build smart_calc_v2 coverage $(ARCHIVE_DIR) $(OBJ)

%.o: %.cc
	$(CC) $(CFLAGS) $(LIBFLAGS) -c $^ -o $@

$(LIBA): $(OBJ)
	ar rcs $(LIBA) $^

tests: $(LIBA)
	$(CC) $(CFLAGS) $(TEST) $(LIBFLAGS) $(LIBA) -o $(EXE) -lm
	./$(EXE)

gcov_report: $(LIBA)
	$(CC) $(GCOV_LIBS) $(TEST) $(SRC) $(LIBFLAGS) $(LIBA) -o coverage -lm
	./coverage
	lcov -t "coverage" -c -d  ./ --no-external --output-file ./coverage.info
	genhtml ./coverage.info --output-directory ./report/
	open ./report/index.html

check: $(LIBA)
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(TEST) $(SRC) $(HEADERS)
	clang-format -i $(TEST) $(SRC) $(HEADERS)
	clang-format -n $(TEST) $(SRC) $(HEADERS)

leaks: $(LIBA)
	$(CC) $(CFLAGS) $(TEST) $(LIBFLAGS) $(LIBA) -o $(EXE) -lm
ifeq ($(OS), Darwin)
	leaks -atExit -- ./$(EXE)
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(EXE)
endif

rebuild: clean uninstall all

reinstall: clean uninstall install

.PHONY: all build install uninstall dist dvi clean tests gcov_report check leaks rebuild reinstall