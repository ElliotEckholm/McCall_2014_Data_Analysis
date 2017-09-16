#ifndef __IO_VIZ_H__
#define __IO_VIZ_H__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <string>

/********************************
* readBinaryFile2D:  Reads table of binary data from fileName into data, and sets num_lines and num_fields to appropriate values.
*
* fileName:      File name of input file to read.
* data:          2D array for storing data.  Consists of num_lines (rows) * num_fields (cols) entries.
* num_lines:     Number of rows in data.
* num_fields:    Number of cols in data.
*
* call function using, for example:
*
*    double ** data;
*    int num_lines, num_fields;
*    readBinaryFile ("path/to/file.bin", data, num_lines, num_fields);
*
* *********************************/
template <typename T>
int readBinaryFile2D (std::string fileName, T ** &data, int &num_lines, int &num_fields) {

    std::cout << "Reading binary file: \"" << fileName << "\"" << std::endl;

    std::ifstream inpt(fileName,std::ios::in|std::ios::binary);

    long int header[2];

    // read header
    inpt.read((char *)header, 2*sizeof(long int));

    num_lines = header[0];
    num_fields = header[1];

    std::cout << "Number of lines: " << num_lines << std::endl;
    std::cout << "Number of fields: " << num_fields << std::endl;

    data = (T **) malloc (num_lines * sizeof(T *));

    int dot_freq = int(ceil(num_lines/10.));

    for (int i = 0; i < num_lines; i++) {
        if (i % dot_freq == 0) {
            std::cout << ".";
            std::cout.flush();
        }
        data[i] = (T *) malloc (num_fields * sizeof(T));
        inpt.read((char *)data[i],sizeof(T)*num_fields);
    }

    inpt.close();

    std::cout << " complete." << std::endl;

    return 0;
}

/********************************
* writeBinaryFile2D:  Writes output file in binary format.
*
* outputFile:    File name of output file to be written.
* data:          2D data to write to output file.  Consists of num_lines (rows) * num_fields (cols) entries.
* num_lines:     Number of rows in data.
* num_fields:    Number of cols in data.
* *********************************/
template <typename T>
int writeBinaryFile2D (std::string outputFile, T ** &data, int num_lines, int num_fields) {

    std::ofstream outfile;
    outfile.open(outputFile.c_str(),std::ios::out|std::ios::binary);

    std::cout << "Writing output file \"" << outputFile << "\"" << std::endl;
    std::cout << "Number of lines: " << num_lines << std::endl;
    std::cout << "Number of fields: " << num_fields << std::endl;

    long int header[2] = {num_lines, num_fields};

    outfile.write((const char *)header,2*sizeof(long int));

    int dot_freq = int(ceil(num_lines/10.));

    for (int i = 0; i < num_lines; i++) {
        if (i % dot_freq == 0) {
            std::cout << ".";
            std::cout.flush();
        }
        outfile.write((const char *)data[i],num_fields*sizeof(T));
    }

    std::cout << " complete." << std::endl;

    outfile.close();

	return 0;
}

/********************************
* readBinaryFile1D:  Reads table of binary data from fileName into data, and sets num_lines appropriate value.
*
* fileName:      File name of input file to read.
* data:          1D array for storing data.  Consists of num_lines (rows) entries.
* num_lines:     Number of rows in data.
*
* call function using, for example:
*
*    double ** data;
*    int num_lines;
*    readBinaryFile ("path/to/file.bin", data, num_lines);
*
* *********************************/
template <typename T>
int readBinaryFile1D (std::string fileName, T * &data, int &num_lines) {

    std::cout << "Reading binary file: \"" << fileName << "\"" << std::endl;

    std::ifstream inpt(fileName,std::ios::in|std::ios::binary);

    long int header[1];

    // read header
    inpt.read((char *)header, sizeof(long int));

    num_lines = header[0];

    std::cout << "Number of lines: " << num_lines << std::endl;

    data = (T *) malloc (num_lines * sizeof(T));

    inpt.read((char *)data, sizeof(T)*num_lines);

    inpt.close();

    std::cout << " complete." << std::endl;

    return 0;
}

/********************************
* writeBinaryFile1D:  Writes output file in binary format.
*
* outputFile:    File name of output file to be written.
* data:          1D data to write to output file.  Consists of num_lines (rows) entries.
* num_lines:     Number of rows in data.
* *********************************/
template <typename T>
int writeBinaryFile1D (std::string outputFile, T * &data, int num_lines) {

    std::ofstream outfile;
    outfile.open(outputFile.c_str(),std::ios::out|std::ios::binary);

    std::cout << "Writing output file \"" << outputFile << "\"" << std::endl;
    std::cout << "Number of lines: " << num_lines << std::endl;

    long int header[1] = {num_lines};

    outfile.write((const char *)header, sizeof(long int));

    outfile.write((const char *)data, num_lines * sizeof(T));

    std::cout << " complete." << std::endl;

    outfile.close();

	return 0;
}

#endif
