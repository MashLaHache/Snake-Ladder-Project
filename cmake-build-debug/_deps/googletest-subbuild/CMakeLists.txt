# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.25.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(googletest-populate NONE)



include(ExternalProject)
ExternalProject_Add(googletest-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip" "DOWNLOAD_DIR" "C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/dependencies" DOWNLOAD_NO_EXTRACT YES
                    SOURCE_DIR          "C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/_deps/googletest-src"
                    BINARY_DIR          "C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/_deps/googletest-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


ExternalProject_Get_Property(googletest-populate DOWNLOADED_FILE)
get_filename_component(dlFileName "${DOWNLOADED_FILE}" NAME)

ExternalProject_Add_Step(googletest-populate copyfile
  COMMAND    "C:/Users/Lanla/AppData/Local/JetBrains/Toolbox/apps/CLion/ch-0/231.9011.31/bin/cmake/win/x64/bin/cmake.exe" -E copy_if_different
             "<DOWNLOADED_FILE>" "C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/_deps/googletest-src"
  DEPENDEES  patch
  DEPENDERS  configure
  BYPRODUCTS "C:/Users/Lanla/OneDrive/Documents/ift2008/TP1/SerpentEchelle/cmake-build-debug/_deps/googletest-src/${dlFileName}"
  COMMENT    "Copying file to SOURCE_DIR"
)

