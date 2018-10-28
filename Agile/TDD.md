Here, we can document changes we make to how we test the code so we can 
discuss them in the final report.

It would be great if someone could discuss how we tested the code (what framework we used and how we came up with tests).

> TEST_CASE( "AI Test calculateMove 1", "[single-file]" ) {
    int* stack = new int[4]{1, 2, 4, 3};
    AI tester(4, NULL, 1);
    int* solution = new int[4]{1, 2, 3, 4};
    int AImove = tester.calculateMove();
    CHECK( AImove == 2 );
    tester.makeMove(AImove);
    REQUIRE( tester.getStack()[2] == solution[2] );
}