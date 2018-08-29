/*
 * task.h
 *
 *  Created on: 26-Feb-2018
 *      Author: edutech
 */

#ifndef TASK_H_
#define TASK_H_


size_t numRows();
size_t numCols();

void preProcess(uchar4 **inputImage, unsigned char **greyImage,
                uchar4 **d_rgbaImage, unsigned char **d_greyImage,
                const std::string &filename);

void postProcess(const std::string& output_file, unsigned char* data_ptr);

void cleanup();

void generateReferenceImage(std::string input_filename, std::string output_filename);


#endif /* TASK_H_ */
