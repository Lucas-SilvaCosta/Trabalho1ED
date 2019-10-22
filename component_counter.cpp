#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "array_queue.h"

using namespace std;

/*
 * The "label" var will be counting how many connected regions the .xml file has based on the connected "1"s.
 * For each connected region, we will be assigning "label + 1", except for the first, which will be full of "1"s; so the second will be
 * full of "2"s and so on.
 * Label starts being 1, in order to not blend with the zeros.
 */

string name; // ------> <name> ... </name>
unsigned int hgt = 1, wth = 1; // ---> <height> ... </height> & <width> ... </width> from a .xml file
unsigned int in[hgt][wth], out[hgt][wth];
unsigned int label; // ---> Result
structures::ArrayQueue<int[]> ql[hgt * wth]; // ----> Try to optmize later!

int connect_four() {
    label = 1;
    for (int i = 0; i < hgt; i++) {
        for (int j = 0; j < wth; j++) {
            out[i][j] = 0; // ----> Resets the matrix
            if (in[i][j] == 1) {
                out[i][j] = label;
        }
    }

    for (int i = 0; i < hgt; i++) {
        for (int j = 0; j < wth; j++) {
            if (in[i][j] == 1) {
                ql.enqueue({i, j});
                while (!ql.empty) {
                    int[] t = ql.dequeue();
                    in[t[0]][t[1]] = 0;
                    out[t[0]][t[1]] = label;
                    if (i != 0 && in[i - 1][j] == 1) { // Above
                        ql.enqueue({i - 1, j});
                    }
                    if (i != hgt - 1 && in[i + 1][j] == 1) { // Below
                        ql.enqueue({i + 1, j});
                    }
                    if (j != 0 && in[i][j - 1] == 1) { // Left
                        ql.enqueue({i, j - 1});
                    }
                    if (j != wth - 1 && in[i][j + 1] == 1) { // Right
                        ql.enqueue({i, j + 1});
                    }
                }
                label++;
            }
        }
    }
}
