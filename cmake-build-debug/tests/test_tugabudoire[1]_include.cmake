if(EXISTS "C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/tests/test_tugabudoire[1]_tests.cmake")
  include("C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/tests/test_tugabudoire[1]_tests.cmake")
else()
  add_test(test_tugabudoire_NOT_BUILT test_tugabudoire_NOT_BUILT)
endif()
