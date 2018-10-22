# New Repository For CSCE315 Project 3

**Team member task allocation:**

1. Troy Fulton
2. James Johnson
3. Marshall Hobbs
4. Abdul Campos
5. Mashall Hobbs
6. James Johnson
7. Troy Fulton
8. Abdul Campos


I have tried compiling tests like AI_test with:

>  g++ -std=c++11 -Wall -I $(CATCH_SINGLE_INCLUDE) -o AI_test AI_test.cpp

but it does not seem to be working... It can't find the AI header for some reason.
I also know tried modifying:

> -I$(CATCH_SINGLE_INCLUDE);../include

to a couple different things but it still didn't work. If we can't figure it out 
how to compile this by lab, maybe we should just write our own.