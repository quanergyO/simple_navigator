
CXX = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra
SANITIZE = -fsanitize=address
FILES = graph/*.cc graph_algorithms/*.cc
TARGETS = tests/tests.cc
GCOV = -fprofile-arcs -ftest-coverage -fPIC -pthread
GTEST = -lgtest -lgtest_main

all: test

test: clean
	${CXX} ${TARGETS} ${FLAGS} ${FILES} ${FLAGS} ${GCOV} ${GTEST} -o test
	./test

gcov_report: tests
	mkdir report
	gcovr --html-details -o report/coverage.html
	open ./report/coverage.html

clean:
	rm -rf *.o *.out *.gch *.dSYM *.gcov *.gcda *.gcno *.a *.css *.html *.info test test_asan report
.PHONY: tests clean gcov_report style



dvi:
	doxygen Doxyfile
	open html/index.html

clang-format:
	clang-format --style=file:../materials/linters/.clang-format -i $(find . -type f -name "*.h")
	clang-format --style=file:../materials/linters/.clang-format -i $(find . -type f -name "*.cc")
	clang-format --style=file:../materials/linters/.clang-format -i $(find . -type f -name "*.cpp")
