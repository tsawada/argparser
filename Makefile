.PHONY: test

test: ArgParser_test
	./ArgParser_test

ArgParser_test: ArgParser_test.cpp ArgParser.h
	$(CXX) $< -o $@
