/* 
 * First step: (Will be needing the other files)
 *  Reading a .xml file using the programm "verArquivo.cpp"
 * Second step: (Algorithm and logic)
 *  After reading:
 *  -> Analyse the matrix;
 *  -> Look for areas;
 *  -> Count.
 * 
 *  (NEEDS MORE DETAILS.)
 */

// #include "verArquivo.cpp"

unsigned short int height, width; // ---> <height> ... </height> & <width> ... </width> from a .xml file
unsigned short int label;

/*
 * The "label" var will be counting how many connected regions the .xml file has based on the connected "1"s.
 * For each connected region, we will be assigning "label + 1", except for the first, which will be full of "1"s; so the second will be
 * full of "2"s and so on.
 * Label starts being 1, in order to not blend with the zeros.
 */

for (int i = 0; i < height; i++) {
    for (int j = 0; i < width; j++) {

    }
}