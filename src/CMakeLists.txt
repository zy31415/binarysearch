add_library(binary_search
        binary_search.c
        binary_search.h
        )

add_executable(
        generate_bin_file.bin
        genbinfile/generate_bin_file.c
)

add_executable(
        seq_search.bin
        binarysearchfile/seq_search.c
)

add_executable(
        bin_search.bin
        binarysearchfile/bin_search.c
)

add_executable(
        check_bin_file.bin
        genbinfile/check_bin_file.c
)