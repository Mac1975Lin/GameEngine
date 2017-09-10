#ifndef _JPEG_H_
#define _JPEG_H_

extern "C"
{

#include "jpeglib.h"

/** 
 * use libjpeg convert JPEG image buffer to rgb buffer, decompression
 *  
 * @param[IN]  jpeg_buffer  JPEG image buffer
 * @param[IN]  jpeg_size    JPEG image buffer size 
 * @param[IN] rgb_buffer    rgb image buffer 
 * @param[IN/OUT] size      rgb image buffer size 
 * @param[OUT] width        image width
 * @param[OUT] height       image height
 * 
 * @return  
 *         0：success
 *         -1：failed
 * @note 
 *         jpeg、rgb buffer is allocated by user，size input/output param，传入为rgb空间大小，转出为rgb实际大小 
 */  
int jpeg2rgb(unsigned char* jpeg_buffer, int jpeg_size, unsigned char* rgb_buffer, int* size, int* width, int* height);  
  
/** 
 * user libjpeg to convert rgb buffer to jpeg buffer, compression
 *  
 * @param[IN]  rgb_buffer  rgb buffer
 * @param[IN]  width       image width
 * @param[IN]  height      image height 
 * @param[IN]  quality     quality 0- 9
 * @param[OUT] jpeg_buffer jpeg buffer pointer 
 * @param[OUT] jpeg_size   jpeg buffer size
 * 
 * @return  
 *         0：成功 
 *         -1：打开文件失败 
 * @note 
 *         jpeg_buffer is allocated by this libjpeg，but caller has to release the function.
 */  
int rgb2jpeg(unsigned char* rgb_buffer, int width, int height, int quality, unsigned char** jpeg_buffer, unsigned long* jpeg_size); 

};

#endif